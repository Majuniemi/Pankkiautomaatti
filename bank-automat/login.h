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

private slots:
    void numberClickHandler();
    void enterClickHandler();
    void cancelClickHandler();
    void stopClickHandler();
    void loginSlot(QNetworkReply *reply);

private:
    Ui::Login *ui;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;

    Mainmenu *olioMainmenu;
};

#endif // LOGIN_H
