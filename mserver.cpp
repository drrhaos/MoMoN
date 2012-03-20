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

    sendToClient(mClientSocket, "Server Response: Connected!");
}
//-------------------------------------------------------------------------------
void MServer::slotReadClient()
{
    QTcpSocket* mClientSocket = (QTcpSocket*)sender();
    QDataStream in(mClientSocket);
    in.setVersion(QDataStream::Qt_4_7);

    forever
    {
        if (!nextBlockSize) {
            if (mClientSocket->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> nextBlockSize;
        }

        if (mClientSocket->bytesAvailable() < nextBlockSize) {
            break;
        }

        nextBlockSize = 0;

//разбор принятого сообщения

    QTime   time;
    QString str;

    QString strStatusName, nameUser, nameSurname, name, namePatronymic, namePost,
    		ipAdress, sendMesseges;


    in >> time >> strStatusName;
/*
* если статус OnLine тогда считывается информация о пользователе
* если статус OffLine тогда удаляется пользователь
* иначе считывается входящее сообщение
*/
    if (strStatusName == "OnLine") {
    	in >> nameUser >> nameSurname >> name >> namePatronymic >> namePost >> ipAdress;
    	emit signalsNewUser(strStatusName, nameUser,
    			nameSurname, name, namePatronymic, namePost,
    			ipAdress);
    } else if (strStatusName == "OffLine") {

	} else if (strStatusName == "message") {
    	in >> nameUser >> str;
    	QString strMessage =
    	            time.toString() + " " + str;
    	emit signalsNewEntering(nameUser, str);
//запись в историю
    	QTime realTime;

    	QString messeg = "<table width=100% bgcolor=#b4fff0><tr><td align=left><b><font color=red>" +
    			nameUser +
    			"</font></b></td><td align=right><div align=right><font color=gray>" +
    			realTime.currentTime().toString() +
    			"</font></div></td></tr></table>" +
    			str;
    	QString home = QDir::homePath() + "/.qlocmes";
    	QDir(home).mkdir(home);
    	QFile fileHistory(home + "/" + nameUser +".txt");
    	if (!fileHistory.open(QIODevice::Append | QIODevice::Text))
    		return;
    	fileHistory.write(messeg.toUtf8());

    	fileHistory.close();
	} else if (strStatusName == "file"){
		QByteArray buffer;
		QString fileName;
		QString dirDownloads = QDir::homePath() + "/Downloads/";
		QDir(dirDownloads).mkdir(dirDownloads);

		in >> nameUser >> fileName >> buffer;

		QFile receiveFile(dirDownloads + fileName);
		receiveFile.open(QIODevice::ReadWrite);

		QMessageBox::about(0, "Message", "Server = " + QString::number(buffer.size()));


		receiveFile.write(buffer);
		receiveFile.close();
	}
    sendToClient(mClientSocket,
                 "Server Response: Received \"" + str + "\"");

    }
}
// ----------------------------------------------------------------------
void MServer::sendToClient(QTcpSocket* mSocket, const QString& str)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_7);
    out << quint16(0) << QTime::currentTime() << str;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    mSocket->write(arrBlock);
}
//-----------------------------------------------------------------------
MServer::~MServer()
{

}
