#include "tilitapahtuma.h"
#include "ui_tilitapahtuma.h"
#include "mainmenu.h"

Tilitapahtuma::Tilitapahtuma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tilitapahtuma)
{
    ui->setupUi(this);
    ui->labelOption1->setText(" ");
    ui->labelOption2->setText("Taaksepäin");
    ui->labelOption3->setText(" ");
    ui->labelOption4->setText(" ");
    ui->labelOption5->setText(" ");
    ui->labelOption6->setText("Eteenpäin");
    ui->labelOption7->setText(" ");
    ui->labelOption8->setText("Takaisin");
    ui->labelPrompt->setText("Tilitapahtumat");
    ui->labelInput->setText(" ");
   /* QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "my_mysql_connection");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("BankSimul_R9");
    db.setUserName("r9user");
    db.setPassword("r9pass");
    if (!db.open()) {
    qDebug() << "TILITAPAHTUMA Tietokantayhteyden avaaminen epäonnistui:" << db.lastError().text();
    }   // ripulia? aluksi ollu käytössä
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
Tilitapahtuma::~Tilitapahtuma()
{
    delete ui;
}
void Tilitapahtuma::setTilitapahtumaa(const QString &newTilitapahtumaa)
{
    tilitapahtumaa = newTilitapahtumaa;
    ui->labelInput->setText(tilitapahtumaa);
}
void Tilitapahtuma::showTilitapahtuma(QString value)
{
ui->labelInput->setText(value);
}
/*
void Tilitapahtuma::haeTilitapahtumat(int offset) {
    QSqlQuery query(db);
    query.prepare("SELECT Aikaleima, Saldomuutos, idTili, Muutoslaji, Paikkatieto FROM `banksimul_r9`.`tilitapahtumat`; LIMIT 5 OFFSET :offset");
    query.bindValue(":offset", offset);
    if (!query.exec()) {
    qDebug() << "TILITAPAHTUMA HAETILITAPAHTUMAT Tietokantakysely epäonnistui:" << query.lastError().text();
    return;
    }
    ui->labelPrompt->clear();
    ui->labelInput->clear();
    while (query.next()) {
    QString Aikaleima = query.value("Aikaleima").toString();
    QString Tilinumero = query.value("Tilinumero").toString();
    QString Paikkatieto = query.value("Paikkatieto").toString();
    QString Saldomuutos = query.value("Saldomuutos").toString();
    qDebug() << "Aikaleima: " << Aikaleima << ", Tilinumero: " << Tilinumero << ", Paikkatieto: " << Paikkatieto << ", Saldomuutos" << Saldomuutos;
    ui->labelPrompt->setText("Aika     ""Tilinumero     ""Paikka     ""Saldomuutos");
    ui->labelInput->setText(Aikaleima + "     " + Tilinumero + "     " + Paikkatieto + "     " + Saldomuutos);
    } // Ripulia? käytetty testivaiheessa
}*/
void Tilitapahtuma::numberClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if(button){
        QLabel *currentEdit = ui->labelInput;
        currentEdit->setText(currentEdit->text() + button->text());
    }
}
void Tilitapahtuma::commandClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if (button->objectName()=="btOption1"){
    }
    else if (button->objectName()=="btOption2"){
        OlioTP = new Tilitapahtuma(this); // nappi jolla saadaan edelliset 5tilitapahtumaa
        OlioTP->showFullScreen();
    }
    else if (button->objectName()=="btOption3"){
    }
    else if (button->objectName()=="btOption4"){
    }
    else if (button->objectName()=="btOption5"){
    }
    else if (button->objectName()=="btOption6"){
        OlioEP = new Tilitapahtuma(this);  // nappi jolla saadaan seuraavat 5tilitapahtumaa
        OlioEP->showFullScreen();
    }
    else if (button->objectName()=="btOption7"){
    }
    else if (button->objectName()=="btOption8"){
        QWidget *OlioTakaisin = new Mainmenu(this);  // siirrytään takasin mainmenuun
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
int nykysettilitapahtumat = 0;
void Tilitapahtuma::paivitatilitapahtuma() {
 /*   QSqlQuery query;
    if  (query.exec(QString("SELECT Aikaleima, Saldomuutos, idTili, Muutoslaji, Paikkatieto FROM `banksimul_r9`.`tilitapahtumat` WHERE Tilinumero = '%1' LIMIT 5 OFFSET %2").arg(nykysettilitapahtumat))){
    while (query.next()) {
    QString aikaleima = query.value(0).toString();
    int saldomuutos = query.value(2).toInt();
    int idTili = query.value(3).toInt();
    QString muutoslaji = query.value(4).toString();
    QString paikkatieto = query.value(5).toString();
    qDebug() << aikaleima << saldomuutos << idTili << muutoslaji << paikkatieto;
    }
    } else {
    qDebug() << "TILITAPAHTUMA Tilitapahtuma::paivitatilitapahtuma " << query.lastError().text();
    }
}  // tulostetaan ruudulle tietokannasta tietoja 5kappaletta.
void Tilitapahtuma::on_btOption2_clicked()
{
    nykysettilitapahtumat -= 5;
    if (nykysettilitapahtumat < 0) {
    nykysettilitapahtumat = 0;
    QSqlQuery query;
    qDebug() << "miinustus epäonnistu" << query.lastError().text();
    }
    paivitatilitapahtuma();
} // taaksepäin buttonille koodi
void Tilitapahtuma::on_btOption6_clicked()
{
    nykysettilitapahtumat += 5;
    QSqlQuery query;
    qDebug() << "Lisäys epäonnistui" << query.lastError().text();
    paivitatilitapahtuma();
} // etenpäin buttonille koodi*/
}
