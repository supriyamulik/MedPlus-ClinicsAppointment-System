#include "bookappointment.h"
#include "ui_bookappointment.h"
#include <QDateTime>
#include <QApplication>

BookAppointment::BookAppointment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BookAppointment)
    , m_patientId(1)
    , m_refreshTimer(new QTimer(this))
    , m_isLoading(false)
{
    ui->setupUi(this);
    setupUI();
    setupDatabase();

    m_refreshTimer->setInterval(30000);
    connect(m_refreshTimer, &QTimer::timeout, this, &BookAppointment::refreshSlots);

    loadDoctors();
}

BookAppointment::BookAppointment(int patientId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BookAppointment)
    , m_patientId(patientId)
    , m_refreshTimer(new QTimer(this))
    , m_isLoading(false)
{
    ui->setupUi(this);
    setupUI();
    setupDatabase();

    m_refreshTimer->setInterval(30000);
    connect(m_refreshTimer, &QTimer::timeout, this, &BookAppointment::refreshSlots);

    loadDoctors();
}

BookAppointment::~BookAppointment()
{
    if (m_refreshTimer) {
        m_refreshTimer->stop();
    }
    if (db.isOpen()) {
        db.close();
    }
    delete ui;
}

void BookAppointment::setPatientId(int patientId)
{
    m_patientId = patientId;
    logBookingActivity(QString("Patient ID set to: %1").arg(patientId));
}

void BookAppointment::setupUI()
{
    setWindowTitle("Book Appointment - MedPlus Clinic");
    setModal(true);

    ui->dateAppointment->setMinimumDate(QDate::currentDate());
    ui->dateAppointment->setMaximumDate(QDate::currentDate().addMonths(3));
    ui->dateAppointment->setDate(QDate::currentDate());

    ui->comboSlot->setEnabled(false);
    ui->btnBook->setEnabled(false);

    ui->comboDoctor->setToolTip("Choose your preferred doctor");
    ui->dateAppointment->setToolTip("Select appointment date (up to 3 months ahead)");
    ui->comboSlot->setToolTip("Available time slots will appear here");
    ui->btnBook->setToolTip("Confirm your appointment booking");
}

void BookAppointment::setupDatabase()
{
    QString connectionName = QString("booking_conn_%1").arg((quintptr)this);
    db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    db.setDatabaseName("C:/Users/Supriya/ClinicsAppointment.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Connection Error",
                              QString("Unable to connect to database.\n\nError: %1\n\nPlease ensure the database file exists.")
                                  .arg(db.lastError().text()));
        logBookingActivity(QString("Database connection failed: %1").arg(db.lastError().text()));
    } else {
        logBookingActivity("Database connected successfully");
    }
}

void BookAppointment::loadDoctors()
{
    if (!db.isOpen()) {
        QMessageBox::warning(this, "Database Error", "Database connection not available.");
        return;
    }

    showLoadingState(true);
    ui->comboDoctor->clear();

    QSqlQuery query(db);
    query.prepare("SELECT id, name, specialization, phone FROM doctors ORDER BY name ASC");

    if (!query.exec()) {
        showLoadingState(false);
        QMessageBox::critical(this, "Query Error",
                              QString("Failed to load doctors from database.\n\nError: %1").arg(query.lastError().text()));
        logBookingActivity(QString("Failed to load doctors: %1").arg(query.lastError().text()));
        return;
    }

    ui->comboDoctor->addItem("-- Select Doctor --", -1);

    bool hasDoctors = false;
    while (query.next()) {
        hasDoctors = true;
        int doctorId = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString specialization = query.value(2).toString();
        QString displayText = QString("Dr. %1 (%2)").arg(name, specialization);
        ui->comboDoctor->addItem(displayText, doctorId);
    }

    if (!hasDoctors) {
        ui->comboDoctor->addItem("No doctors available", -1);
        QMessageBox::information(this, "No Doctors", "No doctors are currently available in the system.");
    }

    showLoadingState(false);
    logBookingActivity(QString("Loaded %1 doctors").arg(ui->comboDoctor->count() - 1));
}

