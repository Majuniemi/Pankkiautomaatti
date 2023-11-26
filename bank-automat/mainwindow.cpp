#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
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
    switch(tila){
    case 0:
        ui->labelOption1->setText(" ");
        ui->labelOption2->setText(" ");
        ui->labelOption3->setText(" ");
        ui->labelOption4->setText(" ");
        ui->labelOption5->setText("Language");
        ui->labelOption6->setText(" ");
        ui->labelOption7->setText(" ");
        ui->labelOption8->setText(" ");
        ui->labelPrompt->setText("Syötä kortti");
        ui->labelInput->setText(" ");
        break;
    case 1:
        ui->labelOption1->setText("Nosto");
        ui->labelOption2->setText("Siirto");
        ui->labelOption3->setText(" ");
        ui->labelOption4->setText(" ");
        ui->labelOption5->setText("Language");
        ui->labelOption6->setText("Tilitapahtumat");
        ui->labelOption7->setText(" ");
        ui->labelOption8->setText("Lopeta");
        ui->labelPrompt->setText(" ");
        ui->labelInput->setText(" ");
        break;
    case 2:
        ui->labelOption1->setText("20 euroa");
        ui->labelOption2->setText("40 euroa");
        ui->labelOption3->setText("50 euroa");
        ui->labelOption4->setText("70 euroa");
        ui->labelOption5->setText("100 euroa");
        ui->labelOption6->setText("150 euroa");
        ui->labelOption7->setText("200 euroa");
        ui->labelOption8->setText("Muu");
        ui->labelPrompt->setText("Valitse summa");
        ui->labelInput->setText(" ");
        break;
    case 3:
        ui->labelOption1->setText("");
        ui->labelOption2->setText("");
        ui->labelOption3->setText("");
        ui->labelOption4->setText("");
        ui->labelOption5->setText("");
        ui->labelOption6->setText("");
        ui->labelOption7->setText("");
        ui->labelOption8->setText("");
        ui->labelPrompt->setText("Syötä tilinumero");
        ui->labelInput->setText("FI");
        break;
    default:
        return;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    switch(tila){
    case 0:

    case 1:

    case 2:

    if(button){
        QLabel *currentEdit = ui->labelInput;
        currentEdit->setText(currentEdit->text() + button->text());
    }
    case 3:
        break;
    default:
        return;
    }

}

void MainWindow::commandClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    switch(tila){
    case 0:
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

        }
        break;
    case 1:
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

        }
        break;
    case 2:
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

        }
        break;
    case 3:
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

        }
        break;
    default:
        return;
    }
}

