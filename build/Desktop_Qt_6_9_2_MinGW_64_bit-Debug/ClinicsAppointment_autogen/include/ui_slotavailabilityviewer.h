/********************************************************************************
** Form generated from reading UI file 'slotavailabilityviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLOTAVAILABILITYVIEWER_H
#define UI_SLOTAVAILABILITYVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_SlotAvailabilityViewer
{
public:
    QFrame *frameHeader;
    QLabel *lblTitle;
    QFrame *frameFilters;
    QLabel *lblSelectDate;
    QDateEdit *dateSelect;
    QLabel *lblFilterDoctor;
    QComboBox *comboFilterDoctor;
    QPushButton *btnSearch;
    QPushButton *btnRefresh;
    QTableWidget *tableSlotAvailability;
    QFrame *frameLegend;
    QLabel *lblLegendAvailable;
    QLabel *lblLegendFull;
    QLabel *lblLegendPast;
    QPushButton *btnClose;

    void setupUi(QDialog *SlotAvailabilityViewer)
    {
        if (SlotAvailabilityViewer->objectName().isEmpty())
            SlotAvailabilityViewer->setObjectName("SlotAvailabilityViewer");
        SlotAvailabilityViewer->resize(1200, 800);
        SlotAvailabilityViewer->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e8f5e9, stop:1 #ffffff);\n"
"}"));
        frameHeader = new QFrame(SlotAvailabilityViewer);
        frameHeader->setObjectName("frameHeader");
        frameHeader->setGeometry(QRect(0, 0, 1200, 100));
        frameHeader->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43a047, stop:1 #66bb6a);\n"
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
        frameFilters = new QFrame(SlotAvailabilityViewer);
        frameFilters->setObjectName("frameFilters");
        frameFilters->setGeometry(QRect(50, 130, 1100, 80));
        frameFilters->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white;\n"
"    border-radius: 12px;\n"
"    border: 2px solid #e0e0e0;\n"
"}"));
        lblSelectDate = new QLabel(frameFilters);
        lblSelectDate->setObjectName("lblSelectDate");
        lblSelectDate->setGeometry(QRect(30, 25, 100, 30));
        lblSelectDate->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 15px;\n"
"    font-weight: 600;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"}"));
        dateSelect = new QDateEdit(frameFilters);
        dateSelect->setObjectName("dateSelect");
        dateSelect->setGeometry(QRect(140, 20, 200, 40));
        dateSelect->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    padding: 8px 12px;\n"
"    border: 2px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    background-color: #fafafa;\n"
"    color: #212121;\n"
"}\n"
"QDateEdit:hover {\n"
"    border: 2px solid #43a047;\n"
"}\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"    width: 30px;\n"
"    background: #43a047;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"}\n"
"QDateEdit::down-arrow {\n"
"    image: none;\n"
"    border: 4px solid transparent;\n"
"    border-top: 4px solid white;\n"
"    margin-right: 12px;\n"
"}"));
        dateSelect->setCalendarPopup(true);
        lblFilterDoctor = new QLabel(frameFilters);
        lblFilterDoctor->setObjectName("lblFilterDoctor");
        lblFilterDoctor->setGeometry(QRect(370, 25, 100, 30));
        lblFilterDoctor->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 15px;\n"
"    font-weight: 600;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"}"));
        comboFilterDoctor = new QComboBox(frameFilters);
        comboFilterDoctor->setObjectName("comboFilterDoctor");
        comboFilterDoctor->setGeometry(QRect(480, 20, 300, 40));
        comboFilterDoctor->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #fafafa;\n"
"    border: 2px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    color: #212121;\n"
"}\n"
"QComboBox:hover {\n"
"    border: 2px solid #43a047;\n"
"}\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 30px;\n"
"    background: #43a047;\n"
"    border-top-right-radius: 6px;\n"
"    border-bottom-right-radius: 6px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: none;\n"
"    border: 4px solid transparent;\n"
"    border-top: 4px solid white;\n"
"    margin-right: 12px;\n"
"}"));
        btnSearch = new QPushButton(frameFilters);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setGeometry(QRect(810, 20, 130, 40));
        btnSearch->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    color: white;\n"
"    background-color: #43a047;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #388e3c;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #2e7d32;\n"
"}"));
        btnRefresh = new QPushButton(frameFilters);
        btnRefresh->setObjectName("btnRefresh");
        btnRefresh->setGeometry(QRect(960, 20, 130, 40));
        btnRefresh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    color: white;\n"
"    background-color: #1976d2;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1565c0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #0d47a1;\n"
"}"));
        tableSlotAvailability = new QTableWidget(SlotAvailabilityViewer);
        if (tableSlotAvailability->columnCount() < 6)
            tableSlotAvailability->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableSlotAvailability->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableSlotAvailability->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableSlotAvailability->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableSlotAvailability->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableSlotAvailability->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableSlotAvailability->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableSlotAvailability->setObjectName("tableSlotAvailability");
        tableSlotAvailability->setGeometry(QRect(50, 230, 1100, 480));
        tableSlotAvailability->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #ffffff;\n"
"    alternate-background-color: #f1f8e9;\n"
"    gridline-color: #c5e1a5;\n"
"    selection-background-color: #81c784;\n"
"    selection-color: white;\n"
"    border: 2px solid #43a047;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 10px;\n"
"    border-bottom: 1px solid #e0e0e0;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: #66bb6a;\n"
"    color: white;\n"
"}\n"
"QHeaderView::section {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #43a047, stop:1 #66bb6a);\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    border-right: 1px solid #2e7d32;\n"
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
"    background: #81c784;\n"
"    min-height: 30px;\n"
"    border-radius: 6px;\n"
"}\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #66bb6a;\n"
"}"));
        tableSlotAvailability->setAlternatingRowColors(true);
        tableSlotAvailability->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableSlotAvailability->setShowGrid(true);
        tableSlotAvailability->setColumnCount(6);
        frameLegend = new QFrame(SlotAvailabilityViewer);
        frameLegend->setObjectName("frameLegend");
        frameLegend->setGeometry(QRect(50, 720, 600, 50));
        frameLegend->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: transparent;\n"
"    border: none;\n"
"}"));
        lblLegendAvailable = new QLabel(frameLegend);
        lblLegendAvailable->setObjectName("lblLegendAvailable");
        lblLegendAvailable->setGeometry(QRect(0, 10, 180, 30));
        lblLegendAvailable->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 13px;\n"
"    color: white;\n"
"    background-color: #4caf50;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        lblLegendFull = new QLabel(frameLegend);
        lblLegendFull->setObjectName("lblLegendFull");
        lblLegendFull->setGeometry(QRect(200, 10, 180, 30));
        lblLegendFull->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 13px;\n"
"    color: white;\n"
"    background-color: #f44336;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        lblLegendPast = new QLabel(frameLegend);
        lblLegendPast->setObjectName("lblLegendPast");
        lblLegendPast->setGeometry(QRect(400, 10, 180, 30));
        lblLegendPast->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 13px;\n"
"    color: white;\n"
"    background-color: #9e9e9e;\n"
"    border-radius: 6px;\n"
"    padding: 5px 10px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        btnClose = new QPushButton(SlotAvailabilityViewer);
        btnClose->setObjectName("btnClose");
        btnClose->setGeometry(QRect(970, 720, 180, 50));
        btnClose->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(SlotAvailabilityViewer);

        QMetaObject::connectSlotsByName(SlotAvailabilityViewer);
    } // setupUi

    void retranslateUi(QDialog *SlotAvailabilityViewer)
    {
        SlotAvailabilityViewer->setWindowTitle(QCoreApplication::translate("SlotAvailabilityViewer", "Slot Availability", nullptr));
        lblTitle->setText(QCoreApplication::translate("SlotAvailabilityViewer", "\360\237\251\272 Doctor Slot Availability", nullptr));
        lblSelectDate->setText(QCoreApplication::translate("SlotAvailabilityViewer", "Select Date:", nullptr));
        lblFilterDoctor->setText(QCoreApplication::translate("SlotAvailabilityViewer", "Filter Doctor:", nullptr));
        btnSearch->setText(QCoreApplication::translate("SlotAvailabilityViewer", "\360\237\224\215 Search", nullptr));
        btnRefresh->setText(QCoreApplication::translate("SlotAvailabilityViewer", "\360\237\224\204 Refresh", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableSlotAvailability->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SlotAvailabilityViewer", "Doctor", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableSlotAvailability->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SlotAvailabilityViewer", "Specialization", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableSlotAvailability->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SlotAvailabilityViewer", "Time Slot", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableSlotAvailability->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SlotAvailabilityViewer", "Booked", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableSlotAvailability->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("SlotAvailabilityViewer", "Available", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableSlotAvailability->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("SlotAvailabilityViewer", "Status", nullptr));
        lblLegendAvailable->setText(QCoreApplication::translate("SlotAvailabilityViewer", "\342\234\223 Available (0-1/2)", nullptr));
        lblLegendFull->setText(QCoreApplication::translate("SlotAvailabilityViewer", "\342\234\227 Full (2/2)", nullptr));
        lblLegendPast->setText(QCoreApplication::translate("SlotAvailabilityViewer", "\342\212\227 Past Time", nullptr));
        btnClose->setText(QCoreApplication::translate("SlotAvailabilityViewer", "\342\206\220 Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SlotAvailabilityViewer: public Ui_SlotAvailabilityViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLOTAVAILABILITYVIEWER_H
