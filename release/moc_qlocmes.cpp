/****************************************************************************
** Meta object code from reading C++ file 'qlocmes.h'
**
** Created: Mon 16. Apr 22:34:49 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qlocmes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlocmes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MFormLocMes[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      31,   12,   12,   12, 0x0a,
      52,   12,   12,   12, 0x0a,
     148,   65,   12,   12, 0x0a,
     220,   12,   12,   12, 0x0a,
     253,  241,   12,   12, 0x0a,
     276,   12,   12,   12, 0x0a,
     289,   12,   12,   12, 0x0a,
     319,  306,   12,   12, 0x0a,
     346,   12,   12,   12, 0x0a,
     370,  366,   12,   12, 0x0a,
     402,   12,   12,   12, 0x0a,
     416,   12,   12,   12, 0x0a,
     454,  435,   12,   12, 0x0a,
     485,   12,   12,   12, 0x0a,
     506,  499,   12,   12, 0x0a,
     606,  571,   12,   12, 0x0a,
     642,   12,   12,   12, 0x0a,
     666,  660,   12,   12, 0x0a,
     691,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MFormLocMes[] = {
    "MFormLocMes\0\0connectToServer()\0"
    "disconnectToServer()\0returnMyIp()\0"
    "strStatusName,nameUser,nameSurname,name,namePatronymic,namePost,ipAdre"
    "ssPullClient\0"
    "addUser(QString&,QString&,QString&,QString&,QString&,QString&,QString&"
    ")\0"
    "deleteUserFromData()\0strHostName\0"
    "diconectUser(QString&)\0showMesseg()\0"
    "showMessegTree()\0name,message\0"
    "showPopup(QString,QString)\0"
    "editPositionPopup()\0pos\0"
    "showContextMenuTreeView(QPoint)\0"
    "showSetting()\0updateInfoClient()\0"
    "visibleDataContact\0setVisibleDockWidgetData(bool)\0"
    "mCreateTray()\0reason\0"
    "mouseClickedBehaviourTrayIcon(QSystemTrayIcon::ActivationReason)\0"
    "statusMesseges,newEnteringMesseges\0"
    "setTrayIconMessege(QString,QString)\0"
    "helpQlocmessege()\0event\0"
    "closeEvent(QCloseEvent*)\0slotIconNewMessage()\0"
};

void MFormLocMes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MFormLocMes *_t = static_cast<MFormLocMes *>(_o);
        switch (_id) {
        case 0: _t->connectToServer(); break;
        case 1: _t->disconnectToServer(); break;
        case 2: _t->returnMyIp(); break;
        case 3: _t->addUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 4: _t->deleteUserFromData(); break;
        case 5: _t->diconectUser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->showMesseg(); break;
        case 7: _t->showMessegTree(); break;
        case 8: _t->showPopup((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->editPositionPopup(); break;
        case 10: _t->showContextMenuTreeView((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 11: _t->showSetting(); break;
        case 12: _t->updateInfoClient(); break;
        case 13: _t->setVisibleDockWidgetData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->mCreateTray(); break;
        case 15: _t->mouseClickedBehaviourTrayIcon((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 16: _t->setTrayIconMessege((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 17: _t->helpQlocmessege(); break;
        case 18: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 19: _t->slotIconNewMessage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MFormLocMes::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MFormLocMes::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MFormLocMes,
      qt_meta_data_MFormLocMes, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MFormLocMes::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MFormLocMes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MFormLocMes::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MFormLocMes))
        return static_cast<void*>(const_cast< MFormLocMes*>(this));
    if (!strcmp(_clname, "Ui_qlocmes"))
        return static_cast< Ui_qlocmes*>(const_cast< MFormLocMes*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MFormLocMes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
