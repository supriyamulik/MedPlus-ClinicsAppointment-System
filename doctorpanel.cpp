#include "doctorpanel.h"
#include "ui_doctorpanel.h"
#include <QDateTime>
#include <QInputDialog>

DoctorPanel::DoctorPanel(int doctorId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DoctorPanel)
    , m_doctorId(doctorId)
    , autoRefreshTimer(nullptr)
{
    ui->setupUi(this);
    this->setStyleSheet(
        "QMainWindow { background-color: white; color: black; }"
        "QMessageBox { background-color: white; color: white; }"
        "QMessageBox QLabel { color: white; }"
        "QMessageBox QPushButton { background-color: #f0f0f0; color: black; border: 1px solid #ccc; padding: 5px 10px; }"
        "QMessageBox QPushButton:hover { background-color: #e0e0e0; }"
        );
    setupDatabase();
    loadDoctorInfo();
    setupUI();
    setupTables();
    setupConnections();
    setupAutoRefresh();

    // Load initial data
    loadDashboard();

    logActivity(QString("Doctor panel opened for doctor ID: %1").arg(m_doctorId));
}

DoctorPanel::~DoctorPanel()
{
    if (autoRefreshTimer) {
        autoRefreshTimer->stop();
        delete autoRefreshTimer;
    }

    delete ui;
}

// ==================== SETUP FUNCTIONS ====================

void DoctorPanel::setupDatabase()
{
    m_db = QSqlDatabase::database();

    if (!m_db.isOpen()) {
        QMessageBox::critical(this, "Database Error",
                              "Unable to connect to database!");
        logActivity("Database connection failed");
        return;
    }

    logActivity("Database connected successfully");
}

void DoctorPanel::loadDoctorInfo()
{
    QSqlQuery query(m_db);
    query.prepare("SELECT name, specialization, phone, email, consultation_fee, is_available, doctor_code FROM doctors WHERE id = :id");
    query.bindValue(":id", m_doctorId);

    if (query.exec() && query.next()) {
        m_doctorName = query.value(0).toString();
        m_specialization = query.value(1).toString();

        // Update UI labels
        ui->lblDoctorName->setText("Dr. " + m_doctorName);
        ui->lblSpecialization->setText(m_specialization);
        ui->lblPhone->setText(query.value(2).toString());
        ui->lblEmail->setText(query.value(3).toString());
        ui->lblConsultationFee->setText("₹" + query.value(4).toString());
        ui->lblAvailability->setText(query.value(5).toBool() ? "Available" : "Unavailable");
        ui->lblDoctorCode->setText(query.value(6).toString());
    } else {
        m_doctorName = "Unknown Doctor";
        m_specialization = "Unknown";
        logActivity("Failed to load doctor info");
    }
}

void DoctorPanel::setupUI()
{
    setWindowTitle(QString("Doctor Panel - Dr. %1").arg(m_doctorName));
    setMinimumSize(1200, 800);

    // Apply improved styling for better contrast
    this->setStyleSheet(R"(
        QMainWindow {
            background-color: #f8fafc;
            font-family: "Segoe UI", "Arial", sans-serif;
        }
        QGroupBox {
            font-weight: 600;
            font-size: 14px;
            border: 1px solid #d1d5db;
            border-radius: 6px;
            margin-top: 1ex;
            padding-top: 10px;
            background-color: white;
        }
        QGroupBox::title {
            subcontrol-origin: margin;
            left: 10px;
            padding: 0 6px 0 6px;
            background-color: white;
            color: #374151;
        }
        QTableWidget {
            gridline-color: #e5e7eb;
            selection-background-color: #e0f2fe;
            alternate-background-color: #f9fafb;
            border: 1px solid #e5e7eb;
            border-radius: 4px;
            color: #1f2937;
            font-size: 13px;
        }
        QHeaderView::section {
            background-color: #f3f4f6;
            padding: 10px;
            border: 1px solid #e5e7eb;
            font-weight: 600;
            color: #374151;
            font-size: 12px;
        }
        QPushButton {
            padding: 8px 16px;
            border: 1px solid #d1d5db;
            border-radius: 4px;
            background-color: white;
            font-weight: 500;
            font-size: 13px;
            color: #374151;
        }
        QPushButton:hover {
            background-color: #f9fafb;
            border-color: #9ca3af;
        }
        QPushButton:pressed {
            background-color: #f3f4f6;
        }
        QLabel {
            color: #374151;
        }
    )");

    // Set initial state
    loadTodayAppointments();
}

