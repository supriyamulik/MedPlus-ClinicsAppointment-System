/********************************************************************************
** Form generated from reading UI file 'myappointments.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYAPPOINTMENTS_H
#define UI_MYAPPOINTMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_MyAppointments
{
public:
    QFrame *frameHeader;
    QLabel *lblTitle;
    QFrame *frameFilters;
    QLabel *lblFilterBy;
    QComboBox *comboFilterStatus;
    QPushButton *btnRefresh;
    QTableWidget *tableAppointments;
    QPushButton *btnViewDetails;
    QPushButton *btnCancelAppointment;
    QPushButton *btnReschedule;
    QPushButton *btnBack;

    void setupUi(QDialog *MyAppointments)
    {
        if (MyAppointments->objectName().isEmpty())
            MyAppointments->setObjectName("MyAppointments");
        MyAppointments->resize(1200, 800);
        MyAppointments->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e3f2fd, stop:1 #ffffff);\n"
"}"));
        frameHeader = new QFrame(MyAppointments);
        frameHeader->setObjectName("frameHeader");
        frameHeader->setGeometry(QRect(0, 0, 1200, 100));
        frameHeader->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #1976d2, stop:1 #42a5f5);\n"
"    border: none;\n"
"}"));
        lblTitle = new QLabel(frameHeader);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setGeometry(QRect(50, 20, 1100, 60));
        lblTitle->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        frameFilters = new QFrame(MyAppointments);
        frameFilters->setObjectName("frameFilters");
        frameFilters->setGeometry(QRect(50, 130, 1100, 80));
        frameFilters->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white;\n"
"    border-radius: 12px;\n"
"    border: 2px solid #e0e0e0;\n"
"}"));
        lblFilterBy = new QLabel(frameFilters);
        lblFilterBy->setObjectName("lblFilterBy");
        lblFilterBy->setGeometry(QRect(30, 25, 100, 30));
        lblFilterBy->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 15px;\n"
"    font-weight: 600;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"}"));
        comboFilterStatus = new QComboBox(frameFilters);
        comboFilterStatus->addItem(QString());
        comboFilterStatus->addItem(QString());
        comboFilterStatus->addItem(QString());
        comboFilterStatus->addItem(QString());
        comboFilterStatus->setObjectName("comboFilterStatus");
        comboFilterStatus->setGeometry(QRect(130, 20, 201, 40));
        comboFilterStatus->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #fafafa;\n"
"    border: 2px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    color: #212121;\n"
"}\n"
"QComboBox:hover {\n"
"    border: 2px solid #1976d2;\n"
"}\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 30px;\n"
"    background: #1976d2;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: none;\n"
"    border: 4px solid transparent;\n"
"    border-top: 4px solid white;\n"
"    margin-right: 12px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 2px solid #1976d2;\n"
"    selection-background-color: #e3f2fd;\n"
"    selection-color: #1565c0;\n"
"}"));
        btnRefresh = new QPushButton(frameFilters);
        btnRefresh->setObjectName("btnRefresh");
        btnRefresh->setGeometry(QRect(900, 20, 170, 40));
        btnRefresh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    color: white;\n"
"    background-color: #1976d2;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1565c0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #0d47a1;\n"
"}"));
        tableAppointments = new QTableWidget(MyAppointments);
        if (tableAppointments->columnCount() < 6)
            tableAppointments->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableAppointments->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableAppointments->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableAppointments->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableAppointments->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableAppointments->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableAppointments->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableAppointments->setObjectName("tableAppointments");
        tableAppointments->setGeometry(QRect(50, 230, 1100, 470));
        tableAppointments->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #ffffff;\n"
"    alternate-background-color: #f5f9ff;\n"
"    gridline-color: #d0e3f7;\n"
"    selection-background-color: #90caf9;\n"
"    selection-color: white;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 10px;\n"
"    border-bottom: 1px solid #e0e0e0;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: #64b5f6;\n"
"    color: white;\n"
"}\n"
"QHeaderView::section {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #1976d2, stop:1 #1565c0);\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    border-right: 1px solid #0d47a1;\n"
"}\n"
"QHeaderView::section:first {\n"
"    border-top-left-radius: 8px;\n"
"}\n"
"QHeaderView::section:last {\n"
"    border-top-right-radius: 8px;\n"
"    border-right: none;\n"
"}\n"
"QScrollBar:vertical {\n"
"    background: #f5f5f5;"
                        "\n"
"    width: 12px;\n"
"    border-radius: 6px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: #90caf9;\n"
"    min-height: 30px;\n"
"    border-radius: 6px;\n"
"}\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #64b5f6;\n"
"}\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}"));
        tableAppointments->setAlternatingRowColors(true);
        tableAppointments->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableAppointments->setShowGrid(true);
        tableAppointments->setColumnCount(6);
        btnViewDetails = new QPushButton(MyAppointments);
        btnViewDetails->setObjectName("btnViewDetails");
        btnViewDetails->setGeometry(QRect(50, 720, 180, 50));
        btnViewDetails->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background-color: #42a5f5;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1976d2;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1565c0;\n"
"}"));
        btnCancelAppointment = new QPushButton(MyAppointments);
        btnCancelAppointment->setObjectName("btnCancelAppointment");
        btnCancelAppointment->setGeometry(QRect(250, 720, 200, 50));
        btnCancelAppointment->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background-color: #ff5252;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #f44336;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #d32f2f;\n"
"}"));
        btnReschedule = new QPushButton(MyAppointments);
        btnReschedule->setObjectName("btnReschedule");
        btnReschedule->setGeometry(QRect(470, 720, 180, 50));
        btnReschedule->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background-color: #ff9800;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #f57c00;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #e65100;\n"
"}"));
        btnBack = new QPushButton(MyAppointments);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(970, 720, 180, 50));
        btnBack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background-color: #78909c;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #546e7a;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #37474f;\n"
"}"));

        retranslateUi(MyAppointments);

        QMetaObject::connectSlotsByName(MyAppointments);
    } // setupUi

    void retranslateUi(QDialog *MyAppointments)
    {
        MyAppointments->setWindowTitle(QCoreApplication::translate("MyAppointments", "My Appointments", nullptr));
        lblTitle->setText(QCoreApplication::translate("MyAppointments", "\360\237\223\213 My Appointments", nullptr));
        lblFilterBy->setText(QCoreApplication::translate("MyAppointments", "Filter by:", nullptr));
        comboFilterStatus->setItemText(0, QCoreApplication::translate("MyAppointments", "All Appointments", nullptr));
        comboFilterStatus->setItemText(1, QCoreApplication::translate("MyAppointments", "Upcoming", nullptr));
        comboFilterStatus->setItemText(2, QCoreApplication::translate("MyAppointments", "Completed", nullptr));
        comboFilterStatus->setItemText(3, QCoreApplication::translate("MyAppointments", "Cancelled", nullptr));

        btnRefresh->setText(QCoreApplication::translate("MyAppointments", "\360\237\224\204 Refresh", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableAppointments->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MyAppointments", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableAppointments->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MyAppointments", "Doctor", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableAppointments->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MyAppointments", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableAppointments->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MyAppointments", "Time Slot", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableAppointments->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MyAppointments", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableAppointments->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MyAppointments", "Actions", nullptr));
        btnViewDetails->setText(QCoreApplication::translate("MyAppointments", "\360\237\221\201\357\270\217 View Details", nullptr));
        btnCancelAppointment->setText(QCoreApplication::translate("MyAppointments", "\342\235\214 Cancel Appointment", nullptr));
        btnReschedule->setText(QCoreApplication::translate("MyAppointments", "\360\237\224\204 Reschedule", nullptr));
        btnBack->setText(QCoreApplication::translate("MyAppointments", "\342\206\220 Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyAppointments: public Ui_MyAppointments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYAPPOINTMENTS_H
