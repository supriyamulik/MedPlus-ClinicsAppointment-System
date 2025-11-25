#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Registration;
class Dashboard;
class AdminPanel;
class DoctorPanel;

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

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db;

    // Helper function to check user type and open appropriate panel
    void openUserPanel(const QString &username, const QString &userType, int userId);
};

#endif // MAINWINDOW_H
