/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QFrame *frameCircle1;
    QFrame *frameCircle2;
    QLabel *label;
    QLabel *lblSubtitle;
    QFrame *frameForm;
    QLabel *label_2;
    QLineEdit *fullNameLineEdit;
    QLabel *label_3;
    QLineEdit *usernameLineEdit;
    QLabel *label_4;
    QLineEdit *passwordLineEdit;
    QLabel *label_5;
    QLineEdit *confirmPasswordLineEdit;
    QLabel *label_6;
    QLineEdit *emailLineEdit;
    QLabel *lblPhone;
    QLineEdit *phoneLineEdit;
    QPushButton *registerButton;
    QPushButton *loginButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName("Registration");
        Registration->resize(750, 750);
        Registration->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #f5f7fa, stop:1 #c3cfe2);\n"
"}"));
        frameCircle1 = new QFrame(Registration);
        frameCircle1->setObjectName("frameCircle1");
        frameCircle1->setGeometry(QRect(-80, -80, 300, 300));
        frameCircle1->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(33, 147, 176, 0.2), stop:1 transparent);\n"
"    border-radius: 150px;\n"
"    border: none;\n"
"}"));
        frameCircle2 = new QFrame(Registration);
        frameCircle2->setObjectName("frameCircle2");
        frameCircle2->setGeometry(QRect(530, 500, 350, 350));
        frameCircle2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(109, 213, 237, 0.2), stop:1 transparent);\n"
"    border-radius: 175px;\n"
"    border: none;\n"
"}"));
        label = new QLabel(Registration);
        label->setObjectName("label");
        label->setGeometry(QRect(125, 40, 500, 100));
        label->setMinimumSize(QSize(4, 0));
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
        lblSubtitle = new QLabel(Registration);
        lblSubtitle->setObjectName("lblSubtitle");
        lblSubtitle->setGeometry(QRect(125, 155, 500, 35));
        lblSubtitle->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"    font-weight: 500;\n"
"}"));
        frameForm = new QFrame(Registration);
        frameForm->setObjectName("frameForm");
        frameForm->setGeometry(QRect(100, 220, 550, 420));
        frameForm->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: rgba(255, 255, 255, 0.95);\n"
"    border-radius: 20px;\n"
"    border: 2px solid rgba(25, 118, 210, 0.3);\n"
"}"));
        label_2 = new QLabel(Registration);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 260, 150, 35));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    color: #1565c0;\n"
"    background: transparent;\n"
"    padding: 4px;\n"
"    letter-spacing: 0.5px;\n"
"}"));
        fullNameLineEdit = new QLineEdit(Registration);
        fullNameLineEdit->setObjectName("fullNameLineEdit");
        fullNameLineEdit->setGeometry(QRect(310, 255, 300, 45));
        fullNameLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-size: 15px;\n"
"    color: #2c3e50;\n"
"    padding: 10px 15px;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 10px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 2px solid #1565c0;\n"
"    background-color: #f5f9ff;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #0d47a1;\n"
"    background-color: white;\n"
"}"));
        label_3 = new QLabel(Registration);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(140, 325, 150, 35));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    color: #1565c0;\n"
"    background: transparent;\n"
"    padding: 4px;\n"
"    letter-spacing: 0.5px;\n"
"}"));
        usernameLineEdit = new QLineEdit(Registration);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(310, 320, 300, 45));
        usernameLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-size: 15px;\n"
"    color: #2c3e50;\n"
"    padding: 10px 15px;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 10px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 2px solid #1565c0;\n"
"    background-color: #f5f9ff;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #0d47a1;\n"
"    background-color: white;\n"
"}"));
        label_4 = new QLabel(Registration);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(140, 390, 150, 35));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    color: #1565c0;\n"
"    background: transparent;\n"
"    padding: 4px;\n"
"    letter-spacing: 0.5px;\n"
"}"));
        passwordLineEdit = new QLineEdit(Registration);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(310, 385, 300, 45));
        passwordLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-size: 15px;\n"
"    color: #2c3e50;\n"
"    padding: 10px 15px;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 10px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 2px solid #1565c0;\n"
"    background-color: #f5f9ff;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #0d47a1;\n"
"    background-color: white;\n"
"}"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        label_5 = new QLabel(Registration);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(140, 455, 150, 35));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    color: #1565c0;\n"
"    background: transparent;\n"
"    padding: 4px;\n"
"    letter-spacing: 0.5px;\n"
"}"));
        confirmPasswordLineEdit = new QLineEdit(Registration);
        confirmPasswordLineEdit->setObjectName("confirmPasswordLineEdit");
        confirmPasswordLineEdit->setGeometry(QRect(310, 450, 300, 45));
        confirmPasswordLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-size: 15px;\n"
