#include "saldo.h"
#include "ui_saldo.h"
<<<<<<< HEAD
Saldo::Saldo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Saldo)
=======
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QDialog>

Saldo::Saldo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Saldo)
>>>>>>> 993d7f0bcf4b48ca59e5c850c957238396dca991
{
    ui->setupUi(this);
    ui->labelOption1->setText(" ");
    ui->labelOption2->setText(" ");
    ui->labelOption3->setText(" ");
    ui->labelOption4->setText(" ");
    ui->labelOption5->setText(" ");
    ui->labelOption6->setText(" ");
    ui->labelOption7->setText(" ");
<<<<<<< HEAD
    ui->labelOption8->setText("Takaisin");
    ui->labelPrompt->setText("Saldo");
    ui->labelInput->setText(" ");
   /* QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "my_mysql_connection");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("BankSimul_R9");
    db.setUserName("r9user");
    db.setPassword("r9pass");
    if (!db.open()) {
    qDebug() << "SALDO Tietokantayhteyden avaaminen epäonnistui:" << db.lastError().text();
    }*/  // ripulia? aluksi ollu käytössä
    connect(ui->btNum1,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum2,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum3,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum4,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum5,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum6,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum7,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum8,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum9,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum0,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
=======
    ui->labelOption8->setText("");


>>>>>>> 993d7f0bcf4b48ca59e5c850c957238396dca991
    connect(ui->btOption1,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption2,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption3,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption4,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption5,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption6,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption7,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption8,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btStop,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btCancel,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btAccept,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
}
<<<<<<< HEAD
=======

>>>>>>> 993d7f0bcf4b48ca59e5c850c957238396dca991
Saldo::~Saldo()
{
    delete ui;
}
<<<<<<< HEAD
void Saldo::showSaldo(QString value)
{
    ui->labelInput->setText(value);
}
void Saldo::setSaldoo(const QString &newSaldoo)
{
    Saldoo = newSaldoo;
    ui->labelInput->setText(Saldoo);
}
void Saldo::numberClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if(button){
    QLabel *currentEdit = ui->labelInput;
    currentEdit->setText(currentEdit->text() + button->text());
    }
} /*
void Saldo::naytaSaldo()
{
    QSqlQuery query(db);
    query.prepare("SELECT Saldo FROM `banksimul_r9`.`tili`");
    if (query.exec() && query.next()) {
    QString Saldo = query.value(0).toString();
    qDebug() << "SALDO " << Saldo;
    ui->labelPrompt->setText("Tilin saldo: " + Saldo);
    } else {
    qDebug() << "SALDO Tietokantakysely epäonnistui: " << query.lastError().text();
    }
}*/  // ripulia?
void Saldo::commandClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if (button->objectName()=="btOption1"){
    }
    else if (button->objectName()=="btOption2"){
    }
    else if (button->objectName()=="btOption3"){
    }
    else if (button->objectName()=="btOption4"){
    }
    else if (button->objectName()=="btOption5"){
    }
    else if (button->objectName()=="btOption6"){
    }
    else if (button->objectName()=="btOption7"){
    }
    else if (button->objectName()=="btOption8"){
        QWidget *OlioTakaisin = new Mainmenu(this);
        OlioTakaisin->showFullScreen();
=======

void Saldo::commandClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    if (button->objectName()=="btOption1"){

    }
    else if (button->objectName()=="btOption2"){

    }
    else if (button->objectName()=="btOption3"){

    }
    else if (button->objectName()=="btOption4"){

    }
    else if (button->objectName()=="btOption5"){

    }
    else if (button->objectName()=="btOption6"){

    }
    else if (button->objectName()=="btOption7"){

    }
    else if (button->objectName()=="btOption8"){

>>>>>>> 993d7f0bcf4b48ca59e5c850c957238396dca991
    }
    else if (button->objectName()=="btStop"){
        accept();
    }
    else if (button->objectName()=="btCancel"){
<<<<<<< HEAD
    }
    else if (button->objectName()=="btAccept"){
=======

    }
    else if (button->objectName()=="btAccept"){

    }
}

void Saldo::setUsername(const QString &newUsername)
{
    username = newUsername;

}

void Saldo::showUsername()
{
    ui->labelInput->setText(username);
}
/*
void Saldo::setSaldo(const QString &newSaldo)
{
    saldo = newSaldo;

    qDebug()<<"Tallennettu saldo luokassa: "<<saldo;
}

void Saldo::showSaldo()
{
    ui->labelInput->setText(saldo);
}*/
void Saldo::setToken(const QByteArray &newToken)
{
    token = newToken;
    qDebug()<<"Token Mainmenu luokassa: "<<&token;
}
void Saldo::onSaldoButtonClicked(QString tilinumero)
{
    QString site_url="http://localhost:3000/Tili/getSaldo/"+tilinumero;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getSaldoSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void Saldo::getSaldoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString Saldo =json_obj["saldo"].toString();
    ui->labelInput->setText(Saldo);
    reply->deleteLater();
    getManager->deleteLater();
   }
/*
void Saldo::setValuutta(const QString &newValuutta)
{
    valuutta = newValuutta;

    qDebug()<<"Tallennettu valuutta luokassa: "<<valuutta;
}

void Saldo::showValuutta()
{
    ui->labelInput2->setText(valuutta);
}*/

void Saldo::onValuuttaButtonClicked(QString tilinumero)
{
    QString site_url="http://localhost:3000/Tili/getValuutta/"+tilinumero;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getValuuttaSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void Saldo::getValuuttaSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString Valuutta =json_obj["valuutta"].toString();
    ui->labelInput2->setText(Valuutta);
    reply->deleteLater();
    getManager->deleteLater();
   }
void Saldo::setKieli(const int &newKieli)
{
    kieli = newKieli;
    qDebug()<<"Kieli Saldo luokassa: "<<kieli;
    if (kieli==1){
    ui->labelPrompt->setText("Tilin saldo on");
    }else if (kieli==2){
    ui->labelPrompt->setText("Kontosaldot är");
    }else if (kieli==3){
        ui->labelPrompt->setText("The account balance is");
    }else{
        ui->labelPrompt->setText("The account balance is");
         qDebug()<<"Kieli ui:ssa saldo luokassa: "<<kieli;
>>>>>>> 993d7f0bcf4b48ca59e5c850c957238396dca991
    }
}
