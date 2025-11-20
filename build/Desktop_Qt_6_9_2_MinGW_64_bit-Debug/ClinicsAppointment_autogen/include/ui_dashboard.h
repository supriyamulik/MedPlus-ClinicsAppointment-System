/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frameSidebar;
    QVBoxLayout *verticalLayout;
    QLabel *lblLogo;
    QLabel *lblBrandName;
    QLabel *lblTagline;
    QFrame *lineDivider;
    QSpacerItem *verticalSpacer_1;
    QPushButton *btnBookAppointment;
    QPushButton *btnMyAppointments;
    QPushButton *btnViewSlotAvailability;
    QPushButton *btnViewDoctors;
    QPushButton *btnMyProfile;
    QPushButton *btnBilling;
    QPushButton *btnAboutUs;
    QSpacerItem *verticalSpacer_2;
    QFrame *lineDivider2;
    QPushButton *btnExit;
    QSpacerItem *verticalSpacer_3;
    QLabel *lblFooter;
    QFrame *frameMainContent;
    QVBoxLayout *verticalLayout_2;
    QFrame *frameTopBar;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblWelcome;
    QLabel *lblDateTime;
    QSpacerItem *horizontalSpacer;
    QFrame *frameUserBadge;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblUserIcon;
    QLabel *lblUserName;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QLabel *lblQuickActions;
    QGridLayout *gridLayout;
    QFrame *cardTotalAppointments;
    QVBoxLayout *verticalLayout_5;
    QLabel *lblCardIcon1;
    QLabel *lblCardTitle1;
    QLabel *lblCardValue1;
    QFrame *cardUpcoming;
    QVBoxLayout *verticalLayout_6;
    QLabel *lblCardIcon2;
    QLabel *lblCardTitle2;
    QLabel *lblCardValue2;
    QFrame *cardDoctors;
    QVBoxLayout *verticalLayout_7;
    QLabel *lblCardIcon3;
    QLabel *lblCardTitle3;
    QLabel *lblCardValue3;
    QFrame *cardPending;
    QVBoxLayout *verticalLayout_8;
    QLabel *lblCardIcon4;
    QLabel *lblCardTitle4;
    QLabel *lblCardValue4;
    QLabel *lblRecentActivity;
    QFrame *frameActivityList;
    QVBoxLayout *verticalLayout_9;
    QLabel *lblActivityInfo;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(1366, 768);
        Dashboard->setMinimumSize(QSize(1024, 768));
        Dashboard->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #f5f7fa;\n"
"}"));
        centralwidget = new QWidget(Dashboard);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frameSidebar = new QFrame(centralwidget);
        frameSidebar->setObjectName("frameSidebar");
        frameSidebar->setMinimumSize(QSize(280, 0));
        frameSidebar->setMaximumSize(QSize(300, 16777215));
        frameSidebar->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: none;\n"
"}"));
        verticalLayout = new QVBoxLayout(frameSidebar);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(15, 20, 15, 20);
        lblLogo = new QLabel(frameSidebar);
        lblLogo->setObjectName("lblLogo");
        lblLogo->setMinimumSize(QSize(0, 70));
        lblLogo->setMaximumSize(QSize(16777215, 70));
        lblLogo->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 48px;\n"
"    color: white;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));

        verticalLayout->addWidget(lblLogo);

        lblBrandName = new QLabel(frameSidebar);
        lblBrandName->setObjectName("lblBrandName");
        lblBrandName->setMinimumSize(QSize(0, 35));
        lblBrandName->setMaximumSize(QSize(16777215, 35));
        lblBrandName->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"    letter-spacing: 1px;\n"
"}"));

        verticalLayout->addWidget(lblBrandName);

        lblTagline = new QLabel(frameSidebar);
        lblTagline->setObjectName("lblTagline");
        lblTagline->setMinimumSize(QSize(0, 20));
        lblTagline->setMaximumSize(QSize(16777215, 20));
        lblTagline->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 11px;\n"
"    color: rgba(255, 255, 255, 0.8);\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"    font-style: italic;\n"
"}"));

        verticalLayout->addWidget(lblTagline);

        lineDivider = new QFrame(frameSidebar);
        lineDivider->setObjectName("lineDivider");
        lineDivider->setMinimumSize(QSize(0, 1));
        lineDivider->setMaximumSize(QSize(16777215, 1));
        lineDivider->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: rgba(255, 255, 255, 0.3);\n"
