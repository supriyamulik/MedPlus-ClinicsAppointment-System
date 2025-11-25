#include "adminpanel.h"
#include "ui_adminpanel.h"
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

AdminPanel::AdminPanel(QSqlDatabase db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminPanel)
    , m_db(db)
    , statsManager(nullptr)
    , autoRefreshTimer(nullptr)
{
    ui->setupUi(this);


    setupDatabase();
    setupUI();
    setupTables();
    setupConnections();
    setupAutoRefresh();

    // Load initial data
    loadDashboard();

    logActivity("Admin panel opened");
}

AdminPanel::~AdminPanel()
{
    if (autoRefreshTimer) {
        autoRefreshTimer->stop();
        delete autoRefreshTimer;
    }

    if (statsManager) {
        delete statsManager;
    }

    delete ui;
}

// ==================== SETUP FUNCTIONS ====================

void AdminPanel::setupDatabase()
{
    if (!m_db.isOpen()) {
        QMessageBox::critical(this, "Database Error",
                              "Unable to connect to database!");
        logActivity("Database connection failed");
        return;
    }

    statsManager = new StatsManager(this);
    logActivity("Database connected successfully");
}

void AdminPanel::setupUI()
{
    setWindowTitle("Admin Panel - MedPlus Clinic Management");
    setMinimumSize(1200, 800);

    // Set initial tab
    ui->tabWidget->setCurrentIndex(0);

    // Enable sorting on tables
    ui->tableDoctors->setSortingEnabled(true);
    ui->tableAppointments->setSortingEnabled(true);
    ui->tableDoctorStats->setSortingEnabled(true);
}

void AdminPanel::setupTables()
{
    // Doctors table
    ui->tableDoctors->setColumnCount(7);
    QStringList doctorHeaders = {"ID", "Name", "Specialization", "Phone",
                                 "Consultation Fee", "Status", "Total Appointments"};
    ui->tableDoctors->setHorizontalHeaderLabels(doctorHeaders);
    ui->tableDoctors->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableDoctors->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableDoctors->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableDoctors->horizontalHeader()->setStretchLastSection(true);

    // Appointments table
    ui->tableAppointments->setColumnCount(8);
    QStringList appointmentHeaders = {"ID", "Doctor", "Patient ID", "Date",
                                      "Time", "Status", "Payment", "Booked At"};
    ui->tableAppointments->setHorizontalHeaderLabels(appointmentHeaders);
    ui->tableAppointments->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableAppointments->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableAppointments->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableAppointments->horizontalHeader()->setStretchLastSection(true);

    // Statistics table
    ui->tableDoctorStats->setColumnCount(8);
    QStringList statsHeaders = {"Doctor", "Specialization", "Total", "Today",
                                "Upcoming", "Completed", "Cancelled", "Revenue"};
    ui->tableDoctorStats->setHorizontalHeaderLabels(statsHeaders);
    ui->tableDoctorStats->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableDoctorStats->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableDoctorStats->horizontalHeader()->setStretchLastSection(true);

    // Recent appointments table (on dashboard)
    ui->tableRecentAppointments->setColumnCount(5);
    QStringList recentHeaders = {"Doctor", "Patient ID", "Date", "Time", "Status"};
    ui->tableRecentAppointments->setHorizontalHeaderLabels(recentHeaders);
    ui->tableRecentAppointments->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableRecentAppointments->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableRecentAppointments->horizontalHeader()->setStretchLastSection(true);
}

void AdminPanel::setupConnections()
{
    // Dashboard
    connect(ui->btnRefreshDashboard, &QPushButton::clicked, this, &AdminPanel::refreshDashboard);

    // Doctors tab
    connect(ui->btnRefreshDoctors, &QPushButton::clicked, this, &AdminPanel::loadDoctorsTable);
    connect(ui->btnViewDoctorDetails, &QPushButton::clicked, this, &AdminPanel::viewDoctorDetails);
    connect(ui->btnToggleAvailability, &QPushButton::clicked, this, &AdminPanel::toggleDoctorAvailability);
    connect(ui->lineEditSearchDoctor, &QLineEdit::textChanged, this, &AdminPanel::searchDoctors);

    // Appointments tab
    connect(ui->btnRefreshAppointments, &QPushButton::clicked, this, &AdminPanel::loadAllAppointments);
    connect(ui->btnViewAppointmentDetails, &QPushButton::clicked, this, &AdminPanel::viewAppointmentDetails);
    connect(ui->lineEditSearchAppointment, &QLineEdit::textChanged, this, &AdminPanel::searchAppointments);

    // Reports tab
    connect(ui->btnRefreshStats, &QPushButton::clicked, this, &AdminPanel::loadDoctorWiseStats);
    connect(ui->btnExportReport, &QPushButton::clicked, this, &AdminPanel::exportReport);
    connect(ui->btnDetailedStats, &QPushButton::clicked, this, &AdminPanel::viewDetailedStats);

    // Logout
    connect(ui->btnLogout, &QPushButton::clicked, this, &AdminPanel::logout);
}

