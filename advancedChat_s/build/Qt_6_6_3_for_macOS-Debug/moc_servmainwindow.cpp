/****************************************************************************
** Meta object code from reading C++ file 'servmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../servmainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'servmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
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
struct qt_meta_stringdata_CLASSservMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSservMainWindowENDCLASS = QtMocHelpers::stringData(
    "servMainWindow",
    "processInitUserList",
    "",
    "checkVertifiedUser",
    "currentUserName",
    "processMsg",
    "data",
    "connectAndverify",
    "verifyUser",
    "onClientDisconnected",
    "sendMsg"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSservMainWindowENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[15];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[16];
    char stringdata5[11];
    char stringdata6[5];
    char stringdata7[17];
    char stringdata8[11];
    char stringdata9[21];
    char stringdata10[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSservMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSservMainWindowENDCLASS_t qt_meta_stringdata_CLASSservMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "servMainWindow"
        QT_MOC_LITERAL(15, 19),  // "processInitUserList"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 18),  // "checkVertifiedUser"
        QT_MOC_LITERAL(55, 15),  // "currentUserName"
        QT_MOC_LITERAL(71, 10),  // "processMsg"
        QT_MOC_LITERAL(82, 4),  // "data"
        QT_MOC_LITERAL(87, 16),  // "connectAndverify"
        QT_MOC_LITERAL(104, 10),  // "verifyUser"
        QT_MOC_LITERAL(115, 20),  // "onClientDisconnected"
        QT_MOC_LITERAL(136, 7)   // "sendMsg"
    },
    "servMainWindow",
    "processInitUserList",
    "",
    "checkVertifiedUser",
    "currentUserName",
    "processMsg",
    "data",
    "connectAndverify",
    "verifyUser",
    "onClientDisconnected",
    "sendMsg"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSservMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    1,   57,    2, 0x06,    2 /* Public */,
       5,    1,   60,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   63,    2, 0x0a,    6 /* Public */,
       8,    0,   64,    2, 0x0a,    7 /* Public */,
       9,    0,   65,    2, 0x0a,    8 /* Public */,
      10,    1,   66,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject servMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSservMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSservMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSservMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<servMainWindow, std::true_type>,
        // method 'processInitUserList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkVertifiedUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'processMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'connectAndverify'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'verifyUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onClientDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void servMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<servMainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->processInitUserList(); break;
        case 1: _t->checkVertifiedUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->processMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->connectAndverify(); break;
        case 4: _t->verifyUser(); break;
        case 5: _t->onClientDisconnected(); break;
        case 6: _t->sendMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (servMainWindow::*)();
            if (_t _q_method = &servMainWindow::processInitUserList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (servMainWindow::*)(QString );
            if (_t _q_method = &servMainWindow::checkVertifiedUser; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (servMainWindow::*)(QString );
            if (_t _q_method = &servMainWindow::processMsg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *servMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *servMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSservMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int servMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void servMainWindow::processInitUserList()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void servMainWindow::checkVertifiedUser(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void servMainWindow::processMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
