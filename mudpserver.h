/*
 * mudpserver.h
 *
 *  Created on: 15.04.2012
 *      Author: drhaos
 */

#ifndef MUDPSERVER_H_
#define MUDPSERVER_H_

#include <QtCore>
#include <qudpsocket.h>

class MUdpServer : public QObject
{
	Q_OBJECT

public:
	MUdpServer(QObject * parent = 0);
	~MUdpServer();

public:
	void sendData(QString typePacket, QString strStatusName, QString nameUser,
			QString nameSurname,QString name, QString namePatronymic,
			QString namePost, QString ipAdressPullClient);

private:
    QUdpSocket socket;

};

#endif /* MUDPSERVER_H_ */