void DoctorPanel::setupTables()
{
    // Appointments table
    ui->tableAppointments->setColumnCount(7);
    QStringList headers = {"ID", "Patient ID", "Patient Name", "Time", "Status", "Payment", "Booked At"};
    ui->tableAppointments->setHorizontalHeaderLabels(headers);
    ui->tableAppointments->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableAppointments->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableAppointments->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableAppointments->horizontalHeader()->setStretchLastSection(true);

    // Set better column widths
    ui->tableAppointments->setColumnWidth(0, 60);  // ID
    ui->tableAppointments->setColumnWidth(1, 80);  // Patient ID
    ui->tableAppointments->setColumnWidth(2, 150); // Patient Name
    ui->tableAppointments->setColumnWidth(3, 120); // Time
    ui->tableAppointments->setColumnWidth(4, 100); // Status
    ui->tableAppointments->setColumnWidth(5, 100); // Payment
    // Booked At will stretch
}

void DoctorPanel::setupConnections()
{
    // Dashboard
    connect(ui->btnRefresh, &QPushButton::clicked, this, &DoctorPanel::refreshDashboard);

    // Appointments
    connect(ui->btnLoadToday, &QPushButton::clicked, this, &DoctorPanel::loadTodayAppointments);
    connect(ui->btnViewDetails, &QPushButton::clicked, this, &DoctorPanel::viewTodayAppointmentDetails);
    connect(ui->btnComplete, &QPushButton::clicked, this, &DoctorPanel::markAsCompleted);
    connect(ui->btnCancel, &QPushButton::clicked, this, &DoctorPanel::markAsNoShow);

    // Other buttons
    connect(ui->btnLoadUpcoming, &QPushButton::clicked, this, &DoctorPanel::loadUpcomingAppointments);
    connect(ui->btnLoadHistory, &QPushButton::clicked, this, &DoctorPanel::loadPastAppointments);
    connect(ui->btnViewProfile, &QPushButton::clicked, this, &DoctorPanel::viewProfile);
    connect(ui->btnUpdateAvailability, &QPushButton::clicked, this, &DoctorPanel::updateAvailability);

    // Next Visit button
    connect(ui->btnSetNextVisit, &QPushButton::clicked, this, &DoctorPanel::on_btnSetNextVisit_clicked);

    // Logout
    connect(ui->btnLogout, &QPushButton::clicked, this, &DoctorPanel::logout);
}

void DoctorPanel::setupAutoRefresh()
{
    autoRefreshTimer = new QTimer(this);
    autoRefreshTimer->setInterval(30000); // Refresh every 30 seconds

    connect(autoRefreshTimer, &QTimer::timeout, [this]() {
        loadDashboard();
    });

    autoRefreshTimer->start();
}

// ==================== DASHBOARD FUNCTIONS ====================

void DoctorPanel::loadDashboard()
{
    showLoadingState(true);

    updateStatistics();
    loadTodayAppointments();

    showLoadingState(false);
    logActivity("Dashboard loaded");
}

