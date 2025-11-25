#include "viewdoctors.h"
#include "ui_viewdoctors.h"
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

ViewDoctors::ViewDoctors(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewDoctors)
{
    ui->setupUi(this);
    // Load doctors data into cards
    loadDoctorsData();
    connect(ui->pushButtonBackViewDoctors, &QPushButton::clicked, this, &QDialog::close);
}

ViewDoctors::~ViewDoctors()
{
    delete ui;
}

void ViewDoctors::loadDoctorsData()
{
    // Sample doctor data (hardcoded for demo; replace with DB query if needed)
    QList<QVariantMap> doctors = {
        {{"id", "D001"}, {"name", "Dr. Arjun Mehta"}, {"specialty", "General Physician"}, {"contact", "9876543210"}, {"email", "arjun.mehta@clinic.com"}},
        {{"id", "D002"}, {"name", "Dr. Priya Nair"}, {"specialty", "Dentist"}, {"contact", "9876543211"}, {"email", "priya.nair@clinic.com"}},
        {{"id", "D003"}, {"name", "Dr. Rohit Kapoor"}, {"specialty", "Pediatrician"}, {"contact", "9876543212"}, {"email", "rohit.kapoor@clinic.com"}},
        {{"id", "D004"}, {"name", "Dr. Neha Sharma"}, {"specialty", "Gynecologist"}, {"contact", "9876543213"}, {"email", "neha.sharma@clinic.com"}},
        {{"id", "D005"}, {"name", "Dr. Karan Deshmukh"}, {"specialty", "Orthopedic"}, {"contact", "9876543214"}, {"email", "karan.deshmukh@clinic.com"}}
    };

    // Get the vertical layout from the scroll area's widget
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    if (!layout) {
        layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
        ui->scrollAreaWidgetContents->setLayout(layout);
    }

    // Create a card for each doctor
    for (const QVariantMap &doctor : doctors) {
        QFrame *card = new QFrame();
        card->setStyleSheet(
            "QFrame {"
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #ffffff, stop:1 #f8f9fa);"
            "border: 1px solid #e0e0e0;"
            "border-radius: 12px;"
            "padding: 15px;"
            "}"
            "QFrame:hover {"
            "border: 2px solid #42a5f5;"
            "}"
            );
        card->setMinimumHeight(150);  // Changed from setFixedHeight to setMinimumHeight
        card->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

        // Horizontal layout for card content
        QHBoxLayout *cardLayout = new QHBoxLayout(card);
        cardLayout->setContentsMargins(10, 10, 10, 10);
        cardLayout->setSpacing(15);

        // Icon label (doctor emoji)
        QLabel *iconLabel = new QLabel("👨‍⚕️");
        iconLabel->setStyleSheet("font-size: 48px; background: transparent;");
        iconLabel->setAlignment(Qt::AlignCenter);
        iconLabel->setFixedSize(80, 80);
        cardLayout->addWidget(iconLabel);

        // Vertical layout for text details
        QVBoxLayout *textLayout = new QVBoxLayout();
        textLayout->setSpacing(5);

        QLabel *nameLabel = new QLabel(doctor["name"].toString());
        nameLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #1976d2; background: transparent;");
        nameLabel->setWordWrap(true);

        QLabel *specialtyLabel = new QLabel("Specialty: " + doctor["specialty"].toString());
        specialtyLabel->setStyleSheet("font-size: 14px; color: #37474f; background: transparent;");
        specialtyLabel->setWordWrap(true);

        QLabel *contactLabel = new QLabel("Contact: " + doctor["contact"].toString());
        contactLabel->setStyleSheet("font-size: 14px; color: #37474f; background: transparent;");
        contactLabel->setWordWrap(true);

        QLabel *emailLabel = new QLabel("Email: " + doctor["email"].toString());
        emailLabel->setStyleSheet("font-size: 13px; color: #546e7a; background: transparent;");
        emailLabel->setWordWrap(true);

        textLayout->addWidget(nameLabel);
        textLayout->addWidget(specialtyLabel);
        textLayout->addWidget(contactLabel);
        textLayout->addWidget(emailLabel);
        textLayout->addStretch();

        cardLayout->addLayout(textLayout, 1);  // Give text layout stretch factor
        cardLayout->addStretch();  // Push content to the left

        // Add card to the scroll area's layout
        layout->addWidget(card);
    }

    layout->addStretch();  // Add stretch at the end to push cards to top
}
