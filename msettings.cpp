#include "msettings.h"



MSettings::MSettings(QWidget *parent)
    : QDialog(parent)
{
	setupUi(this);

	readSettings();
	createTableMyIp();
	createTableNetFilter();
	createTableSounds();

	connect(pushButtonApply, SIGNAL(clicked()), this, SLOT(setSettigs()));
	connect(pushButtonSave, SIGNAL(clicked()), this, SLOT(saveSettings()));
	connect(pushButtonAddAdress, SIGNAL(clicked()), this, SLOT(addNetFilter()));
	connect(pushButtonEditAress, SIGNAL(clicked()), this, SLOT(editNetFilter()));
	connect(pushButtonDelAdress, SIGNAL(clicked()), this, SLOT(deleteNetFilter()));
	connect(pushButtonSaveAress, SIGNAL(clicked()), this, SLOT(saveNetFilter()));
	connect(pushButtonPath, SIGNAL(clicked()), this, SLOT(openDialogPathSounds()));
	connect(pushButtonClearSounds, SIGNAL(clicked()), this, SLOT(clearSounds()));
//обновляет информацию о клиентах в бокоом меню
	connect(treeViewSounds->selectionModel(), SIGNAL(currentRowChanged(const QModelIndex &,
	           const QModelIndex &)), this, SLOT(updateInfoSounds()));
	connect(pushButtonPlay, SIGNAL(clicked()), this, SLOT(testSounds()));
	connect(comboBoxStyle, SIGNAL(currentIndexChanged(int)), this, SLOT(selectStyle(int)));
}
//--------------------------------------------------------------------------
void MSettings::setSettigs()
{
	QSettings mSetting("DrHaos", "qlocmes");
//главные
	mSetting.setValue("Style", comboBoxStyle->currentIndex());

	mSetting.setValue("Position Save", radioButtonSavePos->isChecked());
	mSetting.setValue("Position Right", radioButtonRightPos->isChecked());
	mSetting.setValue("Position Center", radioButtonCenterPos->isChecked());

//учетная запись
	mSetting.setValue("Name User", lineEditUser->text());
	mSetting.setValue("Surname", lineEditSurname->text());
	mSetting.setValue("Name", lineEditName->text());
	mSetting.setValue("Patronymic", lineEditPatronymic->text());
	mSetting.setValue("Pos", lineEditPost->text());

//уведомления
	mSetting.setValue("Popup Online Client", checkBoxOnLineClient->isChecked());
	mSetting.setValue("Popup Offline Client", checkBoxOffLineClient->isChecked());
	mSetting.setValue("Popup New Message Close Form", checkBoxNewMessageCloseForm->isChecked());
	mSetting.setValue("Popup New Message Open Form", checkBoxNewMessageOpenForm->isChecked());

//сетевые настройки
	mSetting.setValue("Number Port", spinBoxNumberPort->value());
	mSetting.setValue("Adres Server", lineEditAdresServer->text());
}
//--------------------------------------------------------------------------
void MSettings::readSettings()
{
	QSettings mSetting("DrHaos", "qlocmes");
//главные
	comboBoxStyle->setCurrentIndex((mSetting.value
				("Style", comboBoxStyle->currentIndex())).toInt());

	radioButtonSavePos->setChecked(mSetting.value("Position Save", radioButtonSavePos->isChecked()).toBool());
	radioButtonRightPos->setChecked(mSetting.value("Position Right", radioButtonRightPos->isChecked()).toBool());
	radioButtonCenterPos->setChecked(mSetting.value("Position Center", radioButtonCenterPos->isChecked()).toBool());

//Учетная запись
	lineEditUser->setText((mSetting.value("Name User", lineEditUser->text())).toString());
	lineEditSurname->setText((mSetting.value("Surname", lineEditSurname->text())).toString());
	lineEditName->setText((mSetting.value("Name", lineEditName->text())).toString());
	lineEditPatronymic->setText((mSetting.value("Patronymic", lineEditPatronymic->text())).toString());
	lineEditPost->setText((mSetting.value("Pos", lineEditPost->text())).toString());

//уведомления
	checkBoxOnLineClient->setChecked(
			(mSetting.value("Popup Online Client", checkBoxOnLineClient->isChecked())).toBool());
	checkBoxOffLineClient->setChecked(
			(mSetting.value("Popup Offline Client", checkBoxOffLineClient->isChecked())).toBool());
	checkBoxNewMessageCloseForm->setChecked(
			(mSetting.value("Popup New Message Close Form", checkBoxNewMessageCloseForm->isChecked())).toBool());
	checkBoxNewMessageOpenForm->setChecked(
			(mSetting.value("Popup New Message Open Form", checkBoxNewMessageOpenForm->isChecked())).toBool());

//сетевые настройки
	spinBoxNumberPort->setValue((mSetting.value("Number Port", spinBoxNumberPort->value())).toInt());
	lineEditAdresServer->setText((mSetting.value("Adres Server", lineEditAdresServer->text())).toString());
}


