#ifndef ADDVEHICULEDIALOG_H
#define ADDVEHICULEDIALOG_H

#include <QDialog>
#include <QErrorMessage>
#include <QDir>
#include <QDateEdit>
#include <QLineEdit>
#include <QAbstractButton>

#include "systeme.h"
#include "mainwindow.h"

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

    void on_b_addChauffeur_accepted();

private:
    Ui::AddVehiculeDialog *ui;
};

#endif // ADDVEHICULEDIALOG_H
