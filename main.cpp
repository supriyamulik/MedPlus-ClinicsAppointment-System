#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Force light theme for entire application
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    palette.setColor(QPalette::WindowText, Qt::black);
    palette.setColor(QPalette::Base, Qt::white);
    palette.setColor(QPalette::Text, Qt::black);
    palette.setColor(QPalette::Button, QColor(240, 240, 240));
    palette.setColor(QPalette::ButtonText, Qt::black);
    palette.setColor(QPalette::Light, Qt::white);
    palette.setColor(QPalette::Midlight, QColor(240, 240, 240));
    palette.setColor(QPalette::Dark, QColor(200, 200, 200));
    palette.setColor(QPalette::Mid, QColor(220, 220, 220));
    palette.setColor(QPalette::Shadow, Qt::black);
    a.setPalette(palette);

    // Setup database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Supriya/ClinicsAppointment.db");

    if(!db.open()) {
        QMessageBox::critical(nullptr, "Database Error",
                              "Failed to open database: " + db.lastError().text());
        qDebug() << "Database Error:" << db.lastError().text();
        return -1;
    } else {
        qDebug() << "Database connected successfully!";
    }

    MainWindow w;
    w.show();
    return a.exec();
}
