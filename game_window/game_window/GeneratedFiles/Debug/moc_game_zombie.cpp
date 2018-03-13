/****************************************************************************
** Meta object code from reading C++ file 'game_zombie.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../game_zombie.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_zombie.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_gameZombie_t {
    QByteArrayData data[18];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gameZombie_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gameZombie_t qt_meta_stringdata_gameZombie = {
    {
QT_MOC_LITERAL(0, 0, 10), // "gameZombie"
QT_MOC_LITERAL(1, 11, 12), // "damageZombie"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "gameZombie*"
QT_MOC_LITERAL(4, 37, 12), // "PixmapUpdate"
QT_MOC_LITERAL(5, 50, 12), // "movie_update"
QT_MOC_LITERAL(6, 63, 7), // "destroy"
QT_MOC_LITERAL(7, 71, 10), // "playAction"
QT_MOC_LITERAL(8, 82, 17), // "ZombieMove_update"
QT_MOC_LITERAL(9, 100, 19), // "ZombieBucket_update"
QT_MOC_LITERAL(10, 120, 16), // "PoleZombieUpdate"
QT_MOC_LITERAL(11, 137, 18), // "ZombieNormalUpdate"
QT_MOC_LITERAL(12, 156, 15), // "ZombieDieUpdate"
QT_MOC_LITERAL(13, 172, 15), // "ZombieEatUpdate"
QT_MOC_LITERAL(14, 188, 10), // "judgeMovie"
QT_MOC_LITERAL(15, 199, 12), // "setnewPixmap"
QT_MOC_LITERAL(16, 212, 1), // "i"
QT_MOC_LITERAL(17, 214, 8) // "setMyGif"

    },
    "gameZombie\0damageZombie\0\0gameZombie*\0"
    "PixmapUpdate\0movie_update\0destroy\0"
    "playAction\0ZombieMove_update\0"
    "ZombieBucket_update\0PoleZombieUpdate\0"
    "ZombieNormalUpdate\0ZombieDieUpdate\0"
    "ZombieEatUpdate\0judgeMovie\0setnewPixmap\0"
    "i\0setMyGif"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gameZombie[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   87,    2, 0x0a /* Public */,
       5,    0,   88,    2, 0x0a /* Public */,
       6,    0,   89,    2, 0x0a /* Public */,
       7,    0,   90,    2, 0x0a /* Public */,
       8,    0,   91,    2, 0x0a /* Public */,
       9,    0,   92,    2, 0x0a /* Public */,
      10,    0,   93,    2, 0x0a /* Public */,
      11,    0,   94,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x0a /* Public */,
      13,    0,   96,    2, 0x0a /* Public */,
      14,    0,   97,    2, 0x0a /* Public */,
      15,    1,   98,    2, 0x0a /* Public */,
      17,    1,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void gameZombie::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gameZombie *_t = static_cast<gameZombie *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->damageZombie((*reinterpret_cast< gameZombie*(*)>(_a[1]))); break;
        case 1: _t->PixmapUpdate(); break;
        case 2: _t->movie_update(); break;
        case 3: _t->destroy(); break;
        case 4: _t->playAction(); break;
        case 5: _t->ZombieMove_update(); break;
        case 6: _t->ZombieBucket_update(); break;
        case 7: _t->PoleZombieUpdate(); break;
        case 8: _t->ZombieNormalUpdate(); break;
        case 9: _t->ZombieDieUpdate(); break;
        case 10: _t->ZombieEatUpdate(); break;
        case 11: _t->judgeMovie(); break;
        case 12: _t->setnewPixmap((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setMyGif((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< gameZombie* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (gameZombie::*_t)(gameZombie * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gameZombie::damageZombie)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject gameZombie::staticMetaObject = {
    { &gamePlayer::staticMetaObject, qt_meta_stringdata_gameZombie.data,
      qt_meta_data_gameZombie,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *gameZombie::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gameZombie::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_gameZombie.stringdata0))
        return static_cast<void*>(const_cast< gameZombie*>(this));
    return gamePlayer::qt_metacast(_clname);
}

int gameZombie::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = gamePlayer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void gameZombie::damageZombie(gameZombie * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
