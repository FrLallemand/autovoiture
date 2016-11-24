#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHeaderView>
#include <QDebug>
#include <QTableView>
#include <QTableWidget>
#include <QColor>
#include <QResizeEvent>

#include <vector>

#include "addvehiculedialog.h"
#include "systeme.h"
#include "vehicule.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_b_addVehicule_clicked();

    void on_b_listVehicule_clicked();

private:
    void resizeEvent(QResizeEvent *event);
    void resetHeaderViewSize();
    void setTvForVehicules();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
