/*
 * MSqlTableModel.cpp
 *
 *  Created on: 09.09.2011
 *      Author: DrHaos
 */

#include "MSqlTableModel.h"

MSqlTableModel::MSqlTableModel(QObject *parent)
       : QSqlTableModel(parent) {
//    refresh();
}
/*
Qt::ItemFlags MSqlTableModel::flags(
        const QModelIndex &index) const {

    Qt::ItemFlags flags = QSqlQueryModel::flags(index);
    if (index.column() >= 1 && index.column() < 4)
        flags |= Qt::ItemIsEditable;
    if (index.column() == 4)
        flags |= Qt::ItemIsUserCheckable;
    return flags;
}
*/
QVariant MSqlTableModel::data(
            const QModelIndex &index,
            int role) const {

    QVariant value = QSqlQueryModel::data(index, role);

    switch (role) {
   // case Qt::DecorationRole:
   //     if (index.column() == 0)
   //         return Qt::red;
   //     else if (index.column() == 1)
   //         return qApp->style()->standardIcon(QStyle::SP_DirIcon);
   //     else if (index.column() == 4)
   //         return qApp->style()->standardIcon(QStyle::SP_ArrowUp);
   //     else
   //         return value;
/*
    case Qt::TextColorRole:
        if(index.column() == 2)
            return qVariantFromValue(QColor(Qt::blue));
        else
            return value;

    case Qt::FontRole:
        if(index.column() == 2) {
            QFont font = QFont("Helvetica", 10, QFont::Bold);
            return qVariantFromValue(font);
        }else
            return value;

    case Qt::BackgroundColorRole: {
        //int a = (index.row() % 2) ? 14 : 0;
        if(index.column() == 2)
            return qVariantFromValue(QColor(220,240,230));
        else if(index.column() == 1)
            return qVariantFromValue(QColor(200,220,255));
        else
            return value;
    }
*/
    case Qt::SizeHintRole:
        if (index.column() == 1)
            return QSize(25, 25);
        else
            return QSize(100, 25);
    }
    return value;
}

//bool MSqlTableModel::setData(
//            const QModelIndex &index,
//            const QVariant &value,
//            int /* role */) {
/*    if (index.column() < 1 || index.column() > 2)
        return false;

    QModelIndex primaryKeyIndex = QSqlQueryModel::index(
        index.row(), 0);
    int id = QSqlQueryModel::data(primaryKeyIndex).toInt();

    //clear();

    bool ok;

    QSqlTableModel::setData(index, value);

    ok = TRUE;
    refresh();
    return ok;
}
*/
//void MSqlTableModel::refresh() {
//   setQuery("select * from basecontacs ORDER BY id");

//}

