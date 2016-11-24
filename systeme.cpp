#include "systeme.h"

Systeme::Systeme()
{
    QDir path_to_db = QDir::homePath() + QString::fromStdString("/.local/share/autovoiture");

    if(!path_to_db.exists()){
        qDebug() << "Création du dossier.";
        path_to_db.mkpath(".");
    }

    this->db_path = path_to_db.path().toStdString() + "/autovoiture.db";
}

void Systeme::ajouterVehicule(string modele, QDate dernierControleTechnique, int prix_horaire, int prix_majoration, string type_vehicule){
    QSqlDatabase db = this->openDatabase();

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

    db.close();
}

vector<Vehicule> Systeme::getVehicules(){
    vector<Vehicule> result;
    QSqlDatabase db = this->openDatabase();

    QSqlQuery fetch_vehicules("select *"
                              "from vehicule;");

    while(fetch_vehicules.next()){
        string modele = fetch_vehicules.value("modele").toString().toStdString();
        QDate dernierCT = fetch_vehicules.value("dernierCT").toDate();
        int prix_horaire = fetch_vehicules.value("prix_horaire").toInt();
        int prix_majoration = fetch_vehicules.value("prix_majoration").toInt();
        string type = fetch_vehicules.value("type").toString().toStdString();

        Vehicule* v = new Vehicule(modele, dernierCT, prix_horaire, prix_majoration, type);
        result.push_back(*v);
    }

    db.close();
    return result;
}

QSqlDatabase Systeme::openDatabase(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(QString::fromStdString(this->db_path));

    if(!db.open()){
        qCritical() << "Impossible d'ouvrir la base de données.";
    }
    else{
        return db;
    }
}
