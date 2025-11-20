/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frameCircle1;
    QFrame *frameCircle2;
    QFrame *frameBranding;
    QLabel *lblBrandIcon;
    QLabel *lblBrandName;
    QLabel *lblTagline;
    QLabel *lblFeature1;
    QLabel *lblFeature2;
    QLabel *lblFeature3;
    QLabel *lblFeature4;
    QFrame *frameLoginPanel;
    QLabel *lblFooter;
    QLabel *lblWelcome;
    QLabel *lblSubtitle;
    QLabel *lblUsernameIcon;
    QLineEdit *lineEdit;
    QLabel *lblPasswordIcon;
    QLineEdit *lineEdit_2;
    QLabel *lblForgotPassword;
    QPushButton *loginButton;
    QFrame *lineDivider;
    QLabel *lblRegisterText;
    QPushButton *regLogin;
    QPushButton *exitButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #0f2027, stop:0.5 #203a43, stop:1 #2c5364);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frameCircle1 = new QFrame(centralwidget);
        frameCircle1->setObjectName("frameCircle1");
        frameCircle1->setGeometry(QRect(-100, -100, 400, 400));
        frameCircle1->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(66, 165, 245, 0.3), stop:1 transparent);\n"
"    border-radius: 200px;\n"
"    border: none;\n"
"}"));
        frameCircle2 = new QFrame(centralwidget);
        frameCircle2->setObjectName("frameCircle2");
        frameCircle2->setGeometry(QRect(1100, 600, 500, 500));
        frameCircle2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(102, 187, 106, 0.3), stop:1 transparent);\n"
"    border-radius: 250px;\n"
"    border: none;\n"
"}"));
        frameBranding = new QFrame(centralwidget);
        frameBranding->setObjectName("frameBranding");
        frameBranding->setGeometry(QRect(0, 0, 731, 851));
        frameBranding->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 rgba(25, 118, 210, 0.95),\n"
"        stop:1 rgba(13, 71, 161, 0.95));\n"
"    border: none;\n"
"}"));
        lblBrandIcon = new QLabel(frameBranding);
        lblBrandIcon->setObjectName("lblBrandIcon");
        lblBrandIcon->setGeometry(QRect(180, 60, 300, 300));
        lblBrandIcon->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:0.8,\n"
"        fx:0.5, fy:0.5,\n"
"        stop:0 rgba(255, 255, 255, 0.2),\n"
"        stop:0.7 rgba(255, 255, 255, 0.1),\n"
"        stop:1 transparent);\n"
"    border: 5px solid rgba(255, 255, 255, 0.3);\n"
"    border-radius: 150px;\n"
"    font-size: 150px;\n"
"    color: white;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        lblBrandName = new QLabel(frameBranding);
        lblBrandName->setObjectName("lblBrandName");
        lblBrandName->setGeometry(QRect(50, 390, 600, 80));
        lblBrandName->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 56px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"    letter-spacing: 2px;\n"
"}"));
        lblTagline = new QLabel(frameBranding);
        lblTagline->setObjectName("lblTagline");
        lblTagline->setGeometry(QRect(50, 500, 600, 40));
        lblTagline->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 20px;\n"
"    color: rgba(255, 255, 255, 0.9);\n"
"    font-style: italic;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"    letter-spacing: 1px;\n"
"}"));
        lblFeature1 = new QLabel(centralwidget);
        lblFeature1->setObjectName("lblFeature1");
        lblFeature1->setGeometry(QRect(150, 550, 400, 35));
        lblFeature1->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: rgba(255, 255, 255, 0.85);\n"
"    background: transparent;\n"
"    padding-left: 10px;\n"
"}"));
        lblFeature2 = new QLabel(centralwidget);
        lblFeature2->setObjectName("lblFeature2");
        lblFeature2->setGeometry(QRect(150, 590, 400, 35));
        lblFeature2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: rgba(255, 255, 255, 0.85);\n"
"    background: transparent;\n"
"    padding-left: 10px;\n"
"}"));
        lblFeature3 = new QLabel(centralwidget);
        lblFeature3->setObjectName("lblFeature3");
        lblFeature3->setGeometry(QRect(150, 630, 400, 35));
        lblFeature3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: rgba(255, 255, 255, 0.85);\n"
"    background: transparent;\n"
"    padding-left: 10px;\n"
"}"));
        lblFeature4 = new QLabel(centralwidget);
        lblFeature4->setObjectName("lblFeature4");
        lblFeature4->setGeometry(QRect(150, 670, 400, 35));
        lblFeature4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: rgba(255, 255, 255, 0.85);\n"
"    background: transparent;\n"
"    padding-left: 10px;\n"
"}"));
        frameLoginPanel = new QFrame(centralwidget);
        frameLoginPanel->setObjectName("frameLoginPanel");
        frameLoginPanel->setGeometry(QRect(710, 0, 851, 851));
        frameLoginPanel->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff;\n"
"    border: none;\n"
"}"));
        lblFooter = new QLabel(frameLoginPanel);
        lblFooter->setObjectName("lblFooter");
        lblFooter->setGeometry(QRect(100, 780, 500, 25));
        lblFooter->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 12px;\n"