void DoctorPanel::updateStatistics()
{
    // Calculate basic statistics
    QSqlQuery query(m_db);

    // Total appointments
    query.prepare("SELECT COUNT(*) FROM appointments WHERE doctor_id = :id");
    query.bindValue(":id", m_doctorId);
    if (query.exec() && query.next()) {
        ui->lblTotalAppointments->setText(query.value(0).toString());
    }

    // Today's appointments
    query.prepare("SELECT COUNT(*) FROM appointments WHERE doctor_id = :id AND date = date('now')");
    query.bindValue(":id", m_doctorId);
    if (query.exec() && query.next()) {
        ui->lblTodayAppointments->setText(query.value(0).toString());
    }

    // Completed appointments
    query.prepare("SELECT COUNT(*) FROM appointments WHERE doctor_id = :id AND status = 'completed'");
    query.bindValue(":id", m_doctorId);
    if (query.exec() && query.next()) {
        ui->lblCompletedAppointments->setText(query.value(0).toString());
    }

    // Total revenue
    query.prepare("SELECT SUM(consultation_fee) FROM appointments WHERE doctor_id = :id AND status = 'completed'");
    query.bindValue(":id", m_doctorId);
    if (query.exec() && query.next()) {
        double revenue = query.value(0).toDouble();
        ui->lblTotalRevenue->setText("₹" + QString::number(revenue, 'f', 2));
    }
}

void DoctorPanel::refreshDashboard()
{
    loadDashboard();
    QMessageBox::information(this, "Refreshed", "Dashboard has been refreshed!");
}

// ==================== TODAY'S APPOINTMENTS ====================

void DoctorPanel::loadTodayAppointments()
{
    ui->tableAppointments->setRowCount(0);

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT a.id, a.patient_id, u.fullname, s.start_time, s.end_time, a.status,
               a.payment_status, a.booked_at
        FROM appointments a
        JOIN slots s ON a.slot_id = s.id
        LEFT JOIN users u ON a.patient_id = u.id
        WHERE a.doctor_id = :doctorId
        AND a.date = date('now')
        ORDER BY s.start_time ASC
    )");

    query.bindValue(":doctorId", m_doctorId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error",
                              "Failed to load today's appointments: " + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->tableAppointments->insertRow(row);

        // ID
        ui->tableAppointments->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));

        // Patient ID
        ui->tableAppointments->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));

        // Patient Name
        ui->tableAppointments->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));

        // Time Slot
        QString timeSlot = QTime::fromString(query.value(3).toString(), "HH:mm").toString("h:mm AP") +
                           " - " +
                           QTime::fromString(query.value(4).toString(), "HH:mm").toString("h:mm AP");
        ui->tableAppointments->setItem(row, 3, new QTableWidgetItem(timeSlot));

        // Status with color
        QString status = query.value(5).toString();
        QTableWidgetItem *statusItem = new QTableWidgetItem(getStatusIcon(status) + " " + status);
        statusItem->setForeground(QBrush(getStatusColor(status)));
        ui->tableAppointments->setItem(row, 4, statusItem);

        // Payment Status
        QString paymentStatus = query.value(6).toString();
        QTableWidgetItem *paymentItem = new QTableWidgetItem(paymentStatus);
        if (paymentStatus == "paid") {
            paymentItem->setForeground(QBrush(QColor("#059669")));
        } else if (paymentStatus == "pending") {
            paymentItem->setForeground(QBrush(QColor("#d97706")));
        }
        ui->tableAppointments->setItem(row, 5, paymentItem);

        // Booked At
        ui->tableAppointments->setItem(row, 6, new QTableWidgetItem(query.value(7).toString()));

        row++;
    }

    logActivity(QString("Today's appointments loaded: %1 appointments").arg(row));
}

