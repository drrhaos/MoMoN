/*
 * mudpserver.cpp
 *
 *  Created on: 15.04.2012
 *      Author: drhaos
 */
#include "mudpserver.h"

MUdpServer::MUdpServer(QObject * parent)
	:QObject(parent)
{

}
//-------------------------------------------------------------------------------
void MUdpServer::sendData(QString typePacket, QString strStatusName,
		QString nameUser, QString  nameSurname, QString name,
		QString namePatronymic,	QString namePost, QString ipAdressPullClient)
{
	QByteArray datagram;
	QDataStream out(&datagram, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_7);
	out << typePacket << strStatusName << nameUser << nameSurname << name <<
			namePatronymic << namePost << ipAdressPullClient;

	socket.writeDatagram(datagram, QHostAddress::Broadcast, 5824);
}
//-------------------------------------------------------------------------------
MUdpServer::~MUdpServer()
{

}
