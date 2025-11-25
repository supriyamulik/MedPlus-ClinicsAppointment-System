#include "bookappointment.h"
#include "ui_bookappointment.h"
#include <QDateTime>
#include <QApplication>
#include <QTextCharFormat>

BookAppointment::BookAppointment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BookAppointment)
    , m_patientId(1)
    , m_refreshTimer(new QTimer(this))
    , m_isLoading(false)
    , m_calendar(nullptr)
{
    ui->setupUi(this);
    setupUI();
    setupDatabase();
    setupCalendar();

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
    , m_calendar(nullptr)
{
    ui->setupUi(this);
    setupUI();
    setupDatabase();
    setupCalendar();

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

    // Apply styling to ensure text visibility
    this->setStyleSheet(
        "QDialog { background-color: white; color: #2c3e50; }"
        "QLabel { color: #2c3e50; font-weight: bold; }"
        "QComboBox { background-color: white; color: #2c3e50; border: 1px solid #ccc; border-radius: 4px; padding: 8px; }"
        "QComboBox QAbstractItemView { background-color: white; color: #2c3e50; selection-background-color: #007bff; selection-color: white; }"
        "QDateEdit { background-color: white; color: #2c3e50; border: 1px solid #ccc; border-radius: 4px; padding: 8px; }"
        "QPushButton { background-color: #007bff; color: white; border: none; border-radius: 4px; padding: 10px 20px; font-weight: bold; }"
        "QPushButton:hover { background-color: #0056b3; }"
        "QPushButton:disabled { background-color: #6c757d; color: #dee2e6; }"
        "QPushButton#btnCancel { background-color: #dc3545; }"
        "QPushButton#btnCancel:hover { background-color: #c82333; }"
        );

    ui->dateAppointment->setMinimumDate(QDate::currentDate());
    ui->dateAppointment->setMaximumDate(QDate::currentDate().addMonths(3));
    ui->dateAppointment->setDate(QDate::currentDate());
    ui->dateAppointment->setCalendarPopup(true);

    ui->comboSlot->setEnabled(false);
    ui->btnBook->setEnabled(false);

    ui->comboDoctor->setToolTip("Choose your preferred doctor");
    ui->dateAppointment->setToolTip("Select appointment date (up to 3 months ahead, Sundays excluded)");
    ui->comboSlot->setToolTip("Available time slots will appear here");
    ui->btnBook->setToolTip("Confirm your appointment booking");
}

void BookAppointment::setupCalendar()
{
    m_calendar = ui->dateAppointment->calendarWidget();

    if (m_calendar) {
        // Style the calendar widget
        m_calendar->setStyleSheet(
            "QCalendarWidget { "
            "   background-color: white; "
            "   color: #2c3e50; "
            "}"
            "QCalendarWidget QToolButton { "
            "   color: white; "
            "   background-color: #1976d2; "
            "   border-radius: 5px; "
            "   padding: 5px; "
            "}"
            "QCalendarWidget QToolButton:hover { "
            "   background-color: #1565c0; "
            "}"
            "QCalendarWidget QMenu { "
            "   background-color: white; "
            "   color: #2c3e50; "
            "}"
            "QCalendarWidget QSpinBox { "
            "   background-color: white; "
            "   color: #2c3e50; "
            "   selection-background-color: #1976d2; "
            "   selection-color: white; "
            "}"
            "QCalendarWidget QAbstractItemView:enabled { "
            "   color: #2c3e50; "
            "   background-color: white; "
            "   selection-background-color: #42a5f5; "
            "   selection-color: white; "
            "}"
            "QCalendarWidget QAbstractItemView:disabled { "
            "   color: #bdc3c7; "
            "}"
            "QCalendarWidget QWidget#qt_calendar_navigationbar { "
            "   background-color: #1976d2; "
            "}"
            );

        // Format for Sundays (holidays)
        QTextCharFormat sundayFormat;
        sundayFormat.setForeground(QBrush(QColor("#e74c3c"))); // Red color
        sundayFormat.setBackground(QBrush(QColor("#ffebee"))); // Light red background
        sundayFormat.setFontWeight(QFont::Bold);
        sundayFormat.setToolTip("Clinic closed on Sundays");
        m_calendar->setWeekdayTextFormat(Qt::Sunday, sundayFormat);

        // Format for Saturdays (optional - working days but different color)
        QTextCharFormat saturdayFormat;
        saturdayFormat.setForeground(QBrush(QColor("#2c3e50")));
        saturdayFormat.setFontWeight(QFont::Normal);
        m_calendar->setWeekdayTextFormat(Qt::Saturday, saturdayFormat);

        // Format for regular weekdays
        QTextCharFormat weekdayFormat;
        weekdayFormat.setForeground(QBrush(QColor("#2c3e50")));
        m_calendar->setWeekdayTextFormat(Qt::Monday, weekdayFormat);
        m_calendar->setWeekdayTextFormat(Qt::Tuesday, weekdayFormat);
        m_calendar->setWeekdayTextFormat(Qt::Wednesday, weekdayFormat);
        m_calendar->setWeekdayTextFormat(Qt::Thursday, weekdayFormat);
        m_calendar->setWeekdayTextFormat(Qt::Friday, weekdayFormat);

        // Highlight current date
        QTextCharFormat todayFormat;
        todayFormat.setBackground(QBrush(QColor("#e3f2fd")));
        todayFormat.setForeground(QBrush(QColor("#1976d2")));
        todayFormat.setFontWeight(QFont::Bold);

        // Set grid visible
        m_calendar->setGridVisible(true);
        m_calendar->setFirstDayOfWeek(Qt::Monday);
        m_calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        m_calendar->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
    }
}

void BookAppointment::setupDatabase()
{
    QString connectionName = QString("booking_conn_%1").arg((quintptr)this);
    db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    db.setDatabaseName("C:/Users/Supriya/ClinicsAppointment.db");

    db.setConnectOptions("QSQLITE_BUSY_TIMEOUT=5000");

    if (!db.open()) {
        QMessageBox *msgBox = createStyledMessageBox(
            "Database Connection Error",
            QString("Unable to connect to database.\n\nError: %1\n\nPlease ensure the database file exists.")
                .arg(db.lastError().text()),
            QMessageBox::Ok
            );
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->exec();
        delete msgBox;
        logBookingActivity(QString("Database connection failed: %1").arg(db.lastError().text()));
        return;
    }

    QSqlQuery pragma(db);
    pragma.exec("PRAGMA journal_mode=WAL;");
    pragma.exec("PRAGMA synchronous=NORMAL;");
    pragma.exec("PRAGMA busy_timeout = 5000;");

    logBookingActivity("Database connected successfully (WAL mode enabled)");
}

void BookAppointment::loadDoctors()
{
    if (!db.isOpen()) {
        QMessageBox *msgBox = createStyledMessageBox("Database Error",
                                                     "Database connection not available.");
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->exec();
        delete msgBox;
        return;
    }

    showLoadingState(true);
    ui->comboDoctor->clear();

    QSqlQuery query(db);
    query.prepare("SELECT id, name, specialization FROM doctors WHERE is_available = 1 ORDER BY name ASC");

    if (!query.exec()) {
        showLoadingState(false);
        QMessageBox *msgBox = createStyledMessageBox(
            "Query Error",
            QString("Failed to load doctors from database.\n\nError: %1").arg(query.lastError().text())
            );
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->exec();
        delete msgBox;
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
        QMessageBox *msgBox = createStyledMessageBox("No Doctors",
                                                     "No doctors are currently available in the system.");
        msgBox->setIcon(QMessageBox::Information);
        msgBox->exec();
        delete msgBox;
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
    // Check if selected date is Sunday
    if (date.dayOfWeek() == Qt::Sunday) {
        QMessageBox *msgBox = createStyledMessageBox(
            "Invalid Date",
            "⚠️ Clinic is closed on Sundays!\n\nPlease select a weekday (Monday - Saturday) for your appointment.",
            QMessageBox::Ok
            );
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->exec();
        delete msgBox;

        // Move to next valid date (Monday)
        QDate nextValidDate = date.addDays(1);
        ui->dateAppointment->setDate(nextValidDate);
        return;
    }

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

    // Check if Sunday
    if (selectedDate.dayOfWeek() == Qt::Sunday) {
        ui->comboSlot->addItem("❌ Clinic closed on Sundays", -1);
        ui->comboSlot->setEnabled(false);
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
             AND a.status = 'booked'
            ) as booked_count
        FROM slots s
        WHERE s.id NOT IN (
            SELECT DISTINCT slot_id
            FROM appointments
            WHERE date = ?
            AND patient_id = ?
            AND status = 'booked'
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
        QMessageBox *msgBox = createStyledMessageBox(
            "Query Error",
            QString("Failed to load available slots.\n\nError: %1").arg(query.lastError().text())
            );
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->exec();
        delete msgBox;
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

        if (isToday && slotStart <= currentTime.addSecs(3600)) {
            continue;
        }

        if (bookedCount >= 2) {
            continue;
        }

        QString start12hr = slotStart.toString("h:mm AP");
        QString end12hr = slotEnd.toString("h:mm AP");

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
    logBookingActivity(QString("Loaded %1 available slots for doctor %2 on %3")
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
        QMessageBox *msgBox = createStyledMessageBox(
            "Validation Error",
            "Please select a doctor before booking an appointment."
            );
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->exec();
        delete msgBox;
        ui->comboDoctor->setFocus();
        return false;
    }

    if (ui->comboSlot->currentData().toInt() <= 0) {
        QMessageBox *msgBox = createStyledMessageBox(
            "Validation Error",
            "Please select an available time slot."
            );
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->exec();
        delete msgBox;
        ui->comboSlot->setFocus();
        return false;
    }

    QDate selectedDate = ui->dateAppointment->date();
    if (selectedDate < QDate::currentDate()) {
        QMessageBox *msgBox = createStyledMessageBox(
            "Validation Error",
            "Cannot book appointments for past dates."
            );
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->exec();
        delete msgBox;
        ui->dateAppointment->setFocus();
        return false;
    }

    if (selectedDate.dayOfWeek() == Qt::Sunday) {
        QMessageBox *msgBox = createStyledMessageBox(
            "Validation Error",
            "⚠️ Cannot book appointments on Sundays!\n\nClinic is closed."
            );
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->exec();
        delete msgBox;
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
        AND status = 'booked'
    )");

    query.addBindValue(doctorId);
    query.addBindValue(date.toString("yyyy-MM-dd"));
    query.addBindValue(slotId);

    if (query.exec() && query.next()) {
        int bookedCount = query.value("booked_count").toInt();
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
        AND status = 'booked'
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
        AND status = 'booked'
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
    QString dateStr = selectedDate.toString("yyyy-MM-dd");

    QString doctorName = ui->comboDoctor->currentText();
    QString slotTime = ui->comboSlot->currentText();

    QSqlQuery countQuery(db);
    countQuery.prepare(R"(
        SELECT COUNT(*) as booked_count
        FROM appointments
        WHERE doctor_id = ? AND date = ? AND slot_id = ?
        AND status = 'booked'
    )");
    countQuery.addBindValue(doctorId);
    countQuery.addBindValue(dateStr);
    countQuery.addBindValue(slotId);

    int currentBookings = 0;
    if (countQuery.exec() && countQuery.next()) {
        currentBookings = countQuery.value("booked_count").toInt();
    }

    if (currentBookings >= 2) {
        QMessageBox *msgBox = createStyledMessageBox(
            "Slot Full",
            "⚠️ This time slot is already full!\n\n"
            "Maximum 2 appointments are allowed per slot.\n"
            "This slot already has 2 bookings.\n\n"
            "Please select a different time slot."
            );
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->exec();
        delete msgBox;
        loadAvailableSlots();
        return;
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

    QMessageBox *confirmDialog = createStyledMessageBox(
        "Confirm Appointment",
        confirmMsg,
        QMessageBox::Yes | QMessageBox::No
        );
    confirmDialog->setDefaultButton(QMessageBox::Yes);
    confirmDialog->setIcon(QMessageBox::Question);

    int result = confirmDialog->exec();
    delete confirmDialog;

    if (result != QMessageBox::Yes) {
        return;
    }

    QSqlQuery bookingQuery(db);
    bookingQuery.prepare(R"(
        INSERT INTO appointments (doctor_id, patient_id, date, slot_id, status)
        VALUES (?, ?, ?, ?, 'booked')
    )");

    bookingQuery.addBindValue(doctorId);
    bookingQuery.addBindValue(m_patientId);
    bookingQuery.addBindValue(dateStr);
    bookingQuery.addBindValue(slotId);

    if (bookingQuery.exec()) {
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

        QMessageBox *successDialog = createStyledMessageBox("Booking Successful", successMsg);
        successDialog->setIcon(QMessageBox::Information);
        successDialog->exec();
        delete successDialog;

        logBookingActivity(QString(
                               "Successfully booked - Doctor: %1, Date: %2, Slot: %3, Capacity: %4/2"
                               ).arg(doctorId).arg(dateStr).arg(slotId).arg(currentBookings + 1));

        accept();
    } else {
        QString errorText = bookingQuery.lastError().text();
        QMessageBox *msgBox = createStyledMessageBox(
            "Booking Error",
            QString("Failed to book appointment.\n\nError: %1\n\n"
                    "Please try again or select a different time slot.").arg(errorText)
            );
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->exec();
        delete msgBox;

        logBookingActivity(QString("Booking failed: %1").arg(errorText));
        loadAvailableSlots();
    }
}

void BookAppointment::on_btnCancel_clicked()
{
    QMessageBox *cancelDialog = createStyledMessageBox(
        "Cancel Booking",
        "Are you sure you want to cancel the booking process?",
        QMessageBox::Yes | QMessageBox::No
        );
    cancelDialog->setDefaultButton(QMessageBox::No);
    cancelDialog->setIcon(QMessageBox::Question);

    int result = cancelDialog->exec();
    delete cancelDialog;

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

QMessageBox* BookAppointment::createStyledMessageBox(const QString &title, const QString &text,
                                                     QMessageBox::StandardButtons buttons)
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setWindowTitle(title);
    msgBox->setText(text);
    msgBox->setStandardButtons(buttons);

    // Enhanced styling for better text visibility
    msgBox->setStyleSheet(
        "QMessageBox { "
        "   background-color: white; "
        "}"
        "QMessageBox QLabel { "
        "   color: #2c3e50; "
        "   font-size: 13px; "
        "   min-width: 150px; "
        "   padding: 10px; "
        "}"
        "QPushButton { "
        "   background-color: #007bff; "
        "   color: white; "
        "   border: none; "
        "   border-radius: 4px; "
        "   padding: 8px 16px; "
        "   min-width: 80px; "
        "   font-weight: bold; "
        "}"
        "QPushButton:hover { "
        "   background-color: #0056b3; "
        "}"
        "QPushButton:pressed { "
        "   background-color: #004085; "
        "}"
        "QPushButton[text='No'], QPushButton[text='Cancel'] { "
        "   background-color: #6c757d; "
        "}"
        "QPushButton[text='No']:hover, QPushButton[text='Cancel']:hover { "
        "   background-color: #5a6268; "
        "}"
        );

    return msgBox;
}
