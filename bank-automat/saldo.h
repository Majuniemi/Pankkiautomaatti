#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include "ui_saldo.h"

namespace Ui {
class Saldo;
}

class Saldo : public QDialog
{
    Q_OBJECT

public:
    explicit Saldo(QWidget *parent = nullptr);
    ~Saldo();
    void showSaldo(QString value);


    void setSaldoo(const QString &newSaldoo);

public slots:

 //   void naytaSaldo();

private:
    Ui::Saldo *ui;
    Saldo *OlioTakaisin; // olio jolla päässään takasin mainmenuun
    //QSqlDatabase db;
    QString Saldoo;
private slots:
    void numberClickHandler();
    void commandClickHandler();
};

#endif // SALDO_H
