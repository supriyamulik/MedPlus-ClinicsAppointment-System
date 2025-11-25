#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QTimer>
// ... existing includes ...

namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QSqlDatabase db, QWidget *parent = nullptr, const QString &username = "");
    ~Dashboard();

private slots:
    // ... existing slots ...
    void openBookAppointment();
    void openMyAppointments();
    void openViewDoctors();
    void openMyProfile();
    void openBilling();
    void openAboutUs();
    void openSlotAvailability();
    void on_btnLogout_clicked();

private:
    Ui::Dashboard *ui;
    QSqlDatabase m_db;
    QString currentUsername;
    int currentUserId;
    QTimer *dateTimeTimer;

    void updateDateTime();
    int fetchUserId();

    // ADD THIS NEW FUNCTION:
    void loadNextVisitInfo();  // Loads next visit data for patient
};

#endif // DASHBOARD_H