void AdminPanel::setupAutoRefresh()
{
    autoRefreshTimer = new QTimer(this);
    autoRefreshTimer->setInterval(60000); // Refresh every 60 seconds

    connect(autoRefreshTimer, &QTimer::timeout, [this]() {
        if (ui->tabWidget->currentIndex() == 0) { // Dashboard tab
            loadDashboard();
        }
    });

    autoRefreshTimer->start();
}

// ==================== DASHBOARD FUNCTIONS ====================

void AdminPanel::loadDashboard()
{
    showLoadingState(true);

    // Get system statistics
    SystemStats stats = statsManager->getSystemStats();
    updateStatsCards(stats);

    // Load recent appointments
    loadRecentAppointments();

    showLoadingState(false);
    logActivity("Dashboard loaded");
}

void AdminPanel::updateStatsCards(const SystemStats &stats)
{
    // Update only the labels that exist in the UI
    ui->lblTotalDoctors->setText(QString::number(stats.totalDoctors));
    ui->lblTotalPatients->setText(QString::number(stats.totalPatients));
    ui->lblTotalAppointments->setText(QString::number(stats.totalAppointments));

    // Calculate total revenue from completed appointments
    double totalRevenue = 0.0;
    QSqlQuery query(m_db);
    query.prepare("SELECT SUM(consultation_fee) FROM appointments WHERE status = 'completed'");
    if (query.exec() && query.next()) {
        totalRevenue = query.value(0).toDouble();
    }
    ui->lblTotalRevenue->setText("₹" + QString::number(totalRevenue, 'f', 2));
}

void AdminPanel::loadRecentAppointments()
{
    ui->tableRecentAppointments->setRowCount(0);

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT d.name, a.patient_id, a.date, s.start_time, s.end_time, a.status
        FROM appointments a
        JOIN doctors d ON a.doctor_id = d.id
        JOIN slots s ON a.slot_id = s.id
        ORDER BY a.booked_at DESC
        LIMIT 10
    )");

    if (!query.exec()) {
        logActivity("Failed to load recent appointments: " + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->tableRecentAppointments->insertRow(row);

        ui->tableRecentAppointments->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableRecentAppointments->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableRecentAppointments->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));

        QString timeSlot = QTime::fromString(query.value(3).toString(), "HH:mm").toString("h:mm AP") +
                           " - " +
                           QTime::fromString(query.value(4).toString(), "HH:mm").toString("h:mm AP");
        ui->tableRecentAppointments->setItem(row, 3, new QTableWidgetItem(timeSlot));

        QString status = query.value(5).toString();
        QTableWidgetItem *statusItem = new QTableWidgetItem(getStatusIcon(status) + " " + status);
        statusItem->setForeground(QBrush(getStatusColor(status)));
        ui->tableRecentAppointments->setItem(row, 4, statusItem);

        row++;
    }
}

void AdminPanel::refreshDashboard()
{
    loadDashboard();
    QMessageBox::information(this, "Refreshed", "Dashboard has been refreshed!");
}

void AdminPanel::applyDateFilter()
{
    // Implementation for date filtering
    QMessageBox::information(this, "Info", "Date filter functionality to be implemented");
}

void AdminPanel::resetDateFilter()
{
    // Implementation for resetting date filter
    loadDashboard();
}

// ==================== DOCTORS MANAGEMENT ====================

