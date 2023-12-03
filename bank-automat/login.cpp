#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->labelOption1->setText(" ");
    ui->labelOption2->setText(" ");
    ui->labelOption3->setText(" ");
    ui->labelOption4->setText(" ");
    ui->labelOption5->setText("Language");
    ui->labelOption6->setText(" ");
    ui->labelOption7->setText(" ");
    ui->labelOption8->setText(" ");

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

    connect(ui->btAccept,SIGNAL(clicked(bool)),this,SLOT(enterClickHandler()));
    connect(ui->btCancel,SIGNAL(clicked(bool)),this,SLOT(cancelClickHandler()));
    connect(ui->btStop,SIGNAL(clicked(bool)),this,SLOT(stopClickHandler()));

    connect(ui->btOption3,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption7,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));

    ui->lineEditPassword->setEchoMode(QLineEdit::Password);     // Asettaa password kentän salasanamoodiin, joka salaa näppäillyt merkit
}

Login::~Login()
{
    delete ui;
}

void Login::lueKortti(const QString &korttinumero)
{
    qDebug()<<"Korttinumero Login luokassa: "<<korttinumero;
    username=korttinumero;
}

void Login::numberClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QLineEdit * currentEdit = ui->lineEditPassword;
    currentEdit->setText(currentEdit->text() + button->text());
}

void Login::enterClickHandler()
{
    //QString username = "0000000011111111";
    //ui->labelUser->setText(username);
    //qDebug()<<"username on nyt: "<<username;
    QString password = ui->lineEditPassword->text();
    QJsonObject jsonObj;
    jsonObj.insert("idKortti",username);
    jsonObj.insert("Pinkoodi",password);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
}

void Login::cancelClickHandler()
{
    QLineEdit *currentEdit = ui->lineEditPassword;
    QString currentText = currentEdit->text();
    currentEdit->setText(currentEdit->text());
    if (!currentText.isEmpty()) {
        currentText.chop(1);
        currentEdit->setText(currentText);
    }
}

void Login::stopClickHandler()
{
    accept();
}

void Login::commandClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if (button->objectName()=="btOption3"){
        //Valitse credit-tili
        qDebug()<<"Valitsit credit-tilin";

        //Vaihda tässä usernameen haluttu tilinumero

        olioMainmenu = new Mainmenu(this);
        olioMainmenu->setToken(token);
        olioMainmenu->setUsername(username);
        olioMainmenu->show();
        accept();
    }
    else if (button->objectName()=="btOption7"){
        //Valitse debit-tili
        qDebug()<<"Valitsit debit-tilin";

        //Vaihda tässä usernameen haluttu tilinumero

        olioMainmenu = new Mainmenu(this);
        olioMainmenu->setToken(token);
        olioMainmenu->setUsername(username);
        olioMainmenu->show();
        accept();
    }
}

void Login::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    //qDebug()<<response_data;
    if(response_data.length()<2){
        qDebug()<<"Palvelin ei vastaa";
        ui->labelPrompt->setText("Palvelin ei vastaa");
    }
    else {
        if(response_data=="-4078"){
            qDebug()<<"Virhe tietokantayhteydessä";
            ui->labelPrompt->setText("Virhe tietokantayhteydessä");
        }
        else {
            if (response_data!="false" && response_data.length()>20){
                qDebug()<<"Login Ok";
                //ui->labelPrompt->setText("Login Ok");
                token = "Bearer "+response_data;
                qDebug()<<token;

                QString site_url="http://localhost:3000/Tili/"+username;
                qDebug()<<"sivun nimi on nyt: "<<site_url;
                QNetworkRequest request((site_url));
                request.setRawHeader(QByteArray("Authorization"),(token));      //Tarkistetaan tokenin voimassaolo
                getManager = new QNetworkAccessManager(this);
                connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getKorttiSlot(QNetworkReply*)));   //Signal-Slot, joka vie tiedon tultua getKorttiSlotiin
                replyKortti = getManager->get(request);
            }
            else{
                qDebug()<<"Korttinumero tai PIN-koodi väärin";
                ui->labelPrompt->setText("Korttinumero tai PIN-koodi väärin");
                ui->lineEditPassword->clear();
            }
        }
    }
    reply->deleteLater();
    postManager->deleteLater();
}

void Login::getKorttiSlot(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError) {      //Tarkistetaan, onko vastauksessa virheitä
        response_dataKortti=reply->readAll();
        qDebug()<<"Tilien lukumäärä: "+response_dataKortti;
    }
    else {
        qDebug() << "Virhe:" << reply->errorString();
    }

    if(response_dataKortti=="{\"count\":2}") {
        qDebug()<<"Onnistui verrata kahta";

        ui->labelOption1->setText(" ");
        ui->labelOption2->setText(" ");
        ui->labelOption3->setText("Credit");
        ui->labelOption4->setText(" ");
        ui->labelOption5->setText("Language");
        ui->labelOption6->setText(" ");
        ui->labelOption7->setText("Debit");
        ui->labelOption8->setText(" ");
        ui->lineEditPassword->hide();
        ui->labelPrompt->setText("Valitse debit/credit");
        ui->label_2->setText(" ");
    }
    else if (response_dataKortti=="{\"count\":1}"){
        qDebug()<<"Onnistui verrata yhtä";

        //Vaihda tässä usernameen korttinumeroon viittaavan tilin numero

        olioMainmenu = new Mainmenu(this);
        olioMainmenu->setToken(token);
        olioMainmenu->setUsername(username);
        olioMainmenu->show();
        accept();
    }
    else {
        ui->labelOption1->setText(" ");
        ui->labelOption2->setText(" ");
        ui->labelOption3->setText("");
        ui->labelOption4->setText(" ");
        ui->labelOption5->setText("Language");
        ui->labelOption6->setText(" ");
        ui->labelOption7->setText("");
        ui->labelOption8->setText(" ");
        ui->lineEditPassword->hide();
        ui->labelPrompt->setText("Tällä kortilla ei ole tiliä, poistu painamalla X");
        ui->label_2->setText(" ");
    }
    reply->deleteLater();
    getManager->deleteLater();
}

/*
// Oletetaan, että db on QSqlDatabase-olio ja on aikaisemmin avattu tietokantaan
QSqlQuery query(db);
korttinumero = username;
query.prepare("SELECT korttityyppi FROM kortit WHERE korttinumero = :korttinumero");
query.bindValue(":korttinumero", korttinumero);

if (query.exec() && query.next()) {
    QString korttityyppi = query.value(0).toString();

    // Tässä voit tarkistaa korttityypin ja tehdä tarvittavat toimenpiteet
    if (korttityyppi == "yhdistelmäkortti") {
        // Tee jotain yhdistelmäkortin kanssa
    } else {
        // Tee jotain muun tyyppisen kortin kanssa
    }
} else {
    // Virhe tietokantakyselyssä
    qDebug() << "Virhe tietokantakyselyssä:" << query.lastError().text();
}*/

