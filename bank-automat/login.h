#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "mainmenu.h"

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
    void setKieli(const int &newKieli);
    void lueKortti(const QString &korttinumero);

private slots:
    void numberClickHandler();
    void enterClickHandler();
    void cancelClickHandler();
    void stopClickHandler();
    void commandClickHandler();
    void loginSlot(QNetworkReply *reply);
    void getKorttiSlot(QNetworkReply *reply);
    void getTiliSlot(QNetworkReply *reply);
    void handleLogout();

signals:
    void logoutRequested();


private:
    Ui::Login *ui;
    QNetworkAccessManager *postManager;
    QNetworkAccessManager *getcountManager;
    QNetworkAccessManager *getoneManager;
    QNetworkReply *reply;
    QNetworkReply *replyKortti;
    QNetworkReply *replyTili;
    QByteArray response_data;
    QByteArray response_dataKortti;
    QByteArray response_dataTili;
    QByteArray token;
    Mainmenu *olioMainmenu;
    QString username;
    int kieli;
};

#endif // LOGIN_H