void AdminPanel::loadDoctorsTable()
{
    ui->tableDoctors->setRowCount(0);

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT d.id, d.name, d.specialization, d.phone, d.consultation_fee,
               d.is_available, COUNT(a.id) as total_appointments
        FROM doctors d
        LEFT JOIN appointments a ON d.id = a.doctor_id
        GROUP BY d.id
        ORDER BY d.name
    )");

    if (!query.exec()) {
        QMessageBox::critical(this, "Error",
                              "Failed to load doctors: " + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->tableDoctors->insertRow(row);

        ui->tableDoctors->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableDoctors->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableDoctors->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableDoctors->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tableDoctors->setItem(row, 4, new QTableWidgetItem("₹" + query.value(4).toString()));

        bool isAvailable = query.value(5).toBool();
        QString statusText = isAvailable ? "✓ Available" : "✗ Unavailable";
        QColor statusColor = isAvailable ? QColor("#4caf50") : QColor("#f44336");

        QTableWidgetItem *statusItem = new QTableWidgetItem(statusText);
        statusItem->setForeground(QBrush(statusColor));
        ui->tableDoctors->setItem(row, 5, statusItem);

        ui->tableDoctors->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));

        row++;
    }

    logActivity("Doctors table loaded");
}

void AdminPanel::viewDoctorDetails()
{
    int currentRow = ui->tableDoctors->currentRow();

    if (currentRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a doctor first.");
        return;
    }

    int doctorId = ui->tableDoctors->item(currentRow, 0)->text().toInt();
    DoctorStats stats = statsManager->getDoctorStats(doctorId);

    QString details = QString(
                          "📋 Doctor Details\n\n"
                          "Name: %1\n"
                          "Specialization: %2\n"
                          "Consultation Fee: ₹%3\n\n"
                          "📊 Statistics:\n"
                          "Total Appointments: %4\n"
                          "Today's Appointments: %5\n"
                          "Upcoming: %6\n"
                          "Completed: %7\n"
                          "Cancelled: %8\n"
                          "Total Revenue: ₹%9"
                          ).arg(stats.doctorName)
                          .arg(stats.specialization)
                          .arg(stats.consultationFee, 0, 'f', 2)
                          .arg(stats.totalAppointments)
                          .arg(stats.todayAppointments)
                          .arg(stats.upcomingAppointments)
                          .arg(stats.completedAppointments)
                          .arg(stats.cancelledAppointments)
                          .arg(stats.totalRevenue, 0, 'f', 2);

    QMessageBox::information(this, "Doctor Details", details);
}

void AdminPanel::toggleDoctorAvailability()
{
    int currentRow = ui->tableDoctors->currentRow();

    if (currentRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a doctor first.");
        return;
    }

    int doctorId = ui->tableDoctors->item(currentRow, 0)->text().toInt();
    QString doctorName = ui->tableDoctors->item(currentRow, 1)->text();

    int result = QMessageBox::question(this, "Toggle Availability",
                                       QString("Change availability status for %1?").arg(doctorName),
                                       QMessageBox::Yes | QMessageBox::No);

    if (result != QMessageBox::Yes) return;

    QSqlQuery query(m_db);
    query.prepare("UPDATE doctors SET is_available = NOT is_available WHERE id = :id");
    query.bindValue(":id", doctorId);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Doctor availability updated!");
        loadDoctorsTable();
        logActivity(QString("Toggled availability for doctor ID: %1").arg(doctorId));
    } else {
        QMessageBox::critical(this, "Error", "Failed to update: " + query.lastError().text());
    }
}

void AdminPanel::searchDoctors()
{
    QString searchText = ui->lineEditSearchDoctor->text().toLower();

    for (int row = 0; row < ui->tableDoctors->rowCount(); ++row) {
        bool match = false;

        for (int col = 0; col < ui->tableDoctors->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableDoctors->item(row, col);
            if (item && item->text().toLower().contains(searchText)) {
                match = true;
                break;
            }
        }

        ui->tableDoctors->setRowHidden(row, !match);
    }
}

// ==================== APPOINTMENTS MANAGEMENT ====================

