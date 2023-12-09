#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "withdraw.h"

Mainmenu::Mainmenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Mainmenu)
{
    ui->setupUi(this);
    /*
    ui->labelOption1->setText("Nosta rahaa");
    ui->labelOption2->setText("Tilisiirto");
    ui->labelOption3->setText("Saldo");
    ui->labelOption4->setText("Tilitapahtumat");
    ui->labelOption5->setText("");
    ui->labelOption6->setText(" ");
    ui->labelOption7->setText(" ");
    ui->labelOption8->setText("");
    ui->labelPrompt->setText("Valitse toiminto");
*/

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

Mainmenu::~Mainmenu()
{
    delete ui;
}

void Mainmenu::numberClickHandler()
{

}

void Mainmenu::commandClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    if (button->objectName()=="btOption1"){
        olioWithdraw = new Withdraw(this);
        olioWithdraw->setToken(token);
        olioWithdraw->setUsername(username);
        olioWithdraw->setKieli(kieli);
        olioWithdraw->onNostoButtonClicked(username);
        olioWithdraw->onLuottorajaButtonClicked(username);
        olioWithdraw->onNpeuroButtonClicked(username);
        olioWithdraw->onNpprosenttiButtonClicked(username);
        olioWithdraw->onMuuntokerroinButtonClicked(username);
        olioWithdraw->showFullScreen();
    }
    else if (button->objectName()=="btOption2"){
        olioTransfer = new Transfer(this);
        olioTransfer->setToken(token);
        olioTransfer->setUsername(username);
        olioTransfer->setKieli(kieli);
        olioTransfer->onNostoButtonClicked(username);
        olioTransfer->onLuottorajaButtonClicked(username);
        olioTransfer->onNpeuroButtonClicked(username);
        olioTransfer->onNpprosenttiButtonClicked(username);
        olioTransfer->onMuuntokerroinButtonClicked(username);
        olioTransfer->showFullScreen();
    }
    else if (button->objectName()=="btOption3"){

        olioSaldo = new Saldo(this);
        olioSaldo->setToken(token);
        olioSaldo->setUsername(username);   
        olioSaldo->setKieli(kieli);
        olioSaldo->onSaldoButtonClicked(username);
        olioSaldo->onValuuttaButtonClicked(username);
        olioSaldo->showFullScreen();
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

void Mainmenu::setUsername(const QString &newUsername)
{
    username = newUsername;
    qDebug()<<"Username Mainmenu luokassa: "<<username;
}
void Mainmenu::on_btOption4_clicked()  // nappi jolla siirrytään Tilitapahtuma ikkunaan
{
    QString site_url="http://localhost:3000/Tilitapahtuma";
    QNetworkRequest request((QUrl(site_url)));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getTT(QNetworkReply*)));
    reply = getManager->get(request);
    // QSqlQuery query;
    qDebug() << "Tilitapahtumat nappia on painettu";

}
    void Mainmenu::getTT(QNetworkReply *reply)  //printataan tilitapahtumiin tietokannasta halutut tiedot
    {
        /*  response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString Tilitapahtumat;
    int TTmaara = 0;
    for (const QJsonValue &value : json_array) {
    if (TTmaara >=5) {
    break;
    }
    QJsonObject json_obj = value.toObject();
    Tilitapahtumat += QString::number(json_obj["Saldomuutos"].toInt()) + "   " +
    QString::number(json_obj["Aikaleima"].toInt()) + "   " +
    json_obj["Muutoslaji"].toString() + "   " +
    QString::number(json_obj["idTili"].toInt()) + "   " +
    json_obj["Paikkatieto"].toString() + "\r";
    TTmaara++; */ // Saadaan 5tilitapahtumaa kerralla mutta nappi sakkas ja moti
        response_data=reply->readAll();
        qDebug() << "response data on nyt:" + response_data;
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();
        QString Tilitapahtumat;
        for (const QJsonValue &value : json_array) {
            QJsonObject json_obj = value.toObject();
            Tilitapahtumat += QString::number(json_obj["Saldomuutos"].toInt()) + "   " +
                              QString::number(json_obj["Aikaleima"].toInt()) + "   " +
                              json_obj["Muutoslaji"].toString() + "   " +
                              QString::number(json_obj["idTili"].toInt()) + "   " +
                              json_obj["Paikkatieto"].toString() + "\r";
            qDebug() << Tilitapahtumat;
        }

        tilitapahtumalista =new Tilitapahtuma(this);
        tilitapahtumalista->showTilitapahtuma(Tilitapahtumat);
        tilitapahtumalista->showFullScreen();
        //  ui->labelInput->setText(Tilitapahtumat);
        reply->deleteLater();
        getManager->deleteLater();
    }
void Mainmenu::setToken(const QByteArray &newToken)
{
    token = newToken;
    qDebug()<<"Token Mainmenu luokassa: "<<&token;
}

void Mainmenu::setKieli(const int &newKieli)
{
    kieli = newKieli;
    qDebug()<<"Kieli Mainmenu luokassa: "<<kieli;
    if (kieli==1){
        ui->labelOption1->setText("Nosta rahaa");
        ui->labelOption2->setText("Tilisiirto");
        ui->labelOption3->setText("Saldo");
        ui->labelOption4->setText("Tilitapahtumat");
        ui->labelOption5->setText("");
        ui->labelOption6->setText(" ");
        ui->labelOption7->setText(" ");
        ui->labelOption8->setText("");
        ui->labelPrompt->setText("Valitse toiminto");
    }else if (kieli==2){
        ui->labelOption1->setText("Uttag");
        ui->labelOption2->setText("Banköverföring");
        ui->labelOption3->setText("Balans");
        ui->labelOption4->setText("Kontotransaktioner");
        ui->labelOption5->setText("");
        ui->labelOption6->setText(" ");
        ui->labelOption7->setText(" ");
        ui->labelOption8->setText("");
        ui->labelPrompt->setText("Välj en åtgärd");
    }else if (kieli==3){
        ui->labelOption1->setText("Withdraw");
        ui->labelOption2->setText("Transfer");
        ui->labelOption3->setText("Account balance");
        ui->labelOption4->setText("Account Transactions");
        ui->labelOption5->setText("");
        ui->labelOption6->setText(" ");
        ui->labelOption7->setText(" ");
        ui->labelOption8->setText("");
        ui->labelPrompt->setText("Select an action");
    }else{
        ui->labelPrompt->setText("The account balance is");
         qDebug()<<"Kieli ui:ssa Mainmenu luokassa: "<<kieli;
    }
}
