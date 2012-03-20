/*
 * MSqlRelationalDelegate.h
 *
 *  Created on: 05.09.2011
 *      Author: DrHaos
 */

#ifndef MSQLRELATIONALDELEGATE_H_
#define MSQLRELATIONALDELEGATE_H_

#include <QModelIndex>
#include <QPixmap>
#include <QSize>
#include <QSqlRelationalDelegate>

QT_FORWARD_DECLARE_CLASS(QPainter)


class MSqlRelationalDelegate : public QSqlRelationalDelegate
{
public:
	MSqlRelationalDelegate(QObject *parent);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                     const QStyleOptionViewItem &option,
                     const QModelIndex &index);

//    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
//                                        const QModelIndex &index) const;

private:
    QPixmap OnLine;
    QPixmap OffLine;
    QPixmap NewMessage;
};

#endif /* MSQLRELATIONALDELEGATE_H_ */
