#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelOption1->setText("Language");
    ui->labelOption2->setText(" ");
    ui->labelOption3->setText(" ");
    ui->labelOption4->setText(" ");
    ui->labelOption5->setText(" ");
    ui->labelOption6->setText(" ");
    ui->labelOption7->setText(" ");
    ui->labelOption8->setText(" ");
    ui->labelPrompt->setText("Tervetuloa!");
    ui->labelInput->setText(" ");

    connect(ui->btOption1, SIGNAL(clicked()), this, SLOT(commandClickHandler()));
    connect(ui->btOption2, SIGNAL(clicked()), this, SLOT(commandClickHandler()));
    connect(ui->btOption3, SIGNAL(clicked()), this, SLOT(commandClickHandler()));
    connect(ui->btOption4, SIGNAL(clicked()), this, SLOT(commandClickHandler()));
    connect(ui->btOption5, SIGNAL(clicked()), this, SLOT(commandClickHandler()));
    connect(ui->btOption6, SIGNAL(clicked()), this, SLOT(commandClickHandler()));
    connect(ui->btOption7, SIGNAL(clicked()), this, SLOT(commandClickHandler()));
    connect(ui->btOption8, SIGNAL(clicked()), this, SLOT(commandClickHandler()));

    connect(ui->btStop, SIGNAL(clicked()), this, SLOT(commandClickHandler()));
    connect(ui->btCancel, SIGNAL(clicked()), this, SLOT(commandClickHandler()));
    connect(ui->btAccept, SIGNAL(clicked()), this, SLOT(commandClickHandler()));

    serialPort = new QSerialPort(this);                                                 //Luodaan sarjamonitoriyhteys, jotta voidaan lukea RFID lukijalla tägin tiedot Qt:ssa
    QSerialPortInfo valittuPortti;
        foreach (const QSerialPortInfo &portInfo, QSerialPortInfo::availablePorts()) {
            qDebug() << "Portti:" << portInfo.portName() << "Valmistaja:" << portInfo.manufacturer();


            if (portInfo.manufacturer().contains("Microsoft") || portInfo.manufacturer().contains("Olimex Ltd.")) {
                valittuPortti = portInfo;                                               //Luetaan sarjaporteissa olevia laitteita ja valitaan niistä Microsoft tai Olimex merkin laite
                break;
            }
        }

        if (!valittuPortti.isNull()) {
            serialPort = new QSerialPort(this);
            serialPort->setPortName(valittuPortti.portName());

            qDebug() << "Valittu sarjaportti:" << valittuPortti.portName();

            serialPort->setBaudRate(QSerialPort::Baud9600);                             //Asettaa baudinopeuden 9600 bit/sek
            serialPort->setDataBits(QSerialPort::Data8);                                //Asettaa bittien määrän 8:n bittiin
            serialPort->setParity(QSerialPort::NoParity);                               //Asettaa pariteetin Ei-tilaan
            serialPort->setStopBits(QSerialPort::OneStop);                              //Asettaa stopbittien määräksi 1

            if (serialPort->open(QIODevice::ReadWrite)) {
                qDebug() << "Sarjaportti avattu onnistuneesti";                         //Tulostaa debug tietona, että onnistuuko sarjaportin yhteys.
            } else {
                qDebug() << "Sarjaportin yhdistämisessä virhe: " << serialPort->errorString();
            }

            qDebug() << "Sarjaportin nimi on: " << valittuPortti.portName();

            connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readData);  //Siirtyy readData-slottiin, kun RFID-lukija lukee tiedon
            serialPort->clear();                                                        //Tyhjennetään sarjaportin lukemat tiedot
        } else {
            qDebug() << "RFID-lukijaa ei löytynyt.";
        }
    }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::commandClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    if (button)
    {
        if (button->objectName() == "btOption1")
        {
            ui->labelOption5->show();
            ui->labelOption6->show();
            ui->labelOption7->show();
            ui->labelOption5->setText("");
            ui->labelOption5->setPixmap(QPixmap(":/liput/Liput/Suomenlippu.png"));
            ui->labelOption6->setPixmap(QPixmap(":/liput/Liput/Ruotsinlippu.png"));
            ui->labelOption7->setPixmap(QPixmap(":/liput/Liput/Brittilippu.png"));

        }
        else if (button->objectName() == "btOption2")
        {

        }
        else if (button->objectName() == "btOption5")
        {

             // Suomen käännös
             ui->labelOption8->setText(" ");
             ui->labelPrompt->setText("Tervetuloa!");
             ui->labelOption6->setText(" ");
             ui->labelOption7->setText(" ");
             kieli =1;
        }
        else if (button->objectName() == "btOption6")
        {
               // Ruotsin käännös
               ui->labelOption8->setText(" ");
               ui->labelPrompt->setText("Välkommen!");
               ui->labelOption5->setText(" ");
               ui->labelOption7->setText(" ");
               kieli =2;
        }
        else if (button->objectName() == "btOption7")
        {
               // Englannin käännös
               ui->labelOption8->setText(" ");
               ui->labelPrompt->setText("Welcome!");
               ui->labelOption5->setText(" ");
               ui->labelOption6->setText(" ");
               kieli =3;
        }


        else if (button->objectName() == "btStop")
        {
            close();
        }

    }
}

void MainWindow::readData()
{
    qDebug()<<"ReadData luokassa: "<<kirjautunut;
    if (!kirjautunut) {                                                                 //Suoritetaan vain, jos ei olla sisäänkirjautuneena
        QString RFIDtieto = serialPort->readAll();                                      //Luetaan RFID-tägin sisältämä tieto

        QString korttinumero;
        for (auto it = RFIDtieto.begin(); it != RFIDtieto.end(); ++it) {                //Siivotaan ylimääräiset merkit vastauksena tulleesta tiedosta, jäljelle jää pelkkä korttinumero
            const QChar &ch = *it;
            if (ch.isDigit() || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f')) {
                korttinumero.append(ch);
            }
        }
        ui->labelOption5->hide();
        ui->labelOption6->hide();
        ui->labelOption7->hide();
        olioLogin = new Login(this);
        olioLogin->lueKortti(korttinumero);                                             //Lähetetään korttinumero signaalissa eteenpäin
        olioLogin->setKieli(kieli);
        olioLogin->showFullScreen();
        connect(olioLogin, &Login::logoutRequested, this, &MainWindow::handleLogout);   //Kun Login luokan logoutReq signaali tulee, niin siirrytään handleLogouttiin
        kirjautunut = true;                                                             //Vaihdetaan kirjautunut tieto "sisäänkirjautuneeksi"
    }
}

void MainWindow::handleLogout()
{
    kirjautunut = false;                                                                //Asetetaan kirjautunut uloskirjautuneeksi
    serialPort->clear();                                                                //Tyhjennetään sarjaportin lukemat tiedot

}
