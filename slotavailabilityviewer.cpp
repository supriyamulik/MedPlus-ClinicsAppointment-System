#include "slotavailabilityviewer.h"
#include "ui_slotavailabilityviewer.h"

SlotAvailabilityViewer::SlotAvailabilityViewer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SlotAvailabilityViewer)
{
    ui->setupUi(this);

    // Setup database and table
    setupDatabase();
    setupTable();
    loadDoctors();

    // Set current date
    ui->dateSelect->setDate(QDate::currentDate());

    // Connect signals
    connect(ui->btnSearch, &QPushButton::clicked, this, &SlotAvailabilityViewer::searchSlots);
    connect(ui->btnRefresh, &QPushButton::clicked, this, &SlotAvailabilityViewer::refreshData);
    connect(ui->btnClose, &QPushButton::clicked, this, &QDialog::close);
    connect(ui->dateSelect, &QDateEdit::dateChanged, this, &SlotAvailabilityViewer::searchSlots);

    // Load initial data
    loadSlotAvailability();
}

SlotAvailabilityViewer::~SlotAvailabilityViewer()
{
    delete ui;
}

void SlotAvailabilityViewer::setupDatabase()
{
    db = QSqlDatabase::database(); // Use existing connection
    if (!db.isOpen())
    {
        QMessageBox::critical(this, "Database Error", "Database is not connected!");
    }
}

void SlotAvailabilityViewer::setupTable()
{
    ui->tableSlotAvailability->setColumnWidth(0, 200); // Doctor
    ui->tableSlotAvailability->setColumnWidth(1, 180); // Specialization
    ui->tableSlotAvailability->setColumnWidth(2, 180); // Time Slot
    ui->tableSlotAvailability->setColumnWidth(3, 120); // Booked
    ui->tableSlotAvailability->setColumnWidth(4, 120); // Available
    ui->tableSlotAvailability->setColumnWidth(5, 280); // Status

    ui->tableSlotAvailability->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableSlotAvailability->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableSlotAvailability->setAlternatingRowColors(true);
}

void SlotAvailabilityViewer::loadDoctors()
{
    ui->comboFilterDoctor->clear();
    ui->comboFilterDoctor->addItem("All Doctors", -1);

    // ✅ Fixed: Use correct column name 'id' instead of 'doctor_id'
    QSqlQuery query("SELECT id, name, specialization FROM doctors ORDER BY name");
    while (query.next()) {
        int doctorId = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString spec = query.value(2).toString();
        ui->comboFilterDoctor->addItem(name + " (" + spec + ")", doctorId);
    }
}

void SlotAvailabilityViewer::loadSlotAvailability()
{
    QDate selectedDate = ui->dateSelect->date();
    int doctorId = ui->comboFilterDoctor->currentData().toInt();
    populateAvailabilityTable(selectedDate, doctorId);
}

void SlotAvailabilityViewer::searchSlots()
{
    loadSlotAvailability();
}

void SlotAvailabilityViewer::refreshData()
{
    loadDoctors();
    loadSlotAvailability();
    QMessageBox::information(this, "Refreshed", "Data has been refreshed successfully!");
}

