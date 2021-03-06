#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHeaderView>
#include <QDebug>
#include <QTableView>
#include <QTableWidget>
#include <QColor>
#include <QVector>
#include <QResizeEvent>
#include <QPushButton>
#include <QSet>
#include <QVariant>
#include <QString>

#include <iostream>

#include "addvehiculedialog.h"
#include "addchauffeurdialog.h"
#include "systeme.h"
#include "vehicule.h"
#include "chauffeur.h"

//Constant related to vehicule displaying
#define COLONNE_ID 0
#define COLONNE_MODELE 1
#define COLONNE_LASTCT 2
#define COLONNE_PRIXH 3
#define COLONNE_PRIXM 4
#define COLONNE_TYPE 5
#define COLONNE_DISPO 6
#define NUM_COLONNE_VEH 7

//Constants related to user displaying
#define COLONNE_USER_USERNAME 0
#define COLONNE_USER_NOM 1
#define COLONNE_USER_FIRSTNAME 2
#define COLONNE_USER_ADRESSE 3
#define COLONNE_USER_RIB 4

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString getAffiche();
    void setAffiche(QString a);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_b_addVehicule_clicked();
    void on_b_listVehicule_clicked();
    void on_b_listeChauffeurs_clicked();
    void deleteSelectedElements();
    void on_tvMain_cellDoubleClicked(int row, int column);
    void on_b_ajouterChauffeur_clicked();
    void toggleDeleteButton();

    void on_b_utilisateurs_clicked();

    void on_tvMain_cellClicked(int row, int column);

private:
    QString affiche;
    void resizeEvent(QResizeEvent *event);
    void setupConnections();
    void resetHeaderViewSize();
    void setTvForVehicules();
    void clearTable();
    void setTvForChauffeurs();
    void setTvForUsers();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
