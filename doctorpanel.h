#ifndef DOCTORPANEL_H
#define DOCTORPANEL_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QDate>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDateEdit>
#include <QTextEdit>
#include <QPushButton>

namespace Ui {
class DoctorPanel;
}

class DoctorPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit DoctorPanel(int doctorId, QWidget *parent = nullptr);
    ~DoctorPanel();

private slots:
    // Dashboard
    void refreshDashboard();

    // Today's appointments
    void loadTodayAppointments();
    void viewTodayAppointmentDetails();
    void markAsCompleted();
    void markAsNoShow();

    // Upcoming appointments
    void loadUpcomingAppointments();
    void viewUpcomingAppointmentDetails();
    void filterUpcomingByDate();

    // Past appointments
    void loadPastAppointments();
    void viewPastAppointmentDetails();
    void searchPastAppointments();

    // Other
    void viewProfile();
    void updateAvailability();
    void logout();

    // Next Visit Feature
    void on_btnSetNextVisit_clicked();

private:
    Ui::DoctorPanel *ui;
    QSqlDatabase m_db;
    int m_doctorId;
    QString m_doctorName;
    QString m_specialization;
    QTimer *autoRefreshTimer;

    void setupDatabase();
    void setupUI();
    void setupTables();
    void setupConnections();
    void setupAutoRefresh();
    void loadDoctorInfo();
    void loadDashboard();
    void updateStatistics();
    void showLoadingState(bool loading);
    void logActivity(const QString &activity);

    // Next Visit Functions
    bool saveNextVisit(int patientId, int appointmentId, const QDate &nextVisitDate, const QString &notes);
    QString getPatientName(int patientId);

    // Utility functions
    bool updateAppointmentStatus(int appointmentId, const QString &status);
    QString getStatusIcon(const QString &status);
    QColor getStatusColor(const QString &status);
};

#endif // DOCTORPANEL_H
