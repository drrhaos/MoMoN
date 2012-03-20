#ifndef MMESSAGE_H
#define MMESSAGE_H

#include <QtGui/QMainWindow>
#include "ui_mmessage.h"
#include "msettings.h"

class MClient;
class MServer;
class QSpacerItem;
class MTabWidgets;

class MMessage : public QMainWindow, public Ui_MMessageClass
{
    Q_OBJECT
public:
    MMessage(QWidget *parent = 0);
    ~MMessage();
    int returnTab();
    bool returnTabText(QString userName);
    void insertFirstTab(QString& userNameTemp, MServer * mainServerTemp,
    		QString ipClient, QString myIpString);

public slots:
    void deleteTabs(int index);
    void slotNewEntering(QString nameUserEntering, QString newEnteringMesseges);
    void slotSetCurentIndex(int index);
    virtual void closeEvent(QCloseEvent *event);

private:
    void moveWindowToCenter();
    MTabWidgets *mainTabWidget;
	MServer *mainServer;
};


#endif // MMESSAGE_H
