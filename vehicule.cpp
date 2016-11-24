#include "vehicule.h"

Vehicule::Vehicule(string modele, QDate dernierControleTechnique, int prix_horaire, int prix_majoration, string type_vehicule){
    this->modele = modele;
    this->dernierControleTechnique = dernierControleTechnique;
    this->prix_horaire = prix_horaire;
    this->prix_majoration = prix_majoration;
    this->type_vehicule = type_vehicule;
}

string Vehicule::getModele(){
    return this->modele;
}

QDate Vehicule::getDernierControleTechnique(){
    return this->dernierControleTechnique;
}

int Vehicule::getPrixHoraire(){
    return this->prix_horaire;
}

int Vehicule::getPrixMajoration(){
    return this->prix_majoration;
}

string Vehicule::getTypeVehicule(){
    return this->type_vehicule;
}