void AdminPanel::loadAllAppointments()
{
    ui->tableAppointments->setRowCount(0);

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT a.id, d.name, a.patient_id, a.date, s.start_time, s.end_time,
               a.status, a.payment_status, a.booked_at
        FROM appointments a
        JOIN doctors d ON a.doctor_id = d.id
        JOIN slots s ON a.slot_id = s.id
        ORDER BY a.date DESC, s.start_time DESC
        LIMIT 500
    )");

    if (!query.exec()) {
        QMessageBox::critical(this, "Error",
                              "Failed to load appointments: " + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->tableAppointments->insertRow(row);

        ui->tableAppointments->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableAppointments->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableAppointments->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableAppointments->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));

        QString timeSlot = QTime::fromString(query.value(4).toString(), "HH:mm").toString("h:mm AP") +
                           " - " +
                           QTime::fromString(query.value(5).toString(), "HH:mm").toString("h:mm AP");
        ui->tableAppointments->setItem(row, 4, new QTableWidgetItem(timeSlot));

        QString status = query.value(6).toString();
        QTableWidgetItem *statusItem = new QTableWidgetItem(getStatusIcon(status) + " " + status);
        statusItem->setForeground(QBrush(getStatusColor(status)));
        ui->tableAppointments->setItem(row, 5, statusItem);

        ui->tableAppointments->setItem(row, 6, new QTableWidgetItem(query.value(7).toString()));
        ui->tableAppointments->setItem(row, 7, new QTableWidgetItem(query.value(8).toString()));

        row++;
    }

    logActivity("Appointments table loaded");
}

void AdminPanel::filterAppointments()
{
    // Implementation for appointment filtering
    QMessageBox::information(this, "Info", "Appointment filter functionality to be implemented");
}

void AdminPanel::viewAppointmentDetails()
{
    int currentRow = ui->tableAppointments->currentRow();

    if (currentRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select an appointment first.");
        return;
    }

    QString details = QString(
                          "📋 Appointment Details\n\n"
                          "Appointment ID: %1\n"
                          "Doctor: %2\n"
                          "Patient ID: %3\n"
                          "Date: %4\n"
                          "Time: %5\n"
                          "Status: %6\n"
                          "Payment: %7\n"
                          "Booked At: %8"
                          ).arg(ui->tableAppointments->item(currentRow, 0)->text())
                          .arg(ui->tableAppointments->item(currentRow, 1)->text())
                          .arg(ui->tableAppointments->item(currentRow, 2)->text())
                          .arg(ui->tableAppointments->item(currentRow, 3)->text())
                          .arg(ui->tableAppointments->item(currentRow, 4)->text())
                          .arg(ui->tableAppointments->item(currentRow, 5)->text())
                          .arg(ui->tableAppointments->item(currentRow, 6)->text())
                          .arg(ui->tableAppointments->item(currentRow, 7)->text());

    QMessageBox::information(this, "Appointment Details", details);
}

void AdminPanel::searchAppointments()
{
    QString searchText = ui->lineEditSearchAppointment->text().toLower();

    for (int row = 0; row < ui->tableAppointments->rowCount(); ++row) {
        bool match = false;

        for (int col = 0; col < ui->tableAppointments->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableAppointments->item(row, col);
            if (item && item->text().toLower().contains(searchText)) {
                match = true;
                break;
            }
        }

        ui->tableAppointments->setRowHidden(row, !match);
    }
}

// ==================== REPORTS & STATISTICS ====================

void AdminPanel::loadDoctorWiseStats()
{
    ui->tableDoctorStats->setRowCount(0);

    QList<DoctorStats> statsList = statsManager->getAllDoctorsStats();

    int row = 0;
    for (const DoctorStats &stats : statsList) {
        ui->tableDoctorStats->insertRow(row);

        ui->tableDoctorStats->setItem(row, 0, new QTableWidgetItem(stats.doctorName));
        ui->tableDoctorStats->setItem(row, 1, new QTableWidgetItem(stats.specialization));
        ui->tableDoctorStats->setItem(row, 2, new QTableWidgetItem(QString::number(stats.totalAppointments)));
        ui->tableDoctorStats->setItem(row, 3, new QTableWidgetItem(QString::number(stats.todayAppointments)));
        ui->tableDoctorStats->setItem(row, 4, new QTableWidgetItem(QString::number(stats.upcomingAppointments)));
        ui->tableDoctorStats->setItem(row, 5, new QTableWidgetItem(QString::number(stats.completedAppointments)));
        ui->tableDoctorStats->setItem(row, 6, new QTableWidgetItem(QString::number(stats.cancelledAppointments)));
        ui->tableDoctorStats->setItem(row, 7, new QTableWidgetItem("₹" + QString::number(stats.totalRevenue, 'f', 2)));

        row++;
    }

    logActivity("Doctor-wise statistics loaded");
}