"    border: none;\n"
"}"));
        lineDivider->setFrameShape(QFrame::HLine);
        lineDivider->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(lineDivider);

        verticalSpacer_1 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_1);

        btnBookAppointment = new QPushButton(frameSidebar);
        btnBookAppointment->setObjectName("btnBookAppointment");
        btnBookAppointment->setMinimumSize(QSize(0, 50));
        btnBookAppointment->setMaximumSize(QSize(16777215, 50));
        btnBookAppointment->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 0.12);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    border: 1.5px solid rgba(255, 255, 255, 0.2);\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    text-align: left;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.2);\n"
"    border-color: rgba(255, 255, 255, 0.35);\n"
"    transform: translateY(-1px);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.25);\n"
"}"));

        verticalLayout->addWidget(btnBookAppointment);

        btnMyAppointments = new QPushButton(frameSidebar);
        btnMyAppointments->setObjectName("btnMyAppointments");
        btnMyAppointments->setMinimumSize(QSize(0, 50));
        btnMyAppointments->setMaximumSize(QSize(16777215, 50));
        btnMyAppointments->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 0.12);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    border: 1.5px solid rgba(255, 255, 255, 0.2);\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    text-align: left;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.2);\n"
"    border-color: rgba(255, 255, 255, 0.35);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.25);\n"
"}"));

        verticalLayout->addWidget(btnMyAppointments);

        btnViewSlotAvailability = new QPushButton(frameSidebar);
        btnViewSlotAvailability->setObjectName("btnViewSlotAvailability");
        btnViewSlotAvailability->setMinimumSize(QSize(0, 50));
        btnViewSlotAvailability->setMaximumSize(QSize(16777215, 50));
        btnViewSlotAvailability->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 0.12);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    border: 1.5px solid rgba(255, 255, 255, 0.2);\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    text-align: left;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.2);\n"
"    border-color: rgba(255, 255, 255, 0.35);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.25);\n"
"}"));

        verticalLayout->addWidget(btnViewSlotAvailability);

        btnViewDoctors = new QPushButton(frameSidebar);
        btnViewDoctors->setObjectName("btnViewDoctors");
        btnViewDoctors->setMinimumSize(QSize(0, 50));
        btnViewDoctors->setMaximumSize(QSize(16777215, 50));
        btnViewDoctors->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 0.12);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    border: 1.5px solid rgba(255, 255, 255, 0.2);\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    text-align: left;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.2);\n"
"    border-color: rgba(255, 255, 255, 0.35);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.25);\n"
"}"));

        verticalLayout->addWidget(btnViewDoctors);

        btnMyProfile = new QPushButton(frameSidebar);
        btnMyProfile->setObjectName("btnMyProfile");
        btnMyProfile->setMinimumSize(QSize(0, 50));
        btnMyProfile->setMaximumSize(QSize(16777215, 50));
        btnMyProfile->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 0.12);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    border: 1.5px solid rgba(255, 255, 255, 0.2);\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    text-align: left;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.2);\n"
"    border-color: rgba(255, 255, 255, 0.35);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.25);\n"
"}"));

        verticalLayout->addWidget(btnMyProfile);

        btnBilling = new QPushButton(frameSidebar);
        btnBilling->setObjectName("btnBilling");
        btnBilling->setMinimumSize(QSize(0, 50));
        btnBilling->setMaximumSize(QSize(16777215, 50));
        btnBilling->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 0.12);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    border: 1.5px solid rgba(255, 255, 255, 0.2);\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    text-align: left;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.2);\n"
"    border-color: rgba(255, 255, 255, 0.35);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.25);\n"
"}"));

        verticalLayout->addWidget(btnBilling);

        btnAboutUs = new QPushButton(frameSidebar);
        btnAboutUs->setObjectName("btnAboutUs");
        btnAboutUs->setMinimumSize(QSize(0, 50));
        btnAboutUs->setMaximumSize(QSize(16777215, 50));
        btnAboutUs->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(255, 255, 255, 0.12);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    border: 1.5px solid rgba(255, 255, 255, 0.2);\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    text-align: left;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.2);\n"
