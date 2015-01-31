#include "qlocmes.h"
#include "mmessage.h"
#include "mclient.h"
#include "mserver.h"
#include "msettings.h"
#include "mpopupmessage.h"
#include "MSqlRelationalDelegate.h"
#include "mudpserver.h"
#include "mudpclient.h"


MFormLocMes::MFormLocMes(QWidget *parent)
    : QMainWindow(parent)
{
	setupUi(this);
//указатель на объект класса MSettings
	readSettings();
	dockWidgetData->setVisible(setVisibleDock);
//установка начального положения всплывающих сообщений
	coutPopupMessage = 0;
//создает модель таблицы фильтра Ip адресов
	createTableNetFilter();
//записывает текущий IP адресс в настройки
	returnMyIp();
//создает модель таблицы контактов
	createTableContacs();
//выравнивание главного окна по центру
	moveWindowToCenter();
//выделение памяти под объект класса MServer
	mainServer = new MServer(setNumberPort);
//выделение памяти под объект класса MUdpServer
	myUdpServer = new MUdpServer();
//выделение памяти под объект класса MUdpClient
	myUdpClient = new MUdpClient();

//выделение памяти под объект класса MMessage
	formMesseg = new MMessage();
//конструктор занчка в трее
    mCreateTray();

//добавление пользователя в список контактов при входящем подключении клиента
	connect(myUdpClient, SIGNAL(signalsNewUser()), this, SLOT(addUser()));
//смена иконки при входящем сообещении
    connect(mainServer, SIGNAL(signalsNewEntering(QString , QString )),
    		this, 		SLOT(setTrayIconMessege(QString , QString )));
//открытие окна сообщений при двойном нажатии на контакт
	connect(treeView, 	SIGNAL(doubleClicked(QModelIndex)), this, SLOT(showMesseg()));
//обновляет информацию о клиентах в бокоом меню
	connect(treeView->selectionModel(), SIGNAL(currentRowChanged()),
            this, 						SLOT(updateInfoClient()));
//открытие контекстного меню
    connect(treeView, SIGNAL(customContextMenuRequested()),
    		this, 	  SLOT(showContextMenuTreeView()));


/*
 * меню
 */
//изменить статус на OnLine
	connect(actionOnLine,      SIGNAL(triggered()), this, SLOT(connectToServer()));
//изменить статус на OffLine
	connect(actionOffLine,     SIGNAL(triggered()), this, SLOT(disconnectToServer()));
//открытие окна настроек
	connect(actionSettings,    SIGNAL(triggered()), this, SLOT(showSetting()));
//закрытие программы
    connect(actionQuit, 	   SIGNAL(triggered()), qApp, SLOT(quit()));
//справка
    connect(actionHelpQt, 	   SIGNAL(triggered()), this, SLOT(helpQlocmessege()));
//удаление пользователя из списка
    connect(actionDeleteUser,  SIGNAL(triggered()), this, SLOT(deleteUserFromData()));
//открытие окна сообщений из контекстного меню
    connect(actionSendMessage, SIGNAL(triggered()), this, SLOT(showMesseg()));

//при нажатии на иконку в трее окно разворачивается
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
    		this,     SLOT(mouseClickedBehaviourTrayIcon(QSystemTrayIcon::ActivationReason)));

//изменение размера при закрытии данных контакта
    connect(dockWidgetData ,SIGNAL(visibilityChanged()),
    		this, SLOT(setVisibleDockWidgetData()));

    trayIcon->setIcon(QIcon(":/tray/icon/offline.png"));
    trayIcon->show();
    setWindowTitle("MoMoN");
    n = new QTimer();
    n->start(5000);
    connect(n, SIGNAL(timeout ()), this, SLOT(connectToServer()));

    timerNewMessage = new QTimer();
    connect(timerNewMessage, SIGNAL(timeout ()), this, SLOT(slotIconNewMessage()));
}

