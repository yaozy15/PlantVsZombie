/****************************************************************************
** Meta object code from reading C++ file 'game_plant.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../game_plant.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_plant.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_gamePlant_t {
    QByteArrayData data[15];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gamePlant_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gamePlant_t qt_meta_stringdata_gamePlant = {
    {
QT_MOC_LITERAL(0, 0, 9), // "gamePlant"
QT_MOC_LITERAL(1, 10, 10), // "needWeapon"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "needMoreWeapon"
QT_MOC_LITERAL(4, 37, 7), // "needSun"
QT_MOC_LITERAL(5, 45, 10), // "gamePlant*"
QT_MOC_LITERAL(6, 56, 6), // "damage"
QT_MOC_LITERAL(7, 63, 12), // "damageCherry"
QT_MOC_LITERAL(8, 76, 8), // "needBomb"
QT_MOC_LITERAL(9, 85, 13), // "needMaxWeapon"
QT_MOC_LITERAL(10, 99, 12), // "PixmapUpdate"
QT_MOC_LITERAL(11, 112, 13), // "PixmapSUpdate"
QT_MOC_LITERAL(12, 126, 12), // "setnewPixmap"
QT_MOC_LITERAL(13, 139, 1), // "i"
QT_MOC_LITERAL(14, 141, 13) // "setnewPixmaps"

    },
    "gamePlant\0needWeapon\0\0needMoreWeapon\0"
    "needSun\0gamePlant*\0damage\0damageCherry\0"
    "needBomb\0needMaxWeapon\0PixmapUpdate\0"
    "PixmapSUpdate\0setnewPixmap\0i\0setnewPixmaps"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gamePlant[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,
       4,    2,   75,    2, 0x06 /* Public */,
       6,    1,   80,    2, 0x06 /* Public */,
       7,    1,   83,    2, 0x06 /* Public */,
       8,    1,   86,    2, 0x06 /* Public */,
       9,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    1,   94,    2, 0x0a /* Public */,
      14,    1,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void gamePlant::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gamePlant *_t = static_cast<gamePlant *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->needWeapon((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->needMoreWeapon((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->needSun((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< gamePlant*(*)>(_a[2]))); break;
        case 3: _t->damage((*reinterpret_cast< gamePlant*(*)>(_a[1]))); break;
        case 4: _t->damageCherry((*reinterpret_cast< gamePlant*(*)>(_a[1]))); break;
        case 5: _t->needBomb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->needMaxWeapon((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->PixmapUpdate(); break;
        case 8: _t->PixmapSUpdate(); break;
        case 9: _t->setnewPixmap((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setnewPixmaps((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< gamePlant* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< gamePlant* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< gamePlant* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (gamePlant::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gamePlant::needWeapon)) {
                *result = 0;
            }
        }
        {
            typedef void (gamePlant::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gamePlant::needMoreWeapon)) {
                *result = 1;
            }
        }
        {
            typedef void (gamePlant::*_t)(int , gamePlant * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gamePlant::needSun)) {
                *result = 2;
            }
        }
        {
            typedef void (gamePlant::*_t)(gamePlant * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gamePlant::damage)) {
                *result = 3;
            }
        }
        {
            typedef void (gamePlant::*_t)(gamePlant * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gamePlant::damageCherry)) {
                *result = 4;
            }
        }
        {
            typedef void (gamePlant::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gamePlant::needBomb)) {
                *result = 5;
            }
        }
        {
            typedef void (gamePlant::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gamePlant::needMaxWeapon)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject gamePlant::staticMetaObject = {
    { &gamePlayer::staticMetaObject, qt_meta_stringdata_gamePlant.data,
      qt_meta_data_gamePlant,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *gamePlant::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gamePlant::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_gamePlant.stringdata0))
        return static_cast<void*>(const_cast< gamePlant*>(this));
    return gamePlayer::qt_metacast(_clname);
}

int gamePlant::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = gamePlayer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void gamePlant::needWeapon(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void gamePlant::needMoreWeapon(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void gamePlant::needSun(int _t1, gamePlant * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void gamePlant::damage(gamePlant * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void gamePlant::damageCherry(gamePlant * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void gamePlant::needBomb(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void gamePlant::needMaxWeapon(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
