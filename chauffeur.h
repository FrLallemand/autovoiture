#ifndef CHAUFFEUR_H
#define CHAUFFEUR_H

#include <QString>

class Chauffeur
{
private:
    int id;
    QString prenom;
    QString nom;
    QString adresse;
    QString rib;

public:
    Chauffeur();
    Chauffeur(int id, QString prenom, QString nom, QString adresse, QString rib);

    int getId();
    QString getPrenom();
    QString getNom();
    QString getAdresse();
    QString getRib();
};

#endif // CHAUFFEUR_H
