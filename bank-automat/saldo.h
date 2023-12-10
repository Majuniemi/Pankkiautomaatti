#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include "ui_saldo.h"
#include "mainmenu.h"
#include <QNetworkAccessManager>
#include <QByteArray>

namespace Ui {
class Saldo;
}

class Saldo : public QDialog
{
    Q_OBJECT

public:
    explicit Saldo(QWidget *parent = nullptr);
    ~Saldo();
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

};

#endif // SALDO_H