void BookAppointment::on_comboDoctor_currentIndexChanged(int index)
{
    Q_UNUSED(index)

    if (ui->comboDoctor->currentData().toInt() > 0) {
        ui->comboSlot->setEnabled(true);
        loadAvailableSlots();

        if (!m_refreshTimer->isActive()) {
            m_refreshTimer->start();
        }
    } else {
        ui->comboSlot->setEnabled(false);
        ui->btnBook->setEnabled(false);
        clearSlots();
        m_refreshTimer->stop();
    }
}

void BookAppointment::on_dateAppointment_dateChanged(const QDate &date)
{
    Q_UNUSED(date)

    if (ui->comboDoctor->currentData().toInt() > 0) {
        loadAvailableSlots();
    }
}

void BookAppointment::loadAvailableSlots()
{
    if (!db.isOpen() || m_isLoading) {
        return;
    }

    showLoadingState(true);
    clearSlots();

    int doctorId = ui->comboDoctor->currentData().toInt();
    QDate selectedDate = ui->dateAppointment->date();

    if (doctorId <= 0) {
        showLoadingState(false);
        return;
    }

    QSqlQuery query(db);
    query.prepare(R"(
        SELECT
            s.id,
            s.start_time,
            s.end_time,
            (SELECT COUNT(*)
             FROM appointments a
             WHERE a.slot_id = s.id
             AND a.doctor_id = ?
             AND a.date = ?
             AND a.status NOT IN ('cancelled', 'completed')
            ) as booked_count
        FROM slots s
        WHERE s.id NOT IN (
            SELECT DISTINCT slot_id
            FROM appointments
            WHERE date = ?
            AND patient_id = ?
            AND status NOT IN ('cancelled', 'completed')
        )
        ORDER BY s.start_time ASC
    )");

    QString dateStr = selectedDate.toString("yyyy-MM-dd");
    query.addBindValue(doctorId);
    query.addBindValue(dateStr);
    query.addBindValue(dateStr);
    query.addBindValue(m_patientId);

    if (!query.exec()) {
        showLoadingState(false);
        QMessageBox::critical(this, "Query Error",
                              QString("Failed to load available slots.\n\nError: %1")
                                  .arg(query.lastError().text()));
        logBookingActivity(QString("Failed to load slots: %1").arg(query.lastError().text()));
        return;
    }

    ui->comboSlot->addItem("-- Select Time Slot --", -1);

    int availableCount = 0;
    QTime currentTime = QTime::currentTime();
    bool isToday = (selectedDate == QDate::currentDate());

    while (query.next()) {
        int slotId = query.value(0).toInt();
        QString startTime = query.value(1).toString();
        QString endTime = query.value(2).toString();
        int bookedCount = query.value(3).toInt();

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

        // Show availability in slot text
        QString availabilityText;
        if (bookedCount == 0) {
            availabilityText = " [2 slots free]";
        } else if (bookedCount == 1) {
            availabilityText = " [⚠ Last slot!]";
        }

        QString displayText = QString("%1 - %2%3").arg(start12hr, end12hr, availabilityText);
        ui->comboSlot->addItem(displayText, slotId);
        availableCount++;
    }

    if (availableCount == 0) {
        ui->comboSlot->addItem("❌ No slots available - All full or booked", -1);
        ui->comboSlot->setEnabled(false);
    } else {
        connect(ui->comboSlot, QOverload<int>::of(&QComboBox::currentIndexChanged),
                [this](int index) {
                    ui->btnBook->setEnabled(index >= 0 && ui->comboSlot->currentData().toInt() > 0);
                });
    }

    showLoadingState(false);
    logBookingActivity(QString("Loaded %1 available slots (excluding full slots) for doctor %2 on %3")
                           .arg(availableCount).arg(doctorId).arg(dateStr));
}

void BookAppointment::clearSlots()
{
    ui->comboSlot->clear();
    ui->btnBook->setEnabled(false);
}

void BookAppointment::refreshSlots()
{
    if (ui->comboDoctor->currentData().toInt() > 0 && !m_isLoading) {
        logBookingActivity("Auto-refreshing available slots");
        loadAvailableSlots();
    }
}

