#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDateTime>
#include <QUrlQuery>

namespace Ui {
class Withdraw;
}

class Withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit Withdraw(QWidget *parent = nullptr);
    ~Withdraw();

public slots:
    void setKieli(const int &newKieli);
    void commandClickHandler();
    void numberClickHandler();
    void setToken(const QByteArray &newToken);

    void setUsername(const QString &newUsername);
    void showUsername();

    void onNostoButtonClicked(QString tilinumero); // haetaan saldo


    void onLuottorajaButtonClicked(QString tilinumero); // haetaan luottoraja


    void onNpeuroButtonClicked(QString tilinumero); // haetaan nostopalkkio euro


    void onNpprosenttiButtonClicked(QString tilinumero); // haetaan nostopalkkio prosentti


    void onMuuntokerroinButtonClicked(QString tilinumero); //haetaan valuutan muuntokerroin

    void upSaldo(QString id, QString newSaldo); //päivitetään saldo
    void uusiTilitapahtuma(QDateTime aikaleima, QString saldoMuutos, QString idTili);


private slots:
    void getNostoSlot (QNetworkReply *reply);
    void getLuottorajaSlot (QNetworkReply *reply);
    void getNpeuroSlot (QNetworkReply *reply);
    void getNpprosenttiSlot (QNetworkReply *reply);
    void getMuuntokerroinSlot (QNetworkReply *reply);

private:
    Ui::Withdraw *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString username;
    QString saldo;
    QString luottoraja;
    QString npeuro;
    QString npprosentti;
    QString muuntokerroin;
    double tilimiinus;
    int muusumma=0;
    QByteArray token;
    QDateTime aikaleima;
    int kieli;
};

#endif // WITHDRAW_H
