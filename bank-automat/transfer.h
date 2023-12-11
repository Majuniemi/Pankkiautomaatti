#ifndef TRANSFER_H
#define TRANSFER_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDateTime>
#include <QUrlQuery>

namespace Ui {
class Transfer;
}

class Transfer : public QDialog
{
    Q_OBJECT

public:
    explicit Transfer(QWidget *parent = nullptr);
    ~Transfer();

public slots:
    void setKieli(const int &newKieli);
    void numberClickHandler();
    void commandClickHandler();
    void setToken(const QByteArray &newToken);
    void setUsername(const QString &newUsername);
    void onNostoButtonClicked(QString tilinumero); // haetaan saldo
    void onLuottorajaButtonClicked(QString tilinumero); // haetaan luottoraja
    void onNpeuroButtonClicked(QString tilinumero); // haetaan nostopalkkio euro
    void onNpprosenttiButtonClicked(QString tilinumero); // haetaan nostopalkkio prosentti
    void onMuuntokerroinButtonClicked(QString tilinumero); //haetaan valuutan muuntokerroin
    void upSaldo(QString id, QString newSaldo); //päivitetään saldo
    void uusiTilitapahtuma(QDateTime aikaleima, QString saldoMuutos, QString muutosLaji, QString idTili);
    void onTiliButtonClicked(QString tilinumero);

private slots:
    void getNostoSlot (QNetworkReply *reply);
    void getLuottorajaSlot (QNetworkReply *reply);
    void getNpeuroSlot (QNetworkReply *reply);
    void getNpprosenttiSlot (QNetworkReply *reply);
    void getMuuntokerroinSlot (QNetworkReply *reply);
    void getTiliSlot(QNetworkReply *reply);

private:
    Ui::Transfer *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;
    QDateTime aikaleima;
    QString username;
    QString saavatilinumero;
    QString saldo;
    QString luottoraja;
    QString npeuro;
    QString npprosentti;
    QString muuntokerroin;
    double tilimiinus;
    int siirtokohde;
    int kieli;
};

#endif // TRANSFER_H
