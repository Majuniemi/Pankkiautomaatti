#include "saldo.h"
#include "ui_saldo.h"
Saldo::Saldo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Saldo)
{
    ui->setupUi(this);
    ui->labelOption1->setText(" ");
    ui->labelOption2->setText(" ");
    ui->labelOption3->setText(" ");
    ui->labelOption4->setText(" ");
    ui->labelOption5->setText(" ");
    ui->labelOption6->setText(" ");
    ui->labelOption7->setText(" ");
    ui->labelOption8->setText("Takaisin");
    ui->labelPrompt->setText("Saldo");
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
Saldo::~Saldo()
{
    delete ui;
}
/*
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
}

void Saldo::setSaldo(const QString &newSaldo)
{
    saldo = newSaldo;

}

void Saldo::showSaldo()
{
    ui->labelInput->setText(saldo);
}
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

    connect(getManager, SIGNAL(finished (QNetworkReply)), this, SLOT(getSaldoSlot(QNetworkReply)));

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
    }
    else if (button->objectName()=="btStop"){
        accept();
    }
    else if (button->objectName()=="btCancel"){
    }
    else if (button->objectName()=="btAccept"){
    }


}

