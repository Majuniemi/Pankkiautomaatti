#include "withdraw.h"
#include "ui_withdraw.h"

Withdraw::Withdraw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Withdraw)
{
    ui->setupUi(this);
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

Withdraw::~Withdraw()
{
    delete ui;
}

void Withdraw::numberClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    if(muusumma == 1){
    if(button){
        QLabel *currentEdit = ui->labelInput;
        QString buttonName = button->objectName();                                      // teksti vaihdettu kuvaan, joten otetaan arvo nimestä
        QString lastCharacter = buttonName.right(1);
        currentEdit->setText(currentEdit->text() + lastCharacter);
    }
    }
}

void Withdraw::commandClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    if (button->objectName()=="btOption1"){
    if(luottoraja.toDouble()==0.0){
        if(saldo.toDouble()>(20.0*muuntokerroin.toDouble())+((20*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()){
        QString teksti = ui->textStorage1->text();
        ui->labelPrompt->setText(teksti);
        ui->labelInput->setText("20 Euro");
        ui->labelInput2->setText("");
        tilimiinus=saldo.toDouble()-(20.0*muuntokerroin.toDouble())+((20*muuntokerroin.toDouble())*(npprosentti.toDouble()/100)+npeuro.toDouble());
        saldo = QString::number(tilimiinus);
        upSaldo(username, saldo);
        aikaleima = QDateTime::currentDateTime();
        uusiTilitapahtuma(aikaleima, "20.00", username);
        }else{
            QString teksti = ui->textStorage2->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText("");
            ui->labelInput2->setText("");
        }
    }else{
        if(luottoraja.toDouble()>(20.0*muuntokerroin.toDouble())+((20*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()+saldo.toDouble()){
        QString teksti = ui->textStorage1->text();
        ui->labelPrompt->setText(teksti);
        ui->labelInput->setText("20 Euro");
        ui->labelInput2->setText("");
        tilimiinus=saldo.toDouble()+((20.0*muuntokerroin.toDouble())+((20*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
        saldo = QString::number(tilimiinus);
        upSaldo(username, saldo);
        aikaleima = QDateTime::currentDateTime();
        uusiTilitapahtuma(aikaleima, "20.00", username);
        }else{
            QString teksti = ui->textStorage3->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText("");
            ui->labelInput2->setText("");
        }
    }
    }
    else if (button->objectName()=="btOption2"){
        if(luottoraja.toDouble()==0.0){
            if(saldo.toDouble()>(40.0*muuntokerroin.toDouble())+((40*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()){
            QString teksti = ui->textStorage1->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText("40 Euro");
            ui->labelInput2->setText("");
            tilimiinus=saldo.toDouble()-((40.0*muuntokerroin.toDouble())+((40*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, "40.00", username);
            }else{
               QString teksti = ui->textStorage2->text();
               ui->labelPrompt->setText(teksti);
               ui->labelInput->setText("");
               ui->labelInput2->setText("");
            }
        }else{
            if(luottoraja.toDouble()>(40.0*muuntokerroin.toDouble())+((40*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()+saldo.toDouble()){
            QString teksti = ui->textStorage1->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText("40 Euro");
            ui->labelInput2->setText("");
            tilimiinus=saldo.toDouble()+((40.0*muuntokerroin.toDouble())+((40*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, "40.00", username);
            }else{
               QString teksti = ui->textStorage3->text();
               ui->labelPrompt->setText(teksti);
               ui->labelInput->setText("");
               ui->labelInput2->setText("");
            }
        }
    }
    else if (button->objectName()=="btOption3"){
        if(luottoraja.toDouble()==0.0){
            if(saldo.toDouble()>(50.0*muuntokerroin.toDouble())+((50*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()){
            QString teksti = ui->textStorage1->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText("50 Euro");
            ui->labelInput2->setText("");
            tilimiinus=saldo.toDouble()-((50.0*muuntokerroin.toDouble())+((50*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, "50.00", username);
            }else{
               QString teksti = ui->textStorage2->text();
               ui->labelPrompt->setText(teksti);
               ui->labelInput->setText("");
               ui->labelInput2->setText("");
            }
        }else{
            if(luottoraja.toDouble()>(50.0*muuntokerroin.toDouble())+((50*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()+saldo.toDouble()){
            QString teksti = ui->textStorage1->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText("50 Euro");
            ui->labelInput2->setText("");
            tilimiinus=saldo.toDouble()+((50.0*muuntokerroin.toDouble())+((50*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, "50.00", username);

            }else{
               QString teksti = ui->textStorage3->text();
               ui->labelPrompt->setText(teksti);
               ui->labelInput->setText("");
               ui->labelInput2->setText("");
            }
        }
    }
    else if (button->objectName()=="btOption4"){
        if(luottoraja.toDouble()==0.0){
            if(saldo.toDouble()>(80.0*muuntokerroin.toDouble())+((80*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()){
            QString teksti = ui->textStorage1->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText("80 Euro");
            ui->labelInput2->setText("");
            tilimiinus=saldo.toDouble()-((80.0*muuntokerroin.toDouble())+((80*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, "80.00", username);
            }else{
               QString teksti = ui->textStorage2->text();
               ui->labelPrompt->setText(teksti);
               ui->labelInput->setText("");
               ui->labelInput2->setText("");
            }
        }else{
            if(luottoraja.toDouble()>(80.0*muuntokerroin.toDouble())+((50*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()+saldo.toDouble()){
            QString teksti = ui->textStorage1->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText("80 Euro");
            ui->labelInput2->setText("");
            tilimiinus=saldo.toDouble()+((80.0*muuntokerroin.toDouble())+((80*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, "80.00", username);

            }else{
               QString teksti = ui->textStorage3->text();
               ui->labelPrompt->setText(teksti);
               ui->labelInput->setText("");
               ui->labelInput2->setText("");
            }
        }
    }
    else if (button->objectName()=="btOption5"){
        if(luottoraja.toDouble()==0.0){
            if(saldo.toDouble()>(100.0*muuntokerroin.toDouble())+((100*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()){
            QString teksti = ui->textStorage1->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText("100 Euro");
            ui->labelInput2->setText("");
            tilimiinus=saldo.toDouble()-((100.0*muuntokerroin.toDouble())+((100*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, "100.00", username);
            }else{
               QString teksti = ui->textStorage2->text();
               ui->labelPrompt->setText(teksti);
               ui->labelInput->setText("");
               ui->labelInput2->setText("");
            }
        }else{
            if(luottoraja.toDouble()>(100.0*muuntokerroin.toDouble())+((100*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()+saldo.toDouble()){
            QString teksti = ui->textStorage1->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText("100 Euro");
            ui->labelInput2->setText("");
            tilimiinus=saldo.toDouble()+((100.0*muuntokerroin.toDouble())+((100*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, "100.00", username);
            }else{
               QString teksti = ui->textStorage3->text();
               ui->labelPrompt->setText(teksti);
               ui->labelInput->setText("");
               ui->labelInput2->setText("");
            }
        }
    }
    else if (button->objectName()=="btOption6"){
        if(luottoraja.toDouble()==0.0){
            if(saldo.toDouble()>(120.0*muuntokerroin.toDouble())+((120*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()){
            QString teksti = ui->textStorage1->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText("120 Euro");
            ui->labelInput2->setText("");
            tilimiinus=saldo.toDouble()-((120.0*muuntokerroin.toDouble())+((120*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, "120.00", username);
            }else{
               QString teksti = ui->textStorage2->text();
               ui->labelPrompt->setText(teksti);
               ui->labelInput->setText("");
               ui->labelInput2->setText("");
            }
        }else{
            if(luottoraja.toDouble()>(120.0*muuntokerroin.toDouble())+((120*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()+saldo.toDouble()){
            QString teksti = ui->textStorage1->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText("120 Euro");
            ui->labelInput2->setText("");
            tilimiinus=saldo.toDouble()+((120.0*muuntokerroin.toDouble())+((120*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, "120.00", username);

            }else{
               QString teksti = ui->textStorage3->text();
               ui->labelPrompt->setText(teksti);
               ui->labelInput->setText("");
               ui->labelInput2->setText("");
            }
        }
    }
    else if (button->objectName()=="btOption8"){
    muusumma=1;
    QString teksti = ui->textStorage4->text();
    ui->labelPrompt->setText(teksti);
    ui->labelInput->setText("");
    ui->labelInput2->setText("");
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

    if(muusumma == 1){
    QString nosto = ui->labelInput->text();
    if(nosto.toInt()%10 == 0 && nosto.toInt()!=10 && nosto.toInt()!=30){
    if(luottoraja.toDouble()==0.0){
        if(saldo.toDouble()>(nosto.toDouble()*muuntokerroin.toDouble())+((nosto.toDouble()*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()){
        QString teksti = ui->textStorage1->text();
        ui->labelPrompt->setText(teksti);
        ui->labelInput->setText(nosto +" Euro");
        tilimiinus=saldo.toDouble()-((nosto.toDouble()*muuntokerroin.toDouble())+((nosto.toDouble()*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
        saldo = QString::number(tilimiinus);
        upSaldo(username, saldo);
        aikaleima = QDateTime::currentDateTime();
        uusiTilitapahtuma(aikaleima, nosto, username);
        }else{
            QString teksti = ui->textStorage2->text();
            ui->labelPrompt->setText(teksti);
        }
    }else{
        if(luottoraja.toDouble()>(nosto.toDouble()*muuntokerroin.toDouble())+((nosto.toDouble()*muuntokerroin.toDouble())*npprosentti.toDouble())+npeuro.toDouble()+saldo.toDouble()){
        QString teksti = ui->textStorage1->text();
        ui->labelPrompt->setText(teksti);
        ui->labelInput->setText(nosto +" Euro");
        tilimiinus=saldo.toDouble()+((nosto.toDouble()*muuntokerroin.toDouble())+((nosto.toDouble()*muuntokerroin.toDouble())*npprosentti.toDouble())+npeuro.toDouble());
        saldo = QString::number(tilimiinus);
        upSaldo(username, saldo);
        aikaleima = QDateTime::currentDateTime();
        uusiTilitapahtuma(aikaleima, nosto, username);

        }else{
            QString teksti = ui->textStorage3->text();
            ui->labelPrompt->setText(teksti);
        }
    }
    }else{
        QString teksti = ui->textStorage5->text();
        QString teksti2 = ui->textStorage6->text();
        QString teksti3 = ui->textStorage7->text();
        ui->labelPrompt->setText(teksti);
        ui->labelInput->setText(teksti2);
        ui->labelInput2->setText(teksti3);
    }

    muusumma=0;
    }
 }
}
void Withdraw::setUsername(const QString &newUsername)
{
    username = newUsername;
    qDebug()<<"Username Mainmenu luokassa: "<<username;
}

void Withdraw::setToken(const QByteArray &newToken)
{
    token = newToken;
    qDebug()<<"Token Mainmenu luokassa: "<<&token;
}

void Withdraw::onNostoButtonClicked(QString tilinumero)
{
    QString site_url="http://localhost:3000/Tili/getSaldo/"+tilinumero;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getNostoSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void Withdraw::getNostoSlot(QNetworkReply *reply)
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


void Withdraw::onLuottorajaButtonClicked(QString tilinumero)
{
    QString site_url="http://localhost:3000/Tili/getLuottoraja/"+tilinumero;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU

    qDebug()<<"Tallennettu token luokassa: "<<token;
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getLuottorajaSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void Withdraw::getLuottorajaSlot(QNetworkReply *reply)
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

void Withdraw::onNpeuroButtonClicked(QString tilinumero)
{
    QString site_url="http://localhost:3000/Tili/getNostopalkkioeuro/"+tilinumero;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getNpeuroSlot(QNetworkReply*)));

    reply = getManager->get(request);
}
void Withdraw::getNpeuroSlot(QNetworkReply *reply)
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
void Withdraw::onNpprosenttiButtonClicked(QString tilinumero)
{
    QString site_url="http://localhost:3000/Tili/getNostopalkkioprosentti/"+tilinumero;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getNpprosenttiSlot(QNetworkReply*)));

    reply = getManager->get(request);
}
void Withdraw::getNpprosenttiSlot(QNetworkReply *reply)
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

void Withdraw::onMuuntokerroinButtonClicked(QString tilinumero)
{
    QString site_url="http://localhost:3000/Tili/getMuuntokerroin/"+tilinumero;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getMuuntokerroinSlot(QNetworkReply*)));

    reply = getManager->get(request);
}
void Withdraw::getMuuntokerroinSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    response_data = response_data.trimmed();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QJsonValue kurssiValue = json_obj.value("kurssi");
    QString Muuntokerroin = kurssiValue.isDouble() ? QString::number(kurssiValue.toDouble()) : kurssiValue.toString();

    qDebug() << "JSON-objekti: " << json_obj;

    qDebug()<<"tuleva muuntokerroin luokassa: "<<Muuntokerroin;
    muuntokerroin=Muuntokerroin;
    qDebug()<<"Tallennettu muuntokerroin luokassa: "<<muuntokerroin;
    reply->deleteLater();
    getManager->deleteLater();
   }
void Withdraw::upSaldo(QString id, QString newSaldo) {
    QString site_url = "http://localhost:3000/Tili/updateSaldo/" + id + "/" + newSaldo;
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Content-Type"), "application/json");
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

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
void Withdraw::uusiTilitapahtuma(QDateTime aikaleima, QString saldoMuutos, QString idTili) {
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
    postData.addQueryItem("Muutoslaji", "Nosto");
    postData.addQueryItem("idTili", idTili);
    postData.addQueryItem("Paikkatieto", "ATM");

    QByteArray postDataByteArray = postData.toString(QUrl::FullyEncoded).toUtf8();
    manager->post(request, postDataByteArray);
}
void Withdraw::setKieli(const int &newKieli)
{
    kieli = newKieli;
    qDebug()<<"Kieli withdraw luokassa: "<<kieli;
    if (kieli==1){
        ui->labelOption1->setText("20 Euro");
        ui->labelOption2->setText("40 Euro");
        ui->labelOption3->setText("50 Euro");
        ui->labelOption4->setText("80 Euro");
        ui->labelOption5->setText("100 Euro");
        ui->labelOption6->setText("120 Euro");
        ui->labelOption7->setText(" ");
        ui->labelOption8->setText("Muu");
        ui->labelPrompt->setText("Valitse summa");
        ui->labelInput->setText(" ");
        ui->textStorage1->setText("Nostit");
        ui->textStorage1->hide();
        ui->textStorage2->setText("Tiln saldo ei riitä");
        ui->textStorage2->hide();
        ui->textStorage3->setText("Tilin luotto ei riitä");
        ui->textStorage3->hide();
        ui->textStorage4->setText("Syötä haluamasi summa");
        ui->textStorage4->hide();
        ui->textStorage5->setText("Automaatissa vain");
        ui->textStorage5->hide();
        ui->textStorage6->setText("20 euron ja 50 euron");
        ui->textStorage6->hide();
        ui->textStorage7->setText("seteleitä");
        ui->textStorage7->hide();
    }else if (kieli==2){
        ui->labelOption1->setText("20 Euro");
        ui->labelOption2->setText("40 Euro");
        ui->labelOption3->setText("50 Euro");
        ui->labelOption4->setText("80 Euro");
        ui->labelOption5->setText("100 Euro");
        ui->labelOption6->setText("120 Euro");
        ui->labelOption7->setText(" ");
        ui->labelOption8->setText("Andra");
        ui->labelPrompt->setText("Välj ett belopp");
        ui->labelInput->setText(" ");
        ui->textStorage1->setText("Du har tagit ut ");
        ui->textStorage1->hide();
        ui->textStorage2->setText("Kontosaldot är otillräckligt");
        ui->textStorage2->hide();
        ui->textStorage3->setText("Kontokrediten är otillräcklig");
        ui->textStorage3->hide();
        ui->textStorage4->setText("Ange önskat belopp");
        ui->textStorage4->hide();
        ui->textStorage5->setText("Endast");
        ui->textStorage5->hide();
        ui->textStorage6->setText("20 Euro och 50 Euro");
        ui->textStorage6->hide();
        ui->textStorage7->setText("sedlar i automaten");
        ui->textStorage7->hide();
    }else if (kieli==3){
        ui->labelOption1->setText("20 Euro");
        ui->labelOption2->setText("40 Euro");
        ui->labelOption3->setText("50 Euro");
        ui->labelOption4->setText("80 Euro");
        ui->labelOption5->setText("100 Euro");
        ui->labelOption6->setText("120 Euro");
        ui->labelOption7->setText(" ");
        ui->labelOption8->setText("Custom");
        ui->labelPrompt->setText("Select an amount");
        ui->labelInput->setText(" ");
        ui->textStorage1->setText("Withdrew");
        ui->textStorage1->hide();
        ui->textStorage2->setText("The account balance is insufficient");
        ui->textStorage2->hide();
        ui->textStorage3->setText("Account credit is insufficient");
        ui->textStorage3->hide();
        ui->textStorage4->setText("Enter the desired amount");
        ui->textStorage4->hide();
        ui->textStorage5->setText("Only");
        ui->textStorage5->hide();
        ui->textStorage6->setText("20 Euro and 50 Euro");
        ui->textStorage6->hide();
        ui->textStorage7->setText("banknotes in the machine");
        ui->textStorage7->hide();
    }else{
        ui->labelOption1->setText("20 Euro");
        ui->labelOption2->setText("40 Euro");
        ui->labelOption3->setText("50 Euro");
        ui->labelOption4->setText("80 Euro");
        ui->labelOption5->setText("100 Euro");
        ui->labelOption6->setText("120 Euro");
        ui->labelOption7->setText(" ");
        ui->labelOption8->setText("Custom");
        ui->labelPrompt->setText("Select an amount");
        ui->labelInput->setText(" ");
        ui->textStorage1->setText("Withdrew");
        ui->textStorage1->hide();
        ui->textStorage2->setText("The account balance is insufficient");
        ui->textStorage2->hide();
        ui->textStorage3->setText("Account credit is insufficient");
        ui->textStorage3->hide();
        ui->textStorage4->setText("Enter the desired amount");
        ui->textStorage4->hide();
        ui->textStorage5->setText("Only");
        ui->textStorage5->hide();
        ui->textStorage6->setText("20 Euro and 50 Euro");
        ui->textStorage6->hide();
        ui->textStorage7->setText("banknotes in the machine");
        ui->textStorage7->hide();
         qDebug()<<"Kieli ui:ssa nosto luokassa: "<<kieli;
    }
}
