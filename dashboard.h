#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTimer>
#include "slotavailabilityviewer.h"

namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr, const QString &username = "");
    ~Dashboard();

private slots:
    void openBookAppointment();
    void openMyAppointments();
    void openViewDoctors();
    void openMyProfile();
    void openBilling();
    void openAboutUs();
    void updateDateTime();
    void openSlotAvailability();  // <-- Moved inside the class correctly

private:
    Ui::Dashboard *ui;
    QString currentUsername;
    int currentUserId;
    QTimer *dateTimeTimer;

    int fetchUserId();
};

#endif // DASHBOARD_H
