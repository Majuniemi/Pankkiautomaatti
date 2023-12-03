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

    void setToken(const QByteArray &newToken);
    void setUsername(const QString &newUsername);

public slots:
    void numberClickHandler();
    void commandClickHandler();

private:
    Ui::Mainmenu *ui;

    QString username;
    QByteArray token;
};

#endif // MAINMENU_H
