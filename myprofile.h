#ifndef MYPROFILE_H
#define MYPROFILE_H

#include <QDialog>

namespace Ui {
class MyProfile;
}

class MyProfile : public QDialog
{
    Q_OBJECT

public:
    explicit MyProfile(const QString &patientId, QWidget *parent = nullptr);
    ~MyProfile();

private slots:
    void onEditProfileClicked();

private:
    Ui::MyProfile *ui;
    QString m_patientId;

    void setupConnections();
    void loadPatientData();
};

#endif // MYPROFILE_H
