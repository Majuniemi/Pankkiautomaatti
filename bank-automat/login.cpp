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

}

Login::~Login()
{
    delete ui;
}

void Login::numberClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QLabel *currentEdit = ui->labelPassword;
    currentEdit->setText(currentEdit->text() + button->text());
}

void Login::enterClickHandler()
{
    QString username = "0000000011111111";
    ui->labelUser->setText(username);
    QString password = ui->labelPassword->text();
    QJsonObject jsonObj;
    jsonObj.insert("idKortti",username);
    jsonObj.insert("Pinkoodi",password);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    //QByteArray myToken="Bearer xRstgr...";
    //request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
}

void Login::cancelClickHandler()
{
    QLabel *currentEdit = ui->labelPassword;
    QString currentText = currentEdit->text();
    currentEdit->setText(currentEdit->text());
    if (!currentText.isEmpty()) {
        currentText.chop(1);
        currentEdit->setText(currentText);
    }
}

void Login::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
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
                ui->labelPrompt->setText("Login Ok");
            }
            else{
                qDebug()<<"Korttinumero tai PIN-koodi väärin";
                ui->labelPrompt->setText("Korttinumero tai PIN-koodi väärin");
            }
        }
    }
    reply->deleteLater();
    postManager->deleteLater();
}
