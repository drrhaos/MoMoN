#include <QtGui>
#include <QtSql>
#include <QApplication>

#include "qlocmes.h"
#include "mcreateuser.h"

//---------------------------------------------------------------------------
bool createConnection(QString fileName)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(fileName);
	if (!db.open()) {
		QMessageBox::warning(0, QObject::tr("Database Error"),
				db.lastError().text());
		return false;
	}
	return true;
}

//---------------------------------------------------------------------------

void createFakeData()
{
    QProgressDialog progress;
    progress.setWindowModality(Qt::WindowModal);
    progress.setWindowTitle(QObject::trUtf8("База данных пользователей"));
    progress.setLabelText(QObject::trUtf8("Создание файла базы данных..."));
    progress.setMinimum(0);
    progress.setMaximum(6);
    progress.setValue(1);
    qApp->processEvents();

    QSqlQuery query;
    query.exec("DROP TABLE basecontacs");
    query.exec("DROP TABLE my_ip");
    query.exec("DROP TABLE range_ip");
    query.exec("DROP TABLE sounds_data");

    progress.setValue(2);
    qApp->processEvents();

    query.exec("CREATE TABLE basecontacs ("
    		"id INTEGER PRIMARY KEY AUTOINCREMENT, "
    		"status TEXT, "
    		"nameUser TEXT, "
    		"nameSurname TEXT, "
    		"name TEXT, "
    		"namePatronymic TEXT, "
    		"namePost TEXT, "
    		"ipAdress TEXT, "
    		"newMessege BOOL )");

    progress.setValue(3);
    qApp->processEvents();

    query.exec("CREATE TABLE my_ip ("
        	"id INTEGER PRIMARY KEY AUTOINCREMENT, "
        	"used BOOL, "
        	"MyIPAdress TEXT )");

    progress.setValue(4);
    qApp->processEvents();

    query.exec("CREATE TABLE range_ip ("
    		"id INTEGER PRIMARY KEY AUTOINCREMENT, "
    		"status TEXT, "
    		"FromIP TEXT, "
    		"toIP TEXT )");

    progress.setValue(5);
    qApp->processEvents();

    query.exec("CREATE TABLE sounds_data ("
        	"id INTEGER PRIMARY KEY AUTOINCREMENT, "
        	"groupSounds TEXT,"
        	"eventQlocmes TEXT, "
    		"usingEvent BOOL, "
        	"patshSounds TEXT )");


    query.exec("INSERT INTO sounds_data (groupSounds, eventQlocmes, usingEvent) "
        	"VALUES ('" + QObject::trUtf8("Сообщение") + "', '" +
        	QObject::trUtf8("Входящее") + "', '" +
        	QObject::trUtf8("false") + "')");
    query.exec("INSERT INTO sounds_data (groupSounds, eventQlocmes, usingEvent) "
        	"VALUES ('" + QObject::trUtf8("Сообщение") + "', '" +
        	QObject::trUtf8("Исходящее") + "', '" +
        	QObject::trUtf8("false") + "')");
    query.exec("INSERT INTO sounds_data (groupSounds, eventQlocmes, usingEvent) "
        	"VALUES ('" + QObject::trUtf8("Событие") + "', '" +
        	QObject::trUtf8("Контакт вошел") + "', '" +
        	QObject::trUtf8("false") + "')");
    query.exec("INSERT INTO sounds_data (groupSounds, eventQlocmes, usingEvent) "
        	"VALUES ('" + QObject::trUtf8("Событие") + "', '" +
        	QObject::trUtf8("Контакт вышел") + "', '" +
        	QObject::trUtf8("false") + "')");

    progress.setValue(progress.maximum());
    qApp->processEvents();

    MCreateUser newUser;
    newUser.show();
    while (newUser.isVisible())
    	qApp->processEvents();
}
//---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(systray);

    QApplication a(argc, argv);

//Задаю стиль приложения
    int n = 0;
    QSettings *settingsLocal = new QSettings("DrHaos", "qlocmes");
    switch ((settingsLocal->value("Style", n)).toInt()) {
    	case 1:
    		QApplication::setStyle(new QPlastiqueStyle);
    		break;
    	case 2:
    		QApplication::setStyle(new QCleanlooksStyle);
    		break;
    	case 3:
    		QApplication::setStyle(new QWindowsStyle);
    		break;
    	case 4:
    		QApplication::setStyle(new QCDEStyle);
    		break;
    	case 5:
    		QApplication::setStyle(new QCommonStyle);
    		break;
    	case 6:
//    	    QApplication::setStyle(new QGtkStyle);
    	    break;
    	default:
    		break;
    }

    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    QTextCodec::setCodecForTr(codec);

//open(create) file data base
    QString home = QDir::homePath() + "/.qlocmes";
    QDir(home).mkdir(home);
    QString fName = home + "/basecontacs.dat";

    bool existingData = QFile::exists(fName);

 	existingData = QFile::exists(fName);
 	if (!createConnection(fName))
 		return 1;
 	if (!existingData)
 		createFakeData();

//open main form

    MFormLocMes fmes;
    fmes.show();
    return a.exec();
}
