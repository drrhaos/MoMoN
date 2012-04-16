#include <QtGui>

#include "mpopupmessage.h"

MPopupMessage::MPopupMessage(QWidget *parent)
		: QWidget(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint)
{
	setupUi(this);
	//скайп
/*	QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0.0, QColor::fromRgb(21, 126, 225));
    gradient.setColorAt(0.1, QColor::fromRgb(56, 132, 236));
    gradient.setColorAt(0.2, QColor::fromRgb(56, 132, 236));
    gradient.setColorAt(0.3, QColor::fromRgb(21, 126, 225));
    gradient.setColorAt(1, QColor::fromRgb(21, 126, 225));
    QPalette m;
    m.setBrush(QPalette::Window, gradient);
    setPalette(m);
*/
	//iphone
	QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0.0, QColor::fromRgb(146, 152, 170));
    gradient.setColorAt(0.1, QColor::fromRgb(101, 111, 138));
    gradient.setColorAt(0.2, QColor::fromRgb(94, 105, 133));
    gradient.setColorAt(0.3, QColor::fromRgb(45, 60, 100));
    gradient.setColorAt(1, QColor::fromRgb(32, 47, 87));
    QPalette m;
    m.setBrush(QPalette::Window, gradient);
    setPalette(m);


    popupTimer = new QTimer(this);
    popupTimer->start(10000);
    connect(popupTimer, SIGNAL(timeout()), this, SLOT(closePopupMessage()));

	setContextMenuPolicy(Qt::ActionsContextMenu);
	setWindowFlags(windowType()|Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::Tool|Qt::SplashScreen);
}
//--------------------------------------------------------------------------------------
void MPopupMessage::setPosition(int coutPopup)
{
	QDesktopWidget *d = QApplication::desktop();
	int cur_x = d->width();
	int cur_y = d->height();

	if (cur_y - 92 - (65 * coutPopup) > 0) {
		setGeometry(QRect(cur_x - 212, cur_y - 92 - (65 * coutPopup) , 210, 60));
	}else{
		setGeometry(QRect(cur_x - 212, cur_y - 92 - (65 * coutPopup) , 210, 60));
	}
}
//--------------------------------------------------------------------------------------
void MPopupMessage::setTextPopupMessage(QString name, QString message)
{
	label->setText(name);
	textBrowser->setText(message);
}
//--------------------------------------------------------------------------------------
void MPopupMessage::editPosition(int coutPopup)
{
	QDesktopWidget *d = QApplication::desktop();
	int cur_x = d->width();
	int cur_y = d->height();


	int i = 0;
	for (int var = 0; var < 65; ++var) {
/*		QTime time;
		time.start();
		for(;time.elapsed() < 40;)
		{
			qApp->processEvents();
		}*/
		var = var + i;
		++i;
		qApp->processEvents();
		setGeometry(QRect(cur_x - 212, cur_y - 92 - (65 * coutPopup) + var, 210, 60));
	}
}
//-------------------------------------------------------------------------------------
void MPopupMessage::paintEvent(QPaintEvent *)
{

}
//--------------------------------------------------------------------------------------
void MPopupMessage::resizeEvent(QResizeEvent * /* event */)
{
	int xPop, yPop, xPopHeight, yPopWidth;
	xPop = yPop = 0;
	xPopHeight = 200;
	yPopWidth = 50;

	QRegion maskedRegion;
    QRegion maskedRegionLeftBotton(xPop, yPop, 10, 10, QRegion::Ellipse);
    QRegion maskedRegionLeftTop(xPop, yPopWidth, 10, 10, QRegion::Ellipse);
    QRegion maskedRegionRichtBotton(xPopHeight, yPop, 10, 10, QRegion::Ellipse);
    QRegion maskedRegionRichtTop(xPopHeight, yPopWidth, 10, 10, QRegion::Ellipse);
    QRegion maskedRegioneRectan(xPop + 5, yPop, xPopHeight, yPopWidth + 10, QRegion::Rectangle);
    QRegion maskedRegioneRectanW(xPop, yPop + 5, xPopHeight + 10, yPopWidth, QRegion::Rectangle);


    maskedRegion = maskedRegion.unite(maskedRegionLeftBotton);
    maskedRegion = maskedRegion.unite(maskedRegionLeftTop);
    maskedRegion = maskedRegion.unite(maskedRegionRichtBotton);
    maskedRegion = maskedRegion.unite(maskedRegionRichtTop);
    maskedRegion = maskedRegion.unite(maskedRegionRichtTop);
    maskedRegion = maskedRegion.unite(maskedRegioneRectan);
    maskedRegion = maskedRegion.unite(maskedRegioneRectanW);

    setMask(maskedRegion);

}
//--------------------------------------------------------------------------------------
void MPopupMessage::closePopupMessage()
{
	//hide();
	popupTimer->stop();
    close();

	emit closePop();
}
