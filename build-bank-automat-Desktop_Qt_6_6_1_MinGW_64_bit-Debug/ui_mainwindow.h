/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *centralwidget_2;
    QPushButton *btNum1;
    QPushButton *btNum2;
    QPushButton *btNum3;
    QPushButton *btNum4;
    QPushButton *btNum5;
    QPushButton *btNum6;
    QPushButton *btNum7;
    QPushButton *btNum8;
    QPushButton *btNum9;
    QPushButton *btBLDBT;
    QPushButton *btNum0;
    QPushButton *btBRDBT;
    QPushButton *btStop;
    QPushButton *btCancel;
    QPushButton *btDBT;
    QPushButton *btAccept;
    QFrame *frame;
    QLabel *labelOption1;
    QLabel *labelOption2;
    QLabel *labelOption4;
    QLabel *labelOption3;
    QLabel *labelOption6;
    QLabel *labelOption7;
    QLabel *labelOption8;
    QLabel *labelOption5;
    QLabel *labelKortti;
    QLabel *labelPrompt;
    QLabel *labelUser;
    QLabel *labelInput;
    QPushButton *btOption4;
    QPushButton *btOption3;
    QPushButton *btOption1;
    QPushButton *btOption2;
    QPushButton *btOption8;
    QPushButton *btOption7;
    QPushButton *btOption5;
    QPushButton *btOption6;
    QMenuBar *menubar;
    QMenu *menuBankSimul_R9;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(2560, 1440);
        MainWindow->setMinimumSize(QSize(2560, 1440));
        MainWindow->setBaseSize(QSize(2560, 1440));
        QPalette palette;
        QBrush brush(QColor(214, 214, 214, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(148, 17, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        QBrush brush2(QColor(73, 12, 17, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 160, 2171, 1251));
        label->setBaseSize(QSize(2560, 1440));
        QPalette palette1;
        QBrush brush3(QColor(191, 191, 191, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        QBrush brush4(QColor(231, 215, 199, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        QBrush brush5(QColor(0, 120, 215, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush5);
        label->setPalette(palette1);
        label->setPixmap(QPixmap(QString::fromUtf8(":/Tausta/Taustakuva.jpg")));
        label->setAlignment(Qt::AlignCenter);
        centralwidget_2 = new QWidget(centralwidget);
        centralwidget_2->setObjectName("centralwidget_2");
        centralwidget_2->setGeometry(QRect(160, 130, 2560, 1440));
        centralwidget_2->setMinimumSize(QSize(2560, 1440));
        centralwidget_2->setBaseSize(QSize(2560, 1440));
        QPalette palette2;
        QBrush brush6(QColor(235, 235, 235, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        centralwidget_2->setPalette(palette2);
        btNum1 = new QPushButton(centralwidget_2);
        btNum1->setObjectName("btNum1");
        btNum1->setGeometry(QRect(150, 390, 41, 41));
        btNum1->setBaseSize(QSize(2560, 1440));
        QPalette palette3;
        QBrush brush7(QColor(28, 240, 54, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btNum1->setPalette(palette3);
        btNum2 = new QPushButton(centralwidget_2);
        btNum2->setObjectName("btNum2");
        btNum2->setGeometry(QRect(200, 390, 41, 41));
        btNum2->setBaseSize(QSize(2560, 1440));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btNum2->setPalette(palette4);
        btNum3 = new QPushButton(centralwidget_2);
        btNum3->setObjectName("btNum3");
        btNum3->setGeometry(QRect(250, 390, 41, 41));
        btNum3->setBaseSize(QSize(2560, 1440));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btNum3->setPalette(palette5);
        btNum4 = new QPushButton(centralwidget_2);
        btNum4->setObjectName("btNum4");
        btNum4->setGeometry(QRect(150, 440, 41, 41));
        btNum4->setBaseSize(QSize(2560, 1440));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btNum4->setPalette(palette6);
        btNum5 = new QPushButton(centralwidget_2);
        btNum5->setObjectName("btNum5");
        btNum5->setGeometry(QRect(200, 440, 41, 41));
        btNum5->setBaseSize(QSize(2560, 1440));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btNum5->setPalette(palette7);
        btNum6 = new QPushButton(centralwidget_2);
        btNum6->setObjectName("btNum6");
        btNum6->setGeometry(QRect(250, 440, 41, 41));
        btNum6->setBaseSize(QSize(2560, 1440));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btNum6->setPalette(palette8);
        btNum7 = new QPushButton(centralwidget_2);
        btNum7->setObjectName("btNum7");
        btNum7->setGeometry(QRect(150, 490, 41, 41));
        btNum7->setBaseSize(QSize(2560, 1440));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btNum7->setPalette(palette9);
        btNum8 = new QPushButton(centralwidget_2);
        btNum8->setObjectName("btNum8");
        btNum8->setGeometry(QRect(200, 490, 41, 41));
        btNum8->setBaseSize(QSize(2560, 1440));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btNum8->setPalette(palette10);
        btNum9 = new QPushButton(centralwidget_2);
        btNum9->setObjectName("btNum9");
        btNum9->setGeometry(QRect(250, 490, 41, 41));
        btNum9->setBaseSize(QSize(2560, 1440));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btNum9->setPalette(palette11);
        btBLDBT = new QPushButton(centralwidget_2);
        btBLDBT->setObjectName("btBLDBT");
        btBLDBT->setGeometry(QRect(150, 540, 41, 41));
        btBLDBT->setBaseSize(QSize(2560, 1440));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btBLDBT->setPalette(palette12);
        btNum0 = new QPushButton(centralwidget_2);
        btNum0->setObjectName("btNum0");
        btNum0->setGeometry(QRect(200, 540, 41, 41));
        btNum0->setBaseSize(QSize(2560, 1440));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btNum0->setPalette(palette13);
        btBRDBT = new QPushButton(centralwidget_2);
        btBRDBT->setObjectName("btBRDBT");
        btBRDBT->setGeometry(QRect(250, 540, 41, 41));
        btBRDBT->setBaseSize(QSize(2560, 1440));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btBRDBT->setPalette(palette14);
        btStop = new QPushButton(centralwidget_2);
        btStop->setObjectName("btStop");
        btStop->setGeometry(QRect(300, 390, 81, 41));
        btStop->setBaseSize(QSize(2560, 1440));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btStop->setPalette(palette15);
        btCancel = new QPushButton(centralwidget_2);
        btCancel->setObjectName("btCancel");
        btCancel->setGeometry(QRect(300, 440, 81, 41));
        btCancel->setBaseSize(QSize(2560, 1440));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btCancel->setPalette(palette16);
        btDBT = new QPushButton(centralwidget_2);
        btDBT->setObjectName("btDBT");
        btDBT->setGeometry(QRect(300, 490, 81, 41));
        btDBT->setBaseSize(QSize(2560, 1440));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btDBT->setPalette(palette17);
        btAccept = new QPushButton(centralwidget_2);
        btAccept->setObjectName("btAccept");
        btAccept->setGeometry(QRect(300, 540, 81, 41));
        btAccept->setBaseSize(QSize(2560, 1440));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btAccept->setPalette(palette18);
        frame = new QFrame(centralwidget_2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(130, 20, 271, 241));
        frame->setBaseSize(QSize(2560, 1440));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        labelOption1 = new QLabel(frame);
        labelOption1->setObjectName("labelOption1");
        labelOption1->setGeometry(QRect(10, 50, 91, 41));
        labelOption1->setBaseSize(QSize(2560, 1440));
        labelOption2 = new QLabel(frame);
        labelOption2->setObjectName("labelOption2");
        labelOption2->setGeometry(QRect(10, 100, 91, 41));
        labelOption2->setBaseSize(QSize(2560, 1440));
        labelOption4 = new QLabel(frame);
        labelOption4->setObjectName("labelOption4");
        labelOption4->setGeometry(QRect(10, 200, 91, 41));
        labelOption4->setBaseSize(QSize(2560, 1440));
        labelOption3 = new QLabel(frame);
        labelOption3->setObjectName("labelOption3");
        labelOption3->setGeometry(QRect(10, 150, 91, 41));
        labelOption3->setBaseSize(QSize(2560, 1440));
        labelOption6 = new QLabel(frame);
        labelOption6->setObjectName("labelOption6");
        labelOption6->setGeometry(QRect(170, 100, 91, 41));
        labelOption6->setBaseSize(QSize(2560, 1440));
        labelOption6->setPixmap(QPixmap(QString::fromUtf8(":/liput/Liput/Ruotsinlippu.png")));
        labelOption6->setScaledContents(true);
        labelOption6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelOption7 = new QLabel(frame);
        labelOption7->setObjectName("labelOption7");
        labelOption7->setGeometry(QRect(170, 150, 91, 41));
        labelOption7->setBaseSize(QSize(2560, 1440));
        labelOption7->setPixmap(QPixmap(QString::fromUtf8(":/liput/Liput/Brittilippu.png")));
        labelOption7->setScaledContents(true);
        labelOption7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelOption8 = new QLabel(frame);
        labelOption8->setObjectName("labelOption8");
        labelOption8->setGeometry(QRect(170, 200, 91, 41));
        labelOption8->setBaseSize(QSize(2560, 1440));
        labelOption8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelOption5 = new QLabel(frame);
        labelOption5->setObjectName("labelOption5");
        labelOption5->setGeometry(QRect(170, 50, 91, 41));
        labelOption5->setBaseSize(QSize(2560, 1440));
        labelOption5->setPixmap(QPixmap(QString::fromUtf8(":/liput/Liput/Suomenlippu.png")));
        labelOption5->setScaledContents(true);
        labelOption5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelKortti = new QLabel(frame);
        labelKortti->setObjectName("labelKortti");
        labelKortti->setGeometry(QRect(70, 60, 121, 16));
        labelKortti->setBaseSize(QSize(2560, 1440));
        labelPrompt = new QLabel(frame);
        labelPrompt->setObjectName("labelPrompt");
        labelPrompt->setGeometry(QRect(70, 100, 131, 41));
        labelPrompt->setBaseSize(QSize(2560, 1440));
        labelPrompt->setAlignment(Qt::AlignCenter);
        labelUser = new QLabel(frame);
        labelUser->setObjectName("labelUser");
        labelUser->setEnabled(false);
        labelUser->setGeometry(QRect(60, 90, 4, 12));
        labelUser->setBaseSize(QSize(2560, 1440));
        labelInput = new QLabel(frame);
        labelInput->setObjectName("labelInput");
        labelInput->setGeometry(QRect(10, 130, 251, 20));
        labelInput->setBaseSize(QSize(2560, 1440));
        labelInput->setAlignment(Qt::AlignCenter);
        btOption4 = new QPushButton(centralwidget_2);
        btOption4->setObjectName("btOption4");
        btOption4->setGeometry(QRect(80, 220, 41, 41));
        btOption4->setBaseSize(QSize(2560, 1440));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btOption4->setPalette(palette19);
        btOption3 = new QPushButton(centralwidget_2);
        btOption3->setObjectName("btOption3");
        btOption3->setGeometry(QRect(80, 170, 41, 41));
        btOption3->setBaseSize(QSize(2560, 1440));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette20.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette20.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btOption3->setPalette(palette20);
        btOption1 = new QPushButton(centralwidget_2);
        btOption1->setObjectName("btOption1");
        btOption1->setGeometry(QRect(80, 70, 41, 41));
        btOption1->setBaseSize(QSize(2560, 1440));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btOption1->setPalette(palette21);
        btOption2 = new QPushButton(centralwidget_2);
        btOption2->setObjectName("btOption2");
        btOption2->setGeometry(QRect(80, 120, 41, 41));
        btOption2->setBaseSize(QSize(2560, 1440));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette22.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette22.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btOption2->setPalette(palette22);
        btOption8 = new QPushButton(centralwidget_2);
        btOption8->setObjectName("btOption8");
        btOption8->setGeometry(QRect(410, 220, 41, 41));
        btOption8->setBaseSize(QSize(2560, 1440));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette23.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette23.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btOption8->setPalette(palette23);
        btOption7 = new QPushButton(centralwidget_2);
        btOption7->setObjectName("btOption7");
        btOption7->setGeometry(QRect(410, 170, 41, 41));
        btOption7->setBaseSize(QSize(2560, 1440));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette24.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette24.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btOption7->setPalette(palette24);
        btOption5 = new QPushButton(centralwidget_2);
        btOption5->setObjectName("btOption5");
        btOption5->setGeometry(QRect(410, 70, 41, 41));
        btOption5->setBaseSize(QSize(2560, 1440));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::Button, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btOption5->setPalette(palette25);
        btOption6 = new QPushButton(centralwidget_2);
        btOption6->setObjectName("btOption6");
        btOption6->setGeometry(QRect(410, 120, 41, 41));
        btOption6->setBaseSize(QSize(2560, 1440));
        QPalette palette26;
        palette26.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette26.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette26.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        btOption6->setPalette(palette26);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 2560, 17));
        menuBankSimul_R9 = new QMenu(menubar);
        menuBankSimul_R9->setObjectName("menuBankSimul_R9");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuBankSimul_R9->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        btNum1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btNum2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btNum3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btNum4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        btNum5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btNum6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btNum7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btNum8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btNum9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btBLDBT->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        btNum0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btBRDBT->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btStop->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        btCancel->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        btDBT->setText(QString());
        btAccept->setText(QCoreApplication::translate("MainWindow", "O", nullptr));
        labelOption1->setText(QCoreApplication::translate("MainWindow", "Option1", nullptr));
        labelOption2->setText(QCoreApplication::translate("MainWindow", "Option2", nullptr));
        labelOption4->setText(QCoreApplication::translate("MainWindow", "Option4", nullptr));
        labelOption3->setText(QCoreApplication::translate("MainWindow", "Option3", nullptr));
        labelOption6->setText(QString());
        labelOption7->setText(QString());
        labelOption8->setText(QCoreApplication::translate("MainWindow", "Option8", nullptr));
        labelOption5->setText(QString());
        labelKortti->setText(QString());
        labelPrompt->setText(QString());
        labelUser->setText(QString());
        labelInput->setText(QCoreApplication::translate("MainWindow", "input", nullptr));
        btOption4->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        btOption3->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        btOption1->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        btOption2->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        btOption8->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        btOption7->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        btOption5->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        btOption6->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        menuBankSimul_R9->setTitle(QCoreApplication::translate("MainWindow", "BankSimul_R9", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
