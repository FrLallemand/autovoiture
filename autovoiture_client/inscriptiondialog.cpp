#include "inscriptiondialog.h"
#include "ui_inscriptiondialog.h"

InscriptionDialog::InscriptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InscriptionDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Inscription");
    this->setupConnections();
}

InscriptionDialog::~InscriptionDialog()
{
    delete ui;
}

void InscriptionDialog::setupConnections(){
    QObject::connect(ui->b_inscription, SIGNAL(clicked()), this, SLOT(tryInscription()));
}

void InscriptionDialog::tryInscription(){
    Systeme* s = new Systeme();

    QString username = ui->le_username->text();
    QString nom = ui->le_name->text();
    QString prenom = ui->le_forname->text();
    QString adresse = ui->le_address->text();
    QString rib = ui->le_rib->text();

    QString password = ui->le_password->text();
    QString passwordConfirm = ui->le_confirmePassword->text();

    if(username.isEmpty()){
        this->showError("Veuillez spécifier un nom d'utilisateur.");
    }
    else if(nom.isEmpty()){
        this->showError("Veuillez spécifier votre nom.");
    }
    else if(prenom.isEmpty()){
        this->showError("Veuillez spécifier votre prénom.");
    }
    else if(adresse.isEmpty()){
        this->showError("Veuillez spécifier votre adresse.");
    }
    else if(rib.isEmpty()){
        this->showError("Veuillez spécifier le rib de l'utilisateur");
    }
    else if(password.isEmpty()){
        this->showError("Veuillez préciser un mot de passe.");
    }
    else if(password != passwordConfirm){
        this->showError("Veuillez saisir deux mots de passe identiques.");
    }
    else{
        QString hashed_password = s->hashPassword(password);
        s->addUser(username, nom, prenom, adresse, rib, hashed_password);

        this->close();
    }
}

void InscriptionDialog::showError(QString message){
    ui->l_errorInfos->setText(message);
    ui->l_errorInfos->setStyleSheet("color: red;");
}
