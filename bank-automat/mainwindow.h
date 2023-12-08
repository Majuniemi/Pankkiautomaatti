#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
MainWindow(QWidget *parent = nullptr);
~MainWindow();

public slots:
void numberClickHandler();
void commandClickHandler();
void readData();
void handleLogout();

private:
Ui::MainWindow *ui;
Login *olioLogin;
QSerialPort *serialPort;
bool kirjautunut = false;
};
#endif // MAINWINDOW_H
