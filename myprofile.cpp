#include "myprofile.h"
#include "ui_myprofile.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>

MyProfile::MyProfile(const QString &patientId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyProfile)
    , m_patientId(patientId)
{
    ui->setupUi(this);
    setupConnections();
    loadPatientData();
}

MyProfile::~MyProfile()
{
    delete ui;
}

void MyProfile::setupConnections()
{
    connect(ui->btnBack, &QPushButton::clicked, this, &QDialog::close);
    connect(ui->btnEditProfile, &QPushButton::clicked, this, &MyProfile::onEditProfileClicked);
}

void MyProfile::loadPatientData()
{
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database is not connected!");
        return;
    }

    qDebug() << "Loading profile for User ID:" << m_patientId;

    QSqlQuery query(db);
    QString sql = "SELECT fullname, email, phone FROM users WHERE id = " + m_patientId;

    qDebug() << "Executing query:" << sql;

    if (query.exec(sql)) {
        if (query.next()) {
            QString fullname = query.value(0).toString();
            QString email = query.value(1).toString();
            QString phone = query.value(2).toString();

            qDebug() << "Data loaded successfully!";
            qDebug() << "Name:" << fullname;
            qDebug() << "Email:" << email;
            qDebug() << "Phone:" << phone;

            // Update UI
            ui->lblName->setText(fullname);
            ui->lblPatientId->setText("User ID: " + m_patientId);

            // Show data or prompt to add
            if (email.isEmpty()) {
                ui->lblEmail->setText("Email: Click Edit to add");
            } else {
                ui->lblEmail->setText("Email: " + email);
            }

            if (phone.isEmpty()) {
                ui->lblPhone->setText("Phone: Click Edit to add");
            } else {
                ui->lblPhone->setText("Phone: " + phone);
            }

            // Address not in database
            ui->lblAddress->setText("Address: Not available");
        } else {
            qDebug() << "No user found with ID:" << m_patientId;
            QMessageBox::warning(this, "Error", "No user found with ID: " + m_patientId);
            ui->lblName->setText("User Not Found");
        }
    } else {
        QString errorMsg = "Failed to load profile data.\n";
        errorMsg += "SQL Error: " + query.lastError().text() + "\n";
        errorMsg += "Query: " + sql;
        qDebug() << "Query failed:" << query.lastError().text();
        QMessageBox::warning(this, "Error", errorMsg);
        ui->lblName->setText("Error Loading Data");
    }
}

void MyProfile::onEditProfileClicked()
{
    QSqlDatabase db = QSqlDatabase::database();

    // Get current data
    QString currentEmail = "";
    QString currentPhone = "";

    QSqlQuery query(db);
    QString selectSql = "SELECT email, phone FROM users WHERE id = " + m_patientId;

    if (query.exec(selectSql) && query.next()) {
        currentEmail = query.value(0).toString();
        currentPhone = query.value(1).toString();
    }

    // Edit dialogs
    bool ok;

    QString newEmail = QInputDialog::getText(this, "Edit Email", "Enter Email:",
                                             QLineEdit::Normal, currentEmail, &ok);
    if (!ok) return;

    QString newPhone = QInputDialog::getText(this, "Edit Phone", "Enter Phone:",
                                             QLineEdit::Normal, currentPhone, &ok);
    if (!ok) return;

    // Update database - escape single quotes for SQL safety
    QString safeEmail = newEmail;
    safeEmail.replace("'", "''");

    QString safePhone = newPhone;
    safePhone.replace("'", "''");

    QSqlQuery updateQuery(db);
    QString updateSql = "UPDATE users SET email = '" + safeEmail +
                        "', phone = '" + safePhone +
                        "' WHERE id = " + m_patientId;

    qDebug() << "Update query:" << updateSql;

    if (updateQuery.exec(updateSql)) {
        QMessageBox::information(this, "Success", "Profile updated successfully!");
        loadPatientData(); // Refresh display
    } else {
        QString errorMsg = "Failed to update profile.\n";
        errorMsg += "SQL Error: " + updateQuery.lastError().text();
        qDebug() << "Update failed:" << updateQuery.lastError().text();
        QMessageBox::warning(this, "Error", errorMsg);
    }
}
