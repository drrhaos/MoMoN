/*
 * mtcpsocket.h
 *
 *  Created on: 05.06.2011
 *      Author: DrHaos
 */

#ifndef MTCPSOCKET_H_
#define MTCPSOCKET_H_

 #include <QTcpSocket>

class MTcpSocket : public QTcpSocket
{
	Q_OBJECT
public:
	MTcpSocket(QObject *parent = 0);
	~MTcpSocket();

private:
};

#endif /* MTCPSOCKET_H_ */
