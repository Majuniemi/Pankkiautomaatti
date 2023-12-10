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
 /*   void onbtOption5clicked();
    void onbtOption6clicked();
    void onbtOption7clicked();
    void onbtOption8clicked();
    void translateTo(const QString &lang);
   void updateFlagVisibility(bool visible); */

private:
    Ui::MainWindow *ui;
    Login *olioLogin;
    QSerialPort *serialPort;
    int kieli =1;
};

#endif // MAINWINDOW_H