void AdminPanel::exportReport()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export Report",
                                                    QDir::homePath() + "/admin_report.csv",
                                                    "CSV Files (*.csv)");

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to create file!");
        return;
    }

    QTextStream out(&file);

    // Write header
    out << "Doctor,Specialization,Total Appointments,Today,Upcoming,Completed,Cancelled,Revenue\n";

    // Write data
    for (int row = 0; row < ui->tableDoctorStats->rowCount(); ++row) {
        for (int col = 0; col < ui->tableDoctorStats->columnCount(); ++col) {
            out << ui->tableDoctorStats->item(row, col)->text();
            if (col < ui->tableDoctorStats->columnCount() - 1) {
                out << ",";
            }
        }
        out << "\n";
    }

    file.close();

    QMessageBox::information(this, "Success",
                             "Report exported successfully!\n\nFile: " + fileName);
    logActivity("Report exported to: " + fileName);
}

void AdminPanel::viewDetailedStats()
{
    SystemStats stats = statsManager->getSystemStats();

    QString detailedStats = QString(
                                "📊 DETAILED SYSTEM STATISTICS\n\n"
                                "═══════════════════════════════\n"
                                "👨‍⚕️ DOCTORS\n"
                                "═══════════════════════════════\n"
                                "Total Doctors: %1\n"
                                "Active Doctors: %2\n"
                                "Inactive Doctors: %3\n\n"
                                "═══════════════════════════════\n"
                                "👥 PATIENTS\n"
                                "═══════════════════════════════\n"
                                "Total Patients: %4\n\n"
                                "═══════════════════════════════\n"
                                " APPOINTMENTS\n"
                                "═══════════════════════════════\n"
                                "Total Appointments: %5\n"
                                "Booked: %6\n"
                                "Completed: %7\n"
                                "Cancelled: %8\n\n"
                                "═══════════════════════════════\n"
                                "PERFORMANCE METRICS\n"
                                "═══════════════════════════════\n"
                                "Completion Rate: %9%\n"
                                "Cancellation Rate: %10%\n"
                                "Average Appointments per Doctor: %11\n\n"
                                "Generated: %12"
                                ).arg(stats.totalDoctors)
                                .arg(stats.activeDoctors)
                                .arg(stats.totalDoctors - stats.activeDoctors)
                                .arg(stats.totalPatients)
                                .arg(stats.totalAppointments)
                                .arg(stats.bookedAppointments)
                                .arg(stats.completedAppointments)
                                .arg(stats.cancelledAppointments)
                                .arg(stats.totalAppointments > 0 ? QString::number((stats.completedAppointments * 100.0) / stats.totalAppointments, 'f', 1) : "0.0")
                                .arg(stats.totalAppointments > 0 ? QString::number((stats.cancelledAppointments * 100.0) / stats.totalAppointments, 'f', 1) : "0.0")
                                .arg(stats.totalDoctors > 0 ? QString::number(stats.totalAppointments / (double)stats.totalDoctors, 'f', 1) : "0.0")
                                .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

    QMessageBox::information(this, "Detailed Statistics", detailedStats);
}

// ==================== UTILITY FUNCTIONS ====================

QString AdminPanel::getStatusIcon(const QString &status)
{
    if (status == "booked") return "📅";
    if (status == "completed") return "✅";
    if (status == "cancelled") return "❌";
    return "❓";
}

QColor AdminPanel::getStatusColor(const QString &status)
{
    if (status == "booked") return QColor("#2196f3");
    if (status == "completed") return QColor("#4caf50");
    if (status == "cancelled") return QColor("#f44336");
    return QColor("#757575");
}

void AdminPanel::showLoadingState(bool loading)
{
    setCursor(loading ? Qt::WaitCursor : Qt::ArrowCursor);
    ui->tabWidget->setEnabled(!loading);
}

void AdminPanel::logActivity(const QString &activity)
{
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    qDebug() << QString("[ADMIN %1] %2").arg(timestamp, activity);
}

void AdminPanel::logout()
{
    int result = QMessageBox::question(this, "Logout",
                                       "Are you sure you want to logout?",
                                       QMessageBox::Yes | QMessageBox::No);

    if (result == QMessageBox::Yes) {
        logActivity("Admin logged out");
        this->close();
    }
}

// Navigation slots
void AdminPanel::showDashboardTab() { ui->tabWidget->setCurrentIndex(0); }
void AdminPanel::showDoctorsTab() { ui->tabWidget->setCurrentIndex(1); loadDoctorsTable(); }
void AdminPanel::showAppointmentsTab() { ui->tabWidget->setCurrentIndex(2); loadAllAppointments(); }
void AdminPanel::showReportsTab() { ui->tabWidget->setCurrentIndex(3); loadDoctorWiseStats(); }
