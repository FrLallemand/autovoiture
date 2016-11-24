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

void MainWindow::resizeEvent(QResizeEvent *event){
    if(ui->tvMain->columnCount() > 0){
        this->resetHeaderViewSize();
    }
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

        if(vehicules[i].isDispo()){
            QTableWidgetItem* item_dispo = new QTableWidgetItem("Disponible");
            item_dispo->setBackgroundColor(QColor(0, 255, 0));
            ui->tvMain->setItem(i, 5, item_dispo);
        }
        else{
            QTableWidgetItem* item_indispo = new QTableWidgetItem("Indisponible");
            item_indispo->setBackgroundColor(QColor(255, 0, 0));
            ui->tvMain->setItem(i, 5, item_indispo);
        }
    }

    this->resetHeaderViewSize();
}

void MainWindow::setTvForVehicules(){
    ui->tvMain->setColumnCount(6);

    ui->tvMain->setHorizontalHeaderLabels(QString("Modèle;Dernier CT;Prix Horaire;Prix Majoration;Type Véhicule;Disponible").split(";"));
}

void MainWindow::resetHeaderViewSize(){
    int columnSize = ui->tvMain->width() / ui->tvMain->columnCount();

    for(int i = 0; i < ui->tvMain->colorCount(); i++){
        ui->tvMain->horizontalHeader()->resizeSection(i, columnSize);
    }
}
