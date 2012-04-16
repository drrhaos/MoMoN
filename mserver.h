/*
 * mserver.h
 *
 *  Created on: 11.01.2011
 *      Author: drhaos
 */

#ifndef MSERVER_H_
#define MSERVER_H_

#include <QTcpServer>

class QTcpServer;
class QTcpSocket;

class MServer : public QObject
{
	Q_OBJECT
public:
	MServer(int nPort, QObject * parent = 0);
	~MServer();

signals:
	void signalsNewUser(QString& strStatusName, QString& nameUser,
			QString&  nameSurname,QString& name, QString& namePatronymic,
			QString& namePost, QString& ipAdress);
	void signalsNewEntering(QString statusMesseges, QString newEnteringMesseges);

public slots:
	virtual void slotNewConnection();//сервер
	void slotReadClient();//сервер

private:
    QTcpServer *mTcpServer;//сервер
    QTcpSocket * mTcpSocket;
    quint16 nextBlockSize;

private:
    void sendToClient(QTcpSocket* mSocket, const QString& typePacket, QString report);//сервер
    void csConnect(QString nameUser);
    void csNewMessage(QString nameUser);
    void csFileTransfer(QString nameUser);

};


#endif /* MSERVER_H_ */
