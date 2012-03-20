#ifndef MSETTINGS_H
#define MSETTINGS_H
#include <QtGui/QDialog>
#include <QtSql>
#include <QDataWidgetMapper>
#include <QFileDialog>
#include <QSound>
#include <phonon/mediaobjectinterface.h>
#include <phonon/audiooutput.h>
#include <phonon/path.h>
#include <qmessagebox.h>

#include "ui_msettings.h"

class QSqlTableModel;
class QDataWidgetMapper;
class QMessageBox;

enum
{
	transport_id = 0,
	transport_name = 1,
	transport_documents_id = 2
};


class MSettings : public QDialog, public Ui_MSettingsClass
{
    Q_OBJECT

public:
    MSettings(QWidget *parent = 0);
    ~MSettings();
    void readSettings();
/*
 * возврат настроек
 */
//главные
    bool isVisibleDockWidgetData();
    QRect rectQlocMessege();
//Учетная запись
    QString nameUser();
    QString surname();
    QString name();
    QString patronymic();
    QString pos();
//Уведомления
    QString mySounds();
//сетевые настройки
    QString numberPort();
    QString adresServer();
    QString myIpAdress();
//скрытые
    int isCoutPopupMessage();
/*
 * установка настроек
 */
//главные
    void setVisibleDockWidgetData(bool tVisibleDockWidgetData);
    void setRectQlocMessege(QRect tRect);
//Учетная запись
    void setNameUser(QString tNameUser);
    void setSurname(QString tSurname);
    void setName(QString tName);
    void setPatronymic(QString tPatronymic);
    void setPos(QString tPos);
//Уведомления
    void setMySounds();
//Сеть
    void setNumberPort(QString tNumberPort);
    void setAdresServer(QString tAdresServer);
    void setMyIpAdress(QString tMyIpAdress);
//скрытые
    void setCoutPopupMessage(int tPopupMessage);

//----------таблицы настроек-------------------------------------
    void createTableMyIp();
    void createTableNetFilter();
    void createTableSounds();

public slots:
	void setSettigs();
	void saveSettings();
	void addNetFilter();
	void editNetFilter();
	void deleteNetFilter();
	void saveNetFilter();
	bool openDialogPathSounds();
	void clearSounds();
	void updateInfoSounds();
	void testSounds();
	void selectStyle(int index);
//	void setMainStyle();
private:
	QString vMyIpAdress;

    QSqlTableModel *tableModelMyIp;
    QSqlTableModel *tableModelNetFilter;
    QSqlTableModel *tableModelSounds;
    QDataWidgetMapper *mapperNetFilter;
    QDataWidgetMapper *mapperSounds;

    Phonon::MediaObject soundObject;
    Phonon::AudioOutput soundOutput;
};

#endif // MSETTINGS_H