void DoctorPanel::viewTodayAppointmentDetails()
{
    int currentRow = ui->tableAppointments->currentRow();

    if (currentRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select an appointment first.");
        return;
    }

    int appointmentId = ui->tableAppointments->item(currentRow, 0)->text().toInt();

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT a.id, u.fullname, u.phone, u.email, a.date, s.start_time, s.end_time,
               a.status, a.payment_status, a.consultation_fee, a.booked_at
        FROM appointments a
        JOIN users u ON a.patient_id = u.id
        JOIN slots s ON a.slot_id = s.id
        WHERE a.id = :id
    )");

    query.bindValue(":id", appointmentId);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Error", "Failed to load appointment details!");
        return;
    }

    QString details = QString(
                          "📋 Appointment Details\n\n"
                          "Appointment ID: %1\n"
                          "Patient Name: %2\n"
                          "Phone: %3\n"
                          "Email: %4\n"
                          "Date: %5\n"
                          "Time: %6 - %7\n"
                          "Status: %8\n"
                          "Payment: %9\n"
                          "Fee: ₹%10\n"
                          "Booked At: %11"
                          ).arg(query.value(0).toString())
                          .arg(query.value(1).toString())
                          .arg(query.value(2).toString())
                          .arg(query.value(3).toString())
                          .arg(query.value(4).toString())
                          .arg(QTime::fromString(query.value(5).toString(), "HH:mm").toString("h:mm AP"))
                          .arg(QTime::fromString(query.value(6).toString(), "HH:mm").toString("h:mm AP"))
                          .arg(query.value(7).toString())
                          .arg(query.value(8).toString())
                          .arg(query.value(9).toDouble(), 0, 'f', 2)
                          .arg(query.value(10).toString());

    QMessageBox::information(this, "Appointment Details", details);
}

void DoctorPanel::markAsCompleted()
{
    int currentRow = ui->tableAppointments->currentRow();

    if (currentRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select an appointment to mark as completed.");
        return;
    }

    int appointmentId = ui->tableAppointments->item(currentRow, 0)->text().toInt();
    QString currentStatus = ui->tableAppointments->item(currentRow, 4)->text();

    if (currentStatus.contains("completed", Qt::CaseInsensitive)) {
        QMessageBox::information(this, "Already Completed", "This appointment is already marked as completed.");
        return;
    }

    int result = QMessageBox::question(this, "Mark as Completed",
                                       "Mark this appointment as completed?",
                                       QMessageBox::Yes | QMessageBox::No);

    if (result != QMessageBox::Yes) return;

    if (updateAppointmentStatus(appointmentId, "completed")) {
        QMessageBox::information(this, "Success", "Appointment marked as completed!");
        loadTodayAppointments();
        updateStatistics();

        logActivity(QString("Marked appointment %1 as completed").arg(appointmentId));
    } else {
        QMessageBox::critical(this, "Error", "Failed to update appointment status!");
    }
}

void DoctorPanel::markAsNoShow()
{
    int currentRow = ui->tableAppointments->currentRow();

    if (currentRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select an appointment to mark as no-show.");
        return;
    }

    int appointmentId = ui->tableAppointments->item(currentRow, 0)->text().toInt();

    int result = QMessageBox::question(this, "Mark as No-Show",
                                       "Mark this appointment as cancelled (patient no-show)?",
                                       QMessageBox::Yes | QMessageBox::No);

    if (result != QMessageBox::Yes) return;

    if (updateAppointmentStatus(appointmentId, "cancelled")) {
        QMessageBox::information(this, "Success", "Appointment marked as cancelled (no-show)!");
        loadTodayAppointments();
        updateStatistics();

        logActivity(QString("Marked appointment %1 as no-show").arg(appointmentId));
    } else {
        QMessageBox::critical(this, "Error", "Failed to update appointment status!");
    }
}

// ==================== UPCOMING APPOINTMENTS ====================

void DoctorPanel::loadUpcomingAppointments()
{
    // Load upcoming appointments (next 7 days)
    ui->tableAppointments->setRowCount(0);

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT a.id, a.patient_id, u.fullname, a.date, s.start_time, s.end_time, a.status, a.payment_status
        FROM appointments a
        JOIN slots s ON a.slot_id = s.id
        LEFT JOIN users u ON a.patient_id = u.id
        WHERE a.doctor_id = :doctorId
        AND a.date >= date('now')
        AND a.status = 'booked'
        ORDER BY a.date ASC, s.start_time ASC
    )");

    query.bindValue(":doctorId", m_doctorId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to load upcoming appointments!");
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->tableAppointments->insertRow(row);

        ui->tableAppointments->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableAppointments->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableAppointments->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));

        QString dateTime = query.value(3).toString() + " " +
                           QTime::fromString(query.value(4).toString(), "HH:mm").toString("h:mm AP");
        ui->tableAppointments->setItem(row, 3, new QTableWidgetItem(dateTime));

        QString status = query.value(6).toString();
        QTableWidgetItem *statusItem = new QTableWidgetItem(getStatusIcon(status) + " " + status);
        statusItem->setForeground(QBrush(getStatusColor(status)));
        ui->tableAppointments->setItem(row, 4, statusItem);

        ui->tableAppointments->setItem(row, 5, new QTableWidgetItem(query.value(7).toString()));
        ui->tableAppointments->setItem(row, 6, new QTableWidgetItem("")); // Empty for booked at

        row++;
    }

    QMessageBox::information(this, "Upcoming Appointments",
                             QString("Loaded %1 upcoming appointments").arg(row));
}

