/*
 * MSqlTableModel.h
 *
 *  Created on: 09.09.2011
 *      Author: DrHaos
 */

#ifndef MSQLTABLEMODEL_H_
#define MSQLTABLEMODEL_H_

#include <QtGui>
#include <QtSql>

class MSqlTableModel : public QSqlTableModel
{
	Q_OBJECT
public:
	MSqlTableModel(QObject *parent = 0);
//    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index,
                  int role = Qt::DisplayRole) const;
//    bool setData(const QModelIndex &index,
//                 const QVariant &value, int role);
private:
//    void refresh();
};

#endif /* MSQLTABLEMODEL_H_ */