void MFormLocMes::createTableContacs()
{
	QSqlQuery query;
	query.exec("UPDATE basecontacs SET status = 'OffLine'");
	tableModelContacs = new MSqlTableModel(this);
	tableModelContacs->setTable("basecontacs");
	tableModelContacs->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
	tableModelContacs->select();

	treeView->setModel(tableModelContacs);
	treeView->setItemDelegate(new MSqlRelationalDelegate(this));
	treeView->setSelectionMode(QAbstractItemView::SingleSelection);
	treeView->setSelectionBehavior(QAbstractItemView::SelectRows);

	treeView->setColumnHidden(0, TRUE);
	treeView->setColumnHidden(1, TRUE);
	treeView->setColumnHidden(3, TRUE);
	treeView->setColumnHidden(4, TRUE);
	treeView->setColumnHidden(5, TRUE);
	treeView->setColumnHidden(6, TRUE);
	treeView->setColumnHidden(7, TRUE);
	treeView->setColumnHidden(8, TRUE);
	treeView->setHeaderHidden(TRUE);
    treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    treeView->setContextMenuPolicy(Qt::CustomContextMenu);

	mapper = new QDataWidgetMapper(this);
	mapper->setModel(tableModelContacs);
	mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
	mapper->setItemDelegate(new QSqlRelationalDelegate(this));
	mapper->addMapping(lineEditSurname, id_nameSurname);
	mapper->addMapping(lineEditName, id_name);
	mapper->addMapping(lineEditPatronymic, id_namePatronymic);
	mapper->addMapping(lineEditPost, id_namePost);

	playNewMessage = tableModelSounds->data(tableModelSounds->index(0, 4)).toString();
	playSendMessage = tableModelSounds->data(tableModelSounds->index(1, 4)).toString();
	playNewUser = tableModelSounds->data(tableModelSounds->index(2, 4)).toString();
	playCloseUser = tableModelSounds->data(tableModelSounds->index(3, 4)).toString();
}

void MFormLocMes::createTableNetFilter()
{
	tableModelNetFilter = new QSqlTableModel(this);
	tableModelNetFilter->setTable("range_ip");
	tableModelNetFilter->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
	tableModelNetFilter->select();

	tableModelMyIp = new QSqlTableModel(this);
	tableModelMyIp->setTable("my_ip");
	tableModelMyIp->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
	tableModelMyIp->select();

	tableModelSounds = new QSqlTableModel(this);
	tableModelSounds->setTable("sounds_data");
	tableModelSounds->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
	tableModelSounds->select();
}

void MFormLocMes::readSettings()
{
	QSettings mSettings("DrHaos", "qlocmes");

	setVisibleDock = mSettings.value("Visible Dock Widget Data", true).toBool();
//главные
/*
	(mSetting.value("Style", comboBoxStyle->currentIndex())).toInt();

	(mSetting.value("Position Save", radioButtonSavePos->isChecked()).toBool();
	(mSetting.value("Position Right", radioButtonRightPos->isChecked()).toBool();
	(mSetting.value("Position Center", radioButtonCenterPos->isChecked()).toBool();

//Учетная запись
 *
 */
	setNameUser = mSettings.value("Name User", "").toString();
	/*
	(mSetting.value("Surname", lineEditSurname->text())).toString();
	(mSetting.value("Name", lineEditName->text())).toString();
	(mSetting.value("Patronymic", lineEditPatronymic->text())).toString();
	(mSetting.value("Pos", lineEditPost->text())).toString();

//уведомления

 *
	(mSetting.value("Popup Online Client", checkBoxOnLineClient->isChecked())).toBool();
	(mSetting.value("Popup Offline Client", checkBoxOffLineClient->isChecked())).toBool();
	(mSetting.value("Popup New Message Close Form", checkBoxNewMessageCloseForm->isChecked())).toBool();
	(mSetting.value("Popup New Message Open Form", checkBoxNewMessageOpenForm->isChecked())).toBool();

//сетевые настройки
 */
	setNumberPort = mSettings.value("Number Port", 1024).toInt();
/*
	(mSetting.value("Adres Server", lineEditAdresServer->text())).toString();
*/
}

void MFormLocMes::playSounds(QString fileName)
{
	if (fileName.length()) {
		soundObject.setCurrentSource(Phonon::MediaSource(fileName));
		Phonon::createPath(&soundObject,&soundOutput);
		soundObject.play();
	}
}
/*-------------public slots------------------------------------------
 * Сканирование области IP адрессов и подключение к
 * другим пользователям в сети
 */