"    border-color: rgba(255, 255, 255, 0.35);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.25);\n"
"}"));

        verticalLayout->addWidget(btnAboutUs);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        lineDivider2 = new QFrame(frameSidebar);
        lineDivider2->setObjectName("lineDivider2");
        lineDivider2->setMinimumSize(QSize(0, 1));
        lineDivider2->setMaximumSize(QSize(16777215, 1));
        lineDivider2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: rgba(255, 255, 255, 0.3);\n"
"    border: none;\n"
"}"));
        lineDivider2->setFrameShape(QFrame::HLine);
        lineDivider2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(lineDivider2);

        btnExit = new QPushButton(frameSidebar);
        btnExit->setObjectName("btnExit");
        btnExit->setMinimumSize(QSize(0, 50));
        btnExit->setMaximumSize(QSize(16777215, 50));
        btnExit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(244, 67, 54, 0.8);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    border: 1.5px solid rgba(198, 40, 40, 0.5);\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(244, 67, 54, 0.9);\n"
"    border-color: rgba(198, 40, 40, 0.7);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(198, 40, 40, 0.9);\n"
"}"));

        verticalLayout->addWidget(btnExit);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        lblFooter = new QLabel(frameSidebar);
        lblFooter->setObjectName("lblFooter");
        lblFooter->setMinimumSize(QSize(0, 35));
        lblFooter->setMaximumSize(QSize(16777215, 35));
        lblFooter->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 10px;\n"
"    color: rgba(255, 255, 255, 0.5);\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));

        verticalLayout->addWidget(lblFooter);


        horizontalLayout->addWidget(frameSidebar);

        frameMainContent = new QFrame(centralwidget);
        frameMainContent->setObjectName("frameMainContent");
        frameMainContent->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #f5f7fa;\n"
"    border: none;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(frameMainContent);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frameTopBar = new QFrame(frameMainContent);
        frameTopBar->setObjectName("frameTopBar");
        frameTopBar->setMinimumSize(QSize(0, 80));
        frameTopBar->setMaximumSize(QSize(16777215, 80));
        frameTopBar->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white;\n"
"    border: none;\n"
"    border-bottom: 2px solid #e0e0e0;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(frameTopBar);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(30, 10, 30, 10);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName("verticalLayout_3");
        lblWelcome = new QLabel(frameTopBar);
        lblWelcome->setObjectName("lblWelcome");
        lblWelcome->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    color: #1e3c72;\n"
"    background: transparent;\n"
"}"));

        verticalLayout_3->addWidget(lblWelcome);

        lblDateTime = new QLabel(frameTopBar);
        lblDateTime->setObjectName("lblDateTime");
        lblDateTime->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 13px;\n"
"    color: #757575;\n"
"    background: transparent;\n"
"}"));

        verticalLayout_3->addWidget(lblDateTime);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        frameUserBadge = new QFrame(frameTopBar);
        frameUserBadge->setObjectName("frameUserBadge");
        frameUserBadge->setMinimumSize(QSize(180, 40));
        frameUserBadge->setMaximumSize(QSize(200, 40));
        frameUserBadge->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #e3f2fd;\n"
"    border: 2px solid #1976d2;\n"
"    border-radius: 20px;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(frameUserBadge);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(10, 5, 15, 5);
        lblUserIcon = new QLabel(frameUserBadge);
        lblUserIcon->setObjectName("lblUserIcon");
        lblUserIcon->setMinimumSize(QSize(24, 24));
        lblUserIcon->setMaximumSize(QSize(24, 24));
        lblUserIcon->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    background: transparent;\n"
"    border: none;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));

        horizontalLayout_3->addWidget(lblUserIcon);

        lblUserName = new QLabel(frameUserBadge);
        lblUserName->setObjectName("lblUserName");
        lblUserName->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 13px;\n"
"    font-weight: 600;\n"
"    color: #1565c0;\n"
"    background: transparent;\n"
"    border: none;\n"
"}"));

        horizontalLayout_3->addWidget(lblUserName);


        horizontalLayout_2->addWidget(frameUserBadge);


        verticalLayout_2->addWidget(frameTopBar);

        scrollArea = new QScrollArea(frameMainContent);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"QScrollArea > QWidget > QWidget {\n"
