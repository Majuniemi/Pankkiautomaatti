#include "tilitapahtuma.h"
#include "ui_tilitapahtuma.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

Tilitapahtuma::Tilitapahtuma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tilitapahtuma)
{
    ui->setupUi(this);
    connect(ui->btOption4,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption8,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btStop,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
}
Tilitapahtuma::~Tilitapahtuma()
{
    delete ui;
}

void Tilitapahtuma::setUsername(const QString &newUsername)
{
    username = newUsername;
}

void Tilitapahtuma::commandClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if (button->objectName()=="btOption4"){
        QString teksti = ui->labelTapahtuma5->text();
        if(teksti!=" "){
        offsetnum=offsetnum+5;
        offset = QString::number(offsetnum);
        onTTButtonClicked(username, offset);
        }
    }
    else if (button->objectName()=="btOption8"){
        if (offsetnum>0){
        offsetnum=offsetnum-5;
        offset = QString::number(offsetnum);
        onTTButtonClicked(username, offset);
        }
    }
    else if (button->objectName()=="btStop"){
        accept();
    }
}
void Tilitapahtuma::onTTButtonClicked(QString tilinumero, QString offset)
{

    QString site_url="http://localhost:3000/Tilitapahtuma/getFive/"+tilinumero+"?offset="+offset;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getTTSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void Tilitapahtuma::getTTSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug() << "DATA : " << response_data;

    // Muunnetaan JSON-merkkijono QJsonDocument-olioksi
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);

    // Tarkista, että JSON-dokumentti on kelvollinen
    if (!json_doc.isNull() && json_doc.isArray()) {
        // Käsittele JSON-taulukko
        QJsonArray json_array = json_doc.array();
        int numberOfItems = json_array.size();
        qDebug() << "Tietueiden määrä: " << numberOfItems;
        if (numberOfItems>0){
        for (int i = 0; i < 5; ++i) {
            QLabel *label = nullptr;

            // Valitse oikea label numeroa vastaavasti
            switch (i) {
            case 0:
                label = ui->labelTapahtuma1;
                break;
            case 1:
                label = ui->labelTapahtuma2;
                break;
            case 2:
                label = ui->labelTapahtuma3;
                break;
            case 3:
                label = ui->labelTapahtuma4;
                break;
            case 4:
                label = ui->labelTapahtuma5;
                break;
            default:
                break;
            }

            if (label) {
                if (i < numberOfItems) {
                    QJsonValue value = json_array[i];
                    if (value.isObject()) {
                        QJsonObject object = value.toObject();
                        QString saldoMuutos = object["Saldomuutos"].toString();
                        QString muutosLaji = object["Muutoslaji"].toString();
                        QString aikaleimaString = object["Aikaleima"].toString();
                        QDateTime aika = QDateTime::fromString(aikaleimaString, Qt::ISODate);
                        QString muotoiltuAika = aika.toString("dd.MM.yyyy hh:mm:ss");
                        qDebug() << "muotoiltuAika: " << muotoiltuAika;
                        qDebug() << "muutosLaji: " << muutosLaji;
                        QString odotettuTeksti = "2";
                        if(ui->kieli->text() == odotettuTeksti){
                            if (muutosLaji=="Nosto"){
                                muutosLaji ="Uttag";
                            }
                            if (muutosLaji=="Pano"){
                                muutosLaji ="Sätta";
                            }
                            if (muutosLaji=="Siirto"){
                                muutosLaji ="Överföring";
                            }
                        }
                        odotettuTeksti = "3";
                        if(ui->kieli->text() == odotettuTeksti){
                            if (muutosLaji=="Nosto"){
                                muutosLaji ="Withdraw";
                            }
                            if (muutosLaji=="Pano"){
                                muutosLaji ="Deposit";
                            }
                            if (muutosLaji=="Siirto"){
                                muutosLaji ="Transfer";
                            }
                            }
                        qDebug() << "saldoMuutos: " << saldoMuutos;
                        QString jsonString = muotoiltuAika + "      " + muutosLaji + " " + saldoMuutos;
                        label->setText(jsonString);
                    }
                } else {
                    label->setText(" ");
                }
            }
        }
        }else{
        offsetnum=offsetnum-5;

        }
    } else {
        qDebug() << "Virheellinen tai tyhjä JSON-dokumentti.";
    }
    reply->deleteLater();
    getManager->deleteLater();
}
void Tilitapahtuma::setKieli(const int &newKieli)
{
    kieli = newKieli;
    qDebug()<<"Kieli tilitapahtuma luokassa: "<<kieli;
    if (kieli==1){
        ui->labelOtsikko->setText("        Aika               Toiminto  Euro ");
        ui->labelOption4->setText("<- Edellinen");
        ui->labelOption8->setText("Seuraava ->");
        ui->kieli->setText("1");
        ui->kieli->hide();
    }else if (kieli==2){
        ui->labelOtsikko->setText("   Tidsstämpel            Action   Euro  ");
        ui->labelOption4->setText("<- Tidigare");
        ui->labelOption8->setText("Nästa ->");
        ui->kieli->setText("2");
        ui->kieli->hide();
    }else if (kieli==3){
        ui->labelOtsikko->setText("    Timestamp             Action   Euro  ");
        ui->labelOption4->setText("<- Previous");
        ui->labelOption8->setText("Next ->");
        ui->kieli->setText("3");
        ui->kieli->hide();
    }else{
        ui->labelOtsikko->setText("    Timestamp             Action   Euro  ");
        ui->labelOption4->setText("<- Previous");
        ui->labelOption8->setText("Next ->");

         qDebug()<<"Kieli ui:ssa tilitapahtuma luokassa: "<<kieli;
    }
}
void Tilitapahtuma::setToken(const QByteArray &newToken)
{
    token = newToken;
    qDebug()<<"Token tilitapahtuma luokassa: "<<token;
}