void DoctorPanel::viewUpcomingAppointmentDetails()
{
    int currentRow = ui->tableAppointments->currentRow();

    if (currentRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select an appointment first.");
        return;
    }

    int appointmentId = ui->tableAppointments->item(currentRow, 0)->text().toInt();

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT a.id, u.fullname, u.phone, u.email, a.date, s.start_time, s.end_time,
               a.status, a.payment_status, a.consultation_fee
        FROM appointments a
        JOIN users u ON a.patient_id = u.id
        JOIN slots s ON a.slot_id = s.id
        WHERE a.id = :id
    )");

    query.bindValue(":id", appointmentId);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Error", "Failed to load appointment details!");
        return;
    }

    QString details = QString(
                          "📅 Upcoming Appointment\n\n"
                          "Appointment ID: %1\n"
                          "Patient Name: %2\n"
                          "Phone: %3\n"
                          "Email: %4\n"
                          "Date: %5\n"
                          "Time: %6 - %7\n"
                          "Status: %8\n"
                          "Payment: %9\n"
                          "Fee: ₹%10"
                          ).arg(query.value(0).toString())
                          .arg(query.value(1).toString())
                          .arg(query.value(2).toString())
                          .arg(query.value(3).toString())
                          .arg(query.value(4).toString())
                          .arg(QTime::fromString(query.value(5).toString(), "HH:mm").toString("h:mm AP"))
                          .arg(QTime::fromString(query.value(6).toString(), "HH:mm").toString("h:mm AP"))
                          .arg(query.value(7).toString())
                          .arg(query.value(8).toString())
                          .arg(query.value(9).toDouble(), 0, 'f', 2);

    QMessageBox::information(this, "Appointment Details", details);
}

void DoctorPanel::filterUpcomingByDate()
{
    loadUpcomingAppointments();
    QMessageBox::information(this, "Filter", "Date filter functionality to be implemented");
}

// ==================== PAST APPOINTMENTS ====================

void DoctorPanel::loadPastAppointments()
{
    // Load past appointments
    ui->tableAppointments->setRowCount(0);

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT a.id, a.patient_id, u.fullname, a.date, s.start_time, s.end_time, a.status, a.payment_status
        FROM appointments a
        JOIN slots s ON a.slot_id = s.id
        LEFT JOIN users u ON a.patient_id = u.id
        WHERE a.doctor_id = :doctorId
        AND (a.date < date('now') OR a.status IN ('completed', 'cancelled'))
        ORDER BY a.date DESC, s.start_time DESC
        LIMIT 50
    )");

    query.bindValue(":doctorId", m_doctorId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to load past appointments!");
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->tableAppointments->insertRow(row);

        ui->tableAppointments->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableAppointments->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableAppointments->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));

        QString dateTime = query.value(3).toString() + " " +
                           QTime::fromString(query.value(4).toString(), "HH:mm").toString("h:mm AP");
        ui->tableAppointments->setItem(row, 3, new QTableWidgetItem(dateTime));

        QString status = query.value(6).toString();
        QTableWidgetItem *statusItem = new QTableWidgetItem(getStatusIcon(status) + " " + status);
        statusItem->setForeground(QBrush(getStatusColor(status)));
        ui->tableAppointments->setItem(row, 4, statusItem);

        ui->tableAppointments->setItem(row, 5, new QTableWidgetItem(query.value(7).toString()));
        ui->tableAppointments->setItem(row, 6, new QTableWidgetItem("")); // Empty for booked at

        row++;
    }

    QMessageBox::information(this, "Past Appointments",
                             QString("Loaded %1 past appointments").arg(row));
}

