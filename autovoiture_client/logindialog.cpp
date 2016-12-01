#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Connexion");
    this->setConnections();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::setConnections(){
    QObject::connect(this, SIGNAL(finished(int)), this->parentWidget(), SLOT(close()));
    QObject::connect(ui->b_connection, SIGNAL(clicked()), this, SLOT(checkPassword()));
    QObject::connect(ui->b_inscription, SIGNAL(clicked()), this, SLOT(inscription()));
}

void LoginDialog::inscription(){
    InscriptionDialog* id = new InscriptionDialog();

    id->exec();
}

void LoginDialog::checkPassword(){
    Systeme* s = new Systeme();

    QString username = ui->le_username->text();
    QString password = s->hashPassword(ui->le_password->text());
    int result = s->checkPassword(username, password);

    switch (result) {
    case Systeme::LoginResult::BAD_USERNAME:
        ui->l_erreurMessage->setText("L'utilisateur saisi n'existe pas.");
        ui->l_erreurMessage->setStyleSheet("color: red;");
        break;
    case Systeme::LoginResult::BAD_PASSWORD:
        ui->l_erreurMessage->setText("Le mot de passe est erroné.");
        ui->l_erreurMessage->setStyleSheet("color: red;");
        break;
    case Systeme::LoginResult::SUCCESS:
        QObject::disconnect(this, SIGNAL(finished(int)), this->parentWidget(), SLOT(close()));
        emit loginSuccess(username);
        this->close();
    default:
        break;
    }
}