"    background: transparent;\n"
"}\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #f0f0f0;\n"
"    width: 10px;\n"
"    margin: 0px;\n"
"    border-radius: 5px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: #c0c0c0;\n"
"    border-radius: 5px;\n"
"    min-height: 20px;\n"
"}\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #a0a0a0;\n"
"}\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    border: none;\n"
"    background: none;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1058, 648));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(20, 20, 20, 20);
        lblQuickActions = new QLabel(scrollAreaWidgetContents);
        lblQuickActions->setObjectName("lblQuickActions");
        lblQuickActions->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"}"));

        verticalLayout_4->addWidget(lblQuickActions);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(15);
        gridLayout->setObjectName("gridLayout");
        cardTotalAppointments = new QFrame(scrollAreaWidgetContents);
        cardTotalAppointments->setObjectName("cardTotalAppointments");
        cardTotalAppointments->setMinimumSize(QSize(220, 150));
        cardTotalAppointments->setMaximumSize(QSize(300, 180));
        cardTotalAppointments->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #42a5f5, stop:1 #1e88e5);\n"
"    border-radius: 12px;\n"
"    border: none;\n"
"}\n"
"QFrame:hover {\n"
"    margin: -1px;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(cardTotalAppointments);
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(15, 15, 15, 15);
        lblCardIcon1 = new QLabel(cardTotalAppointments);
        lblCardIcon1->setObjectName("lblCardIcon1");
        lblCardIcon1->setMinimumSize(QSize(0, 40));
        lblCardIcon1->setMaximumSize(QSize(16777215, 40));
        lblCardIcon1->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 32px;\n"
"    background: transparent;\n"
"    color: white;\n"
"}"));

        verticalLayout_5->addWidget(lblCardIcon1);

        lblCardTitle1 = new QLabel(cardTotalAppointments);
        lblCardTitle1->setObjectName("lblCardTitle1");
        lblCardTitle1->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    color: rgba(255, 255, 255, 0.95);\n"
"    background: transparent;\n"
"}"));

        verticalLayout_5->addWidget(lblCardTitle1);

        lblCardValue1 = new QLabel(cardTotalAppointments);
        lblCardValue1->setObjectName("lblCardValue1");
        lblCardValue1->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: transparent;\n"
"}"));

        verticalLayout_5->addWidget(lblCardValue1);


        gridLayout->addWidget(cardTotalAppointments, 0, 0, 1, 1);

        cardUpcoming = new QFrame(scrollAreaWidgetContents);
        cardUpcoming->setObjectName("cardUpcoming");
        cardUpcoming->setMinimumSize(QSize(220, 150));
        cardUpcoming->setMaximumSize(QSize(300, 180));
        cardUpcoming->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #66bb6a, stop:1 #43a047);\n"
"    border-radius: 12px;\n"
"    border: none;\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(cardUpcoming);
        verticalLayout_6->setSpacing(10);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(15, 15, 15, 15);
        lblCardIcon2 = new QLabel(cardUpcoming);
        lblCardIcon2->setObjectName("lblCardIcon2");
        lblCardIcon2->setMinimumSize(QSize(0, 40));
        lblCardIcon2->setMaximumSize(QSize(16777215, 40));
        lblCardIcon2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 32px;\n"
"    background: transparent;\n"
"    color: white;\n"
"}"));

        verticalLayout_6->addWidget(lblCardIcon2);

        lblCardTitle2 = new QLabel(cardUpcoming);
        lblCardTitle2->setObjectName("lblCardTitle2");
        lblCardTitle2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    color: rgba(255, 255, 255, 0.95);\n"
"    background: transparent;\n"
"}"));

        verticalLayout_6->addWidget(lblCardTitle2);

        lblCardValue2 = new QLabel(cardUpcoming);
        lblCardValue2->setObjectName("lblCardValue2");
        lblCardValue2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: transparent;\n"
"}"));

        verticalLayout_6->addWidget(lblCardValue2);


        gridLayout->addWidget(cardUpcoming, 0, 1, 1, 1);

        cardDoctors = new QFrame(scrollAreaWidgetContents);
        cardDoctors->setObjectName("cardDoctors");
        cardDoctors->setMinimumSize(QSize(220, 150));
        cardDoctors->setMaximumSize(QSize(300, 180));
        cardDoctors->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #ab47bc, stop:1 #8e24aa);\n"
