#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include <QMainWindow>
#include <QSerialPort>

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

private:
Ui::MainWindow *ui;
Login *olioLogin;
QSerialPort *serialPort;
};
#endif // MAINWINDOW_H
