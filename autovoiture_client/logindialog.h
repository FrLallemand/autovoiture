#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QObject>
#include <QPushButton>
#include <QString>
#include <QLineEdit>
#include <QLabel>

#include "mainwindow.h"
#include "systeme.h"
#include "inscriptiondialog.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

signals:
    void loginSuccess(QString);

private slots:
    void checkPassword();
    void inscription();

private:
    void setConnections();
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
