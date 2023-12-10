#include "tilitapahtuma.h"
#include "ui_tilitapahtuma.h"
#include "mainmenu.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

Tilitapahtuma::Tilitapahtuma(QWidget *parent) :
    QDialog(parent),ui(new Ui::Tilitapahtuma), requestedDataCount(5)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(5);
    ui->labelOption1->setText(" ");
    ui->labelOption2->setText("Taaksepäin");
        ui->labelOption3->setText(" ");
    ui->labelOption4->setText(" ");
    ui->labelOption5->setText(" ");
    ui->labelOption6->setText("Eteenpäin");
        ui->labelOption7->setText("Takaisin");
    ui->labelOption8->setText(" ");
    ui->labelPrompt->setText(" ");
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
    connect(ui->btOption2, SIGNAL(clicked(bool)), this, SLOT(commandClickHandler()));
    connect(ui->btOption3,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption4,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption5,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption6, SIGNAL(clicked(bool)), this, SLOT(commandClickHandler()));
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
        QWidget *OlioTakaisin = new Mainmenu(this);  // siirrytään takasin mainmenuun
        OlioTakaisin->showFullScreen();
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
void Tilitapahtuma::paivitatilitapahtuma()
{

}

void Tilitapahtuma::on_btOption2_clicked() {
    qDebug() << "eteenpain nappia on painettu";
    int requestedDataCount = 5;
    updateTransactions(true, requestedDataCount);
}

void Tilitapahtuma::on_btOption6_clicked() {
    qDebug() << "Taaksepain nappi painettu";
    int requestedDataCount = 5;
    updateTransactions(false, requestedDataCount);
}
void Tilitapahtuma::updateTransactions(bool forward, int requestedDataCount) {
    QString site_url = "http://localhost:3000/Tilitapahtuma";
    QNetworkRequest request((QUrl(site_url)));
    request.setRawHeader(QByteArray("Authorization"), token);

    getManager = new QNetworkAccessManager(this);

    if (forward) {
        connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getEP(QNetworkReply*)));
    } else {
        connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getTP(QNetworkReply*)));
    }

    reply = getManager->get(request);
}
void Tilitapahtuma::getEP(QNetworkReply *reply) {
    response_data = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response_data);
    if (jsonDoc.isNull()) {
        qDebug() << "Virheellinen JSON-data.";
        return;
    }
    if (!jsonDoc.isArray()) {
        qDebug() << "JSON ei ole taulukko.";
        return;
    }
    QJsonArray jsonArray = jsonDoc.array();

    if (currentIndex + requestedDataCount <= jsonArray.size()) {
        QStringList visibleTransactions;
        for (int i = currentIndex; i < currentIndex + requestedDataCount; ++i) {
            QJsonObject transactionObject = jsonArray.at(i).toObject();

            QString transactionInfo = QString("Aika: %1, Saldomuutos: %2, Muutoslaji: %3, Tili no.: %4, Paikka: %5")
                                          .arg(transactionObject.value("Aikaleima").toString())
                                          .arg(transactionObject.value("Saldomuutos").toString())
                                          .arg(transactionObject.value("Muutoslaji").toString())
                                          .arg(transactionObject.value("idTili").toString())
                                          .arg(transactionObject.value("Paikkatieto").toString());

            visibleTransactions.append(transactionInfo);
        }
        setTilitapahtumaData(visibleTransactions);
        currentIndex += requestedDataCount;
    } else {
        qDebug() << "Ei tarpeeksi tietoja näytettäväksi.";
    }
}

void Tilitapahtuma::getTP(QNetworkReply *reply) {
    response_data = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response_data);
    if (jsonDoc.isNull()) {
        qDebug() << "Virheellinen JSON-data.";
        return;
    }
    if (!jsonDoc.isArray()) {
        qDebug() << "JSON ei ole taulukko.";
        return;
    }
    QJsonArray jsonArray = jsonDoc.array();

    if (currentIndex - requestedDataCount >= 0) {
        QStringList visibleTransactions;
        for (int i = currentIndex; i < currentIndex - requestedDataCount; ++i) {
            QJsonObject transactionObject = jsonArray.at(i).toObject();

            QString transactionInfo = QString("Aika: %1, Saldomuutos: %2, Muutoslaji: %3, Tili no.: %4, Paikka: %5")
                                          .arg(transactionObject.value("Aikaleima").toString())
                                          .arg(transactionObject.value("Saldomuutos").toString())
                                          .arg(transactionObject.value("Muutoslaji").toString())
                                          .arg(transactionObject.value("idTili").toString())
                                          .arg(transactionObject.value("Paikkatieto").toString());

            visibleTransactions.append(transactionInfo);
        }
        setTilitapahtumaData(visibleTransactions);
        currentIndex -= requestedDataCount;
    } else {
        qDebug() << "Ei tarpeeksi tietoja näytettäväksi taaksepäin.";
    }
}
void Tilitapahtuma::setTilitapahtumaData(const QStringList &tilitapahtumaData) {
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(tilitapahtumaData.size());
    ui->tableWidget->setColumnCount(5);

    int currentIndex = 0;
    for (const QString &currentIndexData : tilitapahtumaData) {
        if (currentIndex >= 5) {
            break;
        }
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Aika"));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Saldomuutos"));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Tili no."));
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Tapahtuma"));
        ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Paikka"));
        ui->tableWidget->setVerticalHeaderItem(0, new QTableWidgetItem(" "));
        ui->tableWidget->setVerticalHeaderItem(1, new QTableWidgetItem(" "));
        ui->tableWidget->setVerticalHeaderItem(2, new QTableWidgetItem(" "));
        ui->tableWidget->setVerticalHeaderItem(3, new QTableWidgetItem(" "));
        ui->tableWidget->setVerticalHeaderItem(4, new QTableWidgetItem(" "));

        QStringList columns = currentIndexData.split("     ");
        for (int col = 0; col < columns.size(); ++col) {
            ui->tableWidget->setItem(currentIndex, col, new QTableWidgetItem(columns[col]));
        }
        ++currentIndex;
    }
}
