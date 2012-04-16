/****************************************************************************
** Meta object code from reading C++ file 'mpopupmessage.h'
**
** Created: Mon 16. Apr 22:00:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mpopupmessage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mpopupmessage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MPopupMessage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   14,   14,   14, 0x0a,
      56,   46,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MPopupMessage[] = {
    "MPopupMessage\0\0closePop()\0closePopupMessage()\0"
    "coutPopup\0editPosition(int)\0"
};

void MPopupMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MPopupMessage *_t = static_cast<MPopupMessage *>(_o);
        switch (_id) {
        case 0: _t->closePop(); break;
        case 1: _t->closePopupMessage(); break;
        case 2: _t->editPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MPopupMessage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MPopupMessage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MPopupMessage,
      qt_meta_data_MPopupMessage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MPopupMessage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MPopupMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MPopupMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MPopupMessage))
        return static_cast<void*>(const_cast< MPopupMessage*>(this));
    if (!strcmp(_clname, "Ui_MPopupMessage"))
        return static_cast< Ui_MPopupMessage*>(const_cast< MPopupMessage*>(this));
    return QWidget::qt_metacast(_clname);
}

int MPopupMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MPopupMessage::closePop()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
