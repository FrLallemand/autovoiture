#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Autovoiture");
    this->setAffiche("Nothing");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b_addVehicule_clicked()
{
    AddVehiculeDialog* avd = new AddVehiculeDialog(this);

    avd->exec();

    if(this->getAffiche() == "Vehicule")
        this->ui->b_listVehicule->click();
}

void MainWindow::resizeEvent(QResizeEvent *event){
    if(this->getAffiche() != "Nothing"){
        this->resetHeaderViewSize();
    }
}

void MainWindow::on_b_listVehicule_clicked()
{
    if(this->getAffiche() != "Vehicule"){
        this->setTvForVehicules();
    }

    Systeme* s = new Systeme();

    QVector<Vehicule> vehicules;

    vehicules = s->getVehicules();

    this->setTvForVehicules();

    for(int i = 0; i < vehicules.size(); i++){
        ui->tvMain->setRowCount(ui->tvMain->rowCount() + 1);
        ui->tvMain->setItem(i, COLONNE_ID, new QTableWidgetItem(QString::number(vehicules[i].getId())));
        ui->tvMain->setItem(i, COLONNE_MODELE, new QTableWidgetItem(QString::fromStdString(vehicules[i].getModele())));
        ui->tvMain->setItem(i, COLONNE_LASTCT, new QTableWidgetItem(vehicules[i].getDernierControleTechnique().toString()));
        ui->tvMain->setItem(i, COLONNE_PRIXH, new QTableWidgetItem(QString::number(vehicules[i].getPrixHoraire())));
        ui->tvMain->setItem(i, COLONNE_PRIXM, new QTableWidgetItem(QString::number(vehicules[i].getPrixMajoration())));
        ui->tvMain->setItem(i, COLONNE_TYPE, new QTableWidgetItem(QString::fromStdString(vehicules[i].getTypeVehicule())));

        if(vehicules[i].isDispo()){
            QTableWidgetItem* item_dispo = new QTableWidgetItem("Disponible");
            item_dispo->setBackgroundColor(QColor(0, 255, 0));
            ui->tvMain->setItem(i, COLONNE_DISPO, item_dispo);
        }
        else{
            QTableWidgetItem* item_indispo = new QTableWidgetItem("Indisponible");
            item_indispo->setBackgroundColor(QColor(255, 0, 0));
            ui->tvMain->setItem(i, COLONNE_DISPO, item_indispo);
        }
    }

    this->setAffiche("Vehicule");
    this->resetHeaderViewSize();
}

void MainWindow::setTvForVehicules(){
    this->clearTable();
    ui->tvMain->setColumnCount(NUM_COLONNE_VEH);

    ui->tvMain->setHorizontalHeaderLabels(QString("ID;Modèle;Dernier CT;Prix Horaire;Prix Majoration;Type Véhicule;Disponible").split(";"));
}

void MainWindow::setTvForChauffeurs(){
    this->clearTable();
    ui->tvMain->setColumnCount(4);

    ui->tvMain->setHorizontalHeaderLabels(QString("Prénom;Nom;Adresse;RIB").split(";"));
}

void MainWindow::clearTable(){
    ui->tvMain->clear();
    ui->tvMain->setRowCount(0);
    ui->tvMain->setColumnCount(0);
}

void MainWindow::resetHeaderViewSize(){
    int columnSize = ui->tvMain->width() / ui->tvMain->columnCount();

    for(int i = 0; i < ui->tvMain->columnCount(); i++){
        ui->tvMain->horizontalHeader()->resizeSection(i, columnSize);
    }
}

void MainWindow::on_b_ajouterChauffeur_clicked()
{
    AddChauffeurDialog* acd = new AddChauffeurDialog();

    acd->exec();

    if(this->getAffiche() == "Chauffeur")
        this->ui->b_listeChauffeurs->click();
}

void MainWindow::on_b_listeChauffeurs_clicked()
{
    if(this->getAffiche() != "Chauffeur"){
        Systeme* s = new Systeme();

        QVector<Chauffeur> chauffeurs = s->getChauffeurs();

        this->setTvForChauffeurs();

        for(int i = 0; i < chauffeurs.size(); i++){
            ui->tvMain->setRowCount(ui->tvMain->rowCount() + 1);

            ui->tvMain->setItem(i, 0, new QTableWidgetItem(chauffeurs[i].getPrenom()));
            ui->tvMain->setItem(i, 1, new QTableWidgetItem(chauffeurs[i].getNom()));
            ui->tvMain->setItem(i, 2, new QTableWidgetItem(chauffeurs[i].getAdresse()));
            ui->tvMain->setItem(i, 3, new QTableWidgetItem(chauffeurs[i].getRib()));
        }

        this->resetHeaderViewSize();
        this->setAffiche("Chauffeur");
    }
}

QString MainWindow::getAffiche(){
    return this->affiche;
}

void MainWindow::setAffiche(QString a){
    this->affiche = a;
}

void MainWindow::on_tvMain_cellDoubleClicked(int row, int column)
{

}
