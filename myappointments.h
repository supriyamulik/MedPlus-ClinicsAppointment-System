#ifndef MYAPPOINTMENTS_H
#define MYAPPOINTMENTS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidgetItem>

namespace Ui{
class MyAppointments;
}

class MyAppointments : public QDialog
{
    Q_OBJECT

public:
    explicit MyAppointments(QWidget *parent = nullptr, const QString &username = "");
    ~MyAppointments();

private slots:
    void loadAppointments();          // Load appointments from DB
    void refreshAppointments();       // Refresh button
    void cancelAppointment();         // Cancel selected appointment
    void rescheduleAppointment();     // Reschedule selected appointment
    void viewDetails();               // View appointment details

private:
    Ui::MyAppointments *ui;
    QString currentUsername;
    int currentUserId;

    void setupTable();                // Setup columns & headers
    int fetchUserId();                // Get user id using username
};
#endif // MYAPPOINTMENTS_H
