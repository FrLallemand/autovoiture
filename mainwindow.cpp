#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->toggleDeleteButton();
    this->setupConnections();
    this->setWindowTitle("Autovoiture");
    this->setAffiche("Nothing");
}

void MainWindow::setupConnections(){
    QObject::connect(ui->tvMain, SIGNAL(itemSelectionChanged()), this, SLOT(toggleDeleteButton()));
}

void MainWindow::toggleDeleteButton(){
    if(ui->tvMain->selectedItems().empty()){
        ui->b_supprimerElement->setStyleSheet("background-color: white; color: grey;");
        QObject::disconnect(ui->b_supprimerElement, SIGNAL(clicked()), this, SLOT(deleteSelectedElements()));
    }
    else{
        ui->b_supprimerElement->setStyleSheet("background-color: red; color: white;");
        QObject::connect(ui->b_supprimerElement, SIGNAL(clicked()), this, SLOT(deleteSelectedElements()));
    }
}

void MainWindow::deleteSelectedElements(){
    if(this->getAffiche() == "Vehicule" || this->getAffiche() == "Chauffeur"){
        QSet<int> set;


        for(int i = 0; i < ui->tvMain->selectedItems().size(); i++){
            int row = ui->tvMain->selectedItems().at(i)->row();
            int id = ui->tvMain->item(row, 0)->text().toInt();

            set.insert(id);
        }

        Systeme* s = new Systeme();

        foreach (const int& i, set) {
            if(this->getAffiche() == "Vehicule"){
                s->deleteVehicule(i);
            }
            else if(this->getAffiche() == "Chauffeur"){
                s->deleteChauffeur(i);
            }
        }
    }
    else if(this->getAffiche() == "Utilisateurs"){
        QSet<QString> set;

        for(int i = 0; i < ui->tvMain->selectedItems().size(); i++){
            set.insert(ui->tvMain->itemAt(0, ui->tvMain->selectedItems().at(i)->row())->text());
        }

        Systeme* s = new Systeme();

        foreach (const QString user, set) {
            s->deleteUtilisateur(user);
        }
    }


    if(this->getAffiche() == "Vehicule"){
        ui->b_listVehicule->click();
    }
    else if(this->getAffiche() == "Chauffeur"){
        ui->b_listeChauffeurs->click();
    }
    else if(this->getAffiche() == "Utilisateurs"){
        ui->b_utilisateurs->click();
    }
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
        QTableWidgetItem* item_id = new QTableWidgetItem(QString::number(vehicules[i].getId()));
        item_id->setFlags(item_id->flags() ^ Qt::ItemIsEditable);
        item_id->setFlags(item_id->flags() ^ Qt::ItemIsSelectable);
        ui->tvMain->setItem(i, COLONNE_ID, item_id);
        ui->tvMain->setItem(i, COLONNE_MODELE, new QTableWidgetItem(QString::fromStdString(vehicules[i].getModele())));
        ui->tvMain->setItem(i, COLONNE_LASTCT, new QTableWidgetItem(vehicules[i].getDernierControleTechnique().toString()));
        ui->tvMain->setItem(i, COLONNE_PRIXH, new QTableWidgetItem(QString::number(vehicules[i].getPrixHoraire())));
        ui->tvMain->setItem(i, COLONNE_PRIXM, new QTableWidgetItem(QString::number(vehicules[i].getPrixMajoration())));
        ui->tvMain->setItem(i, COLONNE_TYPE, new QTableWidgetItem(QString::fromStdString(vehicules[i].getTypeVehicule())));

        if(vehicules[i].isDispo()){
            QTableWidgetItem* item_dispo = new QTableWidgetItem("Disponible");
            item_dispo->setBackgroundColor(QColor(0, 255, 0));
            item_dispo->setFlags(item_dispo->flags() & ~Qt::ItemIsEditable);
            item_dispo->setFlags(item_dispo->flags() & ~Qt::ItemIsSelectable);
            ui->tvMain->setItem(i, COLONNE_DISPO, item_dispo);
        }
        else{
            QTableWidgetItem* item_indispo = new QTableWidgetItem("Indisponible");
            item_indispo->setFlags(item_indispo->flags() & ~Qt::ItemIsEditable);
            item_indispo->setFlags(item_indispo->flags() & ~Qt::ItemIsSelectable);
            item_indispo->setBackgroundColor(QColor(255, 0, 0));
            ui->tvMain->setItem(i, COLONNE_DISPO, item_indispo);
        }
    }

    this->setAffiche("Vehicule");
    this->resetHeaderViewSize();
}

