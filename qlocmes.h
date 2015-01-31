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
class MUdpServer;
class MUdpClient;

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
    //! \brief Конструктор по умолчанию.
    MFormLocMes(QWidget *parent = 0);

    //! \brief Деструктор по умолчанию.
    ~MFormLocMes();

    //! \brief Создать таблицу контактов.
    void createTableContacs();

    //! \brief Создать таблицу IP адресов.
    void createTableNetFilter();

private:
    //! \brief Считать настройки.
    void readSettings();

    //! \brief Воспроизвести звуковые ср=обытия.
    void playSounds(QString fileName);

public slots:
	//! \brief Рассылка сообщений о появлении в сети пользователя.
	void connectToServer();

	//! \brief Рассылка сообщения о выходе пользователя из сети.
	void disconnectToServer();

	//! \brief поиск активного IP адреса.
	void returnMyIp();

	/*!
	 * \brief Добавляет нового пользователя появившегося в сети
	 *
	 */
	void addUser(QString& strStatusName, QString& nameUser,
			QString&  nameSurname,QString& name, QString& namePatronymic,
			QString& namePost, QString& ipAdressPullClient);

	//! \brief Удаление пользователя из списка контактов.
	void deleteUserFromData();

	//! \brief Обновляет статус пользователя. Выход пользователя из сети.
	void diconectUser(QString& strHostName);

	//! \brief Отображает окно сообщений.
	void showMesseg();

	//! \brief Открытие окна сообщений при нажатии на иконку в трее.
	void showMessegTree();

	//! \brief Открытие информационных сообщений (контакт в сети, пришло сообщение).
	virtual void showPopup(QString name, QString message);

	//! \brief Изменяет положение информационных сообщений.
	void editPositionPopup();

	//! \brief Заполняет контекстное меню.
	void showContextMenuTreeView(const QPoint &pos);

	//! \brief Открывает окно настроек.
	void showSetting();

	//! \brief Обновляет информацию о выбранном клиенте в информационном поле.
	void updateInfoClient();

	// \brief Отображает или нет информационное окно.
	void setVisibleDockWidgetData(bool visibleDataContact);

	// \brief Создает элементы меню.
	void mCreateTray();

	// \brief Обработчик события нажатия на иконку в трее.
	void mouseClickedBehaviourTrayIcon(QSystemTrayIcon::ActivationReason reason);

	// \brief Отображает иконку в трее.
	void setTrayIconMessege(QString statusMesseges, QString newEnteringMesseges);

	//! \brief Открывает окно помощи.
	void helpQlocmessege();

	//! \brief Переопределение события закрытия окна на сворачивание.
	virtual void closeEvent(QCloseEvent *event);

	//! \brief Анимация прихода нового сообщения.
	void slotIconNewMessage();

private:
//настройки

	bool setVisibleDock; //!< Состояние видимости информационного поля.
	int setNumberPort; //! < Текущий порт.
	QString setNameUser; //! < Имя пользователя.

    QAction *minimizeAction; //! <
    QAction *maximizeAction; //! <
    QAction *restoreAction; //! <
    QAction *quitAction; //! <

    QSystemTrayIcon *trayIcon; //! <
    QMenu *trayIconMenu; //! <
    QMenu *trayStatusMenu; //! <
    QMenu *mPopupMenu; //! <

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

    MUdpServer *myUdpServer;
    MUdpClient *myUdpClient;
private:
    //! \brief Возвращает IP без последнего поля XXX.XXX.XXX.
	QString returnsIpThirdPoint(QString ipAdress);

	//! \brief Добавление нового подключенного клиента.
	virtual void createNewMClient(QString& ipAdressHost,
				 	 	 	 	  int numberPortHost, QString& myIpAdress);

	//! \brief Отображение окна по центру.
	void moveWindowToCenter();

};
#endif // QLOCMES_H
