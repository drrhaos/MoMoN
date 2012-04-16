/*
 * mudpclient.cpp
 *
 *  Created on: 15.04.2012
 *      Author: drhaos
 */
#include "mudpclient.h"
#include "qlocmes.h"

MUdpClient::MUdpClient(QObject *parent)
    : QObject(parent)
{

	udpsocket.bind(5824);
	connect(&udpsocket, SIGNAL(readyRead()), this, SLOT(readUdp()));
}
//------------------------------------------------------------------------------
void MUdpClient::readUdp()
{
	QByteArray datagram;
	do {
		datagram.resize(udpsocket.pendingDatagramSize());
		udpsocket.readDatagram(datagram.data(), datagram.size());
	} while (udpsocket.hasPendingDatagrams());
	QString typePacket, strStatusName, nameUser, nameSurname, name,
	namePatronymic, namePost, ipAdressPullClient;

	QDataStream in(&datagram, QIODevice::ReadOnly);
	in.setVersion(QDataStream::Qt_4_7);

	in >> typePacket >> strStatusName >> nameUser >> nameSurname >> name >>
	namePatronymic >> namePost >> ipAdressPullClient;

    emit signalsNewUser(strStatusName, nameUser,
    		nameSurname, name, namePatronymic, namePost,
    		ipAdressPullClient);
}
//------------------------------------------------------------------------------
MUdpClient::~MUdpClient()
{

}
