#include "aboutus.h"
#include "ui_aboutus.h"

AboutUs::AboutUs(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutUs)
{
    ui->setupUi(this);
    setupConnections();
}

AboutUs::~AboutUs()
{
    delete ui;
}

void AboutUs::setupConnections()
{
    connect(ui->btnBack, &QPushButton::clicked, this, &QDialog::close);
}
