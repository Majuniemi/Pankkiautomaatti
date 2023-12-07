#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
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

    serialPort = new QSerialPort(this);
    serialPort->setPortName("/dev/tty.usbmodem13101");
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);

    if (serialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "Sarjaportti avattu onnistuneesti";
    }
    else
    {
        qDebug() << "Sarjaportin yhdistämisessä virhe: " << serialPort->errorString();
    }

    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readData);


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

        }
        else if (button->objectName() == "btOption2")
        {

        }

        else if (button->objectName() == "btOption8")
        {
            olioLogin = new Login(this);
            olioLogin->lueKortti("06000649CE");
            olioLogin->showFullScreen();
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

void MainWindow::updateFlagVisibility(bool visible)
{
    ui->labelOption5->setVisible(visible);
    ui->labelOption6->setVisible(visible);
    ui->labelOption7->setVisible(visible);
}

void MainWindow::readData()
{
    QString RFIDtieto = serialPort->readAll();

    QString korttinumero;
    for (const QChar &ch : RFIDtieto)
    {
        if (ch.isDigit() || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f'))
        {
            korttinumero.append(ch);
        }
    }

    olioLogin = new Login(this);
    olioLogin->lueKortti(korttinumero);
    olioLogin->show();
}

void MainWindow::on_btOption5_clicked()
{
    updateFlagVisibility(true);
    ui->labelOption5->setText("");
    ui->labelOption5->setPixmap(QPixmap(":/liput/Liput/Suomenlippu.png"));
    ui->labelOption6->setPixmap(QPixmap(":/liput/Liput/Ruotsinlippu.png"));
    ui->labelOption7->setPixmap(QPixmap(":/liput/Liput/Brittilippu.png"));
    ui->labelOption8->show();
    ui->labelPrompt->show();
    ui->labelOption6->show();
    ui->labelOption7->show();
}

void MainWindow::on_btOption6_clicked()
{
    translateTo("sv");
    ui->labelOption5->hide();
    ui->labelOption6->hide();
    ui->labelOption7->hide();
}

void MainWindow::on_btOption7_clicked()
{
    translateTo("en");
    ui->labelOption5->hide();
    ui->labelOption6->hide();
    ui->labelOption7->hide();
}

void MainWindow::on_btOption8_clicked()
{
    translateTo("en");
    ui->labelOption5->hide();
    ui->labelOption6->hide();
    ui->labelOption7->hide();
}

void MainWindow::translateTo(const QString &lang)
{
    QString language = lang.toLower();

    if (language == "fi")
    {
        // Suomen käännös
        ui->labelOption5->setText("");
        ui->labelOption5->setPixmap(QPixmap(":/Liput/Liput/Suomenlippu.png"));
        ui->labelOption8->setText("Kirjaudu sisään");
        ui->labelPrompt->setText("Tervetuloa!");
    }
    else if (language == "en")
    {
        // Englannin käännös
        ui->labelOption5->setText("");
        ui->labelOption5->setPixmap(QPixmap(":/Liput/Liput/Brittilippu.png"));
        ui->labelOption8->setText("Log in");
        ui->labelPrompt->setText("Welcome!");
    }
    else if (language == "sv")
    {
        // Ruotsin käännös
        ui->labelOption5->setText("");
        ui->labelOption5->setPixmap(QPixmap(":/Liput/Liput/Ruotsinlippu.png"));
        ui->labelOption8->setText("Log in");
        ui->labelPrompt->setText("Välkommen!");
    }
    else
    {
        // Oletuskieli
        ui->labelOption5->setText("Language");
        ui->labelOption5->setPixmap(QPixmap());
        ui->labelOption8->setText("Log in");
        ui->labelPrompt->setText("Welcome!");
    }
}
