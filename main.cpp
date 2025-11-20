#include "mainwindow.h"
#include "databasemanager.h"
#include <QApplication>
#include <QPalette>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ✅ Force Fusion style (better for theming)
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    // ✅ Light Palette
    QPalette lightPalette;
    lightPalette.setColor(QPalette::Window, QColor(240, 240, 240));
    lightPalette.setColor(QPalette::WindowText, Qt::black);
    lightPalette.setColor(QPalette::Base, Qt::white);
    lightPalette.setColor(QPalette::AlternateBase, QColor(225, 225, 225));
    lightPalette.setColor(QPalette::ToolTipBase, Qt::white);
    lightPalette.setColor(QPalette::ToolTipText, Qt::black);
    lightPalette.setColor(QPalette::Text, Qt::black);
    lightPalette.setColor(QPalette::Button, QColor(240, 240, 240));
    lightPalette.setColor(QPalette::ButtonText, Qt::black);
    lightPalette.setColor(QPalette::BrightText, Qt::red);

    a.setPalette(lightPalette);

    // ✅ Set your SQLite database path here
    DatabaseManager dbManager("C:/Users/Supriya/ClinicsAppointment.db");

    if (!dbManager.open()) {
        qDebug() << "❌ Database connection failed!";
        return -1;
    }
    MainWindow w;
    w.show();
    return a.exec();
}
