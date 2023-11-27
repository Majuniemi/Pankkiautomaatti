#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include <QMainWindow>

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

private:
Ui::MainWindow *ui;
Login *olioLogin;
};
#endif // MAINWINDOW_H
