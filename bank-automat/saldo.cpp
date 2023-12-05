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
   /* QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "my_mysql_connection");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("BankSimul_R9");
    db.setUserName("r9user");
    db.setPassword("r9pass");
    if (!db.open()) {
    qDebug() << "SALDO Tietokantayhteyden avaaminen epäonnistui:" << db.lastError().text();
    }*/  // ripulia? aluksi ollu käytössä
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
} /*
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
