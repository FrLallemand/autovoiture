#ifndef CHAUFFEUR_H
#define CHAUFFEUR_H

#include <QString>

class Chauffeur
{
private:
    QString prenom;
    QString nom;
    QString adresse;
    QString rib;

public:
    Chauffeur();
    Chauffeur(QString prenom, QString nom, QString adresse, QString rib);

    QString getPrenom();
    QString getNom();
    QString getAdresse();
    QString getRib();
};

#endif // CHAUFFEUR_H
