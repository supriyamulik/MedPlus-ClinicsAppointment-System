#ifndef BOOKAPPOINTMENT_H
#define BOOKAPPOINTMENT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QDate>
#include <QTimer>
#include <QComboBox>
#include <QPushButton>
#include <QDateEdit>

namespace Ui {
class BookAppointment;
}

class BookAppointment : public QDialog
{
    Q_OBJECT

public:
    explicit BookAppointment(QWidget *parent = nullptr);
    explicit BookAppointment(int patientId, QWidget *parent = nullptr);
    ~BookAppointment();

    void setPatientId(int patientId);

private slots:
    void on_comboDoctor_currentIndexChanged(int index);
    void on_dateAppointment_dateChanged(const QDate &date);
    void on_btnBook_clicked();
    void on_btnCancel_clicked();
    void refreshSlots();

private:
    Ui::BookAppointment *ui;
    int m_patientId;
    QTimer *m_refreshTimer;
    bool m_isLoading;

    void setupUI();
    void setupDatabase();
    void loadDoctors();
    void loadAvailableSlots();
    void clearSlots();
    bool validateBooking();
    bool checkTimeConflict(int doctorId, const QDate &date, int slotId);
    bool checkPatientConflict(const QDate &date, int slotId);
    bool checkSlotCapacity(int doctorId, const QDate &date, int slotId);
    void showLoadingState(bool loading);
    void logBookingActivity(const QString &activity);

    QSqlDatabase db;
};

#endif // BOOKAPPOINTMENT_H
