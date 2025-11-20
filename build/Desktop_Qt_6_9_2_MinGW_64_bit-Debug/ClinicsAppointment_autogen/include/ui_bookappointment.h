/********************************************************************************
** Form generated from reading UI file 'bookappointment.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKAPPOINTMENT_H
#define UI_BOOKAPPOINTMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_BookAppointment
{
public:
    QFrame *frameCircle1;
    QFrame *frameCircle2;
    QLabel *label;
    QLabel *lblSubtitle;
    QFrame *frameForm;
    QLabel *label_2;
    QComboBox *comboDoctor;
    QLabel *label_3;
    QDateEdit *dateAppointment;
    QLabel *label_4;
    QComboBox *comboSlot;
    QLabel *lblPatientInfo;
    QTextEdit *textEditNotes;
    QPushButton *btnBook;
    QPushButton *btnCancel;

    void setupUi(QDialog *BookAppointment)
    {
        if (BookAppointment->objectName().isEmpty())
            BookAppointment->setObjectName("BookAppointment");
        BookAppointment->setEnabled(true);
        BookAppointment->resize(696, 750);
        BookAppointment->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #f5f7fa, stop:1 #c3cfe2);\n"
"}"));
        frameCircle1 = new QFrame(BookAppointment);
        frameCircle1->setObjectName("frameCircle1");
        frameCircle1->setGeometry(QRect(-80, -80, 300, 300));
        frameCircle1->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(33, 147, 176, 0.2), stop:1 transparent);\n"
"    border-radius: 150px;\n"
"    border: none;\n"
"}"));
        frameCircle2 = new QFrame(BookAppointment);
        frameCircle2->setObjectName("frameCircle2");
        frameCircle2->setGeometry(QRect(480, 500, 350, 350));
        frameCircle2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(109, 213, 237, 0.2), stop:1 transparent);\n"
"    border-radius: 175px;\n"
"    border: none;\n"
"}"));
        label = new QLabel(BookAppointment);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 50, 500, 100));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: #ffffff;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #1976d2, stop:0.5 #42a5f5, stop:1 #64b5f6);\n"
"    padding: 20px 30px;\n"
"    border-radius: 15px;\n"
"    border: 3px solid rgba(255, 255, 255, 0.3);\n"
"    letter-spacing: 2px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        lblSubtitle = new QLabel(BookAppointment);
        lblSubtitle->setObjectName("lblSubtitle");
        lblSubtitle->setGeometry(QRect(100, 165, 500, 35));
        lblSubtitle->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"    font-weight: 500;\n"
"}"));
        frameForm = new QFrame(BookAppointment);
        frameForm->setObjectName("frameForm");
        frameForm->setGeometry(QRect(100, 230, 500, 380));
        frameForm->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: rgba(255, 255, 255, 0.95);\n"
"    border-radius: 20px;\n"
"    border: 2px solid rgba(25, 118, 210, 0.3);\n"
"}"));
        label_2 = new QLabel(BookAppointment);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 270, 150, 35));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: 600;\n"
"    color: #1565c0;\n"
"    background: transparent;\n"
"    padding: 4px;\n"
"    letter-spacing: 0.5px;\n"
"}"));
        comboDoctor = new QComboBox(BookAppointment);
        comboDoctor->setObjectName("comboDoctor");
        comboDoctor->setGeometry(QRect(320, 270, 240, 45));
        comboDoctor->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 10px;\n"
"    padding: 8px 12px;\n"
"    font-size: 15px;\n"
"    font-weight: 500;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #1565c0;\n"
"    background-color: #f5f9ff;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border-left: 2px solid #1976d2;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #42a5f5, stop:1 #1976d2);\n"
"    width: 30px;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 6px solid transparent;\n"
"    border-right: 6px solid transparent;\n"
"    border-top: 8px solid white;\n"
"    margin-right: 8px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 8px;\n"
"    selection-background-color: #42a5f5;\n"
"    selec"
                        "tion-color: white;\n"
"    padding: 5px;\n"
"}"));
        label_3 = new QLabel(BookAppointment);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(150, 345, 150, 35));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: 600;\n"
"    color: #1565c0;\n"
"    background: transparent;\n"
"    padding: 4px;\n"
"    letter-spacing: 0.5px;\n"
"}"));
        dateAppointment = new QDateEdit(BookAppointment);
        dateAppointment->setObjectName("dateAppointment");
        dateAppointment->setGeometry(QRect(320, 345, 241, 45));
        dateAppointment->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    font-size: 15px;\n"
"    font-weight: 500;\n"
"    padding: 8px 12px;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 10px;\n"
"    background-color: white;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QDateEdit:hover {\n"
"    border: 2px solid #1565c0;\n"
"    background-color: #f5f9ff;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left: 2px solid #1976d2;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #42a5f5, stop:1 #1976d2);\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 6px solid transparent;\n"
"    border-right: 6px solid transparent;\n"
"    border-top: 8px solid white;\n"
"    margin-right: 8px;\n"
"}\n"
"\n"
"QCalendarWidget {\n"
"    background-color: white;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius:"
                        " 10px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton {\n"
"    color: white;\n"
"    background-color: #1976d2;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView:enabled {\n"
"    color: #2c3e50;\n"
"    background-color: white;\n"
"    selection-background-color: #42a5f5;\n"
"    selection-color: white;\n"
"}"));
        label_4 = new QLabel(BookAppointment);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(150, 420, 150, 35));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: 600;\n"
"    color: #1565c0;\n"
"    background: transparent;\n"
"    padding: 4px;\n"
"    letter-spacing: 0.5px;\n"
"}"));
        comboSlot = new QComboBox(BookAppointment);
        comboSlot->setObjectName("comboSlot");
        comboSlot->setGeometry(QRect(320, 420, 240, 45));
        comboSlot->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 10px;\n"
"    padding: 8px 12px;\n"
"    font-size: 15px;\n"
"    font-weight: 500;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #1565c0;\n"
"    background-color: #f5f9ff;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border-left: 2px solid #1976d2;\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #42a5f5, stop:1 #1976d2);\n"
"    width: 30px;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 6px solid transparent;\n"
"    border-right: 6px solid transparent;\n"
"    border-top: 8px solid white;\n"
"    margin-right: 8px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 8px;\n"
"    selection-background-color: #42a5f5;\n"
"    selec"
                        "tion-color: white;\n"
"    padding: 5px;\n"
"}"));
        lblPatientInfo = new QLabel(BookAppointment);
        lblPatientInfo->setObjectName("lblPatientInfo");
        lblPatientInfo->setGeometry(QRect(150, 495, 150, 35));
        lblPatientInfo->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: 600;\n"
"    color: #1565c0;\n"
"    background: transparent;\n"
"    padding: 4px;\n"
"    letter-spacing: 0.5px;\n"
"}"));
        textEditNotes = new QTextEdit(BookAppointment);
        textEditNotes->setObjectName("textEditNotes");
        textEditNotes->setGeometry(QRect(320, 495, 240, 80));
        textEditNotes->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 10px;\n"
"    padding: 8px 12px;\n"
"    font-size: 14px;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QTextEdit:hover {\n"
"    border: 2px solid #1565c0;\n"
"    background-color: #f5f9ff;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    border: 2px solid #0d47a1;\n"
"}"));
        btnBook = new QPushButton(BookAppointment);
        btnBook->setObjectName("btnBook");
        btnBook->setGeometry(QRect(170, 650, 171, 55));
        btnBook->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 18px;\n"
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
        btnCancel = new QPushButton(BookAppointment);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(360, 650, 140, 55));
        btnCancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: #1976d2;\n"
"    background: transparent;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 12px;\n"
"    padding: 12px 24px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #e3f2fd;\n"
"    border-color: #0d47a1;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #bbdefb;\n"
"}"));

        retranslateUi(BookAppointment);

        QMetaObject::connectSlotsByName(BookAppointment);
    } // setupUi

    void retranslateUi(QDialog *BookAppointment)
    {
        BookAppointment->setWindowTitle(QCoreApplication::translate("BookAppointment", "MedPlus - Book Appointment", nullptr));
        label->setText(QCoreApplication::translate("BookAppointment", "\360\237\223\205 Book Appointment", nullptr));
        lblSubtitle->setText(QCoreApplication::translate("BookAppointment", "Schedule your consultation with our expert doctors", nullptr));
        label_2->setText(QCoreApplication::translate("BookAppointment", "\360\237\221\250\342\200\215\342\232\225\357\270\217 Doctor:", nullptr));
        label_3->setText(QCoreApplication::translate("BookAppointment", "\360\237\223\206 Date:", nullptr));
        label_4->setText(QCoreApplication::translate("BookAppointment", "\360\237\225\220 Time Slot:", nullptr));
        lblPatientInfo->setText(QCoreApplication::translate("BookAppointment", "\360\237\223\235 Notes:", nullptr));
        textEditNotes->setPlaceholderText(QCoreApplication::translate("BookAppointment", "Any specific concerns or symptoms...", nullptr));
        btnBook->setText(QCoreApplication::translate("BookAppointment", "\342\234\223 Book Now", nullptr));
        btnCancel->setText(QCoreApplication::translate("BookAppointment", "\342\234\227 Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookAppointment: public Ui_BookAppointment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKAPPOINTMENT_H
