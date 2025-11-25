#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "registration.h"
#include "dashboard.h"
#include "adminpanel.h"
#include "doctorpanel.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup database connection
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:/Users/Supriya/ClinicsAppointment.db");

    if(!m_db.open()) {
        QMessageBox::critical(this, "Database Error",
                              "Failed to open database: " + m_db.lastError().text());
        qDebug() << "Database Error:" << m_db.lastError().text();
    } else {
        qDebug() << "Database connected successfully!";
    }

    // Connect buttons
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
    connect(ui->regLogin, &QPushButton::clicked, this, &MainWindow::onRegisterClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);
}

MainWindow::~MainWindow()
{
    if(m_db.isOpen()) {
        m_db.close();
    }
    delete ui;
}

void MainWindow::onLoginClicked()
{
    QString username = ui->lineEdit->text().trimmed();
    QString password = ui->lineEdit_2->text().trimmed();

    if(username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter both username and password.");
        return;
    }

    if(!m_db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database connection not available.");
        return;
    }

    // Check login credentials and get user type
    QSqlQuery query(m_db);
    query.prepare("SELECT id, username, user_type FROM users WHERE username = :username AND password = :password AND is_active = 1");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if(query.exec() && query.next()) {
        int userId = query.value(0).toInt();
        QString loggedInUsername = query.value(1).toString();
        QString userType = query.value(2).toString().toLower().trimmed();

        qDebug() << "Login successful - User ID:" << userId << "Type:" << userType;

        QMessageBox::information(this, "Login Successful",
                                 "Welcome " + loggedInUsername + "!\nLogging in as: " + userType);

        // Open appropriate panel based on user type
        openUserPanel(loggedInUsername, userType, userId);

        // Close login window
        this->close();
    } else {
        QMessageBox::warning(this, "Login Failed",
                             "Invalid username or password, or account is inactive.");
        qDebug() << "Login failed. Query error:" << query.lastError().text();
    }
}

void MainWindow::openUserPanel(const QString &username, const QString &userType, int userId)
{
    if(userType == "admin") {
        qDebug() << "Opening Admin Panel for user:" << username;
        AdminPanel *adminPanel = new AdminPanel(m_db);
        adminPanel->setAttribute(Qt::WA_DeleteOnClose);
        adminPanel->show();
    }
    else if(userType == "doctor") {
        qDebug() << "Opening Doctor Panel for user:" << username << "ID:" << userId;

        // Get doctor ID from user ID
        QSqlQuery query(m_db);
        query.prepare("SELECT id FROM doctors WHERE user_id = :user_id");
        query.bindValue(":user_id", userId);

        if(query.exec() && query.next()) {
            int doctorId = query.value(0).toInt();
            DoctorPanel *doctorPanel = new DoctorPanel(doctorId);
            doctorPanel->setAttribute(Qt::WA_DeleteOnClose);
            doctorPanel->show();
        } else {
            QMessageBox::critical(this, "Error", "Doctor profile not found for this user!");
            this->show();  // Show login again
        }
    }
    else if(userType == "patient") {
        qDebug() << "Opening Patient Dashboard for user:" << username;
        // Use your existing Dashboard for patients
        Dashboard *dashboard = new Dashboard(m_db, nullptr, username);
        dashboard->setAttribute(Qt::WA_DeleteOnClose);
        dashboard->show();
    }
    else {
        QMessageBox::warning(this, "Error",
                             "Unknown user type: '" + userType + "'\nPlease contact administrator.");
        qDebug() << "Unknown user type:" << userType;
        this->show();  // Show login again
    }
}

void MainWindow::onRegisterClicked()
{
    Registration *reg = new Registration(this);
    if(reg->exec() == QDialog::Accepted) {
        QMessageBox::information(this, "Success",
                                 "Registration successful! Please login.");
    }
    delete reg;
}

void MainWindow::onExitClicked()
{
    if(m_db.isOpen()) {
        m_db.close();
    }
    qApp->quit();
}
