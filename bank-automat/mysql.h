#ifndef MYSQL_H
#define MYSQL_H

#include <QDialog>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRelationalTableModel>
#include <QString>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlTableModel>
#include <QtMath>
#include <QVector>

namespace Ui {
class MySQL;
}

class MySQL : public QDialog
{
    Q_OBJECT

public:
    explicit MySQL(QWidget *parent = nullptr);
    ~MySQL();

     int getTransactions();
      double balance;
     int actionIndex;
     QVector<QVector<QString> > logArray;

     QString fName;
     QString lName;
     QString idPerson;

private:
    Ui::MySQL *ui;
    void nullLogValues();
    void getLatestLogID();
    double removedMoney;
    int latestLogID;
    int logRowCount;
};

#endif // MYSQL_H
