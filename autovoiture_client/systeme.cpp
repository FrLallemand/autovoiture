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

int Systeme::checkPassword(QString username, QString password){
    QSqlDatabase db = this->openDatabase();

    QSqlQuery fetch_user(db);

    fetch_user.prepare("SELECT username, password FROM users WHERE username=:username;");
    fetch_user.bindValue(":username", username);

    if(!fetch_user.exec()){
        qWarning() << "Impossible de vérifier le mot de passe de l'utilisateur dans la base de données.";
        qWarning() << fetch_user.lastError().text();
    }
    else{
        qDebug() << "On a" << fetch_user.size() << " utilisateurs avec le nom d'utilisateur " << username;
        if(fetch_user.size() == -1){
            return Systeme::LoginResult::BAD_USERNAME;
        }
        else{
            fetch_user.nextResult();
            if(fetch_user.value("password").toString() != password){
                return Systeme::LoginResult::BAD_PASSWORD;
            }
            else{
                return Systeme::LoginResult::SUCCESS;
            }
        }
    }
}

QString Systeme::hashPassword(QString password){
    QByteArray ba = QCryptographicHash::hash(QByteArray(QCryptographicHash::hash(QString(SEL_AVANT).toUtf8(), QCryptographicHash::Md5) +
                                                        QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5) +
                                                        QCryptographicHash::hash(QString(SEL_APRES).toUtf8(), QCryptographicHash::Md5)),
                                             QCryptographicHash::Sha1);

    QString out = ba.toHex();

    return out;
}
