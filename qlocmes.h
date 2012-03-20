#ifndef QLOCMES_H
#define QLOCMES_H

#include <QApplication>
#include <QtGui/QMainWindow>
#include <QtSql>
#include <QtNetwork>
#include <QSystemTrayIcon>
#include <qthread.h>
#include <qtcpserver.h>
#include <phonon/mediaobjectinterface.h>
#include <phonon/audiooutput.h>
#include "ui_qlocmes.h"
#include "MSqlTableModel.h"

class MMessage;
class MPopupMessage;
class MClient;
class MServer;
class QSqlTableModel;
class MSettings;
class QDataWidgetMapper;
class QMenu;
class QPalette;

enum{
	id = 0,
	id_status = 1,
	id_nameUser = 2,
	id_nameSurname = 3,
	id_name = 4,
	id_namePatronymic = 5,
	id_namePost = 6,
	id_ipAdress = 7
};

class MFormLocMes : public QMainWindow, public Ui_qlocmes
{
    Q_OBJECT

public:
    MFormLocMes(QWidget *parent = 0);
    ~MFormLocMes();
    void createTableContacs();
    void createTableNetFilter();

private:
    void readSettings();
    void playSounds(QString fileName);

public slots:
	void connectToServer();
	void disconnectToServer();
	void returnMyIp();

	void addUser(QString& strStatusName, QString& nameUser,
			QString&  nameSurname,QString& name, QString& namePatronymic,
			QString& namePost, QString& ipAdressPullClient);
	void deleteUserFromData();
	void diconectUser(QString& strHostName);

	void showMesseg();
	void showMessegTree();
	virtual void showPopup(QString name, QString message);
	void editPositionPopup();

	void showContextMenuTreeView(const QPoint &pos);

	void showSetting();

	void updateInfoClient();
	void setVisibleDockWidgetData(bool visibleDataContact);

	void mCreateTray();
	void mouseClickedBehaviourTrayIcon(QSystemTrayIcon::ActivationReason reason);
	void setTrayIconMessege(QString statusMesseges, QString newEnteringMesseges);

	void helpQlocmessege();

	virtual void closeEvent(QCloseEvent *event);
	void slotIconNewMessage();

private:
//настройки

	bool setVisibleDock;
	int setNumberPort;
	QString setNameUser;

    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;

    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QMenu *trayStatusMenu;
    QMenu *mPopupMenu;

//последовательность своих адресов в строке
    QString ipAdressString;

	QDataWidgetMapper *mapper;
	MSqlTableModel *tableModelContacs;
    QSqlTableModel *tableModelMyIp;
    QSqlTableModel *tableModelNetFilter;
    QSqlTableModel *tableModelSounds;

	MServer *mainServer;
	MClient *mainClient;

    MMessage *formMesseg;
    MPopupMessage *popMessage[10];

    QTimer *n;
    QTimer *timerNewMessage;
    int coutPopupMessage;

    Phonon::MediaObject soundObject;
    Phonon::AudioOutput soundOutput;
    QString playNewMessage, playSendMessage,
        		playNewUser, playCloseUser;

private:
	QString returnsIpThirdPoint(QString ipAdress);
	virtual void createNewMClient(QString& ipAdressHost,
				 	 	 	 	  int numberPortHost, QString& myIpAdress);
	void moveWindowToCenter();

};
#endif // QLOCMES_H
