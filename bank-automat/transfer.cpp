#include "transfer.h"
#include "ui_transfer.h"

Transfer::Transfer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Transfer)
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
    ui->labelPrompt->setText("Syötä tili jolle haluat siirtää rahaa");
    ui->labelInput->setText(" ");

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

Transfer::~Transfer()
{
    delete ui;
}

void Transfer::numberClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());


    if(button){
        QLabel *currentEdit = ui->labelInput;
        currentEdit->setText(currentEdit->text() + button->text());
    }
}

void Transfer::commandClickHandler()
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
        QLabel *currentLabel = ui->labelInput;                                  //Cancel napin painallus poistaa viimeisimmän merkin
        QString currentText = currentLabel->text();
        currentLabel->setText(currentLabel->text());
        if (!currentText.isEmpty()) {                                                   //kunhan summassa on jotain
            currentText.chop(1);
            currentLabel->setText(currentText);
        }
    }
    else if (button->objectName()=="btAccept"){
        QLabel *currentLabel2 = ui->labelInput_2;                                  //Cancel napin painallus poistaa viimeisimmän merki
        QString currentText2 = currentLabel2->text();
        currentLabel2->setText(currentLabel2->text());
        if (!currentText2.isEmpty()) {
            //kunhan summassa on jotain
            QLabel *currentLabel = ui->labelInput;                                  //tarkistetaan onko syötettyä tiliä olemassa
            QString currentText = currentLabel->text();
            currentText="FI"+currentText.trimmed();
            qDebug()<<"miltä tilinumeronäyttää: "<<currentText.trimmed();
            saavatilinumero=currentText;
        onTiliButtonClicked(currentText);

        }else{

        QString siirto = ui->labelInput->text();
        if(luottoraja.toDouble()==0.0){
            if(saldo.toDouble()>(siirto.toDouble()*muuntokerroin.toDouble())+((siirto.toDouble()*muuntokerroin.toDouble())*npprosentti.toDouble())+npeuro.toDouble()){
            ui->labelPrompt->setText("Siirsit");
            ui->labelInput->setText(siirto +" euroa");
            tilimiinus=saldo.toDouble()-((siirto.toDouble()*muuntokerroin.toDouble())+((siirto.toDouble()*muuntokerroin.toDouble())*npprosentti.toDouble())+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            upSaldo(saavatilinumero, siirto);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, siirto, username);
            uusiTilitapahtuma(aikaleima, siirto, saavatilinumero);

            }else{
               ui->labelPrompt->setText("Tilin Saldo ei riitä");
            }
        }else{
            if(luottoraja.toDouble()>(siirto.toDouble()*muuntokerroin.toDouble())+((siirto.toDouble()*muuntokerroin.toDouble())*npprosentti.toDouble())+npeuro.toDouble()+saldo.toDouble()){
            ui->labelPrompt->setText("Siirsit");
            ui->labelInput->setText(siirto +" euroa");
            tilimiinus=saldo.toDouble()+((siirto.toDouble()*muuntokerroin.toDouble())+((siirto.toDouble()*muuntokerroin.toDouble())*npprosentti.toDouble())+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            upSaldo(saavatilinumero, siirto);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, siirto, username);
            uusiTilitapahtuma(aikaleima, siirto, saavatilinumero);

            }else{
               ui->labelPrompt->setText("Tilin Luotto ei riitä");
            }
        }
        }

    }

}

void Transfer::setUsername(const QString &newUsername)
{
    username = newUsername;
    qDebug()<<"Username Mainmenu luokassa: "<<username;
}

void Transfer::setToken(const QByteArray &newToken)
{
    token = newToken;
    qDebug()<<"Token Mainmenu luokassa: "<<token;
}
void Transfer::showUsername()
{
     ui->labelInput->setText(username);
}

void Transfer::onNostoButtonClicked(QString tilinumero)
{
    QString site_url="http://localhost:3000/Tili/getSaldo/"+tilinumero;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getNostoSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void Transfer::getNostoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString Saldo =json_obj["saldo"].toString();
    saldo=Saldo;

    qDebug()<<"Tallennettu saldo luokassa: "<<saldo;
    // ui->labelInput->setText(Saldo);
    reply->deleteLater();
    getManager->deleteLater();
   }


void Transfer::onLuottorajaButtonClicked(QString tilinumero)
{
    QString site_url="http://localhost:3000/Tili/getLuottoraja/"+tilinumero;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getLuottorajaSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void Transfer::getLuottorajaSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString Luottoraja =json_obj["luottoraja"].toString();
    luottoraja = Luottoraja.isEmpty() ? "0.00" : Luottoraja;
   // ui->labelInput->setText(Luottoraja);


    qDebug()<<"Tallennettu luottoraja luokassa: "<<luottoraja;
    reply->deleteLater();
    getManager->deleteLater();
   }

