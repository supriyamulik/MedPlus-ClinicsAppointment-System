#include "myappointments.h"
#include "ui_myappointments.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QDateEdit>
#include <QComboBox>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTime>

MyAppointments::MyAppointments(QWidget *parent, const QString &username)
    : QDialog(parent),
    ui(new Ui::MyAppointments),
    currentUsername(username)
{
    ui->setupUi(this);
    setupTable();

    // SQLite connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Supriya/ClinicsAppointment.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    currentUserId = fetchUserId();

    if (currentUserId != -1)
        loadAppointments();
    else
        QMessageBox::warning(this, "Error", "User not found in database!");

    // Connect buttons
    connect(ui->btnRefresh, &QPushButton::clicked, this, &MyAppointments::refreshAppointments);
    connect(ui->btnCancelAppointment, &QPushButton::clicked, this, &MyAppointments::cancelAppointment);
    connect(ui->btnReschedule, &QPushButton::clicked, this, &MyAppointments::rescheduleAppointment);
    connect(ui->btnViewDetails, &QPushButton::clicked, this, &MyAppointments::viewDetails);
    connect(ui->btnBack, &QPushButton::clicked, this, &QDialog::close);
}

MyAppointments::~MyAppointments()
{
    delete ui;
}

void MyAppointments::setupTable()
{
    ui->tableAppointments->setColumnCount(6);
    QStringList headers = {"Appointment ID", "Doctor Name", "Date", "Slot", "Status", "Payment"};
    ui->tableAppointments->setHorizontalHeaderLabels(headers);
    ui->tableAppointments->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableAppointments->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableAppointments->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableAppointments->horizontalHeader()->setStretchLastSection(true);
}

int MyAppointments::fetchUserId()
{
    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE username = :username");
    query.bindValue(":username", currentUsername);

    if (query.exec() && query.next())
        return query.value(0).toInt();
    return -1;
}

void MyAppointments::loadAppointments()
{
    ui->tableAppointments->setRowCount(0);

    QSqlQuery query;
    query.prepare(R"(
        SELECT a.id, d.name, a.date, s.start_time, s.end_time,
               a.status, a.payment_status
        FROM appointments a
        JOIN doctors d ON a.doctor_id = d.id
        JOIN slots s ON a.slot_id = s.id
        WHERE a.patient_id = :pid
        ORDER BY a.date DESC
    )");
    query.bindValue(":pid", currentUserId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Query Error", query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->tableAppointments->insertRow(row);

        // Column 0: Appointment ID
        ui->tableAppointments->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));

        // Column 1: Doctor Name
        ui->tableAppointments->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));

        // Column 2: Date
        ui->tableAppointments->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));

        // Column 3: Time Slot (Convert to 12-hour format)
        QString startTime = query.value(3).toString();
        QString endTime = query.value(4).toString();
        QTime start = QTime::fromString(startTime, "HH:mm");
        QTime end = QTime::fromString(endTime, "HH:mm");
        QString slot12hr = start.toString("h:mm AP") + " - " + end.toString("h:mm AP");
        ui->tableAppointments->setItem(row, 3, new QTableWidgetItem(slot12hr));

        // Column 4: Status
        ui->tableAppointments->setItem(row, 4, new QTableWidgetItem(query.value(5).toString()));

        // Column 5: Payment
        ui->tableAppointments->setItem(row, 5, new QTableWidgetItem(query.value(6).toString()));

        row++;
    }

    if (row == 0)
        QMessageBox::information(this, "No Appointments", "You have no appointments yet.");
}

void MyAppointments::refreshAppointments()
{
    loadAppointments();
}

void MyAppointments::cancelAppointment()
{
    int row = ui->tableAppointments->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Select Appointment", "Please select an appointment to cancel.");
        return;
    }

    QString appointmentId = ui->tableAppointments->item(row, 0)->text();
    QString status = ui->tableAppointments->item(row, 4)->text();

    if (status == "Cancelled" || status == "Completed" || status == "cancelled" || status == "completed") {
        QMessageBox::warning(this, "Cannot Cancel", "This appointment cannot be cancelled.");
        return;
    }

    int result = QMessageBox::question(this, "Confirm Cancellation",
                                       "Are you sure you want to cancel this appointment?",
                                       QMessageBox::Yes | QMessageBox::No);
    if (result != QMessageBox::Yes) return;

    QSqlQuery query;
    query.prepare("UPDATE appointments SET status = 'cancelled' WHERE id = :id");
    query.bindValue(":id", appointmentId);

    if (query.exec()) {
        QMessageBox::information(this, "Cancelled", "Appointment cancelled successfully!");
        loadAppointments();
    } else {
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
}

