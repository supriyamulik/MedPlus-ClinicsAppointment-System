#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "registration.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "dashboard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect buttons (names must match your .ui objects)
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
    connect(ui->regLogin, &QPushButton::clicked, this, &MainWindow::onRegisterClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoginClicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if(username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter both username and password.");
        return;
    }

    // Open database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Supriya/ClinicsAppointment.db");

    if(!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    // Check login
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username.trimmed());
    query.bindValue(":password", password.trimmed());

    if(query.exec() && query.next()) {
        QMessageBox::information(this, "Login Successful", "Welcome " + username + "!");

        // ✅ Open Dashboard
        Dashboard *dash = new Dashboard(nullptr, username);
        dash->show();

        // ✅ Close login window
        this->close();

    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }

    db.close();
}

void MainWindow::onRegisterClicked()
{
    Registration reg(this);
    reg.exec();
}

void MainWindow::onExitClicked()
{
    qApp->quit();
}

#include "bookappointment.h"   // make sure this include is present at the top

void MainWindow::openBookAppointment()
{
    BookAppointment *bookApp = new BookAppointment(this);
    bookApp->show();
}
