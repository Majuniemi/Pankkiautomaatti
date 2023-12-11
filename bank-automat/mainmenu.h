#ifndef MAINMENU_H
#define MAINMENU_H

#include "saldo.h"
#include "tilitapahtuma.h"
#include "withdraw.h"
#include "transfer.h"
#include <QDialog>

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
    void commandClickHandler();

signals:
    void logoutRequested();

private:
    Ui::Mainmenu *ui;
    Withdraw *olioWithdraw;
    Saldo *olioSaldo;
    Transfer *olioTransfer;
    Tilitapahtuma *OlioTT;
    QString username;
    QString saldo;
    QString valuutta;
    QByteArray token;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    int kieli;
};

#endif // MAINMENU_H
