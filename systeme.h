#ifndef SYSTEME_H
#define SYSTEME_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVector>
#include <QDebug>
#include <QDate>
#include <QDir>
#include <QString>

#include <iostream>
#include <string>
#include <sstream>

#include "vehicule.h"
#include "chauffeur.h"

using namespace std;

class Systeme
{
private:
    string db_path;
public:
    Systeme();
    void ajouterVehicule(string modele, QDate dernierControleTechnique, int prix_horaire, int prix_majoration, string type_vehicule);
    void ajouterChauffeur(QString prenom, QString nom, QString adresse, QString rib);
    QSqlDatabase openDatabase();
    QVector<Vehicule> getVehicules();
    QVector<Chauffeur> getChauffeurs();
};

#endif // SYSTEME_H
