#ifndef MAINMENU_H
#define MAINMENU_H

#include "saldo.h"
#include "withdraw.h"
#include "transfer.h"
#include <QDialog>
#include "qtablewidget.h"
#include "tilitapahtuma.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDebug>
#include <QMainWindow>

namespace Ui {
class Mainmenu;
}

class Mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit Mainmenu(QWidget *parent = nullptr);
    ~Mainmenu();

    void setToken(const QByteArray &newToken);
    void setUsername(const QString &newUsername);
    void setKieli(const int &newKieli);


public slots:
    void numberClickHandler();
    void commandClickHandler();

private slots:
   void on_btOption4_clicked(); //Tilitapahtuma
   void getTT(QNetworkReply *reply); //GetTilitapahtuma


private:
    Ui::Mainmenu *ui;
    Withdraw *olioWithdraw;
    Saldo *olioSaldo;
    Transfer *olioTransfer;
    QString username;
    QString saldo;
    QString valuutta;
    QByteArray token;
    Tilitapahtuma *OlioTT; //tilitapahtumaolio
    //  Saldo *OlioSaldo; // saldoolio
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QNetworkAccessManager *postManager;
     Tilitapahtuma *tilitapahtumalista; //tilitaphtuman käsittelyyn
    // Saldo *objectSaldo; //saldon käsittelyyn
    int TTmaara; //Tilitapahtumamäärä (CAP5)
    int kieli;
};

#endif // MAINMENU_H
