/****************************************************************************
** Meta object code from reading C++ file 'transfer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../bank-automat/transfer.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transfer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSTransferENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTransferENDCLASS = QtMocHelpers::stringData(
    "Transfer",
    "numberClickHandler",
    "",
    "commandClickHandler",
    "setToken",
    "newToken",
    "setUsername",
    "newUsername",
    "showUsername",
    "onNostoButtonClicked",
    "tilinumero",
    "onLuottorajaButtonClicked",
    "onNpeuroButtonClicked",
    "onNpprosenttiButtonClicked",
    "onMuuntokerroinButtonClicked",
    "upSaldo",
    "id",
    "newSaldo",
    "uusiTilitapahtuma",
    "aikaleima",
    "saldoMuutos",
    "idTili",
    "onTiliButtonClicked",
    "getNostoSlot",
    "QNetworkReply*",
    "reply",
    "getLuottorajaSlot",
    "getNpeuroSlot",
    "getNpprosenttiSlot",
    "getMuuntokerroinSlot",
    "getTiliSlot"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTransferENDCLASS_t {
    uint offsetsAndSizes[62];
    char stringdata0[9];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[9];
    char stringdata5[9];
    char stringdata6[12];
    char stringdata7[12];
    char stringdata8[13];
    char stringdata9[21];
    char stringdata10[11];
    char stringdata11[26];
    char stringdata12[22];
    char stringdata13[27];
    char stringdata14[29];
    char stringdata15[8];
    char stringdata16[3];
    char stringdata17[9];
    char stringdata18[18];
    char stringdata19[10];
    char stringdata20[12];
    char stringdata21[7];
    char stringdata22[20];
    char stringdata23[13];
    char stringdata24[15];
    char stringdata25[6];
    char stringdata26[18];
    char stringdata27[14];
    char stringdata28[19];
    char stringdata29[21];
    char stringdata30[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTransferENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTransferENDCLASS_t qt_meta_stringdata_CLASSTransferENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "Transfer"
        QT_MOC_LITERAL(9, 18),  // "numberClickHandler"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 19),  // "commandClickHandler"
        QT_MOC_LITERAL(49, 8),  // "setToken"
        QT_MOC_LITERAL(58, 8),  // "newToken"
        QT_MOC_LITERAL(67, 11),  // "setUsername"
        QT_MOC_LITERAL(79, 11),  // "newUsername"
        QT_MOC_LITERAL(91, 12),  // "showUsername"
        QT_MOC_LITERAL(104, 20),  // "onNostoButtonClicked"
        QT_MOC_LITERAL(125, 10),  // "tilinumero"
        QT_MOC_LITERAL(136, 25),  // "onLuottorajaButtonClicked"
        QT_MOC_LITERAL(162, 21),  // "onNpeuroButtonClicked"
        QT_MOC_LITERAL(184, 26),  // "onNpprosenttiButtonClicked"
        QT_MOC_LITERAL(211, 28),  // "onMuuntokerroinButtonClicked"
        QT_MOC_LITERAL(240, 7),  // "upSaldo"
        QT_MOC_LITERAL(248, 2),  // "id"
        QT_MOC_LITERAL(251, 8),  // "newSaldo"
        QT_MOC_LITERAL(260, 17),  // "uusiTilitapahtuma"
        QT_MOC_LITERAL(278, 9),  // "aikaleima"
        QT_MOC_LITERAL(288, 11),  // "saldoMuutos"
        QT_MOC_LITERAL(300, 6),  // "idTili"
        QT_MOC_LITERAL(307, 19),  // "onTiliButtonClicked"
        QT_MOC_LITERAL(327, 12),  // "getNostoSlot"
        QT_MOC_LITERAL(340, 14),  // "QNetworkReply*"
        QT_MOC_LITERAL(355, 5),  // "reply"
        QT_MOC_LITERAL(361, 17),  // "getLuottorajaSlot"
        QT_MOC_LITERAL(379, 13),  // "getNpeuroSlot"
        QT_MOC_LITERAL(393, 18),  // "getNpprosenttiSlot"
        QT_MOC_LITERAL(412, 20),  // "getMuuntokerroinSlot"
        QT_MOC_LITERAL(433, 11)   // "getTiliSlot"
    },
    "Transfer",
    "numberClickHandler",
    "",
    "commandClickHandler",
    "setToken",
    "newToken",
    "setUsername",
    "newUsername",
    "showUsername",
    "onNostoButtonClicked",
    "tilinumero",
    "onLuottorajaButtonClicked",
    "onNpeuroButtonClicked",
    "onNpprosenttiButtonClicked",
    "onMuuntokerroinButtonClicked",
    "upSaldo",
    "id",
    "newSaldo",
    "uusiTilitapahtuma",
    "aikaleima",
    "saldoMuutos",
    "idTili",
    "onTiliButtonClicked",
    "getNostoSlot",
    "QNetworkReply*",
    "reply",
    "getLuottorajaSlot",
    "getNpeuroSlot",
    "getNpprosenttiSlot",
    "getMuuntokerroinSlot",
    "getTiliSlot"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTransferENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x0a,    1 /* Public */,
       3,    0,  129,    2, 0x0a,    2 /* Public */,
       4,    1,  130,    2, 0x0a,    3 /* Public */,
       6,    1,  133,    2, 0x0a,    5 /* Public */,
       8,    0,  136,    2, 0x0a,    7 /* Public */,
       9,    1,  137,    2, 0x0a,    8 /* Public */,
      11,    1,  140,    2, 0x0a,   10 /* Public */,
      12,    1,  143,    2, 0x0a,   12 /* Public */,
      13,    1,  146,    2, 0x0a,   14 /* Public */,
      14,    1,  149,    2, 0x0a,   16 /* Public */,
      15,    2,  152,    2, 0x0a,   18 /* Public */,
      18,    3,  157,    2, 0x0a,   21 /* Public */,
      22,    1,  164,    2, 0x0a,   25 /* Public */,
      23,    1,  167,    2, 0x08,   27 /* Private */,
      26,    1,  170,    2, 0x08,   29 /* Private */,
      27,    1,  173,    2, 0x08,   31 /* Private */,
      28,    1,  176,    2, 0x08,   33 /* Private */,
      29,    1,  179,    2, 0x08,   35 /* Private */,
      30,    1,  182,    2, 0x08,   37 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   16,   17,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString,   19,   20,   21,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   25,

       0        // eod
};

