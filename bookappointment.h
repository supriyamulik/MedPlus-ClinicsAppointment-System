#ifndef BOOKAPPOINTMENT_H
#define BOOKAPPOINTMENT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <QCalendarWidget>

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
    QSqlDatabase db;
    int m_patientId;
    QTimer *m_refreshTimer;
    bool m_isLoading;
    QCalendarWidget *m_calendar;

    void setupUI();
    void setupDatabase();
    void setupCalendar();
    void loadDoctors();
    void loadAvailableSlots();
    void clearSlots();
    bool validateBooking();
    bool checkSlotCapacity(int doctorId, const QDate &date, int slotId);
    bool checkTimeConflict(int doctorId, const QDate &date, int slotId);
    bool checkPatientConflict(const QDate &date, int slotId);
    void showLoadingState(bool loading);
    void logBookingActivity(const QString &activity);
    QMessageBox* createStyledMessageBox(const QString &title, const QString &text,
                                        QMessageBox::StandardButtons buttons = QMessageBox::Ok);
};

#endif // BOOKAPPOINTMENT_H