void Transfer::onNpeuroButtonClicked(QString tilinumero)
{
    QString site_url="http://localhost:3000/Tili/getNostopalkkioeuro/"+tilinumero;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getNpeuroSlot(QNetworkReply*)));

    reply = getManager->get(request);
}
void Transfer::getNpeuroSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString Npeuro =json_obj["NPEuro"].toString();
//    ui->labelInput_4->setText(Npeuro);
    npeuro = Npeuro.isEmpty() ? "0.00" : Npeuro;

    qDebug()<<"Tallennettu npeuro luokassa: "<<npeuro;
    reply->deleteLater();
    getManager->deleteLater();
   }
void Transfer::onNpprosenttiButtonClicked(QString tilinumero)
{
    QString site_url="http://localhost:3000/Tili/getNostopalkkioprosentti/"+tilinumero;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getNpprosenttiSlot(QNetworkReply*)));

    reply = getManager->get(request);
}
void Transfer::getNpprosenttiSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString Npprosentti =json_obj["NPProsentti"].toString();
 //   ui->labelInput_5->setText(Npprosentti);
    npprosentti = Npprosentti.isEmpty() ? "0.00" : Npprosentti;

    qDebug()<<"Tallennettu nppprosentti luokassa: "<<npprosentti;
    reply->deleteLater();
    getManager->deleteLater();
   }

void Transfer::onMuuntokerroinButtonClicked(QString tilinumero)
{
    QString site_url="http://localhost:3000/Tili/getMuuntokerroin/"+tilinumero;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getMuuntokerroinSlot(QNetworkReply*)));

    reply = getManager->get(request);
}
void Transfer::getMuuntokerroinSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    response_data = response_data.trimmed();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QJsonValue kurssiValue = json_obj.value("kurssi");
    QString Muuntokerroin = kurssiValue.isDouble() ? QString::number(kurssiValue.toDouble()) : kurssiValue.toString();

    qDebug() << "JSON-objekti: " << json_obj;
 //   ui->labelInput_6->setText(Muuntokerroin);

    qDebug()<<"tuleva muuntokerroin luokassa: "<<Muuntokerroin;
    muuntokerroin=Muuntokerroin;
    qDebug()<<"Tallennettu muuntokerroin luokassa: "<<muuntokerroin;
    reply->deleteLater();
    getManager->deleteLater();
   }
void Transfer::upSaldo(QString id, QString newSaldo) {
    QString site_url = "http://localhost:3000/Tili/updateSaldo/" + id + "/" + newSaldo;
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Content-Type"), "application/json");

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU

    connect(manager, &QNetworkAccessManager::finished, [=](QNetworkReply* reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
            QJsonObject jsonObj = jsonDoc.object();

            // Käsittele vastaus tässä, jos tarpeen
            QString message = jsonObj["message"].toString();
            qDebug() << message;
        } else {
            qDebug() << "Virhe: " << reply->errorString();
        }

        reply->deleteLater();
        manager->deleteLater();
    });
    manager->put(request, QByteArray());
}
void Transfer::onTiliButtonClicked(QString tilinumero)
{
    QString site_url="http://localhost:3000/Tili/getTili/"+tilinumero;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);
    qDebug() << "tilinumero kyselyssä: " << tilinumero;
    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getTiliSlot(QNetworkReply*)));

    reply = getManager->get(request);
}
void Transfer::getTiliSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    response_data = response_data.trimmed();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    siirtokohde = json_obj.value("count").toInt();

    qDebug() << "JSON-objekti: " << json_obj;

    qDebug() << "siirtokohde: " << siirtokohde;



    if (siirtokohde==1){
        ui->labelPrompt->setText("Syötä siirrettävä määrä");
        ui->labelInput_2->setText("");
        ui->labelInput->setText("");
    }else{
        ui->labelInput_2->setText("");
        ui->labelInput->setText("Tilinumero virheellinen");
    }

    reply->deleteLater();
    getManager->deleteLater();
}

void Transfer::uusiTilitapahtuma(QDateTime aikaleima, QString saldoMuutos, QString idTili) {
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, [=](QNetworkReply* reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
            QJsonObject jsonObj = jsonDoc.object();

            QString message = jsonObj["message"].toString();
            qDebug() << message;
        } else {
            qDebug() << "Virhe: " << reply->errorString();
        }

        reply->deleteLater();
        manager->deleteLater();
    });

    QUrl url("http://localhost:3000/Tili/uusiTilitapahtuma");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    QUrlQuery postData;
    postData.addQueryItem("Aikaleima", aikaleima.toString(Qt::ISODate));
    postData.addQueryItem("Saldomuutos", saldoMuutos);
    postData.addQueryItem("Muutoslaji", "Siirto");
    postData.addQueryItem("idTili", idTili);
    postData.addQueryItem("Paikkatieto", "ATM");

    QByteArray postDataByteArray = postData.toString(QUrl::FullyEncoded).toUtf8();
    manager->post(request, postDataByteArray);
}