"    color: #2c3e50;\n"
"    padding: 10px 15px;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 10px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 2px solid #1565c0;\n"
"    background-color: #f5f9ff;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #0d47a1;\n"
"    background-color: white;\n"
"}"));
        confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);
        label_6 = new QLabel(Registration);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(140, 520, 150, 35));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    color: #1565c0;\n"
"    background: transparent;\n"
"    padding: 4px;\n"
"    letter-spacing: 0.5px;\n"
"}"));
        emailLineEdit = new QLineEdit(Registration);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(310, 515, 300, 45));
        emailLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-size: 15px;\n"
"    color: #2c3e50;\n"
"    padding: 10px 15px;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 10px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 2px solid #1565c0;\n"
"    background-color: #f5f9ff;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #0d47a1;\n"
"    background-color: white;\n"
"}"));
        lblPhone = new QLabel(Registration);
        lblPhone->setObjectName("lblPhone");
        lblPhone->setGeometry(QRect(140, 585, 150, 35));
        lblPhone->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    color: #1565c0;\n"
"    background: transparent;\n"
"    padding: 4px;\n"
"    letter-spacing: 0.5px;\n"
"}"));
        phoneLineEdit = new QLineEdit(Registration);
        phoneLineEdit->setObjectName("phoneLineEdit");
        phoneLineEdit->setGeometry(QRect(310, 580, 300, 45));
        phoneLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-size: 15px;\n"
"    color: #2c3e50;\n"
"    padding: 10px 15px;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 10px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 2px solid #1565c0;\n"
"    background-color: #f5f9ff;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #0d47a1;\n"
"    background-color: white;\n"
"}"));
        registerButton = new QPushButton(Registration);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(140, 665, 140, 55));
        registerButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        loginButton = new QPushButton(Registration);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(305, 665, 140, 55));
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        cancelButton = new QPushButton(Registration);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(470, 665, 140, 55));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: #757575;\n"
"    background: transparent;\n"
"    border: 2px solid #bdbdbd;\n"
"    border-radius: 12px;\n"
"    padding: 12px 24px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #f5f5f5;\n"
"    border-color: #757575;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e0e0e0;\n"
"}"));

        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QDialog *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "MedPlus - Registration", nullptr));
        label->setText(QCoreApplication::translate("Registration", "\360\237\223\235 Registration Form", nullptr));
        lblSubtitle->setText(QCoreApplication::translate("Registration", "Create your MedPlus account to get started", nullptr));
        label_2->setText(QCoreApplication::translate("Registration", "\360\237\221\244 Full Name:", nullptr));
        fullNameLineEdit->setPlaceholderText(QCoreApplication::translate("Registration", "Enter your full name", nullptr));
        label_3->setText(QCoreApplication::translate("Registration", "\360\237\206\224 Username:", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("Registration", "Choose a username", nullptr));
        label_4->setText(QCoreApplication::translate("Registration", "\360\237\224\222 Password:", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("Registration", "Create a strong password", nullptr));
        label_5->setText(QCoreApplication::translate("Registration", "\360\237\224\220 Confirm:", nullptr));
        confirmPasswordLineEdit->setPlaceholderText(QCoreApplication::translate("Registration", "Re-enter password", nullptr));
        label_6->setText(QCoreApplication::translate("Registration", "\360\237\223\247 Email:", nullptr));
        emailLineEdit->setPlaceholderText(QCoreApplication::translate("Registration", "your.email@example.com", nullptr));
        lblPhone->setText(QCoreApplication::translate("Registration", "\360\237\223\261 Phone:", nullptr));
        phoneLineEdit->setPlaceholderText(QCoreApplication::translate("Registration", "+91 XXXXX XXXXX", nullptr));
        registerButton->setText(QCoreApplication::translate("Registration", "\342\234\223 Register", nullptr));
        loginButton->setText(QCoreApplication::translate("Registration", "\342\206\220 Login", nullptr));
        cancelButton->setText(QCoreApplication::translate("Registration", "\342\234\227 Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
