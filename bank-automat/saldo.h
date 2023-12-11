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
    void setKieli(const int &newKieli);

    void onSaldoButtonClicked(QString tilinumero);
    void onValuuttaButtonClicked(QString tilinumero);

private slots:
    void getSaldoSlot (QNetworkReply *reply);
    void getValuuttaSlot (QNetworkReply *reply);

private:
    Ui::Saldo *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString username;
    QByteArray token;
    int kieli;
};

#endif // SALDO_H
