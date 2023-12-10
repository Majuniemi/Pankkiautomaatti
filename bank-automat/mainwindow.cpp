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
    ui->labelOption8->setText("Kirjaudu sisään");
    ui->labelPrompt->setText("Tervetuloa!");
    ui->labelInput->setText(" ");

    connect(ui->btNum1, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->btNum2, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->btNum3, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->btNum4, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->btNum5, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->btNum6, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->btNum7, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->btNum8, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->btNum9, SIGNAL(clicked()), this, SLOT(numberClickHandler()));
    connect(ui->btNum0, SIGNAL(clicked()), this, SLOT(numberClickHandler()));

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
    foreach (const QSerialPortInfo &portInfo, QSerialPortInfo::availablePorts()) {      //Luetaan sarjaporteissa olevia laitteita ja valitaan niistä Olimex merkin laite
        if (portInfo.manufacturer() == "Olimex Ltd.") {
            valittuPortti = portInfo;
            break;
        }
    }
    if (!valittuPortti.isNull()) {
        serialPort->setPortName(valittuPortti.portName());                              //Käytetään ylläolevalla Olimex ehdolla löydettyä sarjaporttia
    } else {
        qDebug() << "RFID-lukijaa ei löytynyt.";
    }
    serialPort->setBaudRate(QSerialPort::Baud9600);                                     //Asettaa baudinopeuden 9600 bit/sek
    serialPort->setDataBits(QSerialPort::Data8);                                        //Asettaa bittien määrän 8:n bittiin
    serialPort->setParity(QSerialPort::NoParity);                                       //Asettaa pariteetin Ei-tilaan
    serialPort->setStopBits(QSerialPort::OneStop);                                      //Asettaa stopbittien määräksi 1
        if (serialPort->open(QIODevice::ReadWrite)) {                                   //Tulostaa debug tietona, että onnistuuko sarjaportin yhteys.
            qDebug() << "Sarjaportti avattu onnistuneesti";
        } else {
            qDebug() << "Sarjaportin yhdistämisessä virhe: " << serialPort->errorString();
        }
        qDebug()<<"Sarjaportin nimi on: "<< valittuPortti.portName();

        connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readData);      //Siirtyy readData-slottiin, kun RFID-lukija lukee tiedon
        serialPort->clear();                                                            //Tyhjennetään sarjaportin lukemat tiedot
        
        connect(ui->btOption5, SIGNAL(clicked()), this, SLOT(on_btOption5_clicked()));
        connect(ui->btOption6, SIGNAL(clicked()), this, SLOT(on_btOption6_clicked()));
        connect(ui->btOption7, SIGNAL(clicked()), this, SLOT(on_btOption7_clicked()));
        connect(ui->btOption8, SIGNAL(clicked()), this, SLOT(on_btOption8_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    if (button)
    {
        QLabel *currentEdit = ui->labelInput;
        currentEdit->setText(currentEdit->text() + button->text());
    }
}

void MainWindow::commandClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    if (button)
    {
        if (button->objectName() == "btOption1")
        {
        //    updateFlagVisibility(true);
            ui->labelOption5->setText("");
            ui->labelOption5->setPixmap(QPixmap(":/liput/Liput/Suomenlippu.png"));
            ui->labelOption6->setPixmap(QPixmap(":/liput/Liput/Ruotsinlippu.png"));
            ui->labelOption7->setPixmap(QPixmap(":/liput/Liput/Brittilippu.png"));
        /*    ui->labelOption8->show();
            ui->labelPrompt->show();
            ui->labelOption6->show();
            ui->labelOption7->show(); */
        }
        else if (button->objectName() == "btOption2")
        {

        }
        else if (button->objectName() == "btOption5")
        {
            // translateTo("fi");
             // Suomen käännös
        //     ui->labelOption5->setText("");
         //    ui->labelOption5->setPixmap(QPixmap(":/Liput/Liput/Suomenlippu.png"));
             ui->labelOption8->setText("Kirjaudu sisään");
             ui->labelPrompt->setText("Tervetuloa!");
          //   ui->labelOption5->setText(" ");
             ui->labelOption6->setText(" ");
             ui->labelOption7->setText(" ");
             kieli =1;
        }
        else if (button->objectName() == "btOption6")
        {
            //   translateTo("sv");
               // Ruotsin käännös
            //   ui->labelOption5->setText("");
            //   ui->labelOption5->setPixmap(QPixmap(":/Liput/Liput/Ruotsinlippu.png"));
               ui->labelOption8->setText("Log in");
               ui->labelPrompt->setText("Välkommen!");
               ui->labelOption5->setText(" ");
           //    ui->labelOption6->setText(" ");
               ui->labelOption7->setText(" ");
               kieli =2;
        }
        else if (button->objectName() == "btOption7")
        {
            //  translateTo("en");
            //  Englannin käännös
            //  ui->labelOption5->setText("");
            //  ui->labelOption5->setPixmap(QPixmap(":/Liput/Liput/Brittilippu.png"));
               ui->labelOption8->setText("Log in");
               ui->labelPrompt->setText("Welcome!");
               ui->labelOption5->setText(" ");
               ui->labelOption6->setText(" ");
            //   ui->labelOption7->setText(" ");
               kieli =3;
        }


        else if (button->objectName() == "btOption8")
        {
            olioLogin = new Login(this);
            olioLogin->setKieli(kieli);
            olioLogin->lueKortti("06000649CE");
            olioLogin->show();
        }
        else if (button->objectName() == "btStop")
        {
            close();
        }
        else if (button->objectName() == "btCancel")
        {

        }
        else if (button->objectName() == "btAccept")
        {

        }
    }
}
/*
void MainWindow::updateFlagVisibility(bool visible)
{
    ui->labelOption5->setVisible(visible);
    ui->labelOption6->setVisible(visible);
    ui->labelOption7->setVisible(visible);
}*/

void MainWindow::readData()
{
    qDebug()<<"ReadData luokassa: "<<kirjautunut;
    if (!kirjautunut) {                                                                 //Suoritetaan vain, jos ei olla sisäänkirjautuneena
        QString RFIDtieto = serialPort->readAll();                                      //Luetaan RFID-tägin sisältämä tieto
        //qDebug()<<"Kortinlukija luki:" << RFIDtieto;

        QString korttinumero;
        for (auto it = RFIDtieto.begin(); it != RFIDtieto.end(); ++it) {                //Siivotaan ylimääräiset merkit vastauksena tulleesta tiedosta, jäljelle jää pelkkä korttinumero
            const QChar &ch = *it;
            if (ch.isDigit() || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f')) {
                korttinumero.append(ch);
            }
        }
        //qDebug()<<"Korttinumero nyt:" << korttinumero;
        //qDebug()<<"RFIDtieto nyt: "<<RFIDtieto;
        olioLogin = new Login(this);
        olioLogin->lueKortti(korttinumero);                                             //Lähetetään korttinumero signaalissa eteenpäin
        olioLogin->show();
        connect(olioLogin, &Login::logoutRequested, this, &MainWindow::handleLogout);   //Kun Login luokan logoutReq signaali tulee, niin siirrytään handleLogouttiin
        kirjautunut = true;                                                             //Vaihdetaan kirjautunut tieto "sisäänkirjautuneeksi"
    }
}

void MainWindow::handleLogout()
{
    kirjautunut = false;                                                                //Asetetaan kirjautunut uloskirjautuneeksi
    serialPort->clear();                                                                //Tyhjennetään sarjaportin lukemat tiedot
    //qDebug()<<"Päästiin MainWindow luokassa handleLogouttiin";
}
