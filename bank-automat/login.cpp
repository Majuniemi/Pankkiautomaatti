#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->labelOption1->setText(" ");                                                 //Asetetaan käyttöliittymään halutut tekstit sivunäppäimien kohdalle
    ui->labelOption2->setText(" ");
    ui->labelOption3->setText(" ");
    ui->labelOption4->setText(" ");
    ui->labelOption5->setText("Language");
    ui->labelOption6->setText(" ");
    ui->labelOption7->setText(" ");
    ui->labelOption8->setText(" ");

    connect(ui->btNum1,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));      //Luodaan Signal-Slotit numeronäppäimille
    connect(ui->btNum2,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum3,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum4,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum5,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum6,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum7,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum8,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum9,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum0,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));

    connect(ui->btAccept,SIGNAL(clicked(bool)),this,SLOT(enterClickHandler()));     //Luodaan Signal-Slotit toimintonäppäimille
    connect(ui->btCancel,SIGNAL(clicked(bool)),this,SLOT(cancelClickHandler()));
    connect(ui->btStop,SIGNAL(clicked(bool)),this,SLOT(stopClickHandler()));

    connect(ui->btOption3,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));  //Luodaan Signal-Slotit sivunäppäimille
    connect(ui->btOption7,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));

    ui->lineEditPassword->setEchoMode(QLineEdit::Password);                         //Asettaa password kentän salasanamoodiin, joka näyttää näppäillyt merkit palloina, eikä numeroina
}

Login::~Login()
{
    delete ui;      //Tämän luokan tuhoaja, eli dekonstruktori
}

void Login::lueKortti(const QString &korttinumero)
{
    qDebug()<<"Korttinumero Login luokassa: "<<korttinumero;
    username=korttinumero;                                                          //Otetaan vastaan korttinumero MainWindow luokasta ja asetetaan se tämän luokan jäsenmuuttuja usernameen
}

void Login::numberClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());                    //Otetaan vastaan Pinkoodi numeronäppäimistöltä
    QLineEdit * currentEdit = ui->lineEditPassword;
    currentEdit->setText(currentEdit->text() + button->text());
}

void Login::enterClickHandler()
{
    //qDebug()<<"username on nyt: "<<username;
    QString password = ui->lineEditPassword->text();
    QJsonObject jsonObj;                                                            //Luodaan JSON tieto, joka sisältää idKortti ja Pinkoodi kentät
    jsonObj.insert("idKortti",username);
    jsonObj.insert("Pinkoodi",password);

    QString site_url="http://localhost:3000/login";                                 //Määritetään osoite
    QNetworkRequest request((site_url));                                            //Luodaan QNetworkRequest olio ja käytetään yllä olevaa osoitetta siinä
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");      //Asettaa pyynnölle otsikon ja kertoo rungon olevan JSON muodossa

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));  //Kun saadaan signaali valmiista operaatiosta, niin siirrytään loginSlotiin
    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());            //postManager lähettää Post-pyynnön ja tallentaa vastauksen reply jäsenmuuttujaan
}

void Login::cancelClickHandler()
{
    QLineEdit *currentEdit = ui->lineEditPassword;                                  //Cancel napin painallus poistaa viimeisimmän merkin Pinkoodista
    QString currentText = currentEdit->text();
    currentEdit->setText(currentEdit->text());
    if (!currentText.isEmpty()) {                                                   //kunhan Pinkoodi-kenttä ei ole tyhjä
        currentText.chop(1);
        currentEdit->setText(currentText);
    }
}

void Login::stopClickHandler()
{
    accept();                                                                       //Sulkee X näppäintä painettaessa Login-ikkunan
}

void Login::commandClickHandler()
{
    QString site_url;
    QPushButton * button = qobject_cast<QPushButton*>(sender());                    //Tarkistaa mitä sivunäppäintä painettiin
    if (button->objectName()=="btOption3"){
        //Valitse credit-tili
        qDebug()<<"Valitsit credit-tilin";
        site_url="http://localhost:3000/Tili/getcredit/"+username;                  //Haetaan tietokannasta usernameen credit tilinumero
    }
    else if (button->objectName()=="btOption7"){
        //Valitse debit-tili
        qDebug()<<"Valitsit debit-tilin";
        site_url="http://localhost:3000/Tili/getdebit/"+username;                   //Haetaan tietokannasta usernameen debit tilinumero
    }
    //qDebug()<<"sivun nimi on nyt: "<<site_url;
    QNetworkRequest request((site_url));                                            //Luodaan QNetworkRequest olio ja käytetään yllä olevaa osoitetta siinä
    request.setRawHeader(QByteArray("Authorization"),(token));                      //Tarkistetaan autentikointi
    getoneManager = new QNetworkAccessManager(this);
    connect(getoneManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getTiliSlot(QNetworkReply*)));  //Operaation valmistuttua siirrytään getTiliSlotiin
    replyTili = getoneManager->get(request);                                        //Lähetetään Get-pyyntö palvelimelle ja tallennetaan vastaus reply jäsenmuuttujaan
}