Q_CONSTINIT const QMetaObject Transfer::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSTransferENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTransferENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTransferENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Transfer, std::true_type>,
        // method 'numberClickHandler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'commandClickHandler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setToken'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'setUsername'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showUsername'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onNostoButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onLuottorajaButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onNpeuroButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onNpprosenttiButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onMuuntokerroinButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'upSaldo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'uusiTilitapahtuma'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onTiliButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getNostoSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'getLuottorajaSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'getNpeuroSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'getNpprosenttiSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'getMuuntokerroinSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'getTiliSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>
    >,
    nullptr
} };

void Transfer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Transfer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->numberClickHandler(); break;
        case 1: _t->commandClickHandler(); break;
        case 2: _t->setToken((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 3: _t->setUsername((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->showUsername(); break;
        case 5: _t->onNostoButtonClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->onLuottorajaButtonClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->onNpeuroButtonClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->onNpprosenttiButtonClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->onMuuntokerroinButtonClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->upSaldo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 11: _t->uusiTilitapahtuma((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 12: _t->onTiliButtonClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->getNostoSlot((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 14: _t->getLuottorajaSlot((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 15: _t->getNpeuroSlot((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 16: _t->getNpprosenttiSlot((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 17: _t->getMuuntokerroinSlot((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 18: _t->getTiliSlot((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *Transfer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Transfer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTransferENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Transfer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
