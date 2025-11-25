#include "dashboard.h"
#include "ui_dashboard.h"
#include "bookappointment.h"
#include "myappointments.h"
#include "viewdoctors.h"
#include "myprofile.h"
#include "billing.h"
#include "aboutus.h"
#include "mainwindow.h"
#include "slotavailabilityviewer.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>

Dashboard::Dashboard(QSqlDatabase db, QWidget *parent, const QString &username)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
    , m_db(db)
    , currentUsername(username)
    , currentUserId(-1)
{
    ui->setupUi(this);

    dateTimeTimer = new QTimer(this);
    connect(dateTimeTimer, &QTimer::timeout, this, &Dashboard::updateDateTime);
    updateDateTime();
    dateTimeTimer->start(60000);

    // Fetch and store the user ID on startup
    currentUserId = fetchUserId();
    if (currentUserId == -1) {
        QMessageBox::warning(this, "Error", "Failed to retrieve user ID. Some features may not work.");
    }

    // Load next visit information
    loadNextVisitInfo();

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
    connect(ui->btnLogout, &QPushButton::clicked, this, &Dashboard::on_btnLogout_clicked);
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
    if (!m_db.isOpen()) {
        QMessageBox::critical(this, "Database Error", m_db.lastError().text());
        return -1;
    }

    QSqlQuery query(m_db);
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
void Dashboard::on_btnLogout_clicked()
{
    int result = QMessageBox::question(this, "Logout",
                                       "Are you sure you want to logout?",
                                       QMessageBox::Yes | QMessageBox::No);

    if (result == QMessageBox::Yes) {
        // Close the current dashboard
        this->close();

        // Show the main window (login window)
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
    }
}
void Dashboard::loadNextVisitInfo()
{
    if (currentUserId == -1) return;

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT nv.next_visit_date, nv.notes, d.name, d.specialization
        FROM next_visits nv
        JOIN doctors d ON nv.doctor_id = d.id
        WHERE nv.patient_id = :patient_id
        AND nv.next_visit_date >= date('now')
        ORDER BY nv.next_visit_date ASC
        LIMIT 1
    )");

    query.bindValue(":patient_id", currentUserId);

    if (query.exec() && query.next()) {
        QDate nextVisitDate = query.value(0).toDate();
        QString notes = query.value(1).toString();
        QString doctorName = query.value(2).toString();
        QString specialization = query.value(3).toString();

        QString nextVisitInfo = QString(
                                    "🩺 Your Next Scheduled Visit\n\n"
                                    "Date: %1\n"
                                    "Doctor: Dr. %2\n"
                                    "Specialization: %3\n"
                                    "Notes: %4"
                                    ).arg(nextVisitDate.toString("dddd, MMMM d, yyyy"))
                                    .arg(doctorName)
                                    .arg(specialization)
                                    .arg(notes.isEmpty() ? "No additional notes" : notes);

        ui->lblNextVisitInfo->setText(nextVisitInfo);
        ui->lblNextVisitInfo->setStyleSheet(
            "font-size: 14px; color: #15803d; background: transparent; "
            "qproperty-alignment: AlignCenter; font-weight: 500; line-height: 1.6; padding: 15px;"
            );
    } else {
        // No upcoming visits
        ui->lblNextVisitInfo->setText(
            "📅 Your next scheduled visit will appear here\n\n"
            "Your doctor will schedule follow-up appointments after consultations\n"
            "Check this section regularly for important medical follow-ups"
            );
        ui->lblNextVisitInfo->setStyleSheet(
            "font-size: 16px; color: #64748b; background: transparent; "
            "qproperty-alignment: AlignCenter; font-weight: 500; line-height: 1.6; padding: 20px;"
            );
    }
}
