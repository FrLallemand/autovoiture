#ifndef SYSTEME_H
#define SYSTEME_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Systeme
{
private:
    string db_path;
public:
    Systeme(string p_db_path);
    void ajouterVehicule(string modele, QDate dernierControleTechnique, int prix_horaire, int prix_majoration, string type_vehicule);
};

#endif // SYSTEME_H
