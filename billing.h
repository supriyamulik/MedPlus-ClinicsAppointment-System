#ifndef BILLING_H
#define BILLING_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Billing;
}

class Billing : public QDialog
{
    Q_OBJECT

public:
    explicit Billing(const QString &patientId, QWidget *parent = nullptr);
    ~Billing();

private:
    Ui::Billing *ui;
    QString m_patientId;

    void loadBillingData();
    void setupConnections();
    void updateSummary();
};

#endif // BILLING_H