void Login::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();                                                 //Luetaan QNetworkReplyn tiedot ja tallennetaan se response_data jäsenmuuttujaan
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
                //qDebug()<<token;

                QString site_url="http://localhost:3000/Tili/"+username;            //Määrätään osoite
                //qDebug()<<"sivun nimi on nyt: "<<site_url;
                QNetworkRequest request((site_url));
                request.setRawHeader(QByteArray("Authorization"),(token));          //Tarkistetaan tokenin olemassaolo
                getcountManager = new QNetworkAccessManager(this);
                connect(getcountManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getKorttiSlot(QNetworkReply*)));   //Signal-Slot, joka vie operaation valmistuttua getKorttiSlotiin
                replyKortti = getcountManager->get(request);                        //Lähetetään Get-pyyntö palvelimelle ja tallennetaan vastaus replyKortti jäsenmuuttujaan
            }
            else{
                qDebug()<<"Korttinumero tai PIN-koodi väärin";
                ui->labelPrompt->setText("Korttinumero tai PIN-koodi väärin");
                ui->lineEditPassword->clear();
            }
        }
    }
    reply->deleteLater();                                                           //Poistetaan oliot ja pidetään huolta muistinhallinnasta
    postManager->deleteLater();
}

void Login::getKorttiSlot(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError) {                                  //Tarkistetaan, onko vastauksessa virheitä
        response_dataKortti=reply->readAll();                                       //Jos virheitä ei ole, niin luetaan ja tallennetaan tieto jäsenmuuttujaan
        //qDebug()<<"Tilien lkm: "+response_dataKortti;
    }
    else {
        qDebug() << "Virhe:" << reply->errorString();                               //Ilmoitetaan virheestä terminaalissa
    }

    if(response_dataKortti=="{\"count\":2}") {                                      //Tarkistetaan montako tiliä korttiin on liitetty
        qDebug()<<"Tähän korttiin on liitetty 2 tiliä";

        ui->labelOption1->setText(" ");                                             //Asetetaan sivunäppäimille tekstit, jotka ohjaavat käyttäjää valitsemaan creditin tai debitin
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
        qDebug()<<"Tähän korttiin on liitetty vain 1 tili";
        QString site_url="http://localhost:3000/Tili/getone/"+username;             //Asetetaan osoite
        //qDebug()<<"sivun nimi on nyt: "<<site_url;
        QNetworkRequest request((site_url));
        request.setRawHeader(QByteArray("Authorization"),(token));                  //Tarkistetaan tokenin voimassaolo
        getoneManager = new QNetworkAccessManager(this);
        connect(getoneManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getTiliSlot(QNetworkReply*)));  //Signal-Slot, joka vie operaation valmistuttua getTiliSlotiin
        replyTili = getoneManager->get(request);                                    //Lähetetään Get-pyyntö palvelimelle ja tallennetaan vastaus replyTili jäsenmuuttujaan
    }
    else {
        ui->labelOption1->setText(" ");                                             //Asetetaan näkymään, ettei korttiin ole liitetty tilinumeroa ja poistumisohje
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
    reply->deleteLater();                                                           //Poistetaan oliot ja pidetään huolta muistinhallinnasta
    getcountManager->deleteLater();
}

void Login::getTiliSlot(QNetworkReply *reply)
{
    //qDebug()<<"TiliSlotiin asti päästy";
    if(reply->error() == QNetworkReply::NoError) {                                  //Tarkistetaan, onko vastauksessa virheitä
        response_dataTili=reply->readAll();
        //qDebug()<<"Tilinumero: "+response_dataTili;
        QString tilinumeroTietokannasta = response_dataTili;
        QString tilinumero;
        for (const QChar &ch : tilinumeroTietokannasta) {                           //Siivotaan ylimääräiset merkit vastauksena tulleesta tiedosta, jäljelle jää pelkkä tilinumero
            if (ch.isDigit() || (ch >= 'A' && ch <= 'I') || (ch >= 'a' && ch <= 'f')) {
                tilinumero.append(ch);
            }
        }
        username = tilinumero;                                                      //Vaihdetaan usernameen tilinumero, joka viedään eteenpäin käyttäjätunnuksena
        olioMainmenu = new Mainmenu(this);
        olioMainmenu->setToken(token);                                              //Viedään token eteenpäin Mainmenu-luokkaan
        olioMainmenu->setUsername(username);                                        //Viedään tilinumero eteenpäin Mainmenu-luokkaan
        olioMainmenu->show();                                                       //Avataan Mainmenu-olion ikkuna
        accept();                                                                   //Suljetaan Login-olion ikkuna
    }
    else {
        qDebug() << "Virhe:" << reply->errorString();
    }

    reply->deleteLater();                                                           //Poistetaan oliot ja pidetään huolta muistinhallinnasta
    getoneManager->deleteLater();
}
