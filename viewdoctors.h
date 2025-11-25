#ifndef VIEWDOCTORS_H
#define VIEWDOCTORS_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class ViewDoctors;
}

class ViewDoctors : public QDialog
{
    Q_OBJECT

public:
    explicit ViewDoctors(QWidget *parent = nullptr);
    ~ViewDoctors();

private:
    Ui::ViewDoctors *ui;
    void loadDoctorsData();   // helper function to populate table

};

#endif // VIEWDOCTORS_H
