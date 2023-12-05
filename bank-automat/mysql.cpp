#include "mysql.h"
#include "qsqlquery.h"
#include "ui_mysql.h"

MySQL::MySQL(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MySQL)
{
    ui->setupUi(this);
}

MySQL::~MySQL()
{
    delete ui;
}
int MySQL::getTransactions(){
    logArray.clear();   //Clearing 2D vector
    QSqlTableModel transAcionModel;     //Using QSqlTableModel to get rowCount of the accounts
    transAcionModel.setTable("Log");    //Selecting Log table
    transAcionModel.setFilter("idPerson=\""+idPerson+"\" AND (actionIndex=3 OR actionIndex=4)");  //checkin right person and actionIndex
    transAcionModel.select();   //exec
    qDebug() << "SQLDebug 21 " << "transAcionModel.rowCount()" << transAcionModel.rowCount() << Qt::endl; //Debug 21
    QString array[12];
    QSqlQuery qryL;
    //Get all info from log table if idperson and actionIndex is 3 or 4
    qryL.prepare("SELECT * FROM tilitapahtumat where idTili=\""+idPerson+"\" AND (actionIndex=3 OR actionIndex=4) ORDER BY idTili desc");
    qryL.exec();    //Query L exec
    for (int i = 0; i < transAcionModel.rowCount(); i++) {
        while (qryL.next()) {
            QVector<QString> tempVec;   //Temporary QString vector
            for (int j = 0; j < 12; j++) {
                array[j] = qryL.value(j).toString();    //Putting Log values to array
                tempVec.push_back(array[j]);    //Putting array value to vector
                qDebug() << "SQLDebug 22." << i << "." << j << " " << array[j] << Qt::endl; //Debug 22.*
            }
            //Temporary vector put to 2D vector
            logArray.push_back(tempVec);    //2D vector for all transactions of the person [rows][QString]
        }
    }
    //Debug############# 23.*
    for (int i = 0; i < logArray.length(); i++) {
        qDebug() << "SQLDebug 23." << i << " " << logArray.length() << Qt::endl; //Debug 23.*
        for (int j = 0; j < 12; j++) {
            qDebug() << "SQLDebug  24." << i << "." << j << " " << logArray.value(i).value(j) << Qt::endl; //Debug 24.*.*
        }
    }
    qDebug() << "SQLDebug 25 " << logArray.value(0).value(0) << Qt::endl; //Debug 25
    qDebug() << "SQLDebug 26 " << logArray.value(1).value(0) << Qt::endl; //Debug 26
    qDebug() << "SQLDebug 27 " << logArray.value(2).value(0) << Qt::endl; //Debug 27
    qDebug() << "SQLDebug 28 " << logArray.value(3).value(0) << Qt::endl; //Debug 28
    //###########Debug*
    return transAcionModel.rowCount();  //retunrs how many transactions there are
}
void MySQL::getLatestLogID(){
    QSqlQuery qryL;
    //Get Max log id that has been inserted
    qryL.prepare("SELECT MAX(idLog) from Log order by idLog desc");
    qryL.exec();
    while (qryL.next()) {
        latestLogID = qryL.value(0).toInt() + 1;    //Adding one to Max log id
        qDebug() << "SQLDebug 30 " << "latestLogID = " << latestLogID << Qt::endl;  //Debug 30
    }
}