/*void MFormLocMes::connectToServer()
{
	actionOnLine->setChecked(TRUE);
	actionOffLIne->setChecked(FALSE);
	trayIcon->setIcon(QIcon(":/tray/icon/offline.png"));

 * если в таблице фильтра Ip адресов больше 0 записей
 * разрешающих сканирование, то сканируются толлько эти
 * промежутки адрессов, иначе сканируются весь пулл
 * адресовот 0 до 255 за исключением тех адресов которые
 * запрещены фильтром
 *

	if (tableModelNetFilter->rowCount()) {
		QString firstNetAdress, endNetAdress, ipAdress, maskNetAdress;
		int pixel;
		for (int rowNetAdress = 0; rowNetAdress < tableModelNetFilter->rowCount(); ++rowNetAdress) {
			firstNetAdress = tableModelNetFilter->data(tableModelNetFilter->index(rowNetAdress, 2)).toString();
			endNetAdress = tableModelNetFilter->data(tableModelNetFilter->index(rowNetAdress, 3)).toString();

//IP адресс до последней точки для первого адреса
			maskNetAdress = firstNetAdress;
			maskNetAdress = returnsIpThirdPoint(maskNetAdress);

//IP адресс от последней точки для первого адреса
			pixel = 0;
			for (int i = 0; i < firstNetAdress.size(); ++i) {
				if (firstNetAdress.at(i) == QChar('.')){
					++pixel;
					if (pixel == 3) {
						firstNetAdress = firstNetAdress.remove(0, i+1);
					}
				}
			}
//цикл выделяет IP адресс от последней точки для последнего адреса
			pixel = 0;
			for (int i = 0; i < endNetAdress.size(); ++i) {
				if (endNetAdress.at(i) == QChar('.')){
					++pixel;
					if (pixel == 3) {
						endNetAdress = endNetAdress.remove(0, i+1);
					}
				}
			}

//цикл сканирует IP адреса
			for (int var = firstNetAdress.toInt(); var < endNetAdress.toInt(); ++var) {
				ipAdress = maskNetAdress + QString::number(var);
//нужен пинг
				createNewMClient(ipAdress, setNumberPort, ipAdressString);
				qApp->processEvents();
			}
		}

	} else
	if (tableModelMyIp->rowCount()) {
	QString ipAdress, myIp;
//Цикл выбирает из таблицы Ip адреса
		for (int row = 0; row < tableModelMyIp->rowCount(); ++row) {
//мой IP адресс до последней точки
			myIp = returnsIpThirdPoint(tableModelMyIp->data(tableModelMyIp->index(row, 2)).toString());

//цикл сканирует IP адреса
				for (int var = 0; var < 255; ++var) {
					ipAdress = myIp + QString::number(var);
//нужен пинг
					createNewMClient(ipAdress, setNumberPort, ipAdressString);
					qApp->processEvents();
					switch (var%3) {
						case 0:
							trayIcon->setIcon(QIcon(":/tray/icon/connect0.png"));
							break;
						case 1:
							trayIcon->setIcon(QIcon(":/tray/icon/connect45.png"));
							break;
						case 2:
							trayIcon->setIcon(QIcon(":/tray/icon/connect90.png"));
							break;
					}
				}
		}
		trayIcon->setIcon(QIcon(":/tray/icon/online.png"));
	}else{
		QMessageBox::about(0, QObject::trUtf8("Ошибка"), QObject::trUtf8("Нет доступной сети."));
		trayIcon->setIcon(QIcon(":/tray/icon/offline.png"));
	}

	n->stop();
}*/

void MFormLocMes::connectToServer()
{
	n->stop();
    QSettings mSettings("DrHaos", "qlocmes");

    myUdpServer->sendData(QObject::trUtf8("CS_CONNECT"), QObject::trUtf8("OnLine"),
    			mSettings.value("Name User", "").toString(), mSettings.value("Surname", "").toString(),
    			mSettings.value("Name", "").toString(),	mSettings.value("Patronymic", "").toString(),
    			mSettings.value("Pos", "").toString(), ipAdressString);
    actionOffLine->setChecked(FALSE);
    actionOnLine->setChecked(TRUE);
	trayIcon->setIcon(QIcon(":/tray/icon/online.png"));
}

