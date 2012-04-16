/****************************************************************************
** Meta object code from reading C++ file 'mtabwidgets.h'
**
** Created: Mon 16. Apr 22:34:37 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mtabwidgets.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mtabwidgets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MTabWidgets[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      69,   32,   12,   12, 0x0a,
     102,   12,   12,   12, 0x0a,
     131,   12,  126,   12, 0x0a,
     153,  148,   12,   12, 0x0a,
     179,  148,   12,   12, 0x0a,
     210,  204,   12,   12, 0x0a,
     232,  204,   12,   12, 0x0a,
     256,  204,   12,   12, 0x0a,
     283,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MTabWidgets[] = {
    "MTabWidgets\0\0slotSendMesseges()\0"
    "nameUserEntering,newEnteringMesseges\0"
    "slotNewEntering(QString,QString)\0"
    "enabledSendPuchButton()\0bool\0"
    "slotSendToFile()\0text\0slotSetColorText(QString)\0"
    "slotSetFontText(QString)\0index\0"
    "slotSetBoldText(bool)\0slotSetItalicText(bool)\0"
    "slotSetUnderlineText(bool)\0"
    "slotClearHistory()\0"
};

void MTabWidgets::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MTabWidgets *_t = static_cast<MTabWidgets *>(_o);
        switch (_id) {
        case 0: _t->slotSendMesseges(); break;
        case 1: _t->slotNewEntering((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->enabledSendPuchButton(); break;
        case 3: { bool _r = _t->slotSendToFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->slotSetColorText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->slotSetFontText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->slotSetBoldText((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->slotSetItalicText((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->slotSetUnderlineText((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->slotClearHistory(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MTabWidgets::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MTabWidgets::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MTabWidgets,
      qt_meta_data_MTabWidgets, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MTabWidgets::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MTabWidgets::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MTabWidgets::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MTabWidgets))
        return static_cast<void*>(const_cast< MTabWidgets*>(this));
    if (!strcmp(_clname, "Ui_MTabWidgetsClass"))
        return static_cast< Ui_MTabWidgetsClass*>(const_cast< MTabWidgets*>(this));
    return QWidget::qt_metacast(_clname);
}

int MTabWidgets::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
