/****************************************************************************
** Meta object code from reading C++ file 'teseo_driver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/teseo_driver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teseo_driver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Teseo__TeseoDriver_t {
    QByteArrayData data[54];
    char stringdata0[711];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Teseo__TeseoDriver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Teseo__TeseoDriver_t qt_meta_stringdata_Teseo__TeseoDriver = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Teseo::TeseoDriver"
QT_MOC_LITERAL(1, 19, 9), // "connected"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "disconnected"
QT_MOC_LITERAL(4, 43, 15), // "positionUpdated"
QT_MOC_LITERAL(5, 59, 15), // "Teseo::Position"
QT_MOC_LITERAL(6, 75, 8), // "position"
QT_MOC_LITERAL(7, 84, 15), // "velocityUpdated"
QT_MOC_LITERAL(8, 100, 15), // "Teseo::Velocity"
QT_MOC_LITERAL(9, 116, 8), // "velocity"
QT_MOC_LITERAL(10, 125, 17), // "satellitesUpdated"
QT_MOC_LITERAL(11, 143, 25), // "QVector<Teseo::Satellite>"
QT_MOC_LITERAL(12, 169, 10), // "satellites"
QT_MOC_LITERAL(13, 180, 10), // "dopUpdated"
QT_MOC_LITERAL(14, 191, 10), // "Teseo::DOP"
QT_MOC_LITERAL(15, 202, 3), // "dop"
QT_MOC_LITERAL(16, 206, 15), // "accuracyUpdated"
QT_MOC_LITERAL(17, 222, 15), // "Teseo::Accuracy"
QT_MOC_LITERAL(18, 238, 8), // "accuracy"
QT_MOC_LITERAL(19, 247, 10), // "fixUpdated"
QT_MOC_LITERAL(20, 258, 15), // "Teseo::GnssData"
QT_MOC_LITERAL(21, 274, 4), // "data"
QT_MOC_LITERAL(22, 279, 20), // "nmeaSentenceReceived"
QT_MOC_LITERAL(23, 300, 8), // "sentence"
QT_MOC_LITERAL(24, 309, 19), // "pstmMessageReceived"
QT_MOC_LITERAL(25, 329, 7), // "message"
QT_MOC_LITERAL(26, 337, 16), // "responseReceived"
QT_MOC_LITERAL(27, 354, 8), // "response"
QT_MOC_LITERAL(28, 363, 13), // "errorOccurred"
QT_MOC_LITERAL(29, 377, 5), // "error"
QT_MOC_LITERAL(30, 383, 15), // "rtcTimeReceived"
QT_MOC_LITERAL(31, 399, 14), // "Teseo::RTCData"
QT_MOC_LITERAL(32, 414, 3), // "rtc"
QT_MOC_LITERAL(33, 418, 23), // "softwareVersionReceived"
QT_MOC_LITERAL(34, 442, 22), // "Teseo::SoftwareVersion"
QT_MOC_LITERAL(35, 465, 3), // "ver"
QT_MOC_LITERAL(36, 469, 17), // "ppsStatusReceived"
QT_MOC_LITERAL(37, 487, 16), // "Teseo::PPSStatus"
QT_MOC_LITERAL(38, 504, 3), // "pps"
QT_MOC_LITERAL(39, 508, 19), // "traimStatusReceived"
QT_MOC_LITERAL(40, 528, 18), // "Teseo::TRAIMStatus"
QT_MOC_LITERAL(41, 547, 5), // "traim"
QT_MOC_LITERAL(42, 553, 21), // "standbyStatusReceived"
QT_MOC_LITERAL(43, 575, 7), // "enabled"
QT_MOC_LITERAL(44, 583, 16), // "lowPowerReceived"
QT_MOC_LITERAL(45, 600, 18), // "agpsStatusReceived"
QT_MOC_LITERAL(46, 619, 17), // "parameterReceived"
QT_MOC_LITERAL(47, 637, 2), // "id"
QT_MOC_LITERAL(48, 640, 5), // "value"
QT_MOC_LITERAL(49, 646, 18), // "uniqueCodeReceived"
QT_MOC_LITERAL(50, 665, 4), // "code"
QT_MOC_LITERAL(51, 670, 14), // "onDataReceived"
QT_MOC_LITERAL(52, 685, 13), // "onSerialError"
QT_MOC_LITERAL(53, 699, 11) // "errorString"

    },
    "Teseo::TeseoDriver\0connected\0\0"
    "disconnected\0positionUpdated\0"
    "Teseo::Position\0position\0velocityUpdated\0"
    "Teseo::Velocity\0velocity\0satellitesUpdated\0"
    "QVector<Teseo::Satellite>\0satellites\0"
    "dopUpdated\0Teseo::DOP\0dop\0accuracyUpdated\0"
    "Teseo::Accuracy\0accuracy\0fixUpdated\0"
    "Teseo::GnssData\0data\0nmeaSentenceReceived\0"
    "sentence\0pstmMessageReceived\0message\0"
    "responseReceived\0response\0errorOccurred\0"
    "error\0rtcTimeReceived\0Teseo::RTCData\0"
    "rtc\0softwareVersionReceived\0"
    "Teseo::SoftwareVersion\0ver\0ppsStatusReceived\0"
    "Teseo::PPSStatus\0pps\0traimStatusReceived\0"
    "Teseo::TRAIMStatus\0traim\0standbyStatusReceived\0"
    "enabled\0lowPowerReceived\0agpsStatusReceived\0"
    "parameterReceived\0id\0value\0"
    "uniqueCodeReceived\0code\0onDataReceived\0"
    "onSerialError\0errorString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Teseo__TeseoDriver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      21,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  129,    2, 0x06 /* Public */,
       3,    0,  130,    2, 0x06 /* Public */,
       4,    1,  131,    2, 0x06 /* Public */,
       7,    1,  134,    2, 0x06 /* Public */,
      10,    1,  137,    2, 0x06 /* Public */,
      13,    1,  140,    2, 0x06 /* Public */,
      16,    1,  143,    2, 0x06 /* Public */,
      19,    1,  146,    2, 0x06 /* Public */,
      22,    1,  149,    2, 0x06 /* Public */,
      24,    1,  152,    2, 0x06 /* Public */,
      26,    1,  155,    2, 0x06 /* Public */,
      28,    1,  158,    2, 0x06 /* Public */,
      30,    1,  161,    2, 0x06 /* Public */,
      33,    1,  164,    2, 0x06 /* Public */,
      36,    1,  167,    2, 0x06 /* Public */,
      39,    1,  170,    2, 0x06 /* Public */,
      42,    1,  173,    2, 0x06 /* Public */,
      44,    1,  176,    2, 0x06 /* Public */,
      45,    1,  179,    2, 0x06 /* Public */,
      46,    2,  182,    2, 0x06 /* Public */,
      49,    1,  187,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      51,    1,  190,    2, 0x08 /* Private */,
      52,    1,  193,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, QMetaType::QByteArray,   23,
    QMetaType::Void, QMetaType::QByteArray,   25,
    QMetaType::Void, QMetaType::QByteArray,   27,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void, 0x80000000 | 37,   38,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, QMetaType::Bool,   43,
    QMetaType::Void, QMetaType::QByteArray,   21,
    QMetaType::Void, QMetaType::QByteArray,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,   47,   48,
    QMetaType::Void, QMetaType::QByteArray,   50,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   21,
    QMetaType::Void, QMetaType::QString,   53,

       0        // eod
};