void MFormLocMes::disconnectToServer()
{
//ЛАЖА
	actionOnLine->setChecked(FALSE);
	actionOffLine->setChecked(TRUE);
	trayIcon->setIcon(QIcon(":/tray/icon/offline.png"));
}

void MFormLocMes::returnMyIp()
{
//удаляет свои Ip адреса
	QSqlQuery query;
	QSettings mSettings("DrHaos", "qlocmes");
	query.exec("DELETE FROM my_ip");
//определяет свои Ip адреса и заносит их в базу данных
	QList<QNetworkInterface> myNetworkInterface = QNetworkInterface::allInterfaces();

	for (int n = 0; n < myNetworkInterface.count(); ++n) {
		if (myNetworkInterface.at(n).flags().testFlag(QNetworkInterface::IsUp)
			&& !myNetworkInterface.at(n).flags().testFlag(QNetworkInterface::IsLoopBack))
		{
			QList<QNetworkAddressEntry> myIpAddresses = myNetworkInterface.at(n).addressEntries();
			for (int m = 0; m < myIpAddresses.count(); ++m) {
				if (myIpAddresses.at(m).netmask().toIPv4Address()) {
					tableModelMyIp->setFilter("my_ip.MyIPAdress LIKE '"+myIpAddresses.at(m).ip().toString()+"'");
					tableModelMyIp->select();
					if (!tableModelMyIp->rowCount()) {
						int row = tableModelMyIp->rowCount();
						tableModelMyIp->insertRow(row);
						tableModelMyIp->setData(tableModelMyIp->index(row, 1), TRUE);
						tableModelMyIp->setData(tableModelMyIp->index(row, 2),
									myIpAddresses.at(m).ip().toString());
						tableModelMyIp->submitAll();

						mSettings.setValue("My IP Adress", myIpAddresses.at(m).ip().toString());

						tableModelMyIp->setFilter("");
						tableModelMyIp->select();
					}
				}
			}
		}
	}


//созданиие последовательности своих Ip адресов
	ipAdressString = "";
	for (int row = 0; row < tableModelMyIp->rowCount(); ++row) {
		if (ipAdressString == 0) {
			ipAdressString = tableModelMyIp->data(tableModelMyIp->index(row, 2)).toString()+ ":";
		} else {
			ipAdressString = ipAdressString +tableModelMyIp->data(tableModelMyIp->index(row, 2)).toString()+ ":";
		}
	}

}

