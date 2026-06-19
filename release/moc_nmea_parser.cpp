/****************************************************************************
** Meta object code from reading C++ file 'nmea_parser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/nmea_parser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nmea_parser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Teseo__NmeaParser_t {
    QByteArrayData data[45];
    char stringdata0[600];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Teseo__NmeaParser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Teseo__NmeaParser_t qt_meta_stringdata_Teseo__NmeaParser = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Teseo::NmeaParser"
QT_MOC_LITERAL(1, 18, 15), // "positionUpdated"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 15), // "Teseo::Position"
QT_MOC_LITERAL(4, 51, 8), // "position"
QT_MOC_LITERAL(5, 60, 15), // "velocityUpdated"
QT_MOC_LITERAL(6, 76, 15), // "Teseo::Velocity"
QT_MOC_LITERAL(7, 92, 8), // "velocity"
QT_MOC_LITERAL(8, 101, 17), // "satellitesUpdated"
QT_MOC_LITERAL(9, 119, 25), // "QVector<Teseo::Satellite>"
QT_MOC_LITERAL(10, 145, 10), // "satellites"
QT_MOC_LITERAL(11, 156, 10), // "dopUpdated"
QT_MOC_LITERAL(12, 167, 10), // "Teseo::DOP"
QT_MOC_LITERAL(13, 178, 3), // "dop"
QT_MOC_LITERAL(14, 182, 15), // "accuracyUpdated"
QT_MOC_LITERAL(15, 198, 15), // "Teseo::Accuracy"
QT_MOC_LITERAL(16, 214, 8), // "accuracy"
QT_MOC_LITERAL(17, 223, 10), // "fixUpdated"
QT_MOC_LITERAL(18, 234, 15), // "Teseo::GnssData"
QT_MOC_LITERAL(19, 250, 4), // "data"
QT_MOC_LITERAL(20, 255, 20), // "nmeaSentenceReceived"
QT_MOC_LITERAL(21, 276, 8), // "sentence"
QT_MOC_LITERAL(22, 285, 19), // "pstmMessageReceived"
QT_MOC_LITERAL(23, 305, 7), // "message"
QT_MOC_LITERAL(24, 313, 15), // "rtcTimeReceived"
QT_MOC_LITERAL(25, 329, 14), // "Teseo::RTCData"
QT_MOC_LITERAL(26, 344, 3), // "rtc"
QT_MOC_LITERAL(27, 348, 23), // "softwareVersionReceived"
QT_MOC_LITERAL(28, 372, 22), // "Teseo::SoftwareVersion"
QT_MOC_LITERAL(29, 395, 3), // "ver"
QT_MOC_LITERAL(30, 399, 17), // "ppsStatusReceived"
QT_MOC_LITERAL(31, 417, 16), // "Teseo::PPSStatus"
QT_MOC_LITERAL(32, 434, 3), // "pps"
QT_MOC_LITERAL(33, 438, 19), // "traimStatusReceived"
QT_MOC_LITERAL(34, 458, 18), // "Teseo::TRAIMStatus"
QT_MOC_LITERAL(35, 477, 5), // "traim"
QT_MOC_LITERAL(36, 483, 21), // "standbyStatusReceived"
QT_MOC_LITERAL(37, 505, 7), // "enabled"
QT_MOC_LITERAL(38, 513, 16), // "lowPowerReceived"
QT_MOC_LITERAL(39, 530, 18), // "agpsStatusReceived"
QT_MOC_LITERAL(40, 549, 17), // "parameterReceived"
QT_MOC_LITERAL(41, 567, 2), // "id"
QT_MOC_LITERAL(42, 570, 5), // "value"
QT_MOC_LITERAL(43, 576, 18), // "uniqueCodeReceived"
QT_MOC_LITERAL(44, 595, 4) // "code"

    },
    "Teseo::NmeaParser\0positionUpdated\0\0"
    "Teseo::Position\0position\0velocityUpdated\0"
    "Teseo::Velocity\0velocity\0satellitesUpdated\0"
    "QVector<Teseo::Satellite>\0satellites\0"
    "dopUpdated\0Teseo::DOP\0dop\0accuracyUpdated\0"
    "Teseo::Accuracy\0accuracy\0fixUpdated\0"
    "Teseo::GnssData\0data\0nmeaSentenceReceived\0"
    "sentence\0pstmMessageReceived\0message\0"
    "rtcTimeReceived\0Teseo::RTCData\0rtc\0"
    "softwareVersionReceived\0Teseo::SoftwareVersion\0"
    "ver\0ppsStatusReceived\0Teseo::PPSStatus\0"
    "pps\0traimStatusReceived\0Teseo::TRAIMStatus\0"
    "traim\0standbyStatusReceived\0enabled\0"
    "lowPowerReceived\0agpsStatusReceived\0"
    "parameterReceived\0id\0value\0"
    "uniqueCodeReceived\0code"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Teseo__NmeaParser[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      17,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       5,    1,  102,    2, 0x06 /* Public */,
       8,    1,  105,    2, 0x06 /* Public */,
      11,    1,  108,    2, 0x06 /* Public */,
      14,    1,  111,    2, 0x06 /* Public */,
      17,    1,  114,    2, 0x06 /* Public */,
      20,    1,  117,    2, 0x06 /* Public */,
      22,    1,  120,    2, 0x06 /* Public */,
      24,    1,  123,    2, 0x06 /* Public */,
      27,    1,  126,    2, 0x06 /* Public */,
      30,    1,  129,    2, 0x06 /* Public */,
      33,    1,  132,    2, 0x06 /* Public */,
      36,    1,  135,    2, 0x06 /* Public */,
      38,    1,  138,    2, 0x06 /* Public */,
      39,    1,  141,    2, 0x06 /* Public */,
      40,    2,  144,    2, 0x06 /* Public */,
      43,    1,  149,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::QByteArray,   21,
    QMetaType::Void, QMetaType::QByteArray,   23,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void, QMetaType::QByteArray,   19,
    QMetaType::Void, QMetaType::QByteArray,   19,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,   41,   42,
    QMetaType::Void, QMetaType::QByteArray,   44,

       0        // eod
};