/*
 * возврат настроек
 */
//главные------------------------------------------------------------------
QRect MSettings::rectQlocMessege()
{
	QSettings mSetting("DrHaos", "qlocmes");
	QRect temp = mSetting.value("Rect QlocMessege", temp).toRect();
	return temp;
}
//сетевые настройки---------------------------------------------------------
QString MSettings::myIpAdress()
{
	return vMyIpAdress;
}
//--------------------------------------------------------------------------
int MSettings::isCoutPopupMessage()
{
	QSettings mSetting("DrHaos", "qlocmes");
	int n = 0;
	return mSetting.value("Cout Popup Message", n).toInt();
}
//--------------------------------------------------------------------------

/*
 * установка настроек
 */

//главные
void MSettings::setRectQlocMessege(QRect tRect)
{
	QSettings mSetting("DrHaos", "qlocmes");
	mSetting.setValue("Rect QlocMessege", tRect);
}
//уведомления---------------------------------------------------------------
void MSettings::setMySounds()
{

}
//сетевые настройки---------------------------------------------------------
void MSettings::setMyIpAdress(QString tMyIpAdress)
{
	QSettings mSetting("DrHaos", "qlocmes");
	mSetting.setValue("My IP Adress", tMyIpAdress);

	vMyIpAdress = tMyIpAdress;
}
//--------------------------------------------------------------------------
void MSettings::setCoutPopupMessage(int tPopupMessage)
{
	QSettings mSetting("DrHaos", "qlocmes");
	mSetting.setValue("Cout Popup Message", tPopupMessage);
}


