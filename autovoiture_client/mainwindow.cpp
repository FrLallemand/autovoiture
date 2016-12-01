#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->displayLogin();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayLogin(){
    LoginDialog* ld = new LoginDialog(this);

    QObject::connect(ld, SIGNAL(loginSuccess(QString)), this, SLOT(loginDone(QString)));
    ld->show();
}

void MainWindow::loginDone(QString username){
    qDebug("plop");
}
