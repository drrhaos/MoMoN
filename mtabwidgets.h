#ifndef MTABWIDGETS_H
#define MTABWIDGETS_H

#include <QtGui/QWidget>
#include "ui_mtabwidgets.h"
#include "msettings.h"

class MClient;
class MServer;
class MSendFile;

class MTabWidgets : public QWidget, public Ui_MTabWidgetsClass
{
    Q_OBJECT

public:
    MTabWidgets(QString& userNameTemp, MServer * mainServerTemp,
    		QString ipClient, QString myIpString, QWidget *parent = 0);
    ~MTabWidgets();

public slots:
	void slotSendMesseges();
	void slotNewEntering(QString nameUserEntering, QString newEnteringMesseges);
	void enabledSendPuchButton();
	bool slotSendToFile();
	void slotSetColorText(const QString & text);
	void slotSetFontText(const QString & text);
	void slotSetBoldText(bool index);
	void slotSetItalicText(bool index);
	void slotSetUnderlineText(bool index);
	void slotClearHistory();

private:
    MSettings *mainSettings;
    QSettings *mSettings;
	MServer *mainServer;
	MClient *mainClient;
	QString userName;
	QString strHost;
};

#endif // MTABWIDGETS_H
