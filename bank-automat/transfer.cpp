#include "transfer.h"
#include "ui_transfer.h"

Transfer::Transfer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Transfer)
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
        QString buttonName = button->objectName();                                      // teksti vaihdettu kuvaan, joten otetaan arvo nimestä
        QString lastCharacter = buttonName.right(1);
        currentEdit->setText(currentEdit->text() + lastCharacter);
    }
}

void Transfer::commandClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    if (button->objectName()=="btStop"){
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
            if(saldo.toDouble()>(siirto.toDouble()*muuntokerroin.toDouble())+((siirto.toDouble()*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()){
            QString teksti = ui->textStorage1->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText(siirto +" Euro");
            tilimiinus=saldo.toDouble()-((siirto.toDouble()*muuntokerroin.toDouble())+((siirto.toDouble()*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            upSaldo(saavatilinumero, siirto);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, siirto, "Siirto", username);
            uusiTilitapahtuma(aikaleima, siirto, "Pano", saavatilinumero);

            }else{
                QString teksti = ui->textStorage2->text();
                ui->labelPrompt->setText(teksti);
            }
        }else{
            if(luottoraja.toDouble()>(siirto.toDouble()*muuntokerroin.toDouble())+((siirto.toDouble()*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble()+saldo.toDouble()){
            QString teksti = ui->textStorage1->text();
            ui->labelPrompt->setText(teksti);
            ui->labelInput->setText(siirto +" Euro");
            tilimiinus=saldo.toDouble()+((siirto.toDouble()*muuntokerroin.toDouble())+((siirto.toDouble()*muuntokerroin.toDouble())*(npprosentti.toDouble()/100))+npeuro.toDouble());
            saldo = QString::number(tilimiinus);
            upSaldo(username, saldo);
            upSaldo(saavatilinumero, siirto);
            aikaleima = QDateTime::currentDateTime();
            uusiTilitapahtuma(aikaleima, siirto, "Siirto", username);
            uusiTilitapahtuma(aikaleima, siirto, "Pano", saavatilinumero);

            }else{
               QString teksti = ui->textStorage3->text();
               ui->labelPrompt->setText(teksti);
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

void Transfer::onNostoButtonClicked(QString tilinumero)
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

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getLuottorajaSlot(QNetworkReply*)));

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

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getNpeuroSlot(QNetworkReply*)));

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

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getNpprosenttiSlot(QNetworkReply*)));

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

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getMuuntokerroinSlot(QNetworkReply*)));

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
    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getTiliSlot(QNetworkReply*)));

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



    if (siirtokohde==1)
    {
        QString teksti = ui->labelInput3->text();
        ui->labelPrompt->setText(teksti);
        ui->labelInput_2->setText("");
        ui->labelInput->setText("");
    }else{
        QString teksti = ui->labelInput4->text();
        ui->labelInput_2->setText("");
        ui->labelInput->setText(teksti);
    }

    reply->deleteLater();
    getManager->deleteLater();
}

void Transfer::uusiTilitapahtuma(QDateTime aikaleima, QString saldoMuutos, QString muutosLaji, QString idTili) {
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
    postData.addQueryItem("Muutoslaji", muutosLaji);
    postData.addQueryItem("idTili", idTili);
    postData.addQueryItem("Paikkatieto", "ATM");

    QByteArray postDataByteArray = postData.toString(QUrl::FullyEncoded).toUtf8();
    manager->post(request, postDataByteArray);
}
void Transfer::setKieli(const int &newKieli)
{
    kieli = newKieli;
    qDebug()<<"Kieli transfer luokassa: "<<kieli;
    if (kieli==1){
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
           ui->labelInput3->setText("Syötä siirrettävä määrä");
           ui->labelInput3->hide();
           ui->labelInput4->setText("Tilinumero on virheellinen");
           ui->labelInput4->hide();
           ui->textStorage1->setText("Siirsit");
           ui->textStorage1->hide();
           ui->textStorage2->setText("Tiln saldo ei riitä");
           ui->textStorage2->hide();
           ui->textStorage3->setText("Tilin luotto ei riitä");
           ui->textStorage3->hide();
    }else if (kieli==2){
        ui->labelOption1->setText(" ");
           ui->labelOption2->setText(" ");
           ui->labelOption3->setText(" ");
           ui->labelOption4->setText(" ");
           ui->labelOption5->setText(" ");
           ui->labelOption6->setText(" ");
           ui->labelOption7->setText(" ");
           ui->labelOption8->setText("");
           ui->labelPrompt->setText("Ange kontot som du vill överföra pengar till");
           ui->labelInput->setText(" ");
           ui->labelInput3->setText("Ange beloppet som ska överföras");
           ui->labelInput3->hide();
           ui->labelInput4->setText("Kontonumret är felaktigt");
           ui->labelInput4->hide();
           ui->textStorage1->setText("Du överförde");
           ui->textStorage1->hide();
           ui->textStorage2->setText("Kontosaldot är otillräckligt");
           ui->textStorage2->hide();
           ui->textStorage3->setText("Kontokrediten är otillräcklig");
           ui->textStorage3->hide();
    }else if (kieli==3){
        ui->labelOption1->setText(" ");
           ui->labelOption2->setText(" ");
           ui->labelOption3->setText(" ");
           ui->labelOption4->setText(" ");
           ui->labelOption5->setText(" ");
           ui->labelOption6->setText(" ");
           ui->labelOption7->setText(" ");
           ui->labelOption8->setText("");
           ui->labelPrompt->setText("Enter the account of recipient");
           ui->labelInput->setText(" ");
           ui->labelInput3->setText("Enter the amount to transfer");
           ui->labelInput3->hide();
           ui->labelInput4->setText("The account number is incorrect");
           ui->labelInput4->hide();
           ui->textStorage1->setText("Transferred ");
           ui->textStorage1->hide();
           ui->textStorage2->setText("The account balance is insufficient");
           ui->textStorage2->hide();
           ui->textStorage3->setText("Account credit is insufficient");
           ui->textStorage3->hide();
    }else{
         qDebug()<<"Kieli ui:ssa Mainmenu luokassa: "<<kieli;
         ui->labelOption1->setText(" ");
            ui->labelOption2->setText(" ");
            ui->labelOption3->setText(" ");
            ui->labelOption4->setText(" ");
            ui->labelOption5->setText(" ");
            ui->labelOption6->setText(" ");
            ui->labelOption7->setText(" ");
            ui->labelOption8->setText("");
            ui->labelPrompt->setText("Enter the account of recipient");
            ui->labelInput->setText(" ");
            ui->labelInput3->setText("Enter the amount to transfer");
            ui->labelInput3->hide();
            ui->labelInput4->setText("The account number is incorrect");
            ui->labelInput4->hide();
            ui->textStorage1->setText("Transferred ");
            ui->textStorage1->hide();
            ui->textStorage2->setText("The account balance is insufficient");
            ui->textStorage2->hide();
            ui->textStorage3->setText("Account credit is insufficient");
            ui->textStorage3->hide();
    }
}
