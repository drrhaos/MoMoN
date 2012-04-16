/****************************************************************************
** Meta object code from reading C++ file 'mclient.h'
**
** Created: Mon 16. Apr 22:00:40 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,    9,    8,    8, 0x05,
      60,   51,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     113,   85,    8,    8, 0x0a,
     152,    8,    8,    8, 0x0a,
     168,    8,    8,    8, 0x0a,
     217,  184,    8,    8, 0x0a,
     279,  260,    8,    8, 0x0a,
     311,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MClient[] = {
    "MClient\0\0strHostName\0signalsDisConnected(QString&)\0"
    "fileSize\0signalsFileSize(QString)\0"
    "tIpHost,numberPort,ipString\0"
    "slotConnectToHost(QString,int,QString)\0"
    "slotConnected()\0slotReadyRead()\0"
    "statusName,nameUser,sendMesseges\0"
    "slotSendToMessage(QString,QString,QString)\0"
    "filePatch,nameUser\0slotSendToFile(QString,QString)\0"
    "slotError(QAbstractSocket::SocketError)\0"
};

void MClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MClient *_t = static_cast<MClient *>(_o);
        switch (_id) {
        case 0: _t->signalsDisConnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signalsFileSize((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotConnectToHost((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->slotConnected(); break;
        case 4: _t->slotReadyRead(); break;
        case 5: _t->slotSendToMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->slotSendToFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MClient,
      qt_meta_data_MClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MClient))
        return static_cast<void*>(const_cast< MClient*>(this));
    return QObject::qt_metacast(_clname);
}

int MClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MClient::signalsDisConnected(QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MClient::signalsFileSize(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