void MFormLocMes::addUser(QString& strStatusName, QString& nameUser,
		QString&  nameSurname,QString& name, QString& namePatronymic,
		QString& namePost, QString& ipAdressPullClient)
{
	QString myIp, ipAdressPullClientTemp, ipAdressClient, ipAdressClientRemain;
//выделение из постпувших ip того который находится в той же сети что и пользователь
	for (int rowIpAdress = 0; rowIpAdress < tableModelMyIp->rowCount(); ++rowIpAdress) {
		myIp = tableModelMyIp->data(tableModelMyIp->index(rowIpAdress, 2)).toString();

//цикл выделяет IP адресс до последней точки
		myIp = returnsIpThirdPoint(myIp);

//цикл выделяет IP адреса клиента и сверяет их со своим IP
		int kk = -1;
		for (int k = 0; k < ipAdressPullClient.size(); ++k) {
			ipAdressPullClientTemp = ipAdressPullClient;
			if ((ipAdressPullClient.at(k) == QChar(':'))){
					ipAdressClient = ipAdressPullClientTemp.remove(k, ipAdressPullClient.size()).remove(0, kk+1);
					kk = k;
					ipAdressClientRemain = ipAdressClient;

//цикл выделяет IP клиента адресс до последней точки
					ipAdressClientRemain = returnsIpThirdPoint(ipAdressClientRemain);
//если первые части IP равны то записываются данные
					if (myIp == ipAdressClientRemain) {

//фильтрует список контактов по имени пользователя
						tableModelContacs->setFilter("basecontacs.nameUser LIKE '"+nameUser+"'");
						tableModelContacs->select();
/*
 * если такой пользователь уже существует то обновляем
 * значение его Ip адреса если нет то создается новая
 * запись в таблице с пользователями и записывается
 * информация о них в базу
 */
						int row = tableModelContacs->rowCount();
						if ((tableModelContacs->rowCount() == 1)&&
								(tableModelContacs->data(tableModelContacs->index(row-1, 1)).toString() == "OffLine")) {
							setTrayIconMessege(nameUser, QObject::trUtf8("В сети"));

							tableModelContacs->setData(tableModelContacs->index(row-1, 1), strStatusName);
							tableModelContacs->setData(tableModelContacs->index(row-1, 2), nameUser);
							tableModelContacs->setData(tableModelContacs->index(row-1, 3), nameSurname);
							tableModelContacs->setData(tableModelContacs->index(row-1, 4), name);
							tableModelContacs->setData(tableModelContacs->index(row-1, 5), namePatronymic);
							tableModelContacs->setData(tableModelContacs->index(row-1, 6), namePost);
							tableModelContacs->setData(tableModelContacs->index(row-1, 7), ipAdressClient);
							tableModelContacs->submitAll();
							tableModelContacs->select();
							createNewMClient(ipAdressClient, setNumberPort, ipAdressString);
						}else if ((tableModelContacs->rowCount() == 1)&&
								(tableModelContacs->data(tableModelContacs->index(row-1, 1)).toString() == "OnLine")) {

						} else if (tableModelContacs->rowCount() == 0)
						{
//							if (nameUser != tempSettings->nameUser()) {

								setTrayIconMessege(nameUser, QObject::trUtf8("Добавлен в список!"));
								tableModelContacs->insertRow(row);
								tableModelContacs->setData(tableModelContacs->index(row, 1), strStatusName);
								tableModelContacs->setData(tableModelContacs->index(row, 2), nameUser);
								tableModelContacs->setData(tableModelContacs->index(row, 3), nameSurname);
								tableModelContacs->setData(tableModelContacs->index(row, 4), name);
								tableModelContacs->setData(tableModelContacs->index(row, 5), namePatronymic);
								tableModelContacs->setData(tableModelContacs->index(row, 6), namePost);
								tableModelContacs->setData(tableModelContacs->index(row, 7), ipAdressClient);
								tableModelContacs->submitAll();
//ответный запрос на подключение к серверу
								createNewMClient(ipAdressClient, setNumberPort, ipAdressString);
								}
//							}
						}

//сброс фильтра контактов
						tableModelContacs->setFilter("");
						tableModelContacs->select();
			}
		}

	}
}

void MFormLocMes::deleteUserFromData()
{
    QModelIndex index = treeView->currentIndex();
    if (!index.isValid())
        return;
    tableModelContacs->removeRow(index.row());
    tableModelContacs->submitAll();
    tableModelContacs->select();
}

void MFormLocMes::diconectUser(QString& strHostName)
{
	QSqlQuery query;
	query.exec("UPDATE basecontacs SET status = 'OffLine' WHERE ipAdress = '" + strHostName +"'");
	tableModelContacs->submitAll();
	tableModelContacs->select();
}

void MFormLocMes::showMesseg()
{
	QModelIndex index = treeView->currentIndex();
	if (!index.isValid())
		return;
	if (index.column() == 1) {
		index = tableModelContacs->index(index.row(), 2);
	}
	QString user = (tableModelContacs->data(index)).toString();
    QModelIndex ind = tableModelContacs->index(index.row(), id_ipAdress);

//если окно сообщений закрыто то открывается новое окно
	if (!formMesseg->isVisible()) {
		formMesseg->show();
	}

	if (formMesseg->returnTab()) {
    	if (!formMesseg->returnTabText(user)) {
    		formMesseg->insertFirstTab(user, mainServer, (tableModelContacs->data(ind)).toString(), ipAdressString);
    		trayIcon->setIcon(QIcon(":/tray/icon/online.png"));
		}
	} else {
		formMesseg->show();
		formMesseg->insertFirstTab(user, mainServer, (tableModelContacs->data(ind)).toString(), ipAdressString);
		trayIcon->setIcon(QIcon(":/tray/icon/online.png"));
	}
	QSqlQuery query;
	query.exec("UPDATE basecontacs SET newMessege = 'FALSE' WHERE nameUser = '" + user +"'");
	timerNewMessage->stop();
	tableModelContacs->submitAll();
	tableModelContacs->select();
}

