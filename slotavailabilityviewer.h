#ifndef SLOTAVAILABILITYVIEWER_H
#define SLOTAVAILABILITYVIEWER_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDate>
#include <QTime>
#include <QDebug>

namespace Ui {
class SlotAvailabilityViewer;
}

class SlotAvailabilityViewer : public QDialog
{
    Q_OBJECT

public:
    explicit SlotAvailabilityViewer(QWidget *parent = nullptr);
    ~SlotAvailabilityViewer();

private slots:
    void loadSlotAvailability();
    void searchSlots();
    void refreshData();

private:
    Ui::SlotAvailabilityViewer *ui;
    QSqlDatabase db;
    void setupDatabase();
    void setupTable();
    void loadDoctors();
    void populateAvailabilityTable(const QDate &date, int doctorId = -1);
    int getBookedCount(int doctorId, const QDate &date, int slotId);
    QString getAvailabilityStatus(int bookedCount);
    QColor getStatusColor(int bookedCount);
};

#endif // SLOTAVAILABILITYVIEWER_H
