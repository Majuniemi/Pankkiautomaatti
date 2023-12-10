#include "mainmenu.h"
#include "ui_mainmenu.h"

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

Mainmenu::~Mainmenu()
{
    delete ui;
}

void Mainmenu::numberClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());


    if(button){
        QLabel *currentEdit = ui->labelInput;
        currentEdit->setText(currentEdit->text() + button->text());
    }
}

void Mainmenu::commandClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    if (button->objectName()=="btOption1"){

    }
    else if (button->objectName()=="btOption2"){

    }
    else if (button->objectName()=="btOption3"){

    }
    else if (button->objectName()=="btOption4"){
        OlioTT = new Tilitapahtuma(this);
        OlioTT->showFullScreen();
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
void Mainmenu::getTT(QNetworkReply *reply)
{
   response_data = reply->readAll();
   qDebug() << "response data on nyt:" + response_data;

   QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
   QJsonArray json_array = json_doc.array();
       QStringList tilitapahtumaData;
       int maxRows = qMin(5, json_array.size() - currentIndex);
       for (int i = 0; i < maxRows; ++i) {
           QJsonObject json_obj = json_array.at(currentIndex + i).toObject();
           QString rowData = QString::number(json_obj["Saldomuutos"].toInt()) + "     " +
                             QString::number(json_obj["Aikaleima"].toInt()) + "     " +
                             json_obj["Muutoslaji"].toString() + "     " +
                             QString::number(json_obj["idTili"].toInt()) + "     " +
                             json_obj["Paikkatieto"].toString();
           tilitapahtumaData.append(rowData);
       }
       tilitapahtumalista = new Tilitapahtuma(this);
       tilitapahtumalista->setTilitapahtumaData(tilitapahtumaData);
       tilitapahtumalista->showFullScreen();
       currentIndex += maxRows;
   }
   //}

  //tilitapahtumalista = new Tilitapahtuma(this);
 //  tilitapahtumalista->setTilitapahtumaData(tilitapahtumaData);
  // tilitapahtumalista->showFullScreen();
//}

void Mainmenu::setToken(const QByteArray &newToken)
{
    token = newToken;
    qDebug()<<"Token Mainmenu luokassa: "<<token;
}
