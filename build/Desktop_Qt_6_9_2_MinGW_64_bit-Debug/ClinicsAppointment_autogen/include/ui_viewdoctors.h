/********************************************************************************
** Form generated from reading UI file 'viewdoctors.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWDOCTORS_H
#define UI_VIEWDOCTORS_H

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

class Ui_ViewDoctors
{
public:
    QFrame *frameCircle1;
    QFrame *frameCircle2;
    QLabel *label;
    QLabel *lblSubtitle;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonBackViewDoctors;

    void setupUi(QDialog *ViewDoctors)
    {
        if (ViewDoctors->objectName().isEmpty())
            ViewDoctors->setObjectName("ViewDoctors");
        ViewDoctors->resize(900, 700);
        ViewDoctors->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e3f2fd, stop:1 #ffffff);\n"
"    border-radius: 15px;\n"
"}"));
        frameCircle1 = new QFrame(ViewDoctors);
        frameCircle1->setObjectName("frameCircle1");
        frameCircle1->setGeometry(QRect(-80, -80, 300, 300));
        frameCircle1->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(25, 118, 210, 0.15), stop:1 transparent);\n"
"    border-radius: 150px;\n"
"    border: none;\n"
"}"));
        frameCircle2 = new QFrame(ViewDoctors);
        frameCircle2->setObjectName("frameCircle2");
        frameCircle2->setGeometry(QRect(680, 480, 350, 350));
        frameCircle2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(66, 165, 245, 0.15), stop:1 transparent);\n"
"    border-radius: 175px;\n"
"    border: none;\n"
"}"));
        label = new QLabel(ViewDoctors);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 40, 700, 100));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
"    box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.2);\n"
"}"));
        lblSubtitle = new QLabel(ViewDoctors);
        lblSubtitle->setObjectName("lblSubtitle");
        lblSubtitle->setGeometry(QRect(100, 155, 700, 40));
        lblSubtitle->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"    font-weight: 500;\n"
"    letter-spacing: 0.5px;\n"
"}"));
        scrollArea = new QScrollArea(ViewDoctors);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(100, 220, 700, 360));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 680, 1000));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: transparent;\n"
"}"));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButtonBackViewDoctors = new QPushButton(ViewDoctors);
        pushButtonBackViewDoctors->setObjectName("pushButtonBackViewDoctors");
        pushButtonBackViewDoctors->setGeometry(QRect(350, 610, 200, 55));
        pushButtonBackViewDoctors->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #1976d2, stop:1 #42a5f5);\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 12px 24px;\n"
"    box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.2);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #1565c0, stop:1 #1976d2);\n"
"    box-shadow: 0px 6px 12px rgba(0, 0, 0, 0.3);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #0d47a1, stop:1 #1565c0);\n"
"    box-shadow: 0px 2px 4px rgba(0, 0, 0, 0.2);\n"
"}"));

        retranslateUi(ViewDoctors);

        QMetaObject::connectSlotsByName(ViewDoctors);
    } // setupUi

    void retranslateUi(QDialog *ViewDoctors)
    {
        ViewDoctors->setWindowTitle(QCoreApplication::translate("ViewDoctors", "MedPlus - View Doctors", nullptr));
        label->setText(QCoreApplication::translate("ViewDoctors", "\360\237\251\272 Our Expert Doctors", nullptr));
        lblSubtitle->setText(QCoreApplication::translate("ViewDoctors", "Meet our qualified medical professionals dedicated to your health", nullptr));
        pushButtonBackViewDoctors->setText(QCoreApplication::translate("ViewDoctors", "\342\206\220 Back to Dashboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewDoctors: public Ui_ViewDoctors {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWDOCTORS_H
