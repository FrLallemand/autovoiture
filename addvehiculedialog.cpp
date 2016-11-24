#include "addvehiculedialog.h"
#include "ui_addvehiculedialog.h"

AddVehiculeDialog::AddVehiculeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddVehiculeDialog)
{
    ui->setupUi(this);
}

AddVehiculeDialog::~AddVehiculeDialog()
{
    delete ui;
}

void AddVehiculeDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDir path_to_db = QDir::homePath() + QString::fromStdString("/.local/share/autovoiture");

    if(!path_to_db.exists()){
        qDebug() << "Création du dossier.";
        path_to_db.mkpath(".");
    }

    Systeme* s = new Systeme(path_to_db.path().toStdString() + "/autovoiture.db");

    QString modele = this->ui->le_Modele->text();
    QDate dernierCt = this->ui->de_dernierCt->date();

    QString prixHoraire = this->ui->le_prixHoraire->text();
    QString prixMajo = this->ui->le_prixMajo->text();
    QString typeVehicule = this->ui->cb_typevehicule->currentText();

    QErrorMessage* msg = new QErrorMessage();

    if(dernierCt > QDate::currentDate()){
        msg->showMessage("Date invalide.");
    }
    else if(prixHoraire <= 0){
        msg->showMessage("Le prix horaire du véhicule doit être supérieur à 0.");
    }
    else if(prixHoraire <= 0){
        msg->showMessage("Le prix de la majoration doit être supérieur à 0.");
    }
    else{
        s->ajouterVehicule(modele.toStdString(), dernierCt, prixHoraire.toInt(), prixMajo.toInt(), typeVehicule.toStdString());
        this->close();
    }
}
