#ifndef ADDVEHICULEDIALOG_H
#define ADDVEHICULEDIALOG_H

#include <QDialog>
#include <QDir>
#include "systeme.h"
#include <QDateEdit>
#include <QLineEdit>
#include <QAbstractButton>

namespace Ui {
class AddVehiculeDialog;
}

class AddVehiculeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddVehiculeDialog(QWidget *parent = 0);
    ~AddVehiculeDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::AddVehiculeDialog *ui;
};

#endif // ADDVEHICULEDIALOG_H
