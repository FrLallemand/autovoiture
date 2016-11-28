#ifndef INSCRIPTIONDIALOG_H
#define INSCRIPTIONDIALOG_H

#include <QDialog>

namespace Ui {
class InscriptionDialog;
}

class InscriptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InscriptionDialog(QWidget *parent = 0);
    ~InscriptionDialog();

private:
    Ui::InscriptionDialog *ui;
};

#endif // INSCRIPTIONDIALOG_H
