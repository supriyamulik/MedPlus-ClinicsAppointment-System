#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Registration::Registration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}

// 🔹 Register button action
void Registration::on_registerButton_clicked()
{
    QString fullname = ui->fullNameLineEdit->text();
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString email = ui->emailLineEdit->text();

    // Validation
    if (fullname.isEmpty() || username.isEmpty() || password.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill all fields.");
        return;
    }

    QSqlQuery q("PRAGMA table_info(users);");
    while (q.next()) {
        qDebug() << q.value(1).toString() << q.value(2).toString();
    }

    // Insert into users table
    QSqlQuery query;
    query.prepare("INSERT INTO users (fullname, username, password, email) "
                  "VALUES (:fullname, :username, :password, :email)");
    query.bindValue(":fullname", fullname.trimmed());
    query.bindValue(":username", username.trimmed());
    query.bindValue(":password", password.trimmed());
    query.bindValue(":email", email.trimmed());

    qDebug() << "Prepared Query:" << query.lastQuery();
    qDebug() << "Bound Values:" << query.boundValues();

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Registration successful!");
        this->close();
    } else {
        QMessageBox::critical(this, "Error", "Failed to register: " + query.lastError().text());
    }
}

// 🔹 Go back to login
void Registration::on_loginButton_clicked()
{
    this->close();
}

// 🔹 Cancel button
void Registration::on_cancelButton_clicked()
{
    this->close();
}
