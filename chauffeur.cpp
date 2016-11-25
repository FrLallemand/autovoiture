#include "chauffeur.h"

Chauffeur::Chauffeur()
{

}

Chauffeur::Chauffeur(QString prenom, QString nom, QString adresse, QString rib){
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
