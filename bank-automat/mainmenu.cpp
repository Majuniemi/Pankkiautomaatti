#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "withdraw.h"

Mainmenu::Mainmenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Mainmenu)
{
    ui->setupUi(this);
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
        OlioTT = new Tilitapahtuma(this);
        OlioTT->setToken(token);
        OlioTT->setUsername(username);
        OlioTT->setKieli(kieli);
        OlioTT->onTTButtonClicked(username, 0);
        OlioTT->showFullScreen();
    }
    else if (button->objectName()=="btStop"){
        emit logoutRequested();
        accept();
    }
}

void Mainmenu::setUsername(const QString &newUsername)
{
    username = newUsername;
    qDebug()<<"Username Mainmenu luokassa: "<<username;
}

void Mainmenu::setToken(const QByteArray &newToken)
{
    token = newToken;
    qDebug()<<"Token Mainmenu luokassa: "<<token;
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
        ui->labelOption1->setText("Withdraw");
        ui->labelOption2->setText("Transfer");
        ui->labelOption3->setText("Account balance");
        ui->labelOption4->setText("Account Transactions");
        ui->labelOption5->setText("");
        ui->labelOption6->setText(" ");
        ui->labelOption7->setText(" ");
        ui->labelOption8->setText("");
        ui->labelPrompt->setText("Select an action");
         qDebug()<<"Kieli ui:ssa Mainmenu luokassa: "<<kieli;
    }
}
