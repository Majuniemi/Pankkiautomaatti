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
    ui->labelPrompt->setText("Tilin saldo on");




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

Saldo::~Saldo()
{
    delete ui;
}

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

    }
    else if (button->objectName()=="btStop"){
        accept();
    }
    else if (button->objectName()=="btCancel"){

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

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getSaldoSlot(QNetworkReply*)));

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

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getValuuttaSlot(QNetworkReply*)));

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
