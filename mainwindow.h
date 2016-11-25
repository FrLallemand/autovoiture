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

#include "addvehiculedialog.h"
#include "addchauffeurdialog.h"
#include "systeme.h"
#include "vehicule.h"
#include "chauffeur.h"

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

    void on_b_ajouterChauffeur_clicked();

    void on_b_listeChauffeurs_clicked();

private:
    QString affiche;
    void resizeEvent(QResizeEvent *event);
    void resetHeaderViewSize();
    void setTvForVehicules();
    void setTvForChauffeurs();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
