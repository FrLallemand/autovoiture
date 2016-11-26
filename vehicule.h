#ifndef VEHICULE_H
#define VEHICULE_H

#include <QDate>
#include <string>

using namespace std;

class Vehicule
{
private:
    int id;
    string modele;
    QDate dernierControleTechnique;
    int prix_horaire;
    int prix_majoration;
    bool dispo;
    string type_vehicule;

public:
    Vehicule();
    Vehicule(int id, string modele, QDate dernierControleTechnique, int prix_horaire, int prix_majoration, string type_vehicule, bool dispo);
    int getId();
    string getModele();
    QDate getDernierControleTechnique();
    int getPrixHoraire();
    int getPrixMajoration();
    string getTypeVehicule();
    bool isDispo();
};

#endif // VEHICULE_H
