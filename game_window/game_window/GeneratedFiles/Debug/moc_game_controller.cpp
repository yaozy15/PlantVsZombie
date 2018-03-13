/****************************************************************************
** Meta object code from reading C++ file 'game_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../game_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_game_view_t {
    QByteArrayData data[31];
    char stringdata0[345];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_game_view_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_game_view_t qt_meta_stringdata_game_view = {
    {
QT_MOC_LITERAL(0, 0, 9), // "game_view"
QT_MOC_LITERAL(1, 10, 5), // "check"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 14), // "move_to_screen"
QT_MOC_LITERAL(4, 32, 12), // "createBullet"
QT_MOC_LITERAL(5, 45, 10), // "createBomb"
QT_MOC_LITERAL(6, 56, 16), // "createMoreBullet"
QT_MOC_LITERAL(7, 73, 12), // "createZombie"
QT_MOC_LITERAL(8, 86, 8), // "makeCard"
QT_MOC_LITERAL(9, 95, 9), // "createSun"
QT_MOC_LITERAL(10, 105, 10), // "gamePlant*"
QT_MOC_LITERAL(11, 116, 6), // "attack"
QT_MOC_LITERAL(12, 123, 12), // "damageVector"
QT_MOC_LITERAL(13, 136, 18), // "damageVectorCherry"
QT_MOC_LITERAL(14, 155, 13), // "damageVector1"
QT_MOC_LITERAL(15, 169, 11), // "gameZombie*"
QT_MOC_LITERAL(16, 181, 13), // "damageVector2"
QT_MOC_LITERAL(17, 195, 11), // "gameWeapon*"
QT_MOC_LITERAL(18, 207, 7), // "showSun"
QT_MOC_LITERAL(19, 215, 8), // "gameSun*"
QT_MOC_LITERAL(20, 224, 9), // "getShover"
QT_MOC_LITERAL(21, 234, 13), // "getMousePlace"
QT_MOC_LITERAL(22, 248, 10), // "clearPlant"
QT_MOC_LITERAL(23, 259, 9), // "mouseback"
QT_MOC_LITERAL(24, 269, 8), // "makeFade"
QT_MOC_LITERAL(25, 278, 13), // "makeScreenSun"
QT_MOC_LITERAL(26, 292, 10), // "make_plant"
QT_MOC_LITERAL(27, 303, 1), // "i"
QT_MOC_LITERAL(28, 305, 13), // "getMousePlant"
QT_MOC_LITERAL(29, 319, 15), // "createMaxBullet"
QT_MOC_LITERAL(30, 335, 9) // "endScreen"

    },
    "game_view\0check\0\0move_to_screen\0"
    "createBullet\0createBomb\0createMoreBullet\0"
    "createZombie\0makeCard\0createSun\0"
    "gamePlant*\0attack\0damageVector\0"
    "damageVectorCherry\0damageVector1\0"
    "gameZombie*\0damageVector2\0gameWeapon*\0"
    "showSun\0gameSun*\0getShover\0getMousePlace\0"
    "clearPlant\0mouseback\0makeFade\0"
    "makeScreenSun\0make_plant\0i\0getMousePlant\0"
    "createMaxBullet\0endScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_game_view[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  134,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  139,    2, 0x0a /* Public */,
       4,    1,  140,    2, 0x0a /* Public */,
       5,    1,  143,    2, 0x0a /* Public */,
       6,    1,  146,    2, 0x0a /* Public */,
       7,    0,  149,    2, 0x0a /* Public */,
       8,    1,  150,    2, 0x0a /* Public */,
       9,    2,  153,    2, 0x0a /* Public */,
      11,    0,  158,    2, 0x0a /* Public */,
      12,    1,  159,    2, 0x0a /* Public */,
      13,    1,  162,    2, 0x0a /* Public */,
      14,    1,  165,    2, 0x0a /* Public */,
      16,    1,  168,    2, 0x0a /* Public */,
      18,    1,  171,    2, 0x0a /* Public */,
      20,    0,  174,    2, 0x0a /* Public */,
      21,    0,  175,    2, 0x0a /* Public */,
      22,    0,  176,    2, 0x0a /* Public */,
      23,    0,  177,    2, 0x0a /* Public */,
      24,    1,  178,    2, 0x0a /* Public */,
      25,    1,  181,    2, 0x0a /* Public */,
      26,    1,  184,    2, 0x0a /* Public */,
      28,    0,  187,    2, 0x0a /* Public */,
      29,    1,  188,    2, 0x0a /* Public */,
      30,    0,  191,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 10,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void game_view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        game_view *_t = static_cast<game_view *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->check((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->move_to_screen(); break;
        case 2: _t->createBullet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->createBomb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->createMoreBullet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->createZombie(); break;
        case 6: _t->makeCard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->createSun((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< gamePlant*(*)>(_a[2]))); break;
        case 8: _t->attack(); break;
        case 9: _t->damageVector((*reinterpret_cast< gamePlant*(*)>(_a[1]))); break;
        case 10: _t->damageVectorCherry((*reinterpret_cast< gamePlant*(*)>(_a[1]))); break;
        case 11: _t->damageVector1((*reinterpret_cast< gameZombie*(*)>(_a[1]))); break;
        case 12: _t->damageVector2((*reinterpret_cast< gameWeapon*(*)>(_a[1]))); break;
        case 13: _t->showSun((*reinterpret_cast< gameSun*(*)>(_a[1]))); break;
        case 14: _t->getShover(); break;
        case 15: _t->getMousePlace(); break;
        case 16: _t->clearPlant(); break;
        case 17: _t->mouseback(); break;
        case 18: _t->makeFade((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->makeScreenSun((*reinterpret_cast< gameSun*(*)>(_a[1]))); break;
        case 20: _t->make_plant((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->getMousePlant(); break;
        case 22: _t->createMaxBullet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->endScreen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< gamePlant* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< gamePlant* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< gamePlant* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< gameZombie* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< gameWeapon* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< gameSun* >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< gameSun* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (game_view::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&game_view::check)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject game_view::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_game_view.data,
      qt_meta_data_game_view,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *game_view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *game_view::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_game_view.stringdata0))
        return static_cast<void*>(const_cast< game_view*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int game_view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void game_view::check(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
