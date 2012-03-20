/*
 * mclient.h
 *
 *  Created on: 09.01.2011
 *      Author: drhaos
 */

#ifndef MCLIENT_H_
#define MCLIENT_H_

#include <QtGui>
#include <QMessageBox>
#include <QTcpServer>
#include <QTcpSocket>

class QTcpServer;
class QTcpSocket;
class MSettings;
class QSqlTableModel;

class MClient : public QObject
{
	Q_OBJECT
public:
	MClient(QObject * parent = 0);
	~MClient();

signals:
	void signalsDisConnected(QString& strHostName);

public slots:
	void slotConnectToHost(const QString& strHost, int nPort,  const QString& ipString);
	void slotConnected();
	void slotReadyRead();
	void slotSendToMessage(QString statusName, QString nameUser, QString sendMesseges);
	void slotSendToFile(QString filePatch, QString nameUser);

private slots:
	void slotError(QAbstractSocket::SocketError);


private:
    quint16 nextBlockSize;

private:
	QTcpSocket *mTcpSocket;
	QFile *sendFile;
	QString sHost, ipAdress;

};


#endif /* MCLIENT_H_ */
