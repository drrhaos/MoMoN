/*
 * mudpclient.h
 *
 *  Created on: 15.04.2012
 *      Author: drhaos
 */

#ifndef MUDPCLIENT_H_
#define MUDPCLIENT_H_

#include <QtCore>
#include <QtGui>
#include <qudpsocket.h>

class QMessageBox;

class MUdpClient : public QObject
{
    Q_OBJECT

public:
    MUdpClient(QObject *parent = 0);
    ~MUdpClient();

private:
    QUdpSocket udpsocket;
signals:
	void signalsNewUser(QString& strStatusName, QString& nameUser,
			QString&  nameSurname,QString& name, QString& namePatronymic,
			QString& namePost, QString& ipAdress);

private slots:
	void readUdp();

};

#endif /* MUDPCLIENT_H_ */
