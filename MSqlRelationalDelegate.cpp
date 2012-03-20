/*
 * MSqlRelationalDelegate.cpp
 *
 *  Created on: 05.09.2011
 *      Author: DrHaos
 */

#include <QtGui>

#include "MSqlRelationalDelegate.h"

MSqlRelationalDelegate::MSqlRelationalDelegate(QObject *parent)
: QSqlRelationalDelegate(parent), OnLine(QPixmap(":/list/icon/online_list.png")),
  OffLine(QPixmap(":/list/icon/offline_list.png")), NewMessage(QPixmap(":/list/icon/new_message_list.png"))
{
	// TODO Auto-generated constructor stub

}
//------------------------------------------------------------------------------------
void MSqlRelationalDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const
{
	QStyleOptionViewItemV3 opt = option;
    if (index.column() == 2) {
        const QAbstractItemModel *model = index.model();
        QString rating = model->data(index, Qt::DisplayRole).toString();

        QLinearGradient grad(option.rect.x(), option.rect.y(),
        		option.rect.x(), option.rect.y() + option.rect.height());
        grad.setColorAt(0.0, QColor::fromRgb(194, 220, 253));
        grad.setColorAt(0.5, QColor::fromRgb(214, 232, 253));
        grad.setColorAt(1, QColor::fromRgb(194, 220, 253));

        if (option.state & QStyle::State_Selected)
            painter->fillRect(option.rect, grad);
        painter->setFont(QFont("Helvetica", 10, QFont::System));
        painter->setPen(QColor::fromRgb(0, 0, 255));
        painter->drawText(option.rect.x()+28, option.rect.y()+17 , rating);

        QString status = model->data(model->index(index.row(), index.column() - 1 )
        		, Qt::DisplayRole).toString();
        bool messages = model->data(model->index(index.row(), index.column()+ 6 )
                		, Qt::DisplayRole).toBool();
        //int width = OnLine.width();
        int height = OnLine.height();
        int x = option.rect.x();
        int y = option.rect.y() + (option.rect.height() / 2) - (height / 2);

        if ((status == "OnLine") & (messages == FALSE)) {
        	painter->drawPixmap(x, y, OnLine);
		}else if ((status == "OnLine") & (messages == TRUE)) {
			painter->drawPixmap(x, y, NewMessage);
		}else if ((status == "OffLine") & (messages == FALSE)) {
			painter->drawPixmap(x, y, OffLine);
		}else{
			painter->drawPixmap(x, y, NewMessage);
		}
    }
}
//-------------------------------------------------------------------------------------
QSize MSqlRelationalDelegate::sizeHint(const QStyleOptionViewItem &option,
                                 const QModelIndex &index) const
{
    if (index.column() == 1)
        return QSize(OnLine.width(), OnLine.height()) + QSize(1, 1);

    return QSqlRelationalDelegate::sizeHint(option, index) + QSize(1, 1); // since we draw the grid ourselves
}
//---------------------------------------------------------------------------------------
bool MSqlRelationalDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                               const QStyleOptionViewItem &option,
                               const QModelIndex &index)
{
    if (index.column() != 0)
        return QSqlRelationalDelegate::editorEvent(event, model, option, index);
/*
    if (event->type() == QEvent::MouseButtonDblClick) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        bool stars = !(model->data(index, Qt::DisplayRole).toBool());
        model->setData(index, QVariant(stars));
        model->submit();
        return false; //so that the selection can change
    }
*/
    return true;
}
//----------------------------------------------------------------------------------------
//QWidget *MSqlRelationalDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
//                                    const QModelIndex &index) const
//{
//    if (index.column() != 1)
//       return QSqlRelationalDelegate::createEditor(parent, option, index);

// for editing the year, return a spinbox with a range from -1000 to 2100.
//    QSpinBox *sb = new QSpinBox(parent);
//    sb->setFrame(false);
//    sb->setMaximum(2100);
//    sb->setMinimum(-1000);

//    return sb;
//}