void Teseo::NmeaParser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NmeaParser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->positionUpdated((*reinterpret_cast< const Teseo::Position(*)>(_a[1]))); break;
        case 1: _t->velocityUpdated((*reinterpret_cast< const Teseo::Velocity(*)>(_a[1]))); break;
        case 2: _t->satellitesUpdated((*reinterpret_cast< const QVector<Teseo::Satellite>(*)>(_a[1]))); break;
        case 3: _t->dopUpdated((*reinterpret_cast< const Teseo::DOP(*)>(_a[1]))); break;
        case 4: _t->accuracyUpdated((*reinterpret_cast< const Teseo::Accuracy(*)>(_a[1]))); break;
        case 5: _t->fixUpdated((*reinterpret_cast< const Teseo::GnssData(*)>(_a[1]))); break;
        case 6: _t->nmeaSentenceReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 7: _t->pstmMessageReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 8: _t->rtcTimeReceived((*reinterpret_cast< const Teseo::RTCData(*)>(_a[1]))); break;
        case 9: _t->softwareVersionReceived((*reinterpret_cast< const Teseo::SoftwareVersion(*)>(_a[1]))); break;
        case 10: _t->ppsStatusReceived((*reinterpret_cast< const Teseo::PPSStatus(*)>(_a[1]))); break;
        case 11: _t->traimStatusReceived((*reinterpret_cast< const Teseo::TRAIMStatus(*)>(_a[1]))); break;
        case 12: _t->standbyStatusReceived((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->lowPowerReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 14: _t->agpsStatusReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 15: _t->parameterReceived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 16: _t->uniqueCodeReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Teseo::Position >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Teseo::Velocity >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<Teseo::Satellite> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Teseo::DOP >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Teseo::Accuracy >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Teseo::GnssData >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Teseo::RTCData >(); break;
            }
            break;
        case 9:
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
            using _t = void (NmeaParser::*)(const Teseo::Position & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::positionUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const Teseo::Velocity & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::velocityUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const QVector<Teseo::Satellite> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::satellitesUpdated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const Teseo::DOP & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::dopUpdated)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const Teseo::Accuracy & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::accuracyUpdated)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const Teseo::GnssData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::fixUpdated)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::nmeaSentenceReceived)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::pstmMessageReceived)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const Teseo::RTCData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::rtcTimeReceived)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const Teseo::SoftwareVersion & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::softwareVersionReceived)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const Teseo::PPSStatus & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::ppsStatusReceived)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const Teseo::TRAIMStatus & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::traimStatusReceived)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::standbyStatusReceived)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::lowPowerReceived)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::agpsStatusReceived)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(int , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::parameterReceived)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (NmeaParser::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NmeaParser::uniqueCodeReceived)) {
                *result = 16;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Teseo::NmeaParser::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Teseo__NmeaParser.data,
    qt_meta_data_Teseo__NmeaParser,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Teseo::NmeaParser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Teseo::NmeaParser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Teseo__NmeaParser.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Teseo::NmeaParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Teseo::NmeaParser::positionUpdated(const Teseo::Position & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Teseo::NmeaParser::velocityUpdated(const Teseo::Velocity & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Teseo::NmeaParser::satellitesUpdated(const QVector<Teseo::Satellite> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Teseo::NmeaParser::dopUpdated(const Teseo::DOP & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Teseo::NmeaParser::accuracyUpdated(const Teseo::Accuracy & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Teseo::NmeaParser::fixUpdated(const Teseo::GnssData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Teseo::NmeaParser::nmeaSentenceReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Teseo::NmeaParser::pstmMessageReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Teseo::NmeaParser::rtcTimeReceived(const Teseo::RTCData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Teseo::NmeaParser::softwareVersionReceived(const Teseo::SoftwareVersion & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Teseo::NmeaParser::ppsStatusReceived(const Teseo::PPSStatus & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Teseo::NmeaParser::traimStatusReceived(const Teseo::TRAIMStatus & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Teseo::NmeaParser::standbyStatusReceived(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Teseo::NmeaParser::lowPowerReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Teseo::NmeaParser::agpsStatusReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Teseo::NmeaParser::parameterReceived(int _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Teseo::NmeaParser::uniqueCodeReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
