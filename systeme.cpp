#include "systeme.h"

Systeme::Systeme(string p_db_path)
{
    this->db_path = p_db_path;
}

void Systeme::ajouterVehicule(string modele, QDate dernierControleTechnique, int prix_horaire, int prix_majoration, string type_vehicule){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(QString::fromStdString(this->db_path));

    if(!db.open()){
        qCritical() << "Impossible d'ouvrir la base de données.";
    }

    QSqlQuery create_table(db);
    create_table.prepare("create table if not exists vehicule("
                         "modele varchar(40),"
                         "dernierCT varchar(40),"
                         "prix_horaire integer,"
                         "prix_majoration integer,"
                         "type varchar(40));");

    if(!create_table.exec()){
        qCritical() << "Impossible de créer la table";
        qCritical() << create_table.lastError().text();
    }

    QSqlQuery insert_vehicule(db);
    insert_vehicule.prepare("insert into vehicule values(:modele, :dernierCT, :prix_horaire, :prix_majoration, :type);");
    insert_vehicule.bindValue(":modele", QString::fromStdString(modele));
    insert_vehicule.bindValue(":dernierCT", dernierControleTechnique.toString());
    insert_vehicule.bindValue(":prix_horaire", prix_horaire);
    insert_vehicule.bindValue(":prix_majoration", prix_majoration);
    insert_vehicule.bindValue(":type", QString::fromStdString(type_vehicule));

    if(!insert_vehicule.exec()){
        qCritical() << "Impossible d'insérer le véhicule";
        qCritical() << insert_vehicule.lastError().text();
    }
}
