#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->labelOption1->setText(" ");
    ui->labelOption2->setText(" ");
    ui->labelOption3->setText(" ");
    ui->labelOption4->setText(" ");
    ui->labelOption5->setText("Language");
    ui->labelOption6->setText(" ");
    ui->labelOption7->setText(" ");
    ui->labelOption8->setText("Kirjaudu sisään");
    ui->labelPrompt->setText("Tervetuloa!");
    ui->labelInput->setText(" ");

    connect(ui->btNum1,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum2,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum3,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum4,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum5,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum6,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum7,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum8,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum9,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btNum0,SIGNAL(clicked(bool)),this,SLOT(numberClickHandler()));
    connect(ui->btOption1,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption2,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption3,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption4,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption5,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption6,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption7,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btOption8,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btStop,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btCancel,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));
    connect(ui->btAccept,SIGNAL(clicked(bool)),this,SLOT(commandClickHandler()));

    // Luodaan sarjamonitoriyhteys, jotta voidaan lukea RFID lukijalla tägin tiedot Qt:ssa.
    serialPort = new QSerialPort(this);
    serialPort->setPortName("/dev/tty.usbmodem13101");      // Vaihda tähän lukijan sarjaportin nimi
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    // Tämä tulostaa debug tietona, että onnistuuko sarjaportin yhteys.
    if (serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Sarjaportti avattu onnistuneesti";
    } else {
        qDebug() << "Sarjaportin yhdistämisessä virhe: " << serialPort->errorString();
    }
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());


    if(button){
        QLabel *currentEdit = ui->labelInput;
        currentEdit->setText(currentEdit->text() + button->text());
    }
}

void MainWindow::commandClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());

        if (button->objectName()=="btOption1"){

        }
        else if (button->objectName()=="btOption2"){

        }
        else if (button->objectName()=="btOption3"){

        }
        else if (button->objectName()=="btOption4"){

        }
        else if (button->objectName()=="btOption5"){

        }
        else if (button->objectName()=="btOption6"){

        }
        else if (button->objectName()=="btOption7"){

        }
        else if (button->objectName()=="btOption8"){
            olioLogin = new Login(this);
            olioLogin->lueKortti("0000000011111111");
            olioLogin->show();
        }
        else if (button->objectName()=="btStop"){
            close();
        }
        else if (button->objectName()=="btCancel"){

        }
        else if (button->objectName()=="btAccept"){

        }
}

void MainWindow::readData()
{
    QString RFIDtieto = serialPort->readAll();      // Luetaan RFID-tägin sisältämä tieto
    //qDebug()<<"Kortinlukija luki:" << RFIDtieto;

    QString korttinumero;
    for (const QChar &ch : RFIDtieto) {             // Siivotaan ylimääräiset merkit pois
    if (ch.isDigit() || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f')) {
        korttinumero.append(ch);
        }
    }
    //qDebug()<<"Korttinumero nyt:" << korttinumero;  // Lähetetään korttinumero signaalissa eteenpäin
    olioLogin = new Login(this);
    olioLogin->lueKortti(korttinumero);
    olioLogin->show();
}