void DoctorPanel::viewPastAppointmentDetails()
{
    int currentRow = ui->tableAppointments->currentRow();

    if (currentRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select an appointment first.");
        return;
    }

    int appointmentId = ui->tableAppointments->item(currentRow, 0)->text().toInt();

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT a.id, u.fullname, u.phone, u.email, a.date, s.start_time, s.end_time,
               a.status, a.payment_status, a.consultation_fee, a.booked_at
        FROM appointments a
        JOIN users u ON a.patient_id = u.id
        JOIN slots s ON a.slot_id = s.id
        WHERE a.id = :id
    )");

    query.bindValue(":id", appointmentId);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Error", "Failed to load appointment details!");
        return;
    }

    QString details = QString(
                          "📜 Past Appointment\n\n"
                          "Appointment ID: %1\n"
                          "Patient Name: %2\n"
                          "Phone: %3\n"
                          "Email: %4\n"
                          "Date: %5\n"
                          "Time: %6 - %7\n"
                          "Status: %8\n"
                          "Payment: %9\n"
                          "Fee: ₹%10\n"
                          "Booked At: %11"
                          ).arg(query.value(0).toString())
                          .arg(query.value(1).toString())
                          .arg(query.value(2).toString())
                          .arg(query.value(3).toString())
                          .arg(query.value(4).toString())
                          .arg(QTime::fromString(query.value(5).toString(), "HH:mm").toString("h:mm AP"))
                          .arg(QTime::fromString(query.value(6).toString(), "HH:mm").toString("h:mm AP"))
                          .arg(query.value(7).toString())
                          .arg(query.value(8).toString())
                          .arg(query.value(9).toDouble(), 0, 'f', 2)
                          .arg(query.value(10).toString());

    QMessageBox::information(this, "Appointment Details", details);
}

void DoctorPanel::searchPastAppointments()
{
    loadPastAppointments();
    QMessageBox::information(this, "Search", "Search functionality to be implemented");
}

// ==================== OTHER FUNCTIONS ====================

void DoctorPanel::viewProfile()
{
    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT name, specialization, phone, email, consultation_fee,
               is_available, doctor_code
        FROM doctors
        WHERE id = :id
    )");

    query.bindValue(":id", m_doctorId);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Error", "Failed to load profile!");
        return;
    }

    QString profile = QString(
                          "👨‍⚕️ Doctor Profile\n\n"
                          "Name: Dr. %1\n"
                          "Specialization: %2\n"
                          "Phone: %3\n"
                          "Email: %4\n"
                          "Consultation Fee: ₹%5\n"
                          "Status: %6\n"
                          "Doctor Code: %7"
                          ).arg(query.value(0).toString())
                          .arg(query.value(1).toString())
                          .arg(query.value(2).toString())
                          .arg(query.value(3).toString())
                          .arg(query.value(4).toDouble(), 0, 'f', 2)
                          .arg(query.value(5).toBool() ? "Available" : "Unavailable")
                          .arg(query.value(6).toString());

    QMessageBox::information(this, "My Profile", profile);
}

