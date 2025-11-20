#include "dashboard.h"
#include "ui_dashboard.h"
#include "bookappointment.h"
#include "myappointments.h"
#include "viewdoctors.h"
#include "myprofile.h"
#include "billing.h"
#include "aboutus.h"
#include "slotavailabilityviewer.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>

Dashboard::Dashboard(QWidget *parent, const QString &username)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
    , currentUsername(username)
    , currentUserId(-1)  // Initialize to invalid
{
    ui->setupUi(this);
    dateTimeTimer = new QTimer(this);
    connect(dateTimeTimer, &QTimer::timeout, this, &Dashboard::updateDateTime);
    updateDateTime();  // Immediately update
    dateTimeTimer->start(60000);  // Update every minute

    // Fetch and store the user ID on startup
    currentUserId = fetchUserId();
    if (currentUserId == -1) {
        QMessageBox::warning(this, "Error", "Failed to retrieve user ID. Some features may not work.");
    }

    // Connect buttons
    connect(ui->btnBookAppointment, &QPushButton::clicked, this, &Dashboard::openBookAppointment);
    connect(ui->btnViewDoctors, &QPushButton::clicked, this, &Dashboard::openViewDoctors);
    connect(ui->btnMyAppointments, &QPushButton::clicked, this, &Dashboard::openMyAppointments);
    connect(ui->btnMyProfile, &QPushButton::clicked, this, &Dashboard::openMyProfile);
    connect(ui->btnBilling, &QPushButton::clicked, this, &Dashboard::openBilling);
    connect(ui->btnAboutUs, &QPushButton::clicked, this, &Dashboard::openAboutUs);
    connect(ui->btnExit, &QPushButton::clicked, this, &QWidget::close);
    connect(ui->btnViewSlotAvailability, &QPushButton::clicked,
            this, &Dashboard::openSlotAvailability);
}

Dashboard::~Dashboard()
{
    delete ui;
}
void Dashboard::updateDateTime()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedDate = "Today: " + currentDateTime.toString("dddd, MMMM dd, yyyy");
    ui->lblDateTime->setText(formattedDate);
}
int Dashboard::fetchUserId()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Supriya/ClinicsAppointment.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return -1;
    }

    QSqlQuery query(db);
    query.prepare("SELECT id FROM users WHERE username = :username");
    query.bindValue(":username", currentUsername);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }

    return -1;
}

void Dashboard::openBookAppointment()
{
    if (currentUserId == -1) {
        QMessageBox::warning(this, "Error", "User ID not available. Cannot book appointment.");
        return;
    }

    // Pass the currentUserId to BookAppointment
    BookAppointment bookAppointmentDialog(currentUserId, this);
    bookAppointmentDialog.exec();
}

void Dashboard::openMyAppointments()
{
    MyAppointments *myAppointmentsDialog = new MyAppointments(this, currentUsername);
    myAppointmentsDialog->setModal(true);
    myAppointmentsDialog->exec();
    delete myAppointmentsDialog;
}

void Dashboard::openViewDoctors()
{
    ViewDoctors viewDoctorsDialog(this);
    viewDoctorsDialog.exec();
}

void Dashboard::openMyProfile()
{
    if (currentUserId == -1) {
        QMessageBox::warning(this, "Error", "User ID not available. Cannot open profile.");
        return;
    }

    // Simple - pass user ID directly as string
    QString userIdStr = QString::number(currentUserId);

    MyProfile *profileDialog = new MyProfile(userIdStr, this);
    profileDialog->setModal(true);
    profileDialog->exec();
    delete profileDialog;
}

void Dashboard::openBilling()
{
    if (currentUserId == -1) {
        QMessageBox::warning(this, "Error", "User ID not available. Cannot open billing.");
        return;
    }

    // Pass user ID as string directly
    QString userIdStr = QString::number(currentUserId);

    Billing *billingDialog = new Billing(userIdStr, this);
    billingDialog->setModal(true);
    billingDialog->exec();
    delete billingDialog;
}
void Dashboard::openSlotAvailability()
{
    SlotAvailabilityViewer *viewer = new SlotAvailabilityViewer(this);
    viewer->setModal(true);
    viewer->exec();
    delete viewer;
}

void Dashboard::openAboutUs()
{
    AboutUs *aboutDialog = new AboutUs(this);
    aboutDialog->setModal(true);
    aboutDialog->exec();
    delete aboutDialog;
}
