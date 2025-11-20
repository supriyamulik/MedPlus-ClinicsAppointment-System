/********************************************************************************
** Form generated from reading UI file 'myprofile.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPROFILE_H
#define UI_MYPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MyProfile
{
public:
    QFrame *frameCircle1;
    QFrame *frameCircle2;
    QLabel *lblTitle;
    QFrame *frameProfileCard;
    QFrame *frameAvatar;
    QLabel *lblAvatar;
    QLabel *lblName;
    QLabel *lblPatientId;
    QFrame *lineDiv;
    QLabel *lblEmailIcon;
    QLabel *lblEmail;
    QLabel *lblPhoneIcon;
    QLabel *lblPhone;
    QLabel *lblAddressIcon;
    QLabel *lblAddress;
    QPushButton *btnEditProfile;
    QPushButton *btnBack;

    void setupUi(QDialog *MyProfile)
    {
        if (MyProfile->objectName().isEmpty())
            MyProfile->setObjectName("MyProfile");
        MyProfile->resize(1000, 750);
        MyProfile->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #e3f2fd, stop:1 #ffffff);\n"
"    border-radius: 15px;\n"
"}"));
        frameCircle1 = new QFrame(MyProfile);
        frameCircle1->setObjectName("frameCircle1");
        frameCircle1->setGeometry(QRect(-80, -80, 300, 300));
        frameCircle1->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(25, 118, 210, 0.15), stop:1 transparent);\n"
"    border-radius: 150px;\n"
"    border: none;\n"
"}"));
        frameCircle2 = new QFrame(MyProfile);
        frameCircle2->setObjectName("frameCircle2");
        frameCircle2->setGeometry(QRect(750, 500, 350, 350));
        frameCircle2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1,\n"
"        fx:0.5, fy:0.5, stop:0 rgba(66, 165, 245, 0.15), stop:1 transparent);\n"
"    border-radius: 175px;\n"
"    border: none;\n"
"}"));
        lblTitle = new QLabel(MyProfile);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setGeometry(QRect(100, 30, 800, 80));
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
        frameProfileCard = new QFrame(MyProfile);
        frameProfileCard->setObjectName("frameProfileCard");
        frameProfileCard->setGeometry(QRect(100, 140, 800, 520));
        frameProfileCard->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white;\n"
"    border-radius: 15px;\n"
"    border: 2px solid #e0e0e0;\n"
"}"));
        frameAvatar = new QFrame(frameProfileCard);
        frameAvatar->setObjectName("frameAvatar");
        frameAvatar->setGeometry(QRect(320, 30, 160, 160));
        frameAvatar->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #42a5f5, stop:1 #1e88e5);\n"
"    border-radius: 80px;\n"
"    border: 5px solid white;\n"
"}"));
        lblAvatar = new QLabel(frameAvatar);
        lblAvatar->setObjectName("lblAvatar");
        lblAvatar->setGeometry(QRect(0, 0, 160, 160));
        lblAvatar->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 80px;\n"
"    color: white;\n"
"    background: transparent;\n"
"    border: none;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        lblName = new QLabel(frameProfileCard);
        lblName->setObjectName("lblName");
        lblName->setGeometry(QRect(50, 210, 700, 40));
        lblName->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 28px;\n"
"    font-weight: bold;\n"
"    color: #1976d2;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        lblPatientId = new QLabel(frameProfileCard);
        lblPatientId->setObjectName("lblPatientId");
        lblPatientId->setGeometry(QRect(50, 250, 700, 25));
        lblPatientId->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #757575;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"    font-style: italic;\n"
"}"));
        lineDiv = new QFrame(frameProfileCard);
        lineDiv->setObjectName("lineDiv");
        lineDiv->setGeometry(QRect(50, 290, 700, 2));
        lineDiv->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #e0e0e0;\n"
"    border: none;\n"
"}"));
        lblEmailIcon = new QLabel(frameProfileCard);
        lblEmailIcon->setObjectName("lblEmailIcon");
        lblEmailIcon->setGeometry(QRect(80, 320, 40, 30));
        lblEmailIcon->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 20px;\n"
"    background: transparent;\n"
"}"));
        lblEmail = new QLabel(frameProfileCard);
        lblEmail->setObjectName("lblEmail");
        lblEmail->setGeometry(QRect(130, 320, 600, 30));
        lblEmail->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"}"));
        lblPhoneIcon = new QLabel(frameProfileCard);
        lblPhoneIcon->setObjectName("lblPhoneIcon");
        lblPhoneIcon->setGeometry(QRect(80, 360, 40, 30));
        lblPhoneIcon->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 20px;\n"
"    background: transparent;\n"
"}"));
        lblPhone = new QLabel(frameProfileCard);
        lblPhone->setObjectName("lblPhone");
        lblPhone->setGeometry(QRect(130, 360, 600, 30));
        lblPhone->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"}"));
        lblAddressIcon = new QLabel(frameProfileCard);
        lblAddressIcon->setObjectName("lblAddressIcon");
        lblAddressIcon->setGeometry(QRect(80, 400, 40, 30));
        lblAddressIcon->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 20px;\n"
"    background: transparent;\n"
"}"));
        lblAddress = new QLabel(frameProfileCard);
        lblAddress->setObjectName("lblAddress");
        lblAddress->setGeometry(QRect(130, 400, 600, 30));
        lblAddress->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"}"));
        btnEditProfile = new QPushButton(frameProfileCard);
        btnEditProfile->setObjectName("btnEditProfile");
        btnEditProfile->setGeometry(QRect(250, 450, 300, 50));
        btnEditProfile->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #66bb6a, stop:1 #43a047);\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    padding: 12px 24px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #4caf50, stop:1 #388e3c);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #388e3c, stop:1 #2e7d32);\n"
"}"));
        btnBack = new QPushButton(MyProfile);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(400, 680, 200, 55));
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

        retranslateUi(MyProfile);

        QMetaObject::connectSlotsByName(MyProfile);
    } // setupUi

    void retranslateUi(QDialog *MyProfile)
    {
        MyProfile->setWindowTitle(QCoreApplication::translate("MyProfile", "MedPlus - My Profile", nullptr));
        lblTitle->setText(QCoreApplication::translate("MyProfile", "\360\237\221\244 My Profile", nullptr));
        lblAvatar->setText(QCoreApplication::translate("MyProfile", "\360\237\221\244", nullptr));
        lblName->setText(QCoreApplication::translate("MyProfile", "Loading...", nullptr));
        lblPatientId->setText(QCoreApplication::translate("MyProfile", "Patient ID: ---", nullptr));
        lblEmailIcon->setText(QCoreApplication::translate("MyProfile", "\360\237\223\247", nullptr));
        lblEmail->setText(QCoreApplication::translate("MyProfile", "Email: ---", nullptr));
        lblPhoneIcon->setText(QCoreApplication::translate("MyProfile", "\360\237\223\261", nullptr));
        lblPhone->setText(QCoreApplication::translate("MyProfile", "Phone: ---", nullptr));
        lblAddressIcon->setText(QCoreApplication::translate("MyProfile", "\360\237\217\240", nullptr));
        lblAddress->setText(QCoreApplication::translate("MyProfile", "Address: ---", nullptr));
        btnEditProfile->setText(QCoreApplication::translate("MyProfile", "\342\234\217\357\270\217 Edit Profile", nullptr));
        btnBack->setText(QCoreApplication::translate("MyProfile", "\342\206\220 Back to Dashboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyProfile: public Ui_MyProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPROFILE_H
