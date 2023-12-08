#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "withdraw.h"

Mainmenu::Mainmenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Mainmenu)
{
    ui->setupUi(this);
    ui->labelOption1->setText("Nosta rahaa");
    ui->labelOption2->setText("Tilisiirto");
    ui->labelOption3->setText("Saldo");
    ui->labelOption4->setText("Tilitapahtumat");
    ui->labelOption5->setText("Language");
    ui->labelOption6->setText(" ");
    ui->labelOption7->setText(" ");
    ui->labelOption8->setText("");
    ui->labelPrompt->setText("Valitse toiminto");


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
        olioWithdraw->onNostoButtonClicked(username);
        olioWithdraw->onLuottorajaButtonClicked(username);
        olioWithdraw->onNpeuroButtonClicked(username);
        olioWithdraw->onNpprosenttiButtonClicked(username);
        olioWithdraw->onMuuntokerroinButtonClicked(username);
        olioWithdraw->show();
    }
    else if (button->objectName()=="btOption2"){
        olioTransfer = new Transfer(this);
        olioTransfer->setToken(token);
        olioTransfer->setUsername(username);
        olioTransfer->onNostoButtonClicked(username);
        olioTransfer->onLuottorajaButtonClicked(username);
        olioTransfer->onNpeuroButtonClicked(username);
        olioTransfer->onNpprosenttiButtonClicked(username);
        olioTransfer->onMuuntokerroinButtonClicked(username);
        olioTransfer->show();
    }
    else if (button->objectName()=="btOption3"){

        olioSaldo = new Saldo(this);
        olioSaldo->setToken(token);
        olioSaldo->setUsername(username);
        olioSaldo->onSaldoButtonClicked(username);
        olioSaldo->onValuuttaButtonClicked(username);
        olioSaldo->show();
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
        emit logoutRequested();
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

void Mainmenu::setToken(const QByteArray &newToken)
{
    token = newToken;
    qDebug()<<"Token Mainmenu luokassa: "<<token;
}