"    border-radius: 12px;\n"
"    border: none;\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(cardDoctors);
        verticalLayout_7->setSpacing(10);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(15, 15, 15, 15);
        lblCardIcon3 = new QLabel(cardDoctors);
        lblCardIcon3->setObjectName("lblCardIcon3");
        lblCardIcon3->setMinimumSize(QSize(0, 40));
        lblCardIcon3->setMaximumSize(QSize(16777215, 40));
        lblCardIcon3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 32px;\n"
"    background: transparent;\n"
"    color: white;\n"
"}"));

        verticalLayout_7->addWidget(lblCardIcon3);

        lblCardTitle3 = new QLabel(cardDoctors);
        lblCardTitle3->setObjectName("lblCardTitle3");
        lblCardTitle3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    color: rgba(255, 255, 255, 0.95);\n"
"    background: transparent;\n"
"}"));

        verticalLayout_7->addWidget(lblCardTitle3);

        lblCardValue3 = new QLabel(cardDoctors);
        lblCardValue3->setObjectName("lblCardValue3");
        lblCardValue3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: transparent;\n"
"}"));

        verticalLayout_7->addWidget(lblCardValue3);


        gridLayout->addWidget(cardDoctors, 0, 2, 1, 1);

        cardPending = new QFrame(scrollAreaWidgetContents);
        cardPending->setObjectName("cardPending");
        cardPending->setMinimumSize(QSize(220, 150));
        cardPending->setMaximumSize(QSize(300, 180));
        cardPending->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #ff7043, stop:1 #f4511e);\n"
"    border-radius: 12px;\n"
"    border: none;\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(cardPending);
        verticalLayout_8->setSpacing(10);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(15, 15, 15, 15);
        lblCardIcon4 = new QLabel(cardPending);
        lblCardIcon4->setObjectName("lblCardIcon4");
        lblCardIcon4->setMinimumSize(QSize(0, 40));
        lblCardIcon4->setMaximumSize(QSize(16777215, 40));
        lblCardIcon4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 32px;\n"
"    background: transparent;\n"
"    color: white;\n"
"}"));

        verticalLayout_8->addWidget(lblCardIcon4);

        lblCardTitle4 = new QLabel(cardPending);
        lblCardTitle4->setObjectName("lblCardTitle4");
        lblCardTitle4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    color: rgba(255, 255, 255, 0.95);\n"
"    background: transparent;\n"
"}"));

        verticalLayout_8->addWidget(lblCardTitle4);

        lblCardValue4 = new QLabel(cardPending);
        lblCardValue4->setObjectName("lblCardValue4");
        lblCardValue4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background: transparent;\n"
"}"));

        verticalLayout_8->addWidget(lblCardValue4);


        gridLayout->addWidget(cardPending, 0, 3, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        lblRecentActivity = new QLabel(scrollAreaWidgetContents);
        lblRecentActivity->setObjectName("lblRecentActivity");
        lblRecentActivity->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    color: #37474f;\n"
"    background: transparent;\n"
"}"));

        verticalLayout_4->addWidget(lblRecentActivity);

        frameActivityList = new QFrame(scrollAreaWidgetContents);
        frameActivityList->setObjectName("frameActivityList");
        frameActivityList->setMinimumSize(QSize(0, 200));
        frameActivityList->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white;\n"
"    border-radius: 12px;\n"
"    border: 2px solid #e0e0e0;\n"
"}"));
        verticalLayout_9 = new QVBoxLayout(frameActivityList);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        lblActivityInfo = new QLabel(frameActivityList);
        lblActivityInfo->setObjectName("lblActivityInfo");
        lblActivityInfo->setMinimumSize(QSize(0, 180));
        lblActivityInfo->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #9e9e9e;\n"
