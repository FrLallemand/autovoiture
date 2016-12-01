#include "chauffeur.h"

Chauffeur::Chauffeur()
{

}

Chauffeur::Chauffeur(int id, QString prenom, QString nom, QString adresse, QString rib){
    this->id = id;
    this->prenom = prenom;
    this->nom = nom;
    this->adresse = adresse;
    this->rib = rib;
}

QString Chauffeur::getPrenom(){
    return this->prenom;
}

QString Chauffeur::getNom(){
    return this->nom;
}

QString Chauffeur::getAdresse(){
    return this->adresse;
}

QString Chauffeur::getRib(){
    return this->rib;
}

int Chauffeur::getId(){
    return this->id;
}
