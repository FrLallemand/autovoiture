#ifndef ADDCHAUFFEURDIALOG_H
#define ADDCHAUFFEURDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QErrorMessage>
#include <QString>
#include <QAbstractButton>

#include "systeme.h"

namespace Ui {
class AddChauffeurDialog;
}

class AddChauffeurDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddChauffeurDialog(QWidget *parent = 0);
    ~AddChauffeurDialog();

private slots:
    void on_b_ajouterChauffeur_accepted();

private:
    Ui::AddChauffeurDialog *ui;
};

#endif // ADDCHAUFFEURDIALOG_H
