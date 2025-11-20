/********************************************************************************
** Form generated from reading UI file 'aboutus.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTUS_H
#define UI_ABOUTUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutUs
{
public:
    QFrame *frameCircle1;
    QFrame *frameCircle2;
    QLabel *lblTitle;
    QFrame *frameContent;
    QLabel *lblLogo;
    QLabel *lblBrandName;
    QLabel *lblDescription;
    QLabel *lblTech;
    QLabel *lblThankYou;
    QPushButton *btnBack;

    void setupUi(QDialog *AboutUs)
    {
        if (AboutUs->objectName().isEmpty())
            AboutUs->setObjectName("AboutUs");
        AboutUs->resize(900, 600);
        AboutUs->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e3f2fd, stop:1 #ffffff);\n"
"    border-radius: 15px;\n"
"}"));
        frameCircle1 = new QFrame(AboutUs);
        frameCircle1->setObjectName("frameCircle1");
        frameCircle1->setGeometry(QRect(-80, -80, 300, 300));
        frameCircle1->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(25, 118, 210, 0.15), stop:1 transparent);\n"
"    border-radius: 150px;\n"
"    border: none;\n"
"}"));
        frameCircle2 = new QFrame(AboutUs);
        frameCircle2->setObjectName("frameCircle2");
        frameCircle2->setGeometry(QRect(650, 350, 350, 350));
        frameCircle2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(66, 165, 245, 0.15), stop:1 transparent);\n"
"    border-radius: 175px;\n"
"    border: none;\n"
"}"));
        lblTitle = new QLabel(AboutUs);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setGeometry(QRect(100, 30, 700, 80));
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
        frameContent = new QFrame(AboutUs);
        frameContent->setObjectName("frameContent");
        frameContent->setGeometry(QRect(100, 140, 700, 380));
        frameContent->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white;\n"
"    border-radius: 15px;\n"
"    border: 2px solid #e0e0e0;\n"
"}"));
        lblLogo = new QLabel(frameContent);
        lblLogo->setObjectName("lblLogo");
        lblLogo->setGeometry(QRect(300, 30, 100, 100));
        lblLogo->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 80px;\n"
"    color: #1976d2;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        lblBrandName = new QLabel(frameContent);
        lblBrandName->setObjectName("lblBrandName");
        lblBrandName->setGeometry(QRect(50, 140, 600, 40));
        lblBrandName->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 28px;\n"
"    font-weight: bold;\n"
"    color: #1976d2;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        lblDescription = new QLabel(frameContent);
        lblDescription->setObjectName("lblDescription");
        lblDescription->setGeometry(QRect(50, 190, 600, 80));
        lblDescription->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 15px;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        lblDescription->setWordWrap(true);
        lblTech = new QLabel(frameContent);
        lblTech->setObjectName("lblTech");
        lblTech->setGeometry(QRect(50, 290, 600, 30));
        lblTech->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #546e7a;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        lblThankYou = new QLabel(frameContent);
        lblThankYou->setObjectName("lblThankYou");
        lblThankYou->setGeometry(QRect(50, 330, 600, 30));
        lblThankYou->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    color: #1976d2;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        btnBack = new QPushButton(AboutUs);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(350, 540, 221, 50));
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

        retranslateUi(AboutUs);

        QMetaObject::connectSlotsByName(AboutUs);
    } // setupUi

    void retranslateUi(QDialog *AboutUs)
    {
        AboutUs->setWindowTitle(QCoreApplication::translate("AboutUs", "MedPlus - About Us", nullptr));
        lblTitle->setText(QCoreApplication::translate("AboutUs", "\342\204\271\357\270\217 About MedPlus", nullptr));
        lblLogo->setText(QCoreApplication::translate("AboutUs", "\360\237\217\245", nullptr));
        lblBrandName->setText(QCoreApplication::translate("AboutUs", "MedPlus Healthcare System", nullptr));
        lblDescription->setText(QCoreApplication::translate("AboutUs", "Object Oriented Programming project for comprehensive healthcare management.\n"
"Simplifying appointments, billing, and patient care.", nullptr));
        lblTech->setText(QCoreApplication::translate("AboutUs", "\360\237\222\273 Built with C++ & Qt Framework | \360\237\227\204\357\270\217 SQLite Database", nullptr));
        lblThankYou->setText(QCoreApplication::translate("AboutUs", "Thank you for using MedPlus! \360\237\222\231", nullptr));
        btnBack->setText(QCoreApplication::translate("AboutUs", "\342\206\220 Back to Dashboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutUs: public Ui_AboutUs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTUS_H
