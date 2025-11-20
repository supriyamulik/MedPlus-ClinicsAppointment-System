/********************************************************************************
** Form generated from reading UI file 'billing.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILLING_H
#define UI_BILLING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Billing
{
public:
    QFrame *frameCircle1;
    QFrame *frameCircle2;
    QLabel *lblTitle;
    QLabel *lblSubtitle;
    QFrame *frameSummary;
    QLabel *lblTotalSpentLabel;
    QLabel *lblTotalSpent;
    QLabel *lblTotalBillsLabel;
    QLabel *lblTotalBills;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *btnBack;

    void setupUi(QDialog *Billing)
    {
        if (Billing->objectName().isEmpty())
            Billing->setObjectName("Billing");
        Billing->resize(1100, 750);
        Billing->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e3f2fd, stop:1 #ffffff);\n"
"    border-radius: 15px;\n"
"}"));
        frameCircle1 = new QFrame(Billing);
        frameCircle1->setObjectName("frameCircle1");
        frameCircle1->setGeometry(QRect(-80, -80, 300, 300));
        frameCircle1->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(25, 118, 210, 0.15), stop:1 transparent);\n"
"    border-radius: 150px;\n"
"    border: none;\n"
"}"));
        frameCircle2 = new QFrame(Billing);
        frameCircle2->setObjectName("frameCircle2");
        frameCircle2->setGeometry(QRect(850, 500, 350, 350));
        frameCircle2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(66, 165, 245, 0.15), stop:1 transparent);\n"
"    border-radius: 175px;\n"
"    border: none;\n"
"}"));
        lblTitle = new QLabel(Billing);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setGeometry(QRect(150, 30, 800, 80));
        lblTitle->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 32px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #1976d2, stop:0.5 #42a5f5, stop:1 #64b5f6);\n"
"    padding: 20px 30px;\n"
"    border-radius: 15px;\n"
"    border: 2px solid rgba(255, 255, 255, 0.3);\n"
"    letter-spacing: 1px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        lblSubtitle = new QLabel(Billing);
        lblSubtitle->setObjectName("lblSubtitle");
        lblSubtitle->setGeometry(QRect(150, 120, 800, 30));
        lblSubtitle->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"    font-weight: 500;\n"
"}"));
        frameSummary = new QFrame(Billing);
        frameSummary->setObjectName("frameSummary");
        frameSummary->setGeometry(QRect(150, 170, 800, 100));
        frameSummary->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #66bb6a, stop:1 #43a047);\n"
"    border-radius: 15px;\n"
"    border: none;\n"
"}"));
        lblTotalSpentLabel = new QLabel(frameSummary);
        lblTotalSpentLabel->setObjectName("lblTotalSpentLabel");
        lblTotalSpentLabel->setGeometry(QRect(50, 20, 300, 30));
        lblTotalSpentLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: 600;\n"
"    color: white;\n"
"    background: transparent;\n"
"}"));
        lblTotalSpent = new QLabel(frameSummary);
        lblTotalSpent->setObjectName("lblTotalSpent");
        lblTotalSpent->setGeometry(QRect(50, 50, 300, 40));
        lblTotalSpent->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 32px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: transparent;\n"
"}"));
        lblTotalBillsLabel = new QLabel(frameSummary);
        lblTotalBillsLabel->setObjectName("lblTotalBillsLabel");
        lblTotalBillsLabel->setGeometry(QRect(450, 20, 300, 30));
        lblTotalBillsLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: 600;\n"
"    color: white;\n"
"    background: transparent;\n"
"}"));
        lblTotalBills = new QLabel(frameSummary);
        lblTotalBills->setObjectName("lblTotalBills");
        lblTotalBills->setGeometry(QRect(450, 50, 300, 40));
        lblTotalBills->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 32px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: transparent;\n"
"}"));
        scrollArea = new QScrollArea(Billing);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(150, 290, 800, 360));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 800, 360));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: transparent;\n"
"}"));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        scrollArea->setWidget(scrollAreaWidgetContents);
        btnBack = new QPushButton(Billing);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(439, 670, 211, 55));
        btnBack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #1976d2, stop:1 #42a5f5);\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 12px 24px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #1565c0, stop:1 #1976d2);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #0d47a1, stop:1 #1565c0);\n"
"}"));

        retranslateUi(Billing);

        QMetaObject::connectSlotsByName(Billing);
    } // setupUi

    void retranslateUi(QDialog *Billing)
    {
        Billing->setWindowTitle(QCoreApplication::translate("Billing", "MedPlus - Billing and Payments", nullptr));
        lblTitle->setText(QCoreApplication::translate("Billing", "\360\237\222\263 Billing and Payments", nullptr));
        lblSubtitle->setText(QCoreApplication::translate("Billing", "View your payment history and manage invoices", nullptr));
        lblTotalSpentLabel->setText(QCoreApplication::translate("Billing", "Total Amount Spent", nullptr));
        lblTotalSpent->setText(QCoreApplication::translate("Billing", "\342\202\271 0.00", nullptr));
        lblTotalBillsLabel->setText(QCoreApplication::translate("Billing", "Total Bills", nullptr));
        lblTotalBills->setText(QCoreApplication::translate("Billing", "0", nullptr));
        btnBack->setText(QCoreApplication::translate("Billing", "\342\206\220 Back to Dashboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Billing: public Ui_Billing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILLING_H
