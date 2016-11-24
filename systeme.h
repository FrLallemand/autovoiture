#ifndef SYSTEME_H
#define SYSTEME_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <QDir>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "vehicule.h"

using namespace std;

class Systeme
{
private:
    string db_path;
public:
    Systeme();
    void ajouterVehicule(string modele, QDate dernierControleTechnique, int prix_horaire, int prix_majoration, string type_vehicule);
    QSqlDatabase openDatabase();
    vector<Vehicule> getVehicules();
};

#endif // SYSTEME_H
