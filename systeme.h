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

#define DB_NAME "autovoitureDB"
using namespace std;

/*!
 * \brief La classe \c Systeme est la classe qui permet d'intéragir avec les données enregistrées dans la base de données.
 */
class Systeme
{
private:
    string db_path;
public:
    /*!
     * \brief Le constructeur de Systeme créé le dossier où sera stocké la base de données.
     */
    Systeme();

    /*!
     * \brief Insère un véhicule dans la base de données
     * \param modele modèle du dernier véhicule
     * \param dernierControleTechnique date du dernier contrôle technique
     * \param prix_horaire prix horaire de la location du véhicule
     * \param prix_majoration prix horaire de la majoration si le véhicule est rendu en retard
     * \param type_vehicule type de véhicule : voiture, vélo ou bus
     * \details Quand le véhicule est ajouté, il est rendu disponible par défaut.
     * \see \ref Vehicule
     */
    void ajouterVehicule(string modele, QDate dernierControleTechnique, int prix_horaire, int prix_majoration, string type_vehicule);

    /*!
     * \brief Insère un chauffeur dans la base de données
     * \param prenom Prénom du chauffeur
     * \param nom Nom du chauffeur
     * \param adresse Adresse du chauffeur
     * \param rib RIB du chauffeur
     */
    void ajouterChauffeur(QString prenom, QString nom, QString adresse, QString rib);

    /*!
     * \brief Récupère l'ensemble des véhicules dans la base de données.
     * \return Un ensemble de \ref Vehicule
     */
    QVector<Vehicule> getVehicules();

    /*!
     * \brief Récupère l'ensemble des chauffeurs dans la base de données.
     * \return Un ensemble de \ref Chauffeur
     */
    QVector<Chauffeur> getChauffeurs();

    /*!
     * \brief Ouvre la base de données ou la récupère si elle est déjà ouverte
     * \return Une \c QSqlDatabase
     */
    QSqlDatabase openDatabase();
};

#endif // SYSTEME_H