//--------------------------------------------------------------------------
void MSettings::saveSettings()
{
	setSettigs();
	close();
}
//--------------------------------------------------------------------------
void MSettings::createTableMyIp()
{
	tableModelMyIp = new QSqlTableModel(this);
	tableModelMyIp->setTable("my_ip");
	tableModelMyIp->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
	tableModelMyIp->setHeaderData(1,
								Qt::Horizontal, QObject::trUtf8("Задействовать"));
	tableModelMyIp->setHeaderData(2,
								Qt::Horizontal, QObject::trUtf8("IP"));

	tableModelMyIp->select();

	tableViewMyIp->setModel(tableModelMyIp);
	tableViewMyIp->setSelectionMode(QAbstractItemView::SingleSelection);
	tableViewMyIp->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableViewMyIp->horizontalHeader()->setStretchLastSection(TRUE);
	tableViewMyIp->setColumnHidden(0, TRUE);
	tableViewMyIp->resizeColumnsToContents();
    tableViewMyIp->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
//--------------------------------------------------------------------------
void MSettings::createTableNetFilter()
{
	tableModelNetFilter = new QSqlTableModel(this);
	tableModelNetFilter->setTable("range_ip");
	tableModelNetFilter->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
	tableModelNetFilter->setHeaderData(1,
								Qt::Horizontal, QObject::trUtf8("Разрешить"));
	tableModelNetFilter->setHeaderData(2,
								Qt::Horizontal, QObject::trUtf8("От IP"));
	tableModelNetFilter->setHeaderData(3,
									Qt::Horizontal, QObject::trUtf8("До IP"));
	tableModelNetFilter->select();

	tableViewNetFilter->setModel(tableModelNetFilter);
	tableViewNetFilter->setSelectionMode(QAbstractItemView::SingleSelection);
	tableViewNetFilter->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableViewNetFilter->horizontalHeader()->setStretchLastSection(TRUE);
	tableViewNetFilter->setColumnHidden(0, TRUE);
	tableViewNetFilter->resizeColumnsToContents();
    tableViewNetFilter->setEditTriggers(QAbstractItemView::NoEditTriggers);


	mapperNetFilter = new QDataWidgetMapper(this);
	mapperNetFilter->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
	mapperNetFilter->setModel(tableModelNetFilter);
	mapperNetFilter->addMapping(comboBoxNetFilter, 1, "currentText");
	mapperNetFilter->addMapping(lineEditIpFrom, 2);
	mapperNetFilter->addMapping(lineEditIpTo, 3);
}
//--------------------------------------------------------------------------
void MSettings::createTableSounds()
{
	tableModelSounds = new QSqlTableModel(this);
	tableModelSounds->setTable("sounds_data");
	tableModelSounds->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
	tableModelSounds->setHeaderData(1,
								Qt::Horizontal, QObject::trUtf8("Это"));
	tableModelSounds->setHeaderData(2,
								Qt::Horizontal, QObject::trUtf8("Событие"));
	tableModelSounds->select();

	treeViewSounds->setModel(tableModelSounds);
	treeViewSounds->setEditTriggers(QAbstractItemView::NoEditTriggers);
	treeViewSounds->hideColumn(0);
	treeViewSounds->hideColumn(1);
	treeViewSounds->hideColumn(3);
	treeViewSounds->hideColumn(4);
//	treeViewSounds->expandAll();

	mapperSounds = new QDataWidgetMapper(this);
	mapperSounds->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
	mapperSounds->setModel(tableModelSounds);
	mapperSounds->addMapping(lineEditEvent, 2);
	mapperSounds->addMapping(lineEditPathSounds, 4);
}
//--------------------------------------------------------------------------
void MSettings::addNetFilter()
{
	int row = tableModelNetFilter->rowCount();
	tableModelNetFilter->insertRow(row);
	mapperNetFilter->setCurrentIndex(row);

	pushButtonAddAdress->setEnabled(FALSE);
	pushButtonEditAress->setEnabled(FALSE);
	pushButtonDelAdress->setEnabled(FALSE);
	pushButtonSaveAress->setEnabled(TRUE);
	comboBoxNetFilter->setEnabled(TRUE);
	lineEditIpFrom->setEnabled(TRUE);
	lineEditIpTo->setEnabled(TRUE);
}
//--------------------------------------------------------------------------
void MSettings::editNetFilter()
{
    QModelIndex index = tableViewNetFilter->currentIndex();
    if (!index.isValid())
        return;
	mapperNetFilter->setCurrentIndex(index.row());

	pushButtonAddAdress->setEnabled(FALSE);
	pushButtonEditAress->setEnabled(FALSE);
	pushButtonDelAdress->setEnabled(FALSE);
	pushButtonSaveAress->setEnabled(TRUE);
	comboBoxNetFilter->setEnabled(TRUE);
	lineEditIpFrom->setEnabled(TRUE);
	lineEditIpTo->setEnabled(TRUE);
}
//--------------------------------------------------------------------------
void MSettings::deleteNetFilter()
{
    QModelIndex index = tableViewNetFilter->currentIndex();
    if (!index.isValid())
        return;

    tableModelNetFilter->removeRow(index.row());
    tableModelNetFilter->submitAll();
    tableViewNetFilter->setCurrentIndex(tableModelNetFilter->index(tableModelNetFilter->rowCount()-1, 0));
}
//--------------------------------------------------------------------------
void MSettings::saveNetFilter()
{
	mapperNetFilter->submit();

	pushButtonAddAdress->setEnabled(TRUE);
	pushButtonEditAress->setEnabled(TRUE);
	pushButtonDelAdress->setEnabled(TRUE);
	pushButtonSaveAress->setEnabled(FALSE);
	comboBoxNetFilter->setEnabled(FALSE);
	lineEditIpFrom->setEnabled(FALSE);
	lineEditIpTo->setEnabled(FALSE);
}
//--------------------------------------------------------------------------
bool MSettings::openDialogPathSounds()
{
	QString fileName = QFileDialog::getOpenFileName(this,
			QObject::trUtf8("Выбор звука"), "",
			QObject::trUtf8("Мелодия (*.wav)"));
	if (fileName.isEmpty()) {
		return false;
	}

    QModelIndex index = tableModelSounds->index((treeViewSounds->currentIndex()).row(),
    		(treeViewSounds->currentIndex()).column() + 2);
    tableModelSounds->setData(index, fileName);
    updateInfoSounds();
	tableModelSounds->submitAll();
	mapperSounds->setCurrentIndex(index.row());
	return true;
}
//------------------------------------------------------------------------
void MSettings::clearSounds()
{
	QModelIndex index = tableModelSounds->index((treeViewSounds->currentIndex()).row(),
										(treeViewSounds->currentIndex()).column() + 2);
	tableModelSounds->setData(index, "");
	updateInfoSounds();
	tableModelSounds->submitAll();

	mapperSounds->setCurrentIndex(index.row());
}
//------------------------------------------------------------------------
void MSettings::updateInfoSounds()
{
    QModelIndex index = treeViewSounds->currentIndex();
    if (!index.isValid())
        return;
	mapperSounds->setCurrentIndex(index.row());
}
//-------------------------------------------------------------------------
void MSettings::testSounds()
{
    soundObject.setCurrentSource(Phonon::MediaSource(lineEditPathSounds->text()));
    Phonon::createPath(&soundObject,&soundOutput);
    soundObject.play();
}
//--------------------------------------------------------------------------
void MSettings::selectStyle(int index)
{
	qApp->setStyle(comboBoxStyle->itemText(index));
}
//---------------------------------------------------------------------------
MSettings::~MSettings()
{

}