void MyAppointments::rescheduleAppointment()
{
    int row = ui->tableAppointments->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Select Appointment", "Please select an appointment to reschedule.");
        return;
    }

    QString appointmentId = ui->tableAppointments->item(row, 0)->text();
    QString status = ui->tableAppointments->item(row, 4)->text().toLower();
    QString currentDateStr = ui->tableAppointments->item(row, 2)->text();

    // Check if appointment can be rescheduled
    if (status == "cancelled" || status == "completed") {
        QMessageBox::warning(this, "Cannot Reschedule",
                             "Cancelled or completed appointments cannot be rescheduled.\n"
                             "Please book a new appointment.");
        return;
    }

    // Get doctor ID for this appointment
    QSqlQuery doctorQuery;
    doctorQuery.prepare("SELECT doctor_id FROM appointments WHERE id = :id");
    doctorQuery.bindValue(":id", appointmentId);

    if (!doctorQuery.exec() || !doctorQuery.next()) {
        QMessageBox::critical(this, "Error", "Failed to load appointment details.");
        return;
    }

    int doctorId = doctorQuery.value(0).toInt();

    // Create reschedule dialog
    QDialog rescheduleDialog(this);
    rescheduleDialog.setWindowTitle("Reschedule Appointment");
    rescheduleDialog.setModal(true);
    rescheduleDialog.setFixedSize(450, 350);

    QVBoxLayout *layout = new QVBoxLayout(&rescheduleDialog);
    layout->setSpacing(15);
    layout->setContentsMargins(20, 20, 20, 20);

    // Current appointment info
    QLabel *lblInfo = new QLabel(
        QString("<b>Current Appointment:</b><br>"
                "Doctor: %1<br>"
                "Date: %2<br>"
                "Slot: %3")
            .arg(ui->tableAppointments->item(row, 1)->text())
            .arg(currentDateStr)
            .arg(ui->tableAppointments->item(row, 3)->text())
        );
    lblInfo->setWordWrap(true);
    lblInfo->setStyleSheet("padding: 10px; background-color: #e3f2fd; border-radius: 5px;");

    // New date selection
    QLabel *lblDate = new QLabel("<b>Select New Date:</b>");
    QDateEdit *dateEdit = new QDateEdit(QDate::fromString(currentDateStr, "yyyy-MM-dd"));
    dateEdit->setMinimumDate(QDate::currentDate());
    dateEdit->setMaximumDate(QDate::currentDate().addMonths(3));
    dateEdit->setCalendarPopup(true);
    dateEdit->setDisplayFormat("yyyy-MM-dd");

    // New slot selection
    QLabel *lblSlot = new QLabel("<b>Select New Time Slot:</b>");
    QComboBox *slotCombo = new QComboBox();
    slotCombo->setMinimumHeight(35);

    // Function to load available slots
    auto loadAvailableSlots = [&](const QDate &date) {
        slotCombo->clear();
        slotCombo->addItem("-- Select Time Slot --", -1);

        QTime currentTime = QTime::currentTime();
        bool isToday = (date == QDate::currentDate());

        QSqlQuery slotQuery;
        slotQuery.prepare(R"(
            SELECT
                s.id,
                s.start_time,
                s.end_time,
                (SELECT COUNT(*)
                 FROM appointments a
                 WHERE a.slot_id = s.id
                 AND a.doctor_id = :doctor_id
                 AND a.date = :date
                 AND a.status NOT IN ('cancelled', 'completed')
                 AND a.id != :current_appointment_id
                ) as booked_count
            FROM slots s
            ORDER BY s.start_time ASC
        )");

        slotQuery.bindValue(":doctor_id", doctorId);
        slotQuery.bindValue(":date", date.toString("yyyy-MM-dd"));
        slotQuery.bindValue(":current_appointment_id", appointmentId);

        if (slotQuery.exec()) {
            int availableCount = 0;
            while (slotQuery.next()) {
                int slotId = slotQuery.value(0).toInt();
                QString startTime = slotQuery.value(1).toString();
                QString endTime = slotQuery.value(2).toString();
                int bookedCount = slotQuery.value(3).toInt();

                QTime slotStart = QTime::fromString(startTime, "HH:mm");
                QTime slotEnd = QTime::fromString(endTime, "HH:mm");

                // Skip past slots for today
                if (isToday && slotStart <= currentTime.addSecs(3600)) {
                    continue;
                }

                // Skip full slots (2 or more bookings)
                if (bookedCount >= 2) {
                    continue;
                }

                // Convert to 12-hour format
                QString start12hr = slotStart.toString("h:mm AP");
                QString end12hr = slotEnd.toString("h:mm AP");

                // Show availability
                QString availabilityText;
                if (bookedCount == 0) {
                    availabilityText = " [2 slots free]";
                } else if (bookedCount == 1) {
                    availabilityText = " [⚠ Last slot!]";
                }

                QString displayText = QString("%1 - %2%3")
                                          .arg(start12hr, end12hr, availabilityText);
                slotCombo->addItem(displayText, slotId);
                availableCount++;
            }

            if (availableCount == 0) {
                slotCombo->addItem("❌ No slots available - All full", -1);
                slotCombo->setEnabled(false);
            } else {
                slotCombo->setEnabled(true);
            }
        }
    };

    // Load initial slots
    loadAvailableSlots(dateEdit->date());

    // Reload slots when date changes
    connect(dateEdit, &QDateEdit::dateChanged, [&](const QDate &date) {
        loadAvailableSlots(date);
    });

    // Buttons
    QHBoxLayout *btnLayout = new QHBoxLayout();
    QPushButton *btnConfirm = new QPushButton("✓ Reschedule");
    QPushButton *btnCancel = new QPushButton("✗ Cancel");

    btnConfirm->setStyleSheet(
        "QPushButton { background-color: #4caf50; color: white; "
        "font-weight: bold; padding: 10px; border-radius: 5px; }"
        "QPushButton:hover { background-color: #45a049; }"
        );

    btnCancel->setStyleSheet(
        "QPushButton { background-color: #f44336; color: white; "
        "font-weight: bold; padding: 10px; border-radius: 5px; }"
        "QPushButton:hover { background-color: #da190b; }"
        );

    btnLayout->addWidget(btnConfirm);
    btnLayout->addWidget(btnCancel);

    layout->addWidget(lblInfo);
    layout->addWidget(lblDate);
    layout->addWidget(dateEdit);
    layout->addWidget(lblSlot);
    layout->addWidget(slotCombo);
    layout->addStretch();
    layout->addLayout(btnLayout);

    connect(btnConfirm, &QPushButton::clicked, &rescheduleDialog, &QDialog::accept);
    connect(btnCancel, &QPushButton::clicked, &rescheduleDialog, &QDialog::reject);

    if (rescheduleDialog.exec() == QDialog::Accepted) {
        QDate newDate = dateEdit->date();
        int newSlotId = slotCombo->currentData().toInt();

        if (newSlotId == -1) {
            QMessageBox::warning(this, "Invalid Slot", "Please select a valid time slot.");
            return;
        }

        // Final capacity check before updating
        QSqlQuery capacityCheck;
        capacityCheck.prepare(R"(
            SELECT COUNT(*) as count
            FROM appointments
            WHERE doctor_id = :doctor_id
            AND date = :date
            AND slot_id = :slot_id
            AND status NOT IN ('cancelled', 'completed')
            AND id != :current_id
        )");

        capacityCheck.bindValue(":doctor_id", doctorId);
        capacityCheck.bindValue(":date", newDate.toString("yyyy-MM-dd"));
        capacityCheck.bindValue(":slot_id", newSlotId);
        capacityCheck.bindValue(":current_id", appointmentId);

        if (capacityCheck.exec() && capacityCheck.next()) {
            int bookedCount = capacityCheck.value("count").toInt();
            if (bookedCount >= 2) {
                QMessageBox::warning(this, "Slot Full",
                                     "⚠️ This slot is now full!\n\n"
                                     "Someone else booked while you were selecting.\n"
                                     "Please choose a different slot.");
                return;
            }
        }

        // Update the appointment
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE appointments SET date = :date, slot_id = :slot WHERE id = :id");
        updateQuery.bindValue(":date", newDate.toString("yyyy-MM-dd"));
        updateQuery.bindValue(":slot", newSlotId);
        updateQuery.bindValue(":id", appointmentId);

        if (updateQuery.exec()) {
            QMessageBox::information(this, "Success",
                                     "✅ Appointment rescheduled successfully!\n\n"
                                     "New Date: " + newDate.toString("dddd, MMMM dd, yyyy") + "\n"
                                                                                     "New Time: " + slotCombo->currentText());
            loadAppointments();
        } else {
            QMessageBox::critical(this, "Error",
                                  "Failed to reschedule appointment:\n" + updateQuery.lastError().text());
        }
    }
}

void MyAppointments::viewDetails()
{
    int row = ui->tableAppointments->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select an appointment first.");
        return;
    }

    QString details =
        "📋 Appointment Details\n\n"
        "Doctor: " + ui->tableAppointments->item(row, 1)->text() + "\n"
                                                        "Date: " + ui->tableAppointments->item(row, 2)->text() + "\n"
                                                        "Time Slot: " + ui->tableAppointments->item(row, 3)->text() + "\n"
                                                        "Status: " + ui->tableAppointments->item(row, 4)->text() + "\n"
                                                        "Payment: " + ui->tableAppointments->item(row, 5)->text();

    QMessageBox::information(this, "Appointment Details", details);
}
