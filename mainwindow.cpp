#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Autovoiture");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b_addVehicule_clicked()
{
    AddVehiculeDialog* avd = new AddVehiculeDialog(this);

    avd->show();
}

void MainWindow::on_b_listVehicule_clicked()
{
    Systeme* s = new Systeme();

    vector<Vehicule> vehicules;

    vehicules = s->getVehicules();

    this->setTvForVehicules();

    for(int i = 0; i < vehicules.size(); i++){
        ui->tvMain->setRowCount(ui->tvMain->rowCount() + 1);
        ui->tvMain->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(vehicules[i].getModele())));
        ui->tvMain->setItem(i, 1, new QTableWidgetItem(vehicules[i].getDernierControleTechnique().toString()));
        ui->tvMain->setItem(i, 2, new QTableWidgetItem(QString::number(vehicules[i].getPrixHoraire())));
        ui->tvMain->setItem(i, 3, new QTableWidgetItem(QString::number(vehicules[i].getPrixMajoration())));
        ui->tvMain->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(vehicules[i].getTypeVehicule())));
    }
 }

void MainWindow::setTvForVehicules(){
    ui->tvMain->setColumnCount(5);

    ui->tvMain->setHorizontalHeaderLabels(QString("Modèle;Dernier CT;Prix Horaire;Prix Majoration;Type Véhicule").split(";"));
}
