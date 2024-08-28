/****************************************************************************
** Meta object code from reading C++ file 'userlist.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../userlist.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userlist.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSUserListENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSUserListENDCLASS = QtMocHelpers::stringData(
    "UserList",
    "userMapChanged",
    "",
    "userName",
    "isEntering",
    "enterStatusChange",
    "userEntered",
    "userMap_keys",
    "userMap_values"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSUserListENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[9];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[11];
    char stringdata5[18];
    char stringdata6[12];
    char stringdata7[13];
    char stringdata8[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSUserListENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSUserListENDCLASS_t qt_meta_stringdata_CLASSUserListENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "UserList"
        QT_MOC_LITERAL(9, 14),  // "userMapChanged"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 8),  // "userName"
        QT_MOC_LITERAL(34, 10),  // "isEntering"
        QT_MOC_LITERAL(45, 17),  // "enterStatusChange"
        QT_MOC_LITERAL(63, 11),  // "userEntered"
        QT_MOC_LITERAL(75, 12),  // "userMap_keys"
        QT_MOC_LITERAL(88, 14)   // "userMap_values"
    },
    "UserList",
    "userMapChanged",
    "",
    "userName",
    "isEntering",
    "enterStatusChange",
    "userEntered",
    "userMap_keys",
    "userMap_values"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUserListENDCLASS[] = {

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
       1,    2,   44,    2, 0x06,    1 /* Public */,
       5,    0,   49,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   50,    2, 0x0a,    5 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   53,    2, 0x102,    7 /* Public | MethodIsConst  */,
       8,    1,   54,    2, 0x102,    8 /* Public | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // methods: parameters
    QMetaType::QStringList,
    QMetaType::QVariant, QMetaType::QString,    3,

       0        // eod
};

Q_CONSTINIT const QMetaObject UserList::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSUserListENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUserListENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUserListENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UserList, std::true_type>,
        // method 'userMapChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        // method 'enterStatusChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'userEntered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'userMap_keys'
        QtPrivate::TypeAndForceComplete<QList<QString>, std::false_type>,
        // method 'userMap_values'
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void UserList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->userMapChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 1: _t->enterStatusChange(); break;
        case 2: _t->userEntered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: { QList<QString> _r = _t->userMap_keys();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QVariant _r = _t->userMap_values((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UserList::*)(QString , QVariant );
            if (_t _q_method = &UserList::userMapChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UserList::*)();
            if (_t _q_method = &UserList::enterStatusChange; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *UserList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUserListENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UserList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void UserList::userMapChanged(QString _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UserList::enterStatusChange()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
