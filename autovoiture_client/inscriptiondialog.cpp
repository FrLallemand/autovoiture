#include "inscriptiondialog.h"
#include "ui_inscriptiondialog.h"

InscriptionDialog::InscriptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InscriptionDialog)
{
    ui->setupUi(this);
}

InscriptionDialog::~InscriptionDialog()
{
    delete ui;
}
