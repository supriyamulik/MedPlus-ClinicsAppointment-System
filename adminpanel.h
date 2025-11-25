#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDate>
#include <QTimer>
#include <QDebug>

namespace Ui {
class AdminPanel;
}

struct SystemStats {
    int totalDoctors = 0;
    int activeDoctors = 0;
    int totalPatients = 0;
    int activePatients = 0;
    int totalAppointments = 0;
    int bookedAppointments = 0;
    int completedAppointments = 0;
    int cancelledAppointments = 0;
    int rescheduledCount = 0;
};

struct DoctorStats {
    QString doctorName;
    QString specialization;
    double consultationFee = 0.0;
    int totalAppointments = 0;
    int todayAppointments = 0;
    int upcomingAppointments = 0;
    int completedAppointments = 0;
    int cancelledAppointments = 0;
    double totalRevenue = 0.0;
};

class StatsManager : public QObject {
    Q_OBJECT
public:
    explicit StatsManager(QObject *parent = nullptr) : QObject(parent) {}

    SystemStats getSystemStats() {
        SystemStats stats;
        QSqlDatabase db = QSqlDatabase::database();

        QSqlQuery query(db);

        // Total doctors
        query.exec("SELECT COUNT(*) FROM doctors");
        if (query.next()) stats.totalDoctors = query.value(0).toInt();

        // Active doctors
        query.exec("SELECT COUNT(*) FROM doctors WHERE is_available = 1");
        if (query.next()) stats.activeDoctors = query.value(0).toInt();

        // Total patients
        query.exec("SELECT COUNT(*) FROM users WHERE user_type = 'patient' AND is_active = 1");
        if (query.next()) stats.totalPatients = query.value(0).toInt();

        // Total appointments
        query.exec("SELECT COUNT(*) FROM appointments");
        if (query.next()) stats.totalAppointments = query.value(0).toInt();

        // Booked appointments
        query.exec("SELECT COUNT(*) FROM appointments WHERE status = 'booked'");
        if (query.next()) stats.bookedAppointments = query.value(0).toInt();

        // Completed appointments
        query.exec("SELECT COUNT(*) FROM appointments WHERE status = 'completed'");
        if (query.next()) stats.completedAppointments = query.value(0).toInt();

        // Cancelled appointments
        query.exec("SELECT COUNT(*) FROM appointments WHERE status = 'cancelled'");
        if (query.next()) stats.cancelledAppointments = query.value(0).toInt();

        return stats;
    }

    DoctorStats getDoctorStats(int doctorId) {
        DoctorStats stats;
        QSqlDatabase db = QSqlDatabase::database();

        QSqlQuery query(db);
        query.prepare("SELECT name, specialization, consultation_fee FROM doctors WHERE id = :id");
        query.bindValue(":id", doctorId);
        if (query.exec() && query.next()) {
            stats.doctorName = query.value(0).toString();
            stats.specialization = query.value(1).toString();
            stats.consultationFee = query.value(2).toDouble();
        }

        // Total appointments
        query.prepare("SELECT COUNT(*) FROM appointments WHERE doctor_id = :id");
        query.bindValue(":id", doctorId);
        if (query.exec() && query.next()) stats.totalAppointments = query.value(0).toInt();

        // Today's appointments
        query.prepare("SELECT COUNT(*) FROM appointments WHERE doctor_id = :id AND date = date('now')");
        query.bindValue(":id", doctorId);
        if (query.exec() && query.next()) stats.todayAppointments = query.value(0).toInt();

        // Upcoming appointments
        query.prepare("SELECT COUNT(*) FROM appointments WHERE doctor_id = :id AND date >= date('now') AND status = 'booked'");
        query.bindValue(":id", doctorId);
        if (query.exec() && query.next()) stats.upcomingAppointments = query.value(0).toInt();

        // Completed appointments
        query.prepare("SELECT COUNT(*) FROM appointments WHERE doctor_id = :id AND status = 'completed'");
        query.bindValue(":id", doctorId);
        if (query.exec() && query.next()) stats.completedAppointments = query.value(0).toInt();

        // Cancelled appointments
        query.prepare("SELECT COUNT(*) FROM appointments WHERE doctor_id = :id AND status = 'cancelled'");
        query.bindValue(":id", doctorId);
        if (query.exec() && query.next()) stats.cancelledAppointments = query.value(0).toInt();

        // Total revenue
        query.prepare("SELECT SUM(consultation_fee) FROM appointments WHERE doctor_id = :id AND status = 'completed'");
        query.bindValue(":id", doctorId);
        if (query.exec() && query.next()) stats.totalRevenue = query.value(0).toDouble();

        return stats;
    }

    QList<DoctorStats> getAllDoctorsStats() {
        QList<DoctorStats> statsList;
        QSqlDatabase db = QSqlDatabase::database();

        QSqlQuery query(db);
        query.exec("SELECT id FROM doctors");

        while (query.next()) {
            int doctorId = query.value(0).toInt();
            statsList.append(getDoctorStats(doctorId));
        }

        return statsList;
    }

    SystemStats getSystemStatsByDateRange(const QDate &startDate, const QDate &endDate) {
        // For simplicity, return current stats
        // You can implement date filtering here
        return getSystemStats();
    }
};

class AdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPanel(QSqlDatabase db, QWidget *parent = nullptr);
    ~AdminPanel();

private slots:
    // Dashboard actions
    void loadDashboard();
    void refreshDashboard();
    void applyDateFilter();
    void resetDateFilter();

    // Doctor management
    void loadDoctorsTable();
    void viewDoctorDetails();
    void toggleDoctorAvailability();
    void searchDoctors();

    // Appointment management
    void loadAllAppointments();
    void filterAppointments();
    void viewAppointmentDetails();
    void searchAppointments();

    // Statistics and Reports
    void loadDoctorWiseStats();
    void exportReport();
    void viewDetailedStats();

    // Navigation
    void showDashboardTab();
    void showDoctorsTab();
    void showAppointmentsTab();
    void showReportsTab();

    // Utility
    void logout();

private:
    Ui::AdminPanel *ui;
    QSqlDatabase m_db;
    StatsManager *statsManager;
    QTimer *autoRefreshTimer;

    // Setup functions
    void setupUI();
    void setupDatabase();
    void setupTables();
    void setupConnections();
    void setupAutoRefresh();

    // Dashboard helper functions
    void updateStatsCards(const SystemStats &stats);
    void loadRecentAppointments();
    void loadTopDoctors();

    // Table formatting
    void formatDoctorsTable();
    void formatAppointmentsTable();
    void formatStatsTable();

    // Utility functions
    QString getStatusIcon(const QString &status);
    QColor getStatusColor(const QString &status);
    void showLoadingState(bool loading);
    void logActivity(const QString &activity);
};

#endif // ADMINPANEL_H
