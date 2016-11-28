#ifndef SYSTEME_H
#define SYSTEME_H

#include <QDir>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlResult>
#include <QCryptographicHash>
#include <QByteArray>

#define DB_NAME "autovoitureDB"
#define SEL_AVANT "pdej$dpzeih"
#define SEL_APRES "jdpoa$$a"

class Systeme
{
public:
    QString hashPassword(QString password);
    int checkPassword(QString username, QString password);

    enum LoginResult{
        SUCCESS,
        BAD_USERNAME,
        BAD_PASSWORD,
    };

    Systeme();

private:
    QString db_path;
    QSqlDatabase openDatabase();
};

#endif // SYSTEME_H
