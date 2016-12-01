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
                         "dispo integer,"
                         "type varchar(40));");

    if(!create_table.exec()){
        qCritical() << "Impossible de créer la table vehicule";
        qCritical() << create_table.lastError().text();
    }

    QSqlQuery insert_vehicule(db);
    insert_vehicule.prepare("insert into vehicule values(:modele, :dernierCT, :prix_horaire, :prix_majoration, :dispo, :type);");
    insert_vehicule.bindValue(":modele", QString::fromStdString(modele));
    insert_vehicule.bindValue(":dernierCT", dernierControleTechnique.toString());
    insert_vehicule.bindValue(":prix_horaire", prix_horaire);
    insert_vehicule.bindValue(":prix_majoration", prix_majoration);
    insert_vehicule.bindValue(":dispo", 1);
    insert_vehicule.bindValue(":type", QString::fromStdString(type_vehicule));

    if(!insert_vehicule.exec()){
        qCritical() << "Impossible d'insérer le véhicule";
        qCritical() << insert_vehicule.lastError().text();
    }

    db.close();
}

void Systeme::ajouterChauffeur(QString prenom, QString nom, QString adresse, QString rib){
    QSqlDatabase db = this->openDatabase();

    QSqlQuery create_table(db);
    create_table.prepare("create table if not exists chauffeur("
                         "prenom varchar(40),"
                         "nom varchar(40),"
                         "adresse varchar(200),"
                         "rib varchar(200));");

    if(!create_table.exec()){
        qCritical() << "Impossible de créer la table chauffeur";
        qCritical() << create_table.lastError().text();
    }

    QSqlQuery insert_chauffeur(db);
    insert_chauffeur.prepare("insert into chauffeur values(:prenom, :nom, :adresse, :rib);");
    insert_chauffeur.bindValue(":prenom", prenom);
    insert_chauffeur.bindValue(":nom", nom);
    insert_chauffeur.bindValue(":adresse", adresse);
    insert_chauffeur.bindValue(":rib", rib);

    if(!insert_chauffeur.exec()){
        qCritical() << "Impossible d'insérer le chauffeur dans la base de données";
        qCritical() << insert_chauffeur.lastError().text();
    }

    db.close();
}

QVector<Vehicule> Systeme::getVehicules(){
    QVector<Vehicule> result;
    QSqlDatabase db = this->openDatabase();

    QSqlQuery fetch_vehicules("select ROWID, *"
                              "from vehicule;", db);


    while(fetch_vehicules.next()){
        int id = fetch_vehicules.value("ROWID").toInt();
        string modele = fetch_vehicules.value("modele").toString().toStdString();
        QDate dernierCT = QDate::fromString(fetch_vehicules.value("dernierCT").toString());
        int prix_horaire = fetch_vehicules.value("prix_horaire").toInt();
        int prix_majoration = fetch_vehicules.value("prix_majoration").toInt();
        string type = fetch_vehicules.value("type").toString().toStdString();
        bool dispo = fetch_vehicules.value("dispo").toBool();

        Vehicule* v = new Vehicule(id, modele, dernierCT, prix_horaire, prix_majoration, type, dispo);
        result.push_back(*v);
    }

    db.close();
    return result;
}

void Systeme::deleteChauffeur(int i){
    QSqlDatabase db = this->openDatabase();

    QSqlQuery delete_c_query(db);
    delete_c_query.prepare("delete from chauffeur where ROWID=:id;");
    delete_c_query.bindValue(":id", i);

    if(!delete_c_query.exec()){
        qCritical() << "Impossible de supprimer le chauffeur";
        qCritical() << delete_c_query.lastError().text();
    }

    db.close();
}

void Systeme::deleteVehicule(int i){
    QSqlDatabase db = this->openDatabase();

    QSqlQuery delete_v_query(db);
    delete_v_query.prepare("delete from vehicule where ROWID=:id;");
    delete_v_query.bindValue(":id", i);

    if(!delete_v_query.exec()){
        qCritical() << "Impossible de supprimer le véhicule";
        qCritical() << delete_v_query.lastError().text();
    }

    db.close();
}

void Systeme::deleteUtilisateur(QString username){
    qDebug() << "on supprime l'utilisateur " << username;
    QSqlDatabase db = this->openDatabase();

    QSqlQuery delete_u_query(db);
    delete_u_query.prepare("delete from users where username=:username;");
    delete_u_query.bindValue(":username", username);

    if(!delete_u_query.exec()){
        qCritical() << "Impossible de supprimer l'utilisateur";
        qCritical() << delete_u_query.lastError().text();
    }

    db.close();
}

QVector<Chauffeur> Systeme::getChauffeurs(){
    QVector<Chauffeur> result;

    QSqlDatabase db = this->openDatabase();
    QSqlQuery fetch_chauffeurs("select ROWID, *"
                               "from chauffeur;", db);

    if(!fetch_chauffeurs.exec()){
        qDebug() << "La récupération des chauffeurs a échoué";
        qDebug() << fetch_chauffeurs.lastError().text();
    }

    while(fetch_chauffeurs.next()){
        int id = fetch_chauffeurs.value("ROWID").toInt();
        QString prenom = fetch_chauffeurs.value("prenom").toString();
        QString nom = fetch_chauffeurs.value("nom").toString();
        QString adresse = fetch_chauffeurs.value("adresse").toString();
        QString rib = fetch_chauffeurs.value("rib").toString();

        Chauffeur* c = new Chauffeur(id, prenom, nom, adresse, rib);
        result.push_back(*c);
    }

    db.close();
    return result;
}

QVector<User> Systeme::getUsers(){
    QVector<User> result;

    QSqlDatabase db = this->openDatabase();
    QSqlQuery fetch_users("select *"
                          "from users;", db);

    if(!fetch_users.exec()){
        qCritical() << "La récupération des utilisateurs a échoué";
        qCritical() << fetch_users.lastError().text();
    }

    while(fetch_users.next()){
        QString username = fetch_users.value("username").toString();
        QString name = fetch_users.value("name").toString();
        QString prenom = fetch_users.value("firstname").toString();
        QString adresse = fetch_users.value("adresse").toString();
        QString rib = fetch_users.value("rib").toString();

        User* u = new User(username, name, prenom, adresse, rib);
        result.push_back(*u);
    }

    db.close();
    return result;
}

QSqlDatabase Systeme::openDatabase(){
    QSqlDatabase db;

    if(!QSqlDatabase::contains(DB_NAME)){
        db = QSqlDatabase::addDatabase("QSQLITE", DB_NAME);
    }
    else{
        db = QSqlDatabase::database(DB_NAME);
    }

    db.setDatabaseName(QString::fromStdString(this->db_path));

    if(!db.open()){
        qCritical() << "Impossible d'ouvrir la base de données.";
    }
    else{
        return db;
    }
}

bool Systeme::toggleVehicule(int id, bool dispo){
    QSqlDatabase db = this->openDatabase();

    QSqlQuery toggle_dispo(db);
    toggle_dispo.prepare("update vehicule set dispo = :new_dispo where ROWID=:id;");
    toggle_dispo.bindValue(":new_dispo", !dispo);
    toggle_dispo.bindValue(":id", id);

    if(!toggle_dispo.exec()){
        qCritical() << "Impossible de rendre disponible/indisponible le véhicule";
        qCritical() << toggle_dispo.lastError().text();
    }

    return !dispo;
}