bool BookAppointment::validateBooking()
{
    if (ui->comboDoctor->currentData().toInt() <= 0) {
        QMessageBox::warning(this, "Validation Error",
                             "Please select a doctor before booking an appointment.");
        ui->comboDoctor->setFocus();
        return false;
    }

    if (ui->comboSlot->currentData().toInt() <= 0) {
        QMessageBox::warning(this, "Validation Error",
                             "Please select an available time slot.");
        ui->comboSlot->setFocus();
        return false;
    }

    QDate selectedDate = ui->dateAppointment->date();
    if (selectedDate < QDate::currentDate()) {
        QMessageBox::warning(this, "Validation Error",
                             "Cannot book appointments for past dates.");
        ui->dateAppointment->setFocus();
        return false;
    }

    return true;
}

bool BookAppointment::checkSlotCapacity(int doctorId, const QDate &date, int slotId)
{
    QSqlQuery query(db);
    query.prepare(R"(
        SELECT COUNT(*) as booked_count
        FROM appointments
        WHERE doctor_id = ? AND date = ? AND slot_id = ?
        AND status NOT IN ('cancelled', 'completed')
    )");

    query.addBindValue(doctorId);
    query.addBindValue(date.toString("yyyy-MM-dd"));
    query.addBindValue(slotId);

    if (query.exec() && query.next()) {
        int bookedCount = query.value("booked_count").toInt();

        qDebug() << "Slot Capacity Check - Doctor:" << doctorId
                 << "Date:" << date.toString()
                 << "Slot:" << slotId
                 << "Booked:" << bookedCount << "/2";

        return bookedCount >= 2;
    }

    return true;
}

bool BookAppointment::checkTimeConflict(int doctorId, const QDate &date, int slotId)
{
    QSqlQuery query(db);
    query.prepare(R"(
        SELECT COUNT(*) FROM appointments
        WHERE doctor_id = ? AND date = ? AND slot_id = ?
        AND status NOT IN ('cancelled', 'completed')
    )");

    query.addBindValue(doctorId);
    query.addBindValue(date.toString("yyyy-MM-dd"));
    query.addBindValue(slotId);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    return true;
}

bool BookAppointment::checkPatientConflict(const QDate &date, int slotId)
{
    QSqlQuery query(db);
    query.prepare(R"(
        SELECT COUNT(*) FROM appointments
        WHERE patient_id = ? AND date = ? AND slot_id = ?
        AND status NOT IN ('cancelled', 'completed')
    )");

    query.addBindValue(m_patientId);
    query.addBindValue(date.toString("yyyy-MM-dd"));
    query.addBindValue(slotId);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    return true;
}