void DoctorPanel::updateAvailability()
{
    QSqlQuery checkQuery(m_db);
    checkQuery.prepare("SELECT is_available FROM doctors WHERE id = :id");
    checkQuery.bindValue(":id", m_doctorId);

    if (!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::critical(this, "Error", "Failed to check current status!");
        return;
    }

    bool currentStatus = checkQuery.value(0).toBool();
    QString newStatus = currentStatus ? "Unavailable" : "Available";

    int result = QMessageBox::question(this, "Update Availability",
                                       QString("Change your status to: %1?").arg(newStatus),
                                       QMessageBox::Yes | QMessageBox::No);

    if (result != QMessageBox::Yes) return;

    QSqlQuery updateQuery(m_db);
    updateQuery.prepare("UPDATE doctors SET is_available = NOT is_available WHERE id = :id");
    updateQuery.bindValue(":id", m_doctorId);

    if (updateQuery.exec()) {
        // Update the UI label
        ui->lblAvailability->setText(newStatus);
        QMessageBox::information(this, "Success",
                                 QString("Your availability has been updated to: %1").arg(newStatus));
        logActivity(QString("Availability changed to: %1").arg(newStatus));
    } else {
        QMessageBox::critical(this, "Error", "Failed to update availability!");
    }
}

// ==================== NEXT VISIT FUNCTIONS ====================

void DoctorPanel::on_btnSetNextVisit_clicked()
{
    int currentRow = ui->tableAppointments->currentRow();

    if (currentRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select an appointment first.");
        return;
    }

    int appointmentId = ui->tableAppointments->item(currentRow, 0)->text().toInt();
    int patientId = ui->tableAppointments->item(currentRow, 1)->text().toInt();
    QString patientName = ui->tableAppointments->item(currentRow, 2)->text();

    // Get current appointment status
    QString currentStatus = ui->tableAppointments->item(currentRow, 4)->text();
    if (!currentStatus.contains("completed") && !currentStatus.contains("booked")) {
        QMessageBox::warning(this, "Invalid Status",
                             "Next visit can only be set for completed or booked appointments.");
        return;
    }

    // Create dialog for next visit date
    QDialog dialog(this);
    dialog.setWindowTitle("Schedule Next Visit");
    dialog.setFixedSize(400, 300);
    dialog.setStyleSheet("QDialog { background-color: white; }");

    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    // Patient info
    QLabel *patientLabel = new QLabel(QString("Patient: %1 (ID: %2)").arg(patientName).arg(patientId));
    patientLabel->setStyleSheet("font-weight: 600; font-size: 14px; color: #1e40af; margin-bottom: 10px;");
    layout->addWidget(patientLabel);

    // Date selection
    QLabel *dateLabel = new QLabel("Next Visit Date:");
    dateLabel->setStyleSheet("font-weight: 500; color: #374151; margin-top: 10px;");
    layout->addWidget(dateLabel);

    QDateEdit *dateEdit = new QDateEdit();
    dateEdit->setDate(QDate::currentDate().addDays(7));
    dateEdit->setMinimumDate(QDate::currentDate().addDays(1));
    dateEdit->setCalendarPopup(true);
    dateEdit->setStyleSheet("padding: 6px; border: 1px solid #d1d5db; border-radius: 4px; background-color: white;");
    layout->addWidget(dateEdit);

    // Notes
    QLabel *notesLabel = new QLabel("Notes (Optional):");
    notesLabel->setStyleSheet("font-weight: 500; color: #374151; margin-top: 10px;");
    layout->addWidget(notesLabel);

    QTextEdit *notesEdit = new QTextEdit();
    notesEdit->setMaximumHeight(70);
    notesEdit->setPlaceholderText("Enter any notes or instructions for the patient...");
    notesEdit->setStyleSheet("border: 1px solid #d1d5db; border-radius: 4px; padding: 6px;");
    layout->addWidget(notesEdit);

    // Buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *btnCancel = new QPushButton("Cancel");
    QPushButton *btnSchedule = new QPushButton("Schedule Next Visit");

    btnCancel->setStyleSheet(R"(
        QPushButton {
            padding: 8px 16px;
            border: 1px solid #dc2626;
            color: #dc2626;
            background: white;
            border-radius: 4px;
            font-weight: 500;
        }
        QPushButton:hover {
            background-color: #fef2f2;
        }
    )");

    btnSchedule->setStyleSheet(R"(
        QPushButton {
            padding: 8px 16px;
            border: 1px solid #059669;
            background: #059669;
            color: white;
            border-radius: 4px;
            font-weight: 500;
        }
        QPushButton:hover {
            background-color: #047857;
        }
    )");

    buttonLayout->addWidget(btnCancel);
    buttonLayout->addWidget(btnSchedule);
    layout->addLayout(buttonLayout);

    // Connections
    connect(btnCancel, &QPushButton::clicked, &dialog, &QDialog::reject);
    connect(btnSchedule, &QPushButton::clicked, &dialog, &QDialog::accept);

    if (dialog.exec() == QDialog::Accepted) {
        QDate nextVisitDate = dateEdit->date();
        QString notes = notesEdit->toPlainText();

        if (saveNextVisit(patientId, appointmentId, nextVisitDate, notes)) {
            QMessageBox::information(this, "Success",
                                     QString("Next visit scheduled for:\n"
                                             "Patient: %1\n"
                                             "Date: %2\n\n"
                                             "Patient will be notified on their dashboard.")
                                         .arg(patientName)
                                         .arg(nextVisitDate.toString("dddd, MMMM d, yyyy")));

            logActivity(QString("Scheduled next visit for patient %1 on %2")
                            .arg(patientId).arg(nextVisitDate.toString("yyyy-MM-dd")));
        } else {
            QMessageBox::critical(this, "Error",
                                  "Failed to schedule next visit. Please try again.");
        }
    }
}

