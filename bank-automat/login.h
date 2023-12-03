#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <mainmenu.h>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

public slots:
    void lueKortti(const QString &korttinumero);

private slots:
    void numberClickHandler();
    void enterClickHandler();
    void cancelClickHandler();
    void stopClickHandler();
    void commandClickHandler();
    void loginSlot(QNetworkReply *reply);
    void getKorttiSlot(QNetworkReply *reply);

private:
    Ui::Login *ui;
    QNetworkAccessManager *postManager;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QNetworkReply *replyKortti;
    QByteArray response_data;
    QByteArray response_dataKortti;
    QByteArray token;
    Mainmenu *olioMainmenu;
    QString username;
};

#endif // LOGIN_H