void Teseo::TeseoDriver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TeseoDriver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->positionUpdated((*reinterpret_cast< const Teseo::Position(*)>(_a[1]))); break;
        case 3: _t->velocityUpdated((*reinterpret_cast< const Teseo::Velocity(*)>(_a[1]))); break;
        case 4: _t->satellitesUpdated((*reinterpret_cast< const QVector<Teseo::Satellite>(*)>(_a[1]))); break;
        case 5: _t->dopUpdated((*reinterpret_cast< const Teseo::DOP(*)>(_a[1]))); break;
        case 6: _t->accuracyUpdated((*reinterpret_cast< const Teseo::Accuracy(*)>(_a[1]))); break;
        case 7: _t->fixUpdated((*reinterpret_cast< const Teseo::GnssData(*)>(_a[1]))); break;
        case 8: _t->nmeaSentenceReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 9: _t->pstmMessageReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 10: _t->responseReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 11: _t->errorOccurred((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->rtcTimeReceived((*reinterpret_cast< const Teseo::RTCData(*)>(_a[1]))); break;
        case 13: _t->softwareVersionReceived((*reinterpret_cast< const Teseo::SoftwareVersion(*)>(_a[1]))); break;
        case 14: _t->ppsStatusReceived((*reinterpret_cast< const Teseo::PPSStatus(*)>(_a[1]))); break;
        case 15: _t->traimStatusReceived((*reinterpret_cast< const Teseo::TRAIMStatus(*)>(_a[1]))); break;
        case 16: _t->standbyStatusReceived((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->lowPowerReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 18: _t->agpsStatusReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 19: _t->parameterReceived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 20: _t->uniqueCodeReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 21: _t->onDataReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 22: _t->onSerialError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Teseo::Position >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Teseo::Velocity >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<Teseo::Satellite> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Teseo::DOP >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Teseo::Accuracy >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Teseo::GnssData >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Teseo::RTCData >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Teseo::SoftwareVersion >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TeseoDriver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::disconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const Teseo::Position & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::positionUpdated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const Teseo::Velocity & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::velocityUpdated)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const QVector<Teseo::Satellite> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::satellitesUpdated)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const Teseo::DOP & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::dopUpdated)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const Teseo::Accuracy & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::accuracyUpdated)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const Teseo::GnssData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::fixUpdated)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::nmeaSentenceReceived)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::pstmMessageReceived)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::responseReceived)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::errorOccurred)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const Teseo::RTCData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::rtcTimeReceived)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const Teseo::SoftwareVersion & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::softwareVersionReceived)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const Teseo::PPSStatus & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::ppsStatusReceived)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const Teseo::TRAIMStatus & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::traimStatusReceived)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::standbyStatusReceived)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::lowPowerReceived)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::agpsStatusReceived)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(int , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::parameterReceived)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (TeseoDriver::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeseoDriver::uniqueCodeReceived)) {
                *result = 20;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Teseo::TeseoDriver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Teseo__TeseoDriver.data,
    qt_meta_data_Teseo__TeseoDriver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Teseo::TeseoDriver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Teseo::TeseoDriver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Teseo__TeseoDriver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Teseo::TeseoDriver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void Teseo::TeseoDriver::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Teseo::TeseoDriver::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Teseo::TeseoDriver::positionUpdated(const Teseo::Position & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Teseo::TeseoDriver::velocityUpdated(const Teseo::Velocity & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Teseo::TeseoDriver::satellitesUpdated(const QVector<Teseo::Satellite> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Teseo::TeseoDriver::dopUpdated(const Teseo::DOP & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Teseo::TeseoDriver::accuracyUpdated(const Teseo::Accuracy & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Teseo::TeseoDriver::fixUpdated(const Teseo::GnssData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Teseo::TeseoDriver::nmeaSentenceReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Teseo::TeseoDriver::pstmMessageReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Teseo::TeseoDriver::responseReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Teseo::TeseoDriver::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Teseo::TeseoDriver::rtcTimeReceived(const Teseo::RTCData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Teseo::TeseoDriver::softwareVersionReceived(const Teseo::SoftwareVersion & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Teseo::TeseoDriver::ppsStatusReceived(const Teseo::PPSStatus & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Teseo::TeseoDriver::traimStatusReceived(const Teseo::TRAIMStatus & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Teseo::TeseoDriver::standbyStatusReceived(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Teseo::TeseoDriver::lowPowerReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void Teseo::TeseoDriver::agpsStatusReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Teseo::TeseoDriver::parameterReceived(int _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void Teseo::TeseoDriver::uniqueCodeReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
