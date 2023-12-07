#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class Saldo;
}

class Saldo : public QDialog
{
    Q_OBJECT

public:
    explicit Saldo(QWidget *parent = nullptr);
    ~Saldo();


public slots:

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
};

#endif // SALDO_H
