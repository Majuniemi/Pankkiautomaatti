#ifndef TILITAPAHTUMA_H
#define TILITAPAHTUMA_H
#include <QDialog>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QPushButton>

namespace Ui {
class Tilitapahtuma;
}

class Tilitapahtuma : public QDialog
{
    Q_OBJECT

public:
    explicit Tilitapahtuma(QWidget *parent = nullptr);
    ~Tilitapahtuma();

    void setToken(const QByteArray &newToken);
    void setUsername(const QString &newUsername);
    void setKieli(const int &newKieli);

public slots:
    void onTTButtonClicked(QString tilinumero, QString offset);

private:
    Ui::Tilitapahtuma *ui;
    QString tilitapahtumaa;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QNetworkAccessManager *postManager;
    QByteArray token;
    QString username;
    QString offset;
    int offsetnum = 0;
    int kieli;

private slots:
    void commandClickHandler();
    void getTTSlot(QNetworkReply *reply);
};

#endif // TILITAPAHTUMA_H
