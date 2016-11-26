#ifndef VEHICULE_H
#define VEHICULE_H

#include <QDate>
#include <string>

using namespace std;

/*!
 * \brief La classe véhicule représente un véhicule et les informations qui lui sont associées
 */
class Vehicule
{
private:
    int id; //! \var Identifiant unique du véhicule
    string modele; //! \var Modèle du véhicule
    QDate dernierControleTechnique; //! \var Date du dernier contrôle technique
    int prix_horaire; //! \var Prix horaire de la location du véhicule
    int prix_majoration; //! \var Prix horaire de la majoration si le véhicule est rendu en retard
    bool dispo; //! \var Disponibilité du véhicule
    string type_vehicule; //! \var Type de véhicule : voiture, vélo ou bus

public:
    /*!
     * \brief Constructeur vide de \c Vehicule
     */
    Vehicule();

    /*!
     * \brief Constructeur de \c Vehicule qui prend en paramètres toutes les informations de ce véhicule
     * \param id Identifiant unique du véhicule
     * \param modele Modèle du véhicule
     * \param dernierControleTechnique Date du dernier contrôle technique
     * \param prix_horaire Prix horaire de la location du véhicule
     * \param prix_majoration Prix horaire de majoration si le véhicule est rendu en retard
     * \param type_vehicule Type de véhicule
     * \param dispo Disponibilité du véhicule
     */
    Vehicule(int id, string modele, QDate dernierControleTechnique, int prix_horaire, int prix_majoration, string type_vehicule, bool dispo);

    /*!
     * \brief Identifiant unique du véhicule
     * \return Un \c int
     */
    int getId();

    /*!
     * \brief Modèle du véhicule
     * \return Une \c string
     */
    string getModele();

    /*!
     * \brief Date du dernier contrôle technique
     * \return Une \c QDate
     */
    QDate getDernierControleTechnique();

    /*!
     * \brief Prix horaire de la location du véhicule
     * \return Un \c int
     */
    int getPrixHoraire();

    /*!
     * \brief Prix horaire de la majoration si le véhicule est rendu en retard
     * \return Un \c int
     */
    int getPrixMajoration();

    /*!
     * \brief Type de véhicule
     * \return un \c string
     */
    string getTypeVehicule();

    /*!
     * \brief Disponibilité du véhicule
     * \return Un booléen à vrai si le véhicule est en service, à faux sinon.
     */
    bool isDispo();
};

#endif // VEHICULE_H