bool DoctorPanel::saveNextVisit(int patientId, int appointmentId, const QDate &nextVisitDate, const QString &notes)
{
    QSqlQuery query(m_db);
    query.prepare(R"(
        INSERT INTO next_visits (patient_id, doctor_id, appointment_id, next_visit_date, notes)
        VALUES (:patient_id, :doctor_id, :appointment_id, :next_visit_date, :notes)
    )");

    query.bindValue(":patient_id", patientId);
    query.bindValue(":doctor_id", m_doctorId);
    query.bindValue(":appointment_id", appointmentId);
    query.bindValue(":next_visit_date", nextVisitDate.toString("yyyy-MM-dd"));
    query.bindValue(":notes", notes);

    if (query.exec()) {
        return true;
    } else {
        logActivity("Failed to save next visit: " + query.lastError().text());
        return false;
    }
}

QString DoctorPanel::getPatientName(int patientId)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT fullname FROM users WHERE id = :id");
    query.bindValue(":id", patientId);

    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }

    return "Unknown Patient";
}

// ==================== UTILITY FUNCTIONS ====================

bool DoctorPanel::updateAppointmentStatus(int appointmentId, const QString &status)
{
    QSqlQuery query(m_db);
    query.prepare("UPDATE appointments SET status = :status WHERE id = :id");
    query.bindValue(":status", status);
    query.bindValue(":id", appointmentId);

    return query.exec();
}

QString DoctorPanel::getStatusIcon(const QString &status)
{
    if (status == "booked") return "📅";
    if (status == "completed") return "✅";
    if (status == "cancelled") return "❌";
    return "❓";
}

QColor DoctorPanel::getStatusColor(const QString &status)
{
    if (status == "booked") return QColor("#2196f3");
    if (status == "completed") return QColor("#4caf50");
    if (status == "cancelled") return QColor("#f44336");
    return QColor("#757575");
}

void DoctorPanel::showLoadingState(bool loading)
{
    setCursor(loading ? Qt::WaitCursor : Qt::ArrowCursor);
    // Enable/disable main controls during loading
    ui->frameControls->setEnabled(!loading);
    ui->frameActions->setEnabled(!loading);
}

void DoctorPanel::logActivity(const QString &activity)
{
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    qDebug() << QString("[DOCTOR %1 - %2] %3").arg(m_doctorId).arg(timestamp).arg(activity);
}

void DoctorPanel::logout()
{
    int result = QMessageBox::question(this, "Logout",
                                       "Are you sure you want to logout?",
                                       QMessageBox::Yes | QMessageBox::No);

    if (result == QMessageBox::Yes) {
        logActivity("Doctor logged out");
        this->close();
    }
}
