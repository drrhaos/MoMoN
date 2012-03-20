#ifndef MCREATEUSER_H
#define MCREATEUSER_H

#include <QtGui/QWidget>
#include <QDesktopWidget>
#include <QDecoration>
#include <qmessagebox.h>
#include "ui_mcreateuser.h"

class MSettings;

class MCreateUser : public QWidget, public Ui_mCreateUserClass
{
    Q_OBJECT

public:
    MCreateUser(QWidget *parent = 0);
    ~MCreateUser();
    void moveWindowToCenter();

public slots:
    void setEnabledPuchButtonSave();
    void closeCreateUser();

private:

};

#endif // MCREATEUSER_H
