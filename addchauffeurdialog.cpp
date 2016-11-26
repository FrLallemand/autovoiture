#include "addchauffeurdialog.h"
#include "ui_addchauffeurdialog.h"

AddChauffeurDialog::AddChauffeurDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddChauffeurDialog)
{
    ui->setupUi(this);
}

AddChauffeurDialog::~AddChauffeurDialog()
{
    delete ui;
}

void AddChauffeurDialog::on_b_ajouterChauffeur_accepted(){
    Systeme *s = new Systeme();

    QString prenom = ui->le_prenom->text();
    QString nom = ui->le_nom->text();
    QString adresse = ui->le_adresse->text();
    QString rib = ui->le_rib->text();

    QErrorMessage* msg = new QErrorMessage();

    if(prenom.isEmpty()){
        msg->showMessage("Vous devez renseigner le prénom du chauffeur");
    }
    else if(nom.isEmpty()){
        msg->showMessage("Vous devez renseigner le nom du chauffeur.");
    }
    else if(adresse.isEmpty()){
        msg->showMessage("Vous devez renseigner l'adresse du chauffeur.");
    }
    else if(rib.isEmpty()){
        msg->showMessage("Vous devez renseigner le RIB du chauffeur.");
    }
    else{
        s->ajouterChauffeur(prenom, nom, adresse, rib);

        this->close();
    }
}
