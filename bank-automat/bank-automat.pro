QT       += core gui
QT +=network
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    login.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    saldo.cpp \
<<<<<<< HEAD
    tilitapahtuma.cpp
=======
    transfer.cpp \
    withdraw.cpp
>>>>>>> 993d7f0bcf4b48ca59e5c850c957238396dca991

HEADERS += \
    login.h \
    mainmenu.h \
    mainwindow.h \
    saldo.h \
<<<<<<< HEAD
    tilitapahtuma.h
=======
    transfer.h \
    withdraw.h
>>>>>>> 993d7f0bcf4b48ca59e5c850c957238396dca991

FORMS += \
    login.ui \
    mainmenu.ui \
    mainwindow.ui \
    saldo.ui \
<<<<<<< HEAD
    tilitapahtuma.ui
=======
    transfer.ui \
    withdraw.ui
>>>>>>> 993d7f0bcf4b48ca59e5c850c957238396dca991

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Liput.qrc \
    Tausta.qrc
