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
    transfer.cpp \
    withdraw.cpp

HEADERS += \
    login.h \
    mainmenu.h \
    mainwindow.h \
    saldo.h \
    transfer.h \
    withdraw.h

FORMS += \
    login.ui \
    mainmenu.ui \
    mainwindow.ui \
    saldo.ui \
    transfer.ui \
    withdraw.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Liput.qrc \
    Napit/Napit.qrc \
    Tausta.qrc

DISTFILES += \
    Napit/12BADA76-DC86-41AA-A218-67BD4CBD3CA7.png \
    Napit/233DC32A-8FD4-4C5C-BC60-110DCD022AA2.png \
    Napit/43D1BA8F-A7C2-4D5D-B0CC-1F526F8CD875.png \
    Napit/5ABF8A40-1C7D-4BE3-9B14-EA9CBDDAF52E.jpg \
    Napit/802713C5-D109-4182-83B7-935E8F95A7BC.jpg \
    Napit/E2B6CF6B-1BA8-4A44-84C7-AB047E91A604.png \
    Napit/IMG_8578.jpg \
    Napit/IMG_8583.jpg \
    Napit/IMG_8584.jpg \
    Napit/IMG_8585.jpg \
    Napit/IMG_8586.jpg \
    Napit/IMG_8587.jpg \
    Napit/IMG_8588.jpg \
    Napit/IMG_8589.jpg \
    Napit/IMG_8590.jpg \
    Napit/IMG_8591.jpg \
    Napit/IMG_8593.jpg \
    Napit/IMG_8595.jpg \
    Napit/IMG_8596.jpg \
    Napit/IMG_8597.jpg \
    Napit/IMG_8615.jpg \
    Napit/IMG_8616.jpg \
    Napit/IMG_8619.JPG
