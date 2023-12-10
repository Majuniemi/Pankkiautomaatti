#ifndef TILITAPAHTUMA_H
#define TILITAPAHTUMA_H

#include "qtablewidget.h"
#include <QDialog>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QTableWidget>
#include <QPushButton>


namespace Ui {
class Tilitapahtuma;
}

class Tilitapahtuma : public QDialog
{
    Q_OBJECT

public slots:

    void getEP(QNetworkReply* reply);
    void getTP(QNetworkReply *reply);
public:
    explicit Tilitapahtuma(QWidget *parent = nullptr);
    ~Tilitapahtuma();

    void setToken(const QByteArray &newToken);

    void setTilitapahtumaa(const QString &newTilitapahtumaa);
    void showTilitapahtuma(QString value);
    // int nykysettilitapahtumat; // käsitellään ikkunaan tulevia tilitapahtumia ja näytetään max 5kpl
    void paivitatilitapahtuma();
    void setTilitapahtumaData(const QStringList &tilitapahtumaData);
    void setAllTransactions(const QJsonArray &transactions);
    void updateTransactions(bool forward, int requestedDataCount);

private:
    Ui::Tilitapahtuma *ui;
    Tilitapahtuma *OlioTakaisin; // Olio jolla luodaan nappiin takasin toiminto jolla pääsee takaisin mainmenuun
    Tilitapahtuma *OlioEP; //Olio jolla luodaan nappiin eteenpäin toiminto +5
    Tilitapahtuma *OlioTP; // olio joilla luodaan nappiin taaksepäin toiminto -5
    QString tilitapahtumaa;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QNetworkAccessManager *postManager;
    Tilitapahtuma *tilitapahtumalista;
    QByteArray token;
    QTableWidget* tableWidget;
     QList<QString> PTilitapahtuma;
    int ATMRow;
    int Tilitapahtumatpersivu;
    QStringList allTransactions;
     int currentIndex;
    void EP(const QString &responseData);
    void TP(const QString &responseData);
     int requestedDataCount;


private slots:
    void numberClickHandler();
    void commandClickHandler();
    void on_btOption2_clicked();
    void on_btOption6_clicked();
};

#endif // TILITAPAHTUMA_H
