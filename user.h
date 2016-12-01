#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User();
    User(QString username, QString nom, QString prenom, QString adresse, QString rib);

    QString getUsername();
    QString getNom();
    QString getPrenom();
    QString getAdresse();
    QString getRib();

private:
    QString username;
    QString nom;
    QString prenom;
    QString adresse;
    QString rib;
};

#endif // USER_H