void MainWindow::on_b_listeChauffeurs_clicked()
{
    Systeme* s = new Systeme();

    QVector<Chauffeur> chauffeurs = s->getChauffeurs();

    this->setTvForChauffeurs();

    for(int i = 0; i < chauffeurs.size(); i++){
        ui->tvMain->setRowCount(ui->tvMain->rowCount() + 1);

        ui->tvMain->setItem(i, 0, new QTableWidgetItem(QString::number(chauffeurs[i].getId())));
        ui->tvMain->setItem(i, 1, new QTableWidgetItem(chauffeurs[i].getPrenom()));
        ui->tvMain->setItem(i, 2, new QTableWidgetItem(chauffeurs[i].getNom()));
        ui->tvMain->setItem(i, 3, new QTableWidgetItem(chauffeurs[i].getAdresse()));
        ui->tvMain->setItem(i, 4, new QTableWidgetItem(chauffeurs[i].getRib()));
    }

    this->resetHeaderViewSize();
    this->setAffiche("Chauffeur");
}

void MainWindow::setTvForVehicules(){
    this->clearTable();
    ui->tvMain->setColumnCount(NUM_COLONNE_VEH);

    ui->tvMain->setHorizontalHeaderLabels(QString("ID;Modèle;Dernier CT;Prix Horaire;Prix Majoration;Type Véhicule;Disponible").split(";"));
}

void MainWindow::setTvForChauffeurs(){
    this->clearTable();
    ui->tvMain->setColumnCount(5);

    ui->tvMain->setHorizontalHeaderLabels(QString("ID;Prénom;Nom;Adresse;RIB").split(";"));
}

void MainWindow::setTvForUsers(){
    this->clearTable();
    ui->tvMain->setColumnCount(5);

    ui->tvMain->setHorizontalHeaderLabels(QString("Username;Nom;Prénom;Adresse;RIB").split(";"));
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

    if(this->getAffiche() == "Chauffeur"){
        this->ui->b_listeChauffeurs->click();
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
    Systeme* s = new Systeme();

    if(this->getAffiche() == "Vehicule"){
        if(column == COLONNE_DISPO){
            int id = ui->tvMain->item(row, 0)->text().toInt();

            QTableWidgetItem* item_dispo = ui->tvMain->item(row, column);

            if(item_dispo->text() == "Disponible"){
                s->toggleVehicule(id, true);
                item_dispo->setText("Indisponible");
                item_dispo->setBackgroundColor(QColor(255, 0, 0));
            }
            else{
                s->toggleVehicule(id, false);
                item_dispo->setText("Disponible");
                item_dispo->setBackground(QColor(0, 255, 0));
            }
        }
    }
}

void MainWindow::on_b_utilisateurs_clicked()
{
    if(this->getAffiche() != "Utilisateurs"){
        this->setTvForUsers();
    }

    Systeme* s = new Systeme();

    QVector<User> users;

    users = s->getUsers();

    this->setTvForUsers();

    for(int i = 0; i < users.size(); i++){
        ui->tvMain->setRowCount(ui->tvMain->rowCount() + 1);
        ui->tvMain->setItem(i, COLONNE_USER_USERNAME, new QTableWidgetItem(users[i].getUsername()));
        ui->tvMain->setItem(i, COLONNE_USER_NOM, new QTableWidgetItem(users[i].getNom()));
        ui->tvMain->setItem(i, COLONNE_USER_FIRSTNAME, new QTableWidgetItem(users[i].getPrenom()));
        ui->tvMain->setItem(i, COLONNE_USER_ADRESSE, new QTableWidgetItem(users[i].getAdresse()));
        ui->tvMain->setItem(i, COLONNE_USER_RIB, new QTableWidgetItem(users[i].getRib()));
    }

    this->setAffiche("Utilisateurs");

    this->resetHeaderViewSize();
}

void MainWindow::on_tvMain_cellClicked(int row, int column)
{
    //Cell clicked
}