void BookAppointment::on_btnBook_clicked()
{
    if (!validateBooking()) {
        return;
    }

    int doctorId = ui->comboDoctor->currentData().toInt();
    int slotId = ui->comboSlot->currentData().toInt();
    QDate selectedDate = ui->dateAppointment->date();

    // Check slot capacity (max 2 appointments)
    if (checkSlotCapacity(doctorId, selectedDate, slotId)) {
        QMessageBox::warning(this, "Slot Full",
                             "⚠️ This time slot is already full!\n\n"
                             "Maximum 2 appointments are allowed per slot.\n"
                             "This slot already has 2 bookings.\n\n"
                             "Please select a different time slot.");

        logBookingActivity("Booking failed: Slot capacity full (2/2)");
        loadAvailableSlots();
        return;
    }

    // Check time conflict
    if (checkTimeConflict(doctorId, selectedDate, slotId)) {
        QMessageBox::warning(this, "Booking Conflict",
                             "This time slot is no longer available. Please select a different slot.");
        loadAvailableSlots();
        return;
    }

    // Check patient conflict
    if (checkPatientConflict(selectedDate, slotId)) {
        QMessageBox::warning(this, "Patient Conflict",
                             "You already have an appointment at this time slot. Please choose a different time.");
        return;
    }

    QString doctorName = ui->comboDoctor->currentText();
    QString slotTime = ui->comboSlot->currentText();

    // Get current bookings count
    QSqlQuery countQuery(db);
    countQuery.prepare(R"(
        SELECT COUNT(*) as booked_count
        FROM appointments
        WHERE doctor_id = ? AND date = ? AND slot_id = ?
        AND status NOT IN ('cancelled', 'completed')
    )");
    countQuery.addBindValue(doctorId);
    countQuery.addBindValue(selectedDate.toString("yyyy-MM-dd"));
    countQuery.addBindValue(slotId);

    int currentBookings = 0;
    if (countQuery.exec() && countQuery.next()) {
        currentBookings = countQuery.value("booked_count").toInt();
    }

    int remainingSlots = 2 - currentBookings - 1;

    QString confirmMsg = QString(
                             "Confirm booking:\n\n"
                             "Doctor: %1\n"
                             "Date: %2\n"
                             "Time: %3\n\n"
                             "📊 Slot Status:\n"
                             "Current Bookings: %4/2\n"
                             "After your booking: %5/2\n"
                             "Remaining slots: %6\n\n"
                             "Proceed with booking?"
                             ).arg(doctorName,
                                  selectedDate.toString("dddd, MMMM dd, yyyy"),
                                  slotTime)
                             .arg(currentBookings)
                             .arg(currentBookings + 1)
                             .arg(remainingSlots);

    int result = QMessageBox::question(this, "Confirm Appointment", confirmMsg,
                                       QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    if (result != QMessageBox::Yes) {
        return;
    }

    db.transaction();

    QSqlQuery bookingQuery(db);
    bookingQuery.prepare(R"(
        INSERT INTO appointments (doctor_id, patient_id, date, slot_id, status)
        VALUES (?, ?, ?, ?, 'booked')
    )");

    bookingQuery.addBindValue(doctorId);
    bookingQuery.addBindValue(m_patientId);
    bookingQuery.addBindValue(selectedDate.toString("yyyy-MM-dd"));
    bookingQuery.addBindValue(slotId);

    if (bookingQuery.exec()) {
        if (db.commit()) {
            QString successMsg = QString(
                                     "✅ Your appointment has been successfully booked!\n\n"
                                     "Appointment Details:\n"
                                     "Doctor: %1\n"
                                     "Date: %2\n"
                                     "Time: %3\n\n"
                                     "📊 Slot Status: %4/2 booked\n"
                                     "Remaining slots: %5\n\n"
                                     "⏰ Please arrive 15 minutes early.\n"
                                     "Bring your ID and insurance card."
                                     ).arg(doctorName,
                                          selectedDate.toString("dddd, MMMM dd, yyyy"),
                                          slotTime)
                                     .arg(currentBookings + 1)
                                     .arg(remainingSlots);

            QMessageBox::information(this, "Booking Successful", successMsg);

            logBookingActivity(QString(
                                   "Successfully booked - Doctor: %1, Date: %2, Slot: %3, Capacity: %4/2"
                                   ).arg(doctorId).arg(selectedDate.toString()).arg(slotId).arg(currentBookings + 1));

            accept();
        } else {
            db.rollback();
            QMessageBox::critical(this, "Booking Error",
                                  "Failed to commit booking to database. Please try again.");
            logBookingActivity("Failed to commit booking transaction");
        }
    } else {
        db.rollback();
        QMessageBox::critical(this, "Booking Error",
                              QString("Failed to book appointment.\n\nError: %1\n\n"
                                      "The time slot may have been taken by another patient.")
                                  .arg(bookingQuery.lastError().text()));

        logBookingActivity(QString("Booking failed: %1").arg(bookingQuery.lastError().text()));
        loadAvailableSlots();
    }
}

void BookAppointment::on_btnCancel_clicked()
{
    int result = QMessageBox::question(this, "Cancel Booking",
                                       "Are you sure you want to cancel the booking process?",
                                       QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if (result == QMessageBox::Yes) {
        logBookingActivity("User cancelled booking process");
        reject();
    }
}

void BookAppointment::showLoadingState(bool loading)
{
    m_isLoading = loading;
    ui->comboDoctor->setEnabled(!loading);
    ui->dateAppointment->setEnabled(!loading);
    ui->comboSlot->setEnabled(!loading && ui->comboDoctor->currentData().toInt() > 0);
    ui->btnBook->setEnabled(!loading && ui->comboSlot->currentData().toInt() > 0);

    setCursor(loading ? Qt::WaitCursor : Qt::ArrowCursor);
}

void BookAppointment::logBookingActivity(const QString &activity)
{
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    qDebug() << QString("[BOOKING %1] Patient %2: %3")
                    .arg(timestamp).arg(m_patientId).arg(activity);
}
