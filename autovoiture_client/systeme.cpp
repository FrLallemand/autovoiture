#include "systeme.h"

Systeme::Systeme()
{
    QDir path_to_db = QDir::homePath() + QString::fromStdString("/.local/share/autovoiture");

    if(!path_to_db.exists()){
        qDebug() << "Création du dossier.";
        path_to_db.mkpath(".");
    }

    this->db_path = path_to_db.path() + QString("/autovoiture.db");
}

QSqlDatabase Systeme::openDatabase(){
    QSqlDatabase db;

    if(!QSqlDatabase::contains(DB_NAME)){
        db = QSqlDatabase::addDatabase("QSQLITE", DB_NAME);
    }
    else{
        db = QSqlDatabase::database(DB_NAME);
    }

    db.setDatabaseName(this->db_path);

    if(!db.open()){
        qCritical() << "Impossible d'ouvrir la base de données.";
    }
    else{
        return db;
    }

}

void Systeme::addUser(QString username, QString nom, QString prenom, QString adresse, QString rib, QString password){
    QSqlDatabase db = this->openDatabase();

    QSqlQuery create_table_users(db);
    create_table_users.prepare("create table if not exists users("
                               "username varchar(40) primary key,"
                               "name varchar(40),"
                               "firstname varchar(40),"
                               "adresse varchar(200),"
                               "rib varchar(200),"
                               "password varchar(256));");

    if(!create_table_users.exec()){
        qCritical() << "Impossible de créer la table des utilisateurs";
        qCritical() << create_table_users.lastError().text();
    }

    QSqlQuery insert_new_user(db);

    insert_new_user.prepare("insert into users values(?, ?, ?, ?, ?, ?);");
    insert_new_user.addBindValue(username);
    insert_new_user.addBindValue(nom);
    insert_new_user.addBindValue(prenom);
    insert_new_user.addBindValue(adresse);
    insert_new_user.addBindValue(rib);
    insert_new_user.addBindValue(password);

    if(!insert_new_user.exec()){
        qCritical() << insert_new_user.lastError().text();
        qCritical() << insert_new_user.executedQuery();
    }

    db.close();
}

int Systeme::checkPassword(QString username, QString password){
    QSqlDatabase db = this->openDatabase();

    QSqlQuery fetch_user(QString("select username, password from users where username = '%1';").arg(username), db);

    if(!fetch_user.exec()){
        qWarning() << "Impossible de vérifier le mot de passe de l'utilisateur dans la base de données.";
        qWarning() << fetch_user.lastError().text();
    }

    else{
        if(fetch_user.next()){
            if(fetch_user.value("password").toString() != password){
                return Systeme::LoginResult::BAD_PASSWORD;
            }
            else{
                return Systeme::LoginResult::SUCCESS;
            }
        }
        else{
            return Systeme::LoginResult::BAD_USERNAME;
        }
    }

    db.close();
}

QString Systeme::hashPassword(QString password){
    QByteArray ba = QByteArray(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha1));

    QString out = ba.toHex();

    return out;
}
