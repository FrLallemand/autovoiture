#ifndef INSCRIPTIONDIALOG_H
#define INSCRIPTIONDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QString>

#include "systeme.h"

namespace Ui {
class InscriptionDialog;
}

class InscriptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InscriptionDialog(QWidget *parent = 0);
    ~InscriptionDialog();

private slots:
    void tryInscription();

private:
    void showError(QString message);
    void setupConnections();
    Ui::InscriptionDialog *ui;
};

#endif // INSCRIPTIONDIALOG_H