"    color: #9e9e9e;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        lblWelcome = new QLabel(centralwidget);
        lblWelcome->setObjectName("lblWelcome");
        lblWelcome->setGeometry(QRect(800, 120, 500, 60));
        lblWelcome->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 42px;\n"
"    font-weight: bold;\n"
"    color: #1565c0;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignLeft;\n"
"}"));
        lblSubtitle = new QLabel(centralwidget);
        lblSubtitle->setObjectName("lblSubtitle");
        lblSubtitle->setGeometry(QRect(800, 185, 500, 30));
        lblSubtitle->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #757575;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignLeft;\n"
"}"));
        lblUsernameIcon = new QLabel(centralwidget);
        lblUsernameIcon->setObjectName("lblUsernameIcon");
        lblUsernameIcon->setGeometry(QRect(800, 270, 500, 30));
        lblUsernameIcon->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 15px;\n"
"    font-weight: 600;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"}"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(800, 310, 500, 55));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-size: 16px;\n"
"    color: #212121;\n"
"    padding: 15px 20px;\n"
"    border: 2px solid #e0e0e0;\n"
"    border-radius: 12px;\n"
"    background-color: #fafafa;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #1976d2;\n"
"    background-color: #ffffff;\n"
"}"));
        lblPasswordIcon = new QLabel(centralwidget);
        lblPasswordIcon->setObjectName("lblPasswordIcon");
        lblPasswordIcon->setGeometry(QRect(800, 400, 500, 30));
        lblPasswordIcon->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 15px;\n"
"    font-weight: 600;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"}"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(800, 440, 500, 55));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-size: 16px;\n"
"    color: #212121;\n"
"    padding: 15px 20px;\n"
"    border: 2px solid #e0e0e0;\n"
"    border-radius: 12px;\n"
"    background-color: #fafafa;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #1976d2;\n"
"    background-color: #ffffff;\n"
"}"));
        lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
        lblForgotPassword = new QLabel(centralwidget);
        lblForgotPassword->setObjectName("lblForgotPassword");
        lblForgotPassword->setGeometry(QRect(1080, 520, 220, 25));
        lblForgotPassword->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 13px;\n"
"    color: #1976d2;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignRight;\n"
"}"));
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(800, 580, 500, 60));
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #1976d2, stop:1 #42a5f5);\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #1565c0, stop:1 #1976d2);\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #0d47a1, stop:1 #1565c0);\n"
"}"));
        lineDivider = new QFrame(centralwidget);
        lineDivider->setObjectName("lineDivider");
        lineDivider->setGeometry(QRect(800, 680, 500, 2));
        lineDivider->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #e0e0e0;\n"
"    border: none;\n"
"}"));
        lblRegisterText = new QLabel(centralwidget);
        lblRegisterText->setObjectName("lblRegisterText");
        lblRegisterText->setGeometry(QRect(800, 710, 300, 30));
        lblRegisterText->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #757575;\n"
"    background: transparent;\n"
"}"));
        regLogin = new QPushButton(centralwidget);
        regLogin->setObjectName("regLogin");
        regLogin->setGeometry(QRect(985, 705, 140, 40));
        regLogin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    color: #1976d2;\n"
"    background: transparent;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e3f2fd;\n"
"    border-color: #0d47a1;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #bbdefb;\n"
"}"));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(1160, 705, 140, 40));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    color: #757575;\n"
"    background: transparent;\n"
"    border: 2px solid #bdbdbd;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #f5f5f5;\n"
"    border-color: #757575;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #e0e0e0;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MedPlus Clinic - Advanced Healthcare System", nullptr));
        lblBrandIcon->setText(QCoreApplication::translate("MainWindow", "\360\237\217\245", nullptr));
        lblBrandName->setText(QCoreApplication::translate("MainWindow", "MedPlus", nullptr));
        lblTagline->setText(QCoreApplication::translate("MainWindow", "Advanced Healthcare Management System", nullptr));
        lblFeature1->setText(QCoreApplication::translate("MainWindow", "\342\234\223 Easy Online Appointment Booking", nullptr));
        lblFeature2->setText(QCoreApplication::translate("MainWindow", "\342\234\223 24/7 Access to Medical Records", nullptr));
        lblFeature3->setText(QCoreApplication::translate("MainWindow", "\342\234\223 Secure & Confidential", nullptr));
        lblFeature4->setText(QCoreApplication::translate("MainWindow", "\342\234\223 Expert Doctors Available", nullptr));
        lblFooter->setText(QCoreApplication::translate("MainWindow", "\302\251 2025 MedPlus Clinic. All rights reserved.", nullptr));
        lblWelcome->setText(QCoreApplication::translate("MainWindow", "Welcome Back!", nullptr));
        lblSubtitle->setText(QCoreApplication::translate("MainWindow", "Sign in to continue to your account", nullptr));
        lblUsernameIcon->setText(QCoreApplication::translate("MainWindow", "\360\237\221\244 Username", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your username", nullptr));
        lblPasswordIcon->setText(QCoreApplication::translate("MainWindow", "\360\237\224\222 Password", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your password", nullptr));
        lblForgotPassword->setText(QCoreApplication::translate("MainWindow", "Forgot Password?", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Sign In", nullptr));
        lblRegisterText->setText(QCoreApplication::translate("MainWindow", "Don't have an account?", nullptr));
        regLogin->setText(QCoreApplication::translate("MainWindow", "Register Now", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