void MFormLocMes::showMessegTree()
{
	QSqlQuery query;
	query.exec("SELECT nameUser, ipAdress FROM basecontacs WHERE newMessege = 'TRUE'");

	if (!formMesseg->isVisible()) {
		formMesseg = new MMessage();
	}
    while (query.next()) {
    	QString user = query.value(0).toString();

    	QString ipAdresClient = query.value(1).toString();

		if (formMesseg->returnTab()) {
    		if (!formMesseg->returnTabText(user)) {
    			formMesseg->insertFirstTab(user, mainServer, ipAdresClient, ipAdressString);
			}
		} else {
			formMesseg->show();
			formMesseg->insertFirstTab(user, mainServer, ipAdresClient, ipAdressString);
		}
		query.exec("UPDATE basecontacs SET newMessege = 'FALSE' WHERE nameUser = '" + user +"'");
    }

	timerNewMessage->stop();
	tableModelContacs->submitAll();
	tableModelContacs->select();
}

/*virtual*/ void MFormLocMes::showPopup(QString name, QString message)
{
	if (coutPopupMessage < 10) {
		popMessage[coutPopupMessage] = new MPopupMessage;
		popMessage[coutPopupMessage]->setPosition(coutPopupMessage);
		popMessage[coutPopupMessage]->setTextPopupMessage(name, message);
		popMessage[coutPopupMessage]->show();
		connect(popMessage[coutPopupMessage], SIGNAL(closePop()), this, SLOT(editPositionPopup()));
		++coutPopupMessage;
	}
}

void MFormLocMes::editPositionPopup()
{
	for (int i = 1; i < coutPopupMessage; ++i) {
		popMessage[i]->editPosition(i);
		popMessage[i-1] = popMessage[i];
	}
	popMessage[coutPopupMessage-1] = NULL;
	--coutPopupMessage;
}

void MFormLocMes::showContextMenuTreeView(const QPoint &pos)
{
    QMenu menu(this);
    menu.addAction(actionSendMessage);
    menu.addAction(actionSendFile);
    menu.addAction(actionDeleteUser);
    menu.exec(treeView->viewport()->mapToGlobal(pos));

}

void MFormLocMes::showSetting()
{
	MSettings n;
	n.exec();
	tableModelSounds->select();
	tableModelNetFilter->select();
}

void MFormLocMes::updateInfoClient()
{
    QModelIndex index = treeView->currentIndex();
    if (!index.isValid())
        return;
	mapper->setCurrentIndex(index.row());
}
//----------------------------------------------------------------------
void MFormLocMes::setVisibleDockWidgetData(bool visibleDataContact)
{
	QSettings mSettings("DrHaos", "qlocmes");
	mSettings.setValue("Visible Dock Widget Data" ,visibleDataContact);
}

void MFormLocMes::mCreateTray()
{
    trayIconMenu = new QMenu(this);
    trayStatusMenu = new QMenu(QObject::trUtf8("Статус"));
    trayStatusMenu->setIcon(QIcon(":/tray/icon/online.png"));

    trayStatusMenu->addAction(actionOnLine);
    trayStatusMenu->addAction(actionOffLine);

    trayIconMenu->addMenu(trayStatusMenu);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(actionQuit);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
}

void MFormLocMes::mouseClickedBehaviourTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
//при клике по иконке в трее проверяет если это конверт то открывает
//окно сообщений иначе открывает главное окно
	if (trayIcon->icon().pixmap(10, 10, QIcon::Normal, QIcon::Off).toImage() ==
			QIcon(":/tray/icon/messege.png").pixmap(10, 10, QIcon::Normal, QIcon::Off).toImage()) {
		trayIcon->setIcon(QIcon(":/tray/icon/online.png"));
		showMessegTree();
	} else {
		if (reason == QSystemTrayIcon::Trigger) {
			if (MFormLocMes::isVisible()) {
				hide();
			}else{
				showNormal();
			}
		}
	}
}

