#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>             // For QSqlDatabase, QSqlQuery, etc.
#include "registration.h"
#include "dashboard.h"
#include "bookappointment.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoginClicked();
    void onRegisterClicked();
    void onExitClicked();
    void openBookAppointment();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
