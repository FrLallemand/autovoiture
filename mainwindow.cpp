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
