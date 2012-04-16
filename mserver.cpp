/*
 * mserver.cpp
 *
 *  Created on: 11.01.2011
 *      Author: drhaos
 */
#include "mserver.h"
#include "msettings.h"
#include "qlocmes.h"


MServer::MServer(int nPort, QObject * parent)
	:QObject(parent), nextBlockSize(0)
{
	mTcpServer = new QTcpServer(this);

	if (!mTcpServer->listen(QHostAddress::Any, nPort)) {
		QMessageBox::critical(0,
				"Server Error",
				QObject::trUtf8("Невозможно запустить сервер: ")
				+ mTcpServer->errorString());
		mTcpServer->close();
		return;
	}

	connect(mTcpServer, SIGNAL(newConnection()),
			this, 		SLOT(slotNewConnection()));
}
//-------------------------------------------------------------------------------
/*virtual*/ void MServer::slotNewConnection()
{
    QTcpSocket* mClientSocket = mTcpServer->nextPendingConnection();
    connect(mClientSocket, SIGNAL(disconnected()),
            mClientSocket, SLOT(deleteLater()));
    connect(mClientSocket, SIGNAL(readyRead()),
            this,          SLOT(slotReadClient()));

    sendToClient(mClientSocket, "SC_OFFICE", "Server Response: Connected!");
}
//-------------------------------------------------------------------------------
void MServer::slotReadClient()
{
    QTime   time;
    QString typePacket, nameUser;

    QTcpSocket* mClientSocket = (QTcpSocket*)sender();
    QDataStream in(mClientSocket);
    in.setVersion(QDataStream::Qt_4_7);


    if (!nextBlockSize) {
    	if (quint16(mClientSocket->bytesAvailable()) < sizeof(quint16)) {
    		return;
    	}
    	in >> nextBlockSize;
    }

    if (mClientSocket->bytesAvailable() < nextBlockSize) {
    	return;
    }

    in >> time >> typePacket >> nameUser;

   	if (typePacket == "CS_CONNECT") {
   		csConnect(nameUser);
   	} else if (typePacket == "CS_MESSAGE") {
   		csNewMessage(nameUser);
   	} else if (typePacket == "CS_STATUS") {

   	} else if (typePacket == "CS_MODIFY_CONTACT") {

   	} else if (typePacket == "CS_USER_INFO") {

   	} else if (typePacket == "CS_FILE_TRANSFER") {
   		csFileTransfer(nameUser);
   	} else {

   	}
    nextBlockSize = 0;
}
//---------------------------------------------------------------------
void MServer::csConnect(QString nameUser)
{
    QString nameSurname, name, namePatronymic, namePost,
    		ipAdress, sendMesseges;
    QString strStatusName = "OnLine";

	QTcpSocket* mClientSocket = (QTcpSocket*)sender();
    QDataStream in(mClientSocket);
    in.setVersion(QDataStream::Qt_4_7);

    in >> nameSurname >> name >> namePatronymic >> namePost >> ipAdress;

    emit signalsNewUser(strStatusName, nameUser,
    		nameSurname, name, namePatronymic, namePost,
    		ipAdress);
}
//---------------------------------------------------------------------
void MServer::csNewMessage(QString nameUser)
{
    QString enteringMessage;
    QTime   time;

	QTcpSocket* mClientSocket = (QTcpSocket*)sender();
    QDataStream in(mClientSocket);
    in.setVersion(QDataStream::Qt_4_7);


	in >> enteringMessage;
	QString fullMessage = time.toString() + " " + enteringMessage;
	emit signalsNewEntering(nameUser, enteringMessage);

//запись в историю
	QTime realTime;

	QString messag = "<table width=100% bgcolor=#b4fff0><tr><td align=left><b><font color=red>" +
			nameUser +
			"</font></b></td><td align=right><div align=right><font color=gray>" +
			realTime.currentTime().toString() +
			"</font></div></td></tr></table>" +
			enteringMessage;
	QString home = QDir::homePath() + "/.qlocmes";
	QDir(home).mkdir(home);
	QFile fileHistory(home + "/" + nameUser +".txt");
	if (!fileHistory.open(QIODevice::Append | QIODevice::Text))
		return;
	fileHistory.write(messag.toUtf8());
	fileHistory.close();


}
//---------------------------------------------------------------------
void MServer::csFileTransfer(QString nameUser)
{
	QTcpSocket* mClientSocket = (QTcpSocket*)sender();
    QDataStream in(mClientSocket);
    in.setVersion(QDataStream::Qt_4_7);

	QByteArray buffer;
	QString fileName;
	qint64 fileSize;

	QString dirDownloads = QDir::homePath() + "/Downloads/";
	QDir(dirDownloads).mkdir(dirDownloads);

	in >> fileName >> fileSize;

	QMessageBox messageBox;
	messageBox.setInformativeText(QObject::trUtf8("Принять файл ") + fileName +
			QObject::trUtf8(" от ") + nameUser + "?");
	messageBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
	int ret = messageBox.exec();

	if (ret == QMessageBox::Save) {

		forever
	    {
	        if (!nextBlockSize) {

	            if (quint16(mClientSocket->bytesAvailable()) < sizeof(quint16)) {
	                break;
	            }
	            in >> nextBlockSize;
	        }

	        in >> buffer;

	        sendToClient(mClientSocket, "SC_FILE_TRANSFER_ASK", fileName);

	        if (mClientSocket->bytesAvailable() < nextBlockSize) {
	            break;
	        }
	    }

	    QFile receiveFile(dirDownloads + fileName);
	    receiveFile.open(QIODevice::ReadWrite);
	    receiveFile.write(buffer);
	    receiveFile.close();
	    buffer.clear();
	} else {


	}
	nextBlockSize = 0;
}
// ----------------------------------------------------------------------
void MServer::sendToClient(QTcpSocket* mSocket, const QString& typePacket, QString report)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_7);
    out << quint16(0) << QTime::currentTime() << typePacket << report;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    mSocket->write(arrBlock);
}
//-----------------------------------------------------------------------
MServer::~MServer()
{

}
