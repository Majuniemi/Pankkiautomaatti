#include "saldo.h"
#include "ui_saldo.h"
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
{
    ui->setupUi(this);
    ui->labelOption1->setText(" ");
    ui->labelOption2->setText(" ");
    ui->labelOption3->setText(" ");
    ui->labelOption4->setText(" ");
    ui->labelOption5->setText(" ");
    ui->labelOption6->setText(" ");
    ui->labelOption7->setText(" ");
    ui->labelOption8->setText("");

    connect(ui->btStop,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
}

Saldo::~Saldo()
{
    delete ui;
}

void Saldo::commandClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    if (button->objectName()=="btStop"){
        accept();
    }
}

void Saldo::setUsername(const QString &newUsername)
{
    username = newUsername;
}

void Saldo::setToken(const QByteArray &newToken)
{
    token = newToken;
    qDebug()<<"Token Saldo luokassa: "<<token;
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
    }
}