void MFormLocMes::setTrayIconMessege(QString statusMesseges, QString newEnteringMesseges)
{
	QSettings mSettings("DrHaos", "qlocmes");
	if ((newEnteringMesseges == QObject::trUtf8("В сети"))||
			(newEnteringMesseges == QObject::trUtf8("Добавлен в список!"))) {
		if (mSettings.value("Popup Online Client", TRUE).toBool()) {
			showPopup(statusMesseges,
					  newEnteringMesseges);
		}
		playSounds(playNewUser);
	}else if (!formMesseg->isVisible()) {
		if (mSettings.value("Popup New Message Close Form", TRUE).toBool()) {
			showPopup(statusMesseges, newEnteringMesseges);
		}
		QSqlQuery query;
		query.exec("UPDATE basecontacs SET newMessege = 'TRUE' WHERE nameUser = '" + statusMesseges +"'");
		tableModelContacs->submitAll();
		tableModelContacs->select();
	    playSounds(playNewMessage);
		timerNewMessage->start(1000);
	} else if (formMesseg->isVisible()) {
		QApplication::alert(formMesseg, 0);
		if (mSettings.value("Popup New Message Open Form", TRUE).toBool()) {
			showPopup(statusMesseges, newEnteringMesseges);
		}
	    playSounds(playNewMessage);
	} else {


	}
}

void MFormLocMes::helpQlocmessege()
{
	QMessageBox::aboutQt(0);
}

/*virtual*/void MFormLocMes::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible()) {
        hide();
        event->ignore();
    }
}

void MFormLocMes::slotIconNewMessage()
{
	trayIcon->setIcon(QIcon(":/tray/icon/messege1.png"));
	QTime time;
	time.start();
	for(;time.elapsed() < 500;)
	{
		qApp->processEvents();
	}
	trayIcon->setIcon(QIcon(":/tray/icon/messege2.png"));
	time.start();
	for(;time.elapsed() < 500;)
	{
		qApp->processEvents();
	}
	trayIcon->setIcon(QIcon(":/tray/icon/messege.png"));
	time.start();
	for(;time.elapsed() < 500;)
	{
		qApp->processEvents();
	}
	trayIcon->setIcon(QIcon(":/tray/icon/messege3.png"));
	time.start();
	for(;time.elapsed() < 500;)
	{
		qApp->processEvents();
	}
	trayIcon->setIcon(QIcon(":/tray/icon/messege4.png"));
	time.start();
	for(;time.elapsed() < 500;)
	{
		qApp->processEvents();
	}
	trayIcon->setIcon(QIcon(":/tray/icon/online.png"));
}

QString MFormLocMes::returnsIpThirdPoint(QString ipAdress)
{
	int pixel = 0;
	for (int i = 0; i < ipAdress.size(); ++i) {
		if (ipAdress.at(i) == QChar('.')){
			++pixel;
			if (pixel == 3) {
				ipAdress = ipAdress.remove(i, ipAdress.size()) + ".";
			}
		}
	}
	return ipAdress;
}

/*virtual*/void MFormLocMes::createNewMClient(QString& ipAdressHost,
		int numberPortHost, QString& myIpAdress)
{
	mainClient = new MClient(this);
	mainClient->slotConnectToHost(ipAdressHost, numberPortHost, myIpAdress);
	connect(mainClient, SIGNAL(signalsDisConnected(QString& )), this, SLOT(diconectUser(QString& )));
}

void MFormLocMes::moveWindowToCenter()
{
	QSettings mSetting("DrHaos", "qlocmes");
	QRect temp = mSetting.value("Rect QlocMessege", temp).toRect();
    bool position = FALSE;
	if (mSetting.value("Position Save", position).toBool()) {
		setGeometry(temp);
	} else if (mSetting.value("Position Right", position).toBool()) {
		setGeometry(QDesktopWidget().availableGeometry().width() - temp.width(),
					30, temp.width(), QDesktopWidget().availableGeometry(-1).height() - 40);
	} else {
		QRect frect = frameGeometry();
		frect.moveCenter(QDesktopWidget().availableGeometry().center());
		move(frect.topLeft());
	}
}

MFormLocMes::~MFormLocMes()
{
	QSettings mSettings("DrHaos", "qlocmes");
	mSettings.setValue("Rect QlocMessege", geometry());
}