void SlotAvailabilityViewer::populateAvailabilityTable(const QDate &date, int doctorId)
{
    ui->tableSlotAvailability->setRowCount(0);

    // ✅ Fixed: Use correct column names from your database
    QString queryStr = R"(
        SELECT d.id, d.name, d.specialization,
               s.id, s.start_time, s.end_time
        FROM doctors d
        CROSS JOIN slots s
    )";

    if (doctorId != -1) {
        queryStr += " WHERE d.id = :doctorId";
    }

    queryStr += " ORDER BY d.name, s.start_time";

    QSqlQuery query;
    query.prepare(queryStr);
    if (doctorId != -1) {
        query.bindValue(":doctorId", doctorId);
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Query Error",
                              QString("Failed to load data:\n%1\n\nQuery: %2")
                                  .arg(query.lastError().text())
                                  .arg(queryStr));
        return;
    }

    QTime currentTime = QTime::currentTime();
    QDate currentDate = QDate::currentDate();

    int rowCount = 0;
    while (query.next()) {
        int docId = query.value(0).toInt();
        QString doctorName = query.value(1).toString();
        QString specialization = query.value(2).toString();
        int slotId = query.value(3).toInt();
        QTime startTime = query.value(4).toTime();
        QTime endTime = query.value(5).toTime();

        // ✅ Get booked count for this specific doctor, date, and slot
        int bookedCount = getBookedCount(docId, date, slotId);
        int available = 2 - bookedCount; // Max 2 appointments per slot
        QString status = getAvailabilityStatus(bookedCount);
        QColor statusColor = getStatusColor(bookedCount);

        // Check if slot is in the past
        bool isPast = false;
        if (date < currentDate) {
            isPast = true;
        } else if (date == currentDate && startTime < currentTime) {
            isPast = true;
        }

        if (isPast) {
            status = "⏰ Past Time";
            statusColor = QColor("#9e9e9e");
        }

        int row = ui->tableSlotAvailability->rowCount();
        ui->tableSlotAvailability->insertRow(row);

        ui->tableSlotAvailability->setItem(row, 0, new QTableWidgetItem(doctorName));
        ui->tableSlotAvailability->setItem(row, 1, new QTableWidgetItem(specialization));
        ui->tableSlotAvailability->setItem(row, 2, new QTableWidgetItem(
                                                       startTime.toString("hh:mm AP") + " - " + endTime.toString("hh:mm AP")));

        QTableWidgetItem *bookedItem = new QTableWidgetItem(QString::number(bookedCount));
        bookedItem->setTextAlignment(Qt::AlignCenter);
        ui->tableSlotAvailability->setItem(row, 3, bookedItem);

        QTableWidgetItem *availItem = new QTableWidgetItem(QString::number(available));
        availItem->setTextAlignment(Qt::AlignCenter);
        ui->tableSlotAvailability->setItem(row, 4, availItem);

        QTableWidgetItem *statusItem = new QTableWidgetItem(status);
        statusItem->setBackground(QBrush(statusColor));
        statusItem->setForeground(QBrush(Qt::white));
        statusItem->setTextAlignment(Qt::AlignCenter);
        QFont boldFont = statusItem->font();
        boldFont.setBold(true);
        statusItem->setFont(boldFont);
        ui->tableSlotAvailability->setItem(row, 5, statusItem);

        rowCount++;
    }

    if (rowCount == 0) {
        QMessageBox::information(this, "No Data", "No slots found for the selected criteria.");
    }
}

int SlotAvailabilityViewer::getBookedCount(int doctorId, const QDate &date, int slotId)
{
    QSqlQuery query;
    // ✅ Fixed: Use correct column name 'date' instead of 'appointment_date'
    query.prepare(R"(
        SELECT COUNT(*)
        FROM appointments
        WHERE doctor_id = :doctorId
        AND date = :date
        AND slot_id = :slotId
        AND status NOT IN ('cancelled', 'completed')
    )");
    query.bindValue(":doctorId", doctorId);
    query.bindValue(":date", date.toString("yyyy-MM-dd"));
    query.bindValue(":slotId", slotId);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }

    // Debug log
    qDebug() << "Error getting booked count:" << query.lastError().text();
    return 0;
}

QString SlotAvailabilityViewer::getAvailabilityStatus(int bookedCount)
{
    if (bookedCount >= 2) {
        return "🔴 Full (2/2)";
    } else if (bookedCount == 1) {
        return "🟡 Limited (1/2)";
    } else {
        return "🟢 Available (0/2)";
    }
}

QColor SlotAvailabilityViewer::getStatusColor(int bookedCount)
{
    if (bookedCount >= 2) {
        return QColor("#f44336"); // Red - Full
    } else if (bookedCount == 1) {
        return QColor("#ff9800"); // Orange - Limited
    } else {
        return QColor("#4caf50"); // Green - Available
    }
}
