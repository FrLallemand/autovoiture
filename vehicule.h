#ifndef VEHICULE_H
#define VEHICULE_H

#include <QDate>
#include <string>

using namespace std;

class Vehicule
{
private:
    string modele;
    QDate dernierControleTechnique;
    int prix_horaire;
    int prix_majoration;
    bool dispo;
    string type_vehicule;

public:
    Vehicule(string modele, QDate dernierControleTechnique, int prix_horaire, int prix_majoration, string type_vehicule, bool dispo);
    string getModele();
    QDate getDernierControleTechnique();
    int getPrixHoraire();
    int getPrixMajoration();
    string getTypeVehicule();
    bool isDispo();
};

#endif // VEHICULE_H
