#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
MainWindow(QWidget *parent = nullptr);
~MainWindow();
int tila=0;

public slots:
void numberClickHandler();
void commandClickHandler();
void enterClickedHandler();

private slots:
void loginSlot(QNetworkReply *reply);

private:
Ui::MainWindow *ui;
QNetworkAccessManager *postManager;
QNetworkReply *reply;
QByteArray response_data;
};
#endif // MAINWINDOW_H
