/****************************************************************************
** Meta object code from reading C++ file 'serv_interaction.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../serv_interaction.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serv_interaction.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSserv_interactionENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSserv_interactionENDCLASS = QtMocHelpers::stringData(
    "serv_interaction",
    "imAccepted",
    "",
    "imRejected",
    "sendUserName",
    "readData",
    "getServerConnectionResult",
    "username",
    "serverAddress",
    "serverPort"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSserv_interactionENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[17];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[13];
    char stringdata5[9];
    char stringdata6[26];
    char stringdata7[9];
    char stringdata8[14];
    char stringdata9[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSserv_interactionENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSserv_interactionENDCLASS_t qt_meta_stringdata_CLASSserv_interactionENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "serv_interaction"
        QT_MOC_LITERAL(17, 10),  // "imAccepted"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 10),  // "imRejected"
        QT_MOC_LITERAL(40, 12),  // "sendUserName"
        QT_MOC_LITERAL(53, 8),  // "readData"
        QT_MOC_LITERAL(62, 25),  // "getServerConnectionResult"
        QT_MOC_LITERAL(88, 8),  // "username"
        QT_MOC_LITERAL(97, 13),  // "serverAddress"
        QT_MOC_LITERAL(111, 10)   // "serverPort"
    },
    "serv_interaction",
    "imAccepted",
    "",
    "imRejected",
    "sendUserName",
    "readData",
    "getServerConnectionResult",
    "username",
    "serverAddress",
    "serverPort"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSserv_interactionENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    0,   45,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       6,    3,   48,    2, 0x02,    5 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int,    7,    8,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject serv_interaction::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSserv_interactionENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSserv_interactionENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSserv_interactionENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<serv_interaction, std::true_type>,
        // method 'imAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'imRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendUserName'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getServerConnectionResult'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void serv_interaction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serv_interaction *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->imAccepted(); break;
        case 1: _t->imRejected(); break;
        case 2: _t->sendUserName(); break;
        case 3: _t->readData(); break;
        case 4: { bool _r = _t->getServerConnectionResult((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (serv_interaction::*)();
            if (_t _q_method = &serv_interaction::imAccepted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (serv_interaction::*)();
            if (_t _q_method = &serv_interaction::imRejected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *serv_interaction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serv_interaction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSserv_interactionENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int serv_interaction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void serv_interaction::imAccepted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void serv_interaction::imRejected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
