#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
<<<<<<< HEAD
#include "ui_saldo.h"
=======
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

>>>>>>> 993d7f0bcf4b48ca59e5c850c957238396dca991

namespace Ui {
class Saldo;
}

class Saldo : public QDialog
{
    Q_OBJECT

public:
    explicit Saldo(QWidget *parent = nullptr);
    ~Saldo();
<<<<<<< HEAD
    void showSaldo(QString value);


    void setSaldoo(const QString &newSaldoo);

public slots:

    void getSaldoSlot (QNetworkReply reply);
    void commandClickHandler();
    void setToken(const QByteArray &newToken);

    void setUsername(const QString &newUsername);
    void showUsername();

    void onSaldoButtonClicked(QString tilinumero);
    void setSaldo(const QString &newSaldo);
    void showSaldo();

private:
    Ui::Saldo *ui;
    Saldo *OlioTakaisin; // olio jolla päässään takasin mainmenuun
    QString *Saldoo;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray *response_data;
    QString *username;
    QString *saldo;
    QByteArray *token;

private slots:
    void numberClickHandler();
    void commandClickHandler();
=======


public slots:
    void setKieli(const int &newKieli);
    void commandClickHandler();
    void setToken(const QByteArray &newToken);

    void setUsername(const QString &newUsername);
    void showUsername();

    void onSaldoButtonClicked(QString tilinumero);
/*    void setSaldo(const QString &newSaldo);
    void showSaldo(); */

    void onValuuttaButtonClicked(QString tilinumero);
 /*   void setValuutta(const QString &newValuutta);
    void showValuutta();*/

private slots:
    void getSaldoSlot (QNetworkReply *reply);
    void getValuuttaSlot (QNetworkReply *reply);

private:
    Ui::Saldo *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString username;
 /*   QString saldo;
    QString valuutta;*/
    QByteArray token;
    int kieli;
>>>>>>> 993d7f0bcf4b48ca59e5c850c957238396dca991
};

#endif // SALDO_H
