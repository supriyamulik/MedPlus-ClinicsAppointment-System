#include "billing.h"
#include "ui_billing.h"
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

Billing::Billing(const QString &patientId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Billing)
    , m_patientId(patientId)
{
    ui->setupUi(this);
    setupConnections();
    loadBillingData();
}

Billing::~Billing()
{
    delete ui;
}

void Billing::setupConnections()
{
    connect(ui->btnBack, &QPushButton::clicked, this, &QDialog::close);
}

void Billing::updateSummary()
{
    // Static summary data
    int totalBills = 5;
    double totalAmount = 8750.00;

    ui->lblTotalBills->setText(QString::number(totalBills));
    ui->lblTotalSpent->setText(QString("₹ %1").arg(totalAmount, 0, 'f', 2));
}

void Billing::loadBillingData()
{
    updateSummary();

    // Static billing data
    QList<QVariantMap> bills = {
        {{"bill_id", "B001"}, {"doctor_name", "Dr. Arjun Mehta"}, {"appointment_date", "2024-10-15"},
         {"billing_date", "2024-10-15"}, {"amount", 1500.00}, {"payment_status", "Paid"}},

        {{"bill_id", "B002"}, {"doctor_name", "Dr. Priya Nair"}, {"appointment_date", "2024-10-20"},
         {"billing_date", "2024-10-20"}, {"amount", 2000.00}, {"payment_status", "Paid"}},

        {{"bill_id", "B003"}, {"doctor_name", "Dr. Rohit Kapoor"}, {"appointment_date", "2024-10-25"},
         {"billing_date", "2024-10-25"}, {"amount", 1750.00}, {"payment_status", "Pending"}},

        {{"bill_id", "B004"}, {"doctor_name", "Dr. Neha Sharma"}, {"appointment_date", "2024-10-28"},
         {"billing_date", "2024-10-28"}, {"amount", 2500.00}, {"payment_status", "Paid"}},

        {{"bill_id", "B005"}, {"doctor_name", "Dr. Karan Deshmukh"}, {"appointment_date", "2024-11-01"},
         {"billing_date", "2024-11-01"}, {"amount", 1000.00}, {"payment_status", "Pending"}}
    };

    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    if (!layout) {
        layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
        ui->scrollAreaWidgetContents->setLayout(layout);
    }

    // Clear existing items
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Create cards for each bill
    for (const QVariantMap &bill : bills) {
        QString billId = bill["bill_id"].toString();
        QString appointmentDate = bill["appointment_date"].toString();
        QString billingDate = bill["billing_date"].toString();
        double amount = bill["amount"].toDouble();
        QString paymentStatus = bill["payment_status"].toString();
        QString doctorName = bill["doctor_name"].toString();

        // Create card for each bill
        QFrame *card = new QFrame();
        card->setStyleSheet(
            "QFrame {"
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #ffffff, stop:1 #f8f9fa);"
            "border: 1px solid #e0e0e0;"
            "border-radius: 12px;"
            "padding: 15px;"
            "}"
            "QFrame:hover {"
            "border: 2px solid #42a5f5;"
            "}"
            );
        card->setMinimumHeight(140);
        card->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

        QHBoxLayout *cardLayout = new QHBoxLayout(card);
        cardLayout->setContentsMargins(15, 15, 15, 15);
        cardLayout->setSpacing(20);

        // Icon
        QLabel *iconLabel = new QLabel("💰");
        iconLabel->setStyleSheet("font-size: 48px; background: transparent;");
        iconLabel->setAlignment(Qt::AlignCenter);
        iconLabel->setFixedSize(80, 80);
        cardLayout->addWidget(iconLabel);

        // Details section
        QVBoxLayout *detailsLayout = new QVBoxLayout();
        detailsLayout->setSpacing(5);

        QLabel *billIdLabel = new QLabel("Bill ID: " + billId);
        billIdLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #1976d2; background: transparent;");
        billIdLabel->setWordWrap(true);

        QLabel *doctorLabel = new QLabel("Doctor: " + doctorName);
        doctorLabel->setStyleSheet("font-size: 14px; color: #37474f; background: transparent;");
        doctorLabel->setWordWrap(true);

        QLabel *appointmentLabel = new QLabel("Appointment: " + appointmentDate);
        appointmentLabel->setStyleSheet("font-size: 14px; color: #546e7a; background: transparent;");
        appointmentLabel->setWordWrap(true);

        QLabel *billingDateLabel = new QLabel("Billing Date: " + billingDate);
        billingDateLabel->setStyleSheet("font-size: 14px; color: #546e7a; background: transparent;");
        billingDateLabel->setWordWrap(true);

        detailsLayout->addWidget(billIdLabel);
        detailsLayout->addWidget(doctorLabel);
        detailsLayout->addWidget(appointmentLabel);
        detailsLayout->addWidget(billingDateLabel);
        detailsLayout->addStretch();

        cardLayout->addLayout(detailsLayout, 1);

        // Amount and status section
        QVBoxLayout *amountLayout = new QVBoxLayout();
        amountLayout->setSpacing(10);
        amountLayout->setAlignment(Qt::AlignCenter);

        QLabel *amountLabel = new QLabel(QString("₹ %1").arg(amount, 0, 'f', 2));
        amountLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #43a047; background: transparent;");
        amountLabel->setAlignment(Qt::AlignCenter);

        // Payment status badge
        QFrame *statusBadge = new QFrame();
        QString statusColor = (paymentStatus == "Paid") ? "#4caf50" : "#ff9800";
        statusBadge->setStyleSheet(QString(
                                       "QFrame {"
                                       "background-color: %1;"
                                       "border-radius: 12px;"
                                       "padding: 5px 15px;"
                                       "}"
                                       ).arg(statusColor));
        statusBadge->setFixedHeight(30);

        QHBoxLayout *badgeLayout = new QHBoxLayout(statusBadge);
        badgeLayout->setContentsMargins(10, 5, 10, 5);

        QLabel *statusLabel = new QLabel(paymentStatus);
        statusLabel->setStyleSheet("font-size: 13px; font-weight: bold; color: white; background: transparent;");
        statusLabel->setAlignment(Qt::AlignCenter);
        badgeLayout->addWidget(statusLabel);

        amountLayout->addWidget(amountLabel);
        amountLayout->addWidget(statusBadge);

        cardLayout->addLayout(amountLayout);

        layout->addWidget(card);
    }

    layout->addStretch();
}
