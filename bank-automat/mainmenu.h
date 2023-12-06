#ifndef MAINMENU_H
#define MAINMENU_H

#include "saldo.h"
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

public slots:
    void numberClickHandler();
    void commandClickHandler();
    void setUsername(const QString &newUsername);
    void setToken(const QByteArray &newToken);
    void showUsername();

private:
    Ui::Mainmenu *ui;
    Withdraw *olioWithdraw;
    Saldo *olioSaldo;
    Transfer *olioTransfer;
    QString username;
    QString saldo;
    QString valuutta;
    QByteArray token;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // MAINMENU_H
