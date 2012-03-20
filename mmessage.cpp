#include "mserver.h"
#include "mclient.h"
#include "mmessage.h"
#include "mtabwidgets.h"

MMessage::MMessage(QWidget *parent)
    : QMainWindow(parent)
{
	setupUi(this);

	moveWindowToCenter();
    connect(tabWidget, SIGNAL(tabCloseRequested(int )), this, SLOT(deleteTabs(int)));
    connect(tabWidget, SIGNAL(currentChanged (int )), this, SLOT(slotSetCurentIndex(int )));
}
//------------------------------------------------------------------------------------------
int MMessage::returnTab()
{
	return tabWidget->count();
}
//------------------------------------------------------------------------------------------
bool MMessage::returnTabText(QString userName)
{
	for (int tab = 0; tab < tabWidget->count(); ++tab) {
		if (tabWidget->tabText(tab) == userName) {
			return TRUE;
		}
	}
	return FALSE;
}
//---------------------------------------------------------------------------------------
void MMessage::insertFirstTab(QString& userNameTemp, MServer * mainServerTemp,
		QString ipClient, QString myIpString)
{
	mainServer = mainServerTemp;
	connect(mainServer, SIGNAL(signalsNewEntering(QString , QString )),
			this, SLOT(slotNewEntering(QString , QString )));

	mainTabWidget = new MTabWidgets(userNameTemp, mainServerTemp, ipClient, myIpString);
	tabWidget->addTab(mainTabWidget, QIcon(":/tray/icon/online.png"), userNameTemp);

//извлечение из истории
	QString home = QDir::homePath() + "/.qlocmes";
  	QDir(home).mkdir(home);
  	QFile fileHistory(home + "/" + userNameTemp +".txt");
	if (!fileHistory.open(QIODevice::ReadWrite | QIODevice::Text))
		return;

  	QByteArray data = fileHistory.readAll();
	QTextCodec *codec = Qt::codecForHtml(data);
	QString str = codec->toUnicode(data);
	if (Qt::mightBeRichText(str)) {
		str = QString::fromUtf8(data);
		mainTabWidget->textEditEntering->setHtml(str);
	} else {
		str = QString::fromUtf8(data);
		mainTabWidget->textEditEntering->setPlainText(str);
	}
}
//------------------------------------------------------------------------------------------
void MMessage::deleteTabs(int index)
{	if (tabWidget->count() > 1) {
		tabWidget->removeTab(index);
	} else {
		tabWidget->removeTab(index);
		close();
	}
}
//----------------------------------------------------------------------------------------
void MMessage::slotNewEntering(QString nameUserEntering, QString newEnteringMesseges)
{
	for (int var = 0; var < tabWidget->count(); ++var) {
		if ((tabWidget->tabText(var) == nameUserEntering)&&(tabWidget->currentIndex() != var)) {
			tabWidget->setTabIcon(var, QIcon(":/tray/icon/messege.png"));
		}
	}
	QString n = newEnteringMesseges;
}
//------------------------------------------------------------------------------------------
void MMessage::slotSetCurentIndex(int index)
{
	tabWidget->setTabIcon(index ,QIcon(":/tray/icon/online.png"));
}
//----------------------------------------------------------------------
void MMessage::closeEvent(QCloseEvent *event)
{
	hide();
	tabWidget->clear();
	event->ignore();
}
//----------------------------------------------------------------------
void MMessage::moveWindowToCenter()
{
    QRect frect = frameGeometry();
    frect.moveCenter(QDesktopWidget().availableGeometry().center());
    move(frect.topLeft());
}
//------------------------------------------------------------------------------------------
MMessage::~MMessage()
{
	delete [] tabWidget;
}
