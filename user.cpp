#include "user.h"

User::User()
{

}

User::User(QString username, QString nom, QString prenom, QString adresse, QString rib){
    this->username = username;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->rib = rib;
}

QString User::getUsername(){
    return this->username;
}

QString User::getNom(){
    return this->nom;
}

QString User::getPrenom(){
    return this->prenom;
}

QString User::getAdresse(){
    return this->adresse;
}

QString User::getRib(){
    return this->rib;
}
