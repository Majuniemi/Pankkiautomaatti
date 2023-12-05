#ifndef TILITAPAHTUMA_H
#define TILITAPAHTUMA_H

#include <QDialog>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

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

    void setTilitapahtumaa(const QString &newTilitapahtumaa);
    void showTilitapahtuma(QString value);
int nykysettilitapahtumat; // käsitellään ikkunaan tulevia tilitapahtumia ja näytetään max 5kpl
private:
    Ui::Tilitapahtuma *ui;
    Tilitapahtuma *OlioTakaisin; // Olio jolla luodaan nappiin takasin toiminto jolla pääsee takaisin mainmenuun
    Tilitapahtuma *OlioEP; //Olio jolla luodaan nappiin eteenpäin toiminto +5
    Tilitapahtuma *OlioTP; // olio joilla luodaan nappiin taaksepäin toiminto -5
    QString tilitapahtumaa;

private slots:
    void numberClickHandler();
    void commandClickHandler();
    void paivitatilitapahtuma(); // päivitetään tilitapahtumat näytölle


   // void on_btOption2_clicked(); // -5nappi
   // void on_btOption6_clicked(); //+5 nappi
};

#endif // TILITAPAHTUMA_H