"    background: transparent;\n"
"    qproperty-alignment: AlignCenter;\n"
"    font-style: italic;\n"
"    line-height: 1.6;\n"
"}"));
        lblActivityInfo->setWordWrap(true);

        verticalLayout_9->addWidget(lblActivityInfo);


        verticalLayout_4->addWidget(frameActivityList);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        horizontalLayout->addWidget(frameMainContent);

        Dashboard->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Dashboard);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1366, 25));
        Dashboard->setMenuBar(menubar);
        statusbar = new QStatusBar(Dashboard);
        statusbar->setObjectName("statusbar");
        Dashboard->setStatusBar(statusbar);

        retranslateUi(Dashboard);

        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QMainWindow *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "MedPlus - Dashboard", nullptr));
        lblLogo->setText(QCoreApplication::translate("Dashboard", "\360\237\217\245", nullptr));
        lblBrandName->setText(QCoreApplication::translate("Dashboard", "MedPlus", nullptr));
        lblTagline->setText(QCoreApplication::translate("Dashboard", "Healthcare Management System", nullptr));
        btnBookAppointment->setText(QCoreApplication::translate("Dashboard", "\360\237\223\205  Book Appointment", nullptr));
        btnMyAppointments->setText(QCoreApplication::translate("Dashboard", "\360\237\223\213  My Appointments", nullptr));
        btnViewSlotAvailability->setText(QCoreApplication::translate("Dashboard", "\360\237\224\215  Check Availability", nullptr));
        btnViewDoctors->setText(QCoreApplication::translate("Dashboard", "\360\237\221\250\342\200\215\342\232\225\357\270\217  View Doctors", nullptr));
        btnMyProfile->setText(QCoreApplication::translate("Dashboard", "\360\237\221\244  My Profile", nullptr));
        btnBilling->setText(QCoreApplication::translate("Dashboard", "\360\237\222\263  Billing", nullptr));
        btnAboutUs->setText(QCoreApplication::translate("Dashboard", "\342\204\271\357\270\217  About Us", nullptr));
        btnExit->setText(QCoreApplication::translate("Dashboard", "\360\237\232\252  Exit Application", nullptr));
        lblFooter->setText(QCoreApplication::translate("Dashboard", "\302\251 2025 MedPlus Healthcare\n"
"v1.0.0", nullptr));
        lblWelcome->setText(QCoreApplication::translate("Dashboard", "Welcome to MedPlus Dashboard", nullptr));
        lblDateTime->setText(QCoreApplication::translate("Dashboard", "Today: Tuesday, October 28, 2025", nullptr));
        lblUserIcon->setText(QCoreApplication::translate("Dashboard", "\360\237\221\244", nullptr));
        lblUserName->setText(QCoreApplication::translate("Dashboard", "User Profile", nullptr));
        lblQuickActions->setText(QCoreApplication::translate("Dashboard", "Dashboard Overview", nullptr));
        lblCardIcon1->setText(QCoreApplication::translate("Dashboard", "\360\237\223\205", nullptr));
        lblCardTitle1->setText(QCoreApplication::translate("Dashboard", "Total Appointments", nullptr));
        lblCardValue1->setText(QCoreApplication::translate("Dashboard", "24", nullptr));
        lblCardIcon2->setText(QCoreApplication::translate("Dashboard", "\342\217\260", nullptr));
        lblCardTitle2->setText(QCoreApplication::translate("Dashboard", "Upcoming Today", nullptr));
        lblCardValue2->setText(QCoreApplication::translate("Dashboard", "3", nullptr));
        lblCardIcon3->setText(QCoreApplication::translate("Dashboard", "\360\237\221\250\342\200\215\342\232\225\357\270\217", nullptr));
        lblCardTitle3->setText(QCoreApplication::translate("Dashboard", "Available Doctors", nullptr));
        lblCardValue3->setText(QCoreApplication::translate("Dashboard", "12", nullptr));
        lblCardIcon4->setText(QCoreApplication::translate("Dashboard", "\342\217\263", nullptr));
        lblCardTitle4->setText(QCoreApplication::translate("Dashboard", "Pending Actions", nullptr));
        lblCardValue4->setText(QCoreApplication::translate("Dashboard", "5", nullptr));
        lblRecentActivity->setText(QCoreApplication::translate("Dashboard", "Recent Activity", nullptr));
        lblActivityInfo->setText(QCoreApplication::translate("Dashboard", "\360\237\223\212 Your recent appointments and activities will appear here\n"
"\n"
"Navigate using the sidebar to manage your healthcare journey\n"
"Book appointments \342\200\242 View doctors \342\200\242 Check availability \342\200\242 Manage billing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
