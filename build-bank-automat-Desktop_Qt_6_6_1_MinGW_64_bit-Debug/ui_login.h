/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "login.h"

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
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
    QLabel *label_2;
    QLabel *labelPrompt;
    QLabel *labelUser;
    QLineEdit *lineEditPassword;
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
    QLabel *label;

    void setupUi(Login *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(2560, 1440);
        Login->setMinimumSize(QSize(2560, 1440));
        Login->setBaseSize(QSize(2560, 1440));
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
        Login->setPalette(palette);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(1160, 650, 2560, 1440));
        centralwidget->setMinimumSize(QSize(2560, 1440));
        centralwidget->setBaseSize(QSize(2560, 1440));
        QPalette palette1;
        QBrush brush3(QColor(235, 235, 235, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        centralwidget->setPalette(palette1);
        btNum1 = new QPushButton(centralwidget);
        btNum1->setObjectName("btNum1");
        btNum1->setGeometry(QRect(150, 390, 41, 41));
        btNum1->setBaseSize(QSize(2560, 1440));
        QPalette palette2;
        QBrush brush4(QColor(28, 240, 54, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btNum1->setPalette(palette2);
        btNum2 = new QPushButton(centralwidget);
        btNum2->setObjectName("btNum2");
        btNum2->setGeometry(QRect(200, 390, 41, 41));
        btNum2->setBaseSize(QSize(2560, 1440));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btNum2->setPalette(palette3);
        btNum3 = new QPushButton(centralwidget);
        btNum3->setObjectName("btNum3");
        btNum3->setGeometry(QRect(250, 390, 41, 41));
        btNum3->setBaseSize(QSize(2560, 1440));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btNum3->setPalette(palette4);
        btNum4 = new QPushButton(centralwidget);
        btNum4->setObjectName("btNum4");
        btNum4->setGeometry(QRect(150, 440, 41, 41));
        btNum4->setBaseSize(QSize(2560, 1440));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btNum4->setPalette(palette5);
        btNum5 = new QPushButton(centralwidget);
        btNum5->setObjectName("btNum5");
        btNum5->setGeometry(QRect(200, 440, 41, 41));
        btNum5->setBaseSize(QSize(2560, 1440));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btNum5->setPalette(palette6);
        btNum6 = new QPushButton(centralwidget);
        btNum6->setObjectName("btNum6");
        btNum6->setGeometry(QRect(250, 440, 41, 41));
        btNum6->setBaseSize(QSize(2560, 1440));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btNum6->setPalette(palette7);
        btNum7 = new QPushButton(centralwidget);
        btNum7->setObjectName("btNum7");
        btNum7->setGeometry(QRect(150, 490, 41, 41));
        btNum7->setBaseSize(QSize(2560, 1440));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btNum7->setPalette(palette8);
        btNum8 = new QPushButton(centralwidget);
        btNum8->setObjectName("btNum8");
        btNum8->setGeometry(QRect(200, 490, 41, 41));
        btNum8->setBaseSize(QSize(2560, 1440));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btNum8->setPalette(palette9);
        btNum9 = new QPushButton(centralwidget);
        btNum9->setObjectName("btNum9");
        btNum9->setGeometry(QRect(250, 490, 41, 41));
        btNum9->setBaseSize(QSize(2560, 1440));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btNum9->setPalette(palette10);
        btBLDBT = new QPushButton(centralwidget);
        btBLDBT->setObjectName("btBLDBT");
        btBLDBT->setGeometry(QRect(150, 540, 41, 41));
        btBLDBT->setBaseSize(QSize(2560, 1440));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btBLDBT->setPalette(palette11);
        btNum0 = new QPushButton(centralwidget);
        btNum0->setObjectName("btNum0");
        btNum0->setGeometry(QRect(200, 540, 41, 41));
        btNum0->setBaseSize(QSize(2560, 1440));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btNum0->setPalette(palette12);
        btBRDBT = new QPushButton(centralwidget);
        btBRDBT->setObjectName("btBRDBT");
        btBRDBT->setGeometry(QRect(250, 540, 41, 41));
        btBRDBT->setBaseSize(QSize(2560, 1440));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btBRDBT->setPalette(palette13);
        btStop = new QPushButton(centralwidget);
        btStop->setObjectName("btStop");
        btStop->setGeometry(QRect(300, 390, 81, 41));
        btStop->setBaseSize(QSize(2560, 1440));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btStop->setPalette(palette14);
        btCancel = new QPushButton(centralwidget);
        btCancel->setObjectName("btCancel");
        btCancel->setGeometry(QRect(300, 440, 81, 41));
        btCancel->setBaseSize(QSize(2560, 1440));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btCancel->setPalette(palette15);
        btDBT = new QPushButton(centralwidget);
        btDBT->setObjectName("btDBT");
        btDBT->setGeometry(QRect(300, 490, 81, 41));
        btDBT->setBaseSize(QSize(2560, 1440));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btDBT->setPalette(palette16);
        btAccept = new QPushButton(centralwidget);
        btAccept->setObjectName("btAccept");
        btAccept->setGeometry(QRect(300, 540, 81, 41));
        btAccept->setBaseSize(QSize(2560, 1440));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btAccept->setPalette(palette17);
        frame = new QFrame(centralwidget);
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
        labelOption6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelOption7 = new QLabel(frame);
        labelOption7->setObjectName("labelOption7");
        labelOption7->setGeometry(QRect(170, 150, 91, 41));
        labelOption7->setBaseSize(QSize(2560, 1440));
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
        labelOption5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelKortti = new QLabel(frame);
        labelKortti->setObjectName("labelKortti");
        labelKortti->setGeometry(QRect(70, 60, 121, 16));
        labelKortti->setBaseSize(QSize(2560, 1440));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 110, 271, 20));
        label_2->setBaseSize(QSize(2560, 1440));
        label_2->setAlignment(Qt::AlignCenter);
        labelPrompt = new QLabel(frame);
        labelPrompt->setObjectName("labelPrompt");
        labelPrompt->setGeometry(QRect(10, 180, 251, 20));
        labelPrompt->setBaseSize(QSize(2560, 1440));
        labelPrompt->setAlignment(Qt::AlignCenter);
        labelUser = new QLabel(frame);
        labelUser->setObjectName("labelUser");
        labelUser->setGeometry(QRect(60, 90, 141, 16));
        labelUser->setBaseSize(QSize(2560, 1440));
        lineEditPassword = new QLineEdit(frame);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(100, 130, 71, 21));
        lineEditPassword->setBaseSize(QSize(2560, 1440));
        lineEditPassword->setAlignment(Qt::AlignCenter);
        btOption4 = new QPushButton(centralwidget);
        btOption4->setObjectName("btOption4");
        btOption4->setGeometry(QRect(80, 220, 41, 41));
        btOption4->setBaseSize(QSize(2560, 1440));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btOption4->setPalette(palette18);
        btOption3 = new QPushButton(centralwidget);
        btOption3->setObjectName("btOption3");
        btOption3->setGeometry(QRect(80, 170, 41, 41));
        btOption3->setBaseSize(QSize(2560, 1440));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btOption3->setPalette(palette19);
        btOption1 = new QPushButton(centralwidget);
        btOption1->setObjectName("btOption1");
        btOption1->setGeometry(QRect(80, 70, 41, 41));
        btOption1->setBaseSize(QSize(2560, 1440));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette20.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette20.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btOption1->setPalette(palette20);
        btOption2 = new QPushButton(centralwidget);
        btOption2->setObjectName("btOption2");
        btOption2->setGeometry(QRect(80, 120, 41, 41));
        btOption2->setBaseSize(QSize(2560, 1440));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btOption2->setPalette(palette21);
        btOption8 = new QPushButton(centralwidget);
        btOption8->setObjectName("btOption8");
        btOption8->setGeometry(QRect(410, 220, 41, 41));
        btOption8->setBaseSize(QSize(2560, 1440));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette22.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette22.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btOption8->setPalette(palette22);
        btOption7 = new QPushButton(centralwidget);
        btOption7->setObjectName("btOption7");
        btOption7->setGeometry(QRect(410, 170, 41, 41));
        btOption7->setBaseSize(QSize(2560, 1440));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette23.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette23.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btOption7->setPalette(palette23);
        btOption5 = new QPushButton(centralwidget);
        btOption5->setObjectName("btOption5");
        btOption5->setGeometry(QRect(410, 70, 41, 41));
        btOption5->setBaseSize(QSize(2560, 1440));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::Button, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btOption5->setPalette(palette24);
        btOption6 = new QPushButton(centralwidget);
        btOption6->setObjectName("btOption6");
        btOption6->setGeometry(QRect(410, 120, 41, 41));
        btOption6->setBaseSize(QSize(2560, 1440));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette25.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette25.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btOption6->setPalette(palette25);
        menubar = new QMenuBar(Login);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menubar->setBaseSize(QSize(2560, 1440));
        menuBankSimul_R9 = new QMenu(menubar);
        menuBankSimul_R9->setObjectName("menuBankSimul_R9");
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 27));
        statusbar->setBaseSize(QSize(2560, 1440));
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 180, 2171, 1251));
        label->setBaseSize(QSize(2560, 1440));
        QPalette palette26;
        QBrush brush5(QColor(191, 191, 191, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette26.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush6(QColor(231, 215, 199, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette26.setBrush(QPalette::Active, QPalette::Highlight, brush6);
        palette26.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette26.setBrush(QPalette::Inactive, QPalette::Highlight, brush6);
        palette26.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        QBrush brush7(QColor(0, 120, 215, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette26.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        label->setPalette(palette26);
        label->setPixmap(QPixmap(QString::fromUtf8(":/Tausta/Taustakuva.jpg")));
        label->setAlignment(Qt::AlignCenter);
        label->raise();
        centralwidget->raise();
        menubar->raise();
        statusbar->raise();

        menubar->addAction(menuBankSimul_R9->menuAction());

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(Login *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        btNum1->setText(QCoreApplication::translate("Login", "1", nullptr));
        btNum2->setText(QCoreApplication::translate("Login", "2", nullptr));
        btNum3->setText(QCoreApplication::translate("Login", "3", nullptr));
        btNum4->setText(QCoreApplication::translate("Login", "4", nullptr));
        btNum5->setText(QCoreApplication::translate("Login", "5", nullptr));
        btNum6->setText(QCoreApplication::translate("Login", "6", nullptr));
        btNum7->setText(QCoreApplication::translate("Login", "7", nullptr));
        btNum8->setText(QCoreApplication::translate("Login", "8", nullptr));
        btNum9->setText(QCoreApplication::translate("Login", "9", nullptr));
        btBLDBT->setText(QCoreApplication::translate("Login", "*", nullptr));
        btNum0->setText(QCoreApplication::translate("Login", "0", nullptr));
        btBRDBT->setText(QCoreApplication::translate("Login", "+", nullptr));
        btStop->setText(QCoreApplication::translate("Login", "X", nullptr));
        btCancel->setText(QCoreApplication::translate("Login", "<-", nullptr));
        btDBT->setText(QString());
        btAccept->setText(QCoreApplication::translate("Login", "O", nullptr));
        labelOption1->setText(QCoreApplication::translate("Login", "Option1", nullptr));
        labelOption2->setText(QCoreApplication::translate("Login", "Option2", nullptr));
        labelOption4->setText(QCoreApplication::translate("Login", "Option4", nullptr));
        labelOption3->setText(QCoreApplication::translate("Login", "Option3", nullptr));
        labelOption6->setText(QCoreApplication::translate("Login", "Option6", nullptr));
        labelOption7->setText(QCoreApplication::translate("Login", "Option7", nullptr));
        labelOption8->setText(QCoreApplication::translate("Login", "Option8", nullptr));
        labelOption5->setText(QCoreApplication::translate("Login", "Option5", nullptr));
        labelKortti->setText(QString());
        label_2->setText(QCoreApplication::translate("Login", "PIN-koodi:", nullptr));
        labelPrompt->setText(QString());
        labelUser->setText(QString());
        lineEditPassword->setText(QString());
        btOption4->setText(QCoreApplication::translate("Login", ">", nullptr));
        btOption3->setText(QCoreApplication::translate("Login", ">", nullptr));
        btOption1->setText(QCoreApplication::translate("Login", ">", nullptr));
        btOption2->setText(QCoreApplication::translate("Login", ">", nullptr));
        btOption8->setText(QCoreApplication::translate("Login", "<", nullptr));
        btOption7->setText(QCoreApplication::translate("Login", "<", nullptr));
        btOption5->setText(QCoreApplication::translate("Login", "<", nullptr));
        btOption6->setText(QCoreApplication::translate("Login", "<", nullptr));
        menuBankSimul_R9->setTitle(QCoreApplication::translate("Login", "BankSimul_R9", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
