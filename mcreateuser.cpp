#include "msettings.h"
#include "mcreateuser.h"

MCreateUser::MCreateUser(QWidget *parent)
    : QWidget(parent)
{
	setupUi(this);
	moveWindowToCenter();
	setWindowFlags(Qt::Tool);
	setWindowFlags(Qt::CustomizeWindowHint);
	connect(pushButtonSave, SIGNAL(clicked()), this, SLOT(closeCreateUser()));
	connect(lineEditUser, SIGNAL(textChanged(const QString &)), this, SLOT(setEnabledPuchButtonSave()));
}
//-----------------------------------------------------------------------
void MCreateUser::setEnabledPuchButtonSave()
{
	if(lineEditUser->text().length()) {
		pushButtonSave->setEnabled(TRUE);
	} else {
		pushButtonSave->setEnabled(FALSE);
	}
}
//----------------------------------------------------------------------
void MCreateUser::moveWindowToCenter()
{
    QRect frect = frameGeometry();
    frect.moveCenter(QDesktopWidget().availableGeometry().center());
    move(frect.topLeft());
}
//-----------------------------------------------------------------------
void MCreateUser::closeCreateUser()
{
	QSettings mSettings("DrHaos", "qlocmes");
	mSettings.setValue("Number Port", spinBoxNumberPort->text());
	mSettings.setValue("Name User", lineEditUser->text());
	mSettings.setValue("Surname", lineEditSurname->text());
	mSettings.setValue("Name", lineEditName->text());
	mSettings.setValue("Patronymic", lineEditPatronymic->text());
	mSettings.setValue("Pos", lineEditPost->text());
	close();
}
//-----------------------------------------------------------------------
MCreateUser::~MCreateUser()
{

}
