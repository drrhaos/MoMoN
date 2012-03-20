/*
 * mclient.cpp
 *
 *  Created on: 09.01.2011
 *      Author: drhaos
 */
#include "mclient.h"
#include "msettings.h"


//----------------------------------------------------------------------------------
MClient::MClient(QObject * parent)
	:QObject(parent), nextBlockSize(0)
{

}
//----------------------------------------------------------------------------------
void MClient::slotConnectToHost(const QString& strHost, int nPort, const QString& ipString)
{
	sHost = strHost;
	ipAdress = ipString;

	mTcpSocket = new QTcpSocket(this);
	mTcpSocket->connectToHost(strHost, nPort);

	connect(mTcpSocket, SIGNAL(connected()), this, SLOT(slotConnected()));
	connect(mTcpSocket, SIGNAL(readyRead()), this,  SLOT(slotReadyRead()));

    connect(mTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this,       SLOT(slotError(QAbstractSocket::SocketError)));
}
//--------------------------------------------------------------------------------------
void MClient::slotConnected()
{
//подключение к серверу
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    QSettings mSettings("DrHaos", "qlocmes");

    out.setVersion(QDataStream::Qt_4_7);
    out << quint16(0) << QTime::currentTime() << QObject::trUtf8("OnLine")
    		<< mSettings.value("Name User", "").toString()
    		<< mSettings.value("Surname", "").toString()
    		<< mSettings.value("Name", "").toString()
    		<< mSettings.value("Patronymic", "").toString()
    		<< mSettings.value("Pos", "").toString()
    		<< ipAdress;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    mTcpSocket->write(arrBlock);


//запись в log файл
    QString home = QDir::homePath() + "/.qlocmes";
  	QDir(home).mkdir(home);

	QFile fileLog(home +"/client.log");
	if (!fileLog.open(QIODevice::Append | QIODevice::Text))
		return;

	fileLog.write("Received the connected() signal\n");
	fileLog.close();
}
//----------------------------------------------------------------------------------
void MClient::slotReadyRead()
{
    QDataStream in(mTcpSocket);
    in.setVersion(QDataStream::Qt_4_7);
    forever
    {
        if (!nextBlockSize) {
            if (mTcpSocket->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> nextBlockSize;
        }

        if (mTcpSocket->bytesAvailable() < nextBlockSize) {
            break;
        }

        QTime   time;
        QString str;
        in >> time >> str;


//запись в log файл
        QString home = QDir::homePath() + "/.qlocmes";
      	QDir(home).mkdir(home);

    	QFile fileLog(home +"/client.log");
    	if (!fileLog.open(QIODevice::Append | QIODevice::Text))
    		return;
    	fileLog.write((time.toString() + " " + str + "\n").toAscii());
    	fileLog.close();

        nextBlockSize = 0;
    }
}
// ----------------------------------------------------------------------
void MClient::slotError(QAbstractSocket::SocketError err)
{
     QString strError =
        "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                     "The host was not found.":
                     err == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed.":
                     err == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused." :
                     QString(mTcpSocket->errorString()));
    QString home = QDir::homePath() + "/.qlocmes";
  	QDir(home).mkdir(home);

	QFile fileLog(home +"/client.log");
	if (!fileLog.open(QIODevice::Append | QIODevice::Text))
		return;
	fileLog.write((strError + " " + sHost + "\n").toAscii());
	fileLog.close();

//в случае отключения от сервера посылается сигнал об скрытии контакта
	if (err == QAbstractSocket::RemoteHostClosedError)
		emit signalsDisConnected(sHost);

//вывод ошибок подключения
//	if ((err == QAbstractSocket::SocketTimeoutError)||(err == QAbstractSocket::ConnectionRefusedError)) {
//		QMessageBox::about(0, "Error", strError + "\n" + sHost);
//	}
}
//-----------------------------------------------------------------------------------
void MClient::slotSendToMessage(QString statusName, QString nameUser, QString sendMesseges)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_7);
    out << quint16(0) << QTime::currentTime() << statusName << nameUser << sendMesseges;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    mTcpSocket->write(arrBlock);
}
//-----------------------------------------------------------------------------------
void MClient::slotSendToFile(QString filePatch, QString nameUser)
{
	QByteArray  arrBlock;
	QDataStream out(&arrBlock, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_7);

	sendFile = new QFile(filePatch);
	sendFile->open(QFile::ReadOnly);
	QFileInfo fi(filePatch);
	QString fileName = fi.fileName();


	QByteArray buffer = sendFile->readAll();

	out << quint16(0) << QTime::currentTime() << QString("file") << nameUser
			<< fileName << buffer;

	out.device()->seek(0);
	out << quint16(arrBlock.size() - sizeof(quint16));

	QMessageBox::about(0, "Message", "Client = " + QString::number(buffer.size()));

    mTcpSocket->write(arrBlock);
}
//------------------------------------------------------------------------------------
MClient::~MClient()
{

}
