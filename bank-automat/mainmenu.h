#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>

namespace Ui {
class Mainmenu;
}

class Mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit Mainmenu(QWidget *parent = nullptr);
    ~Mainmenu();

public slots:
    void numberClickHandler();
    void commandClickHandler();

private:
    Ui::Mainmenu *ui;
};

#endif // MAINMENU_H
