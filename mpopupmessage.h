#ifndef MPOPUPMESSAGE_H
#define MPOPUPMESSAGE_H

#include <QWidget>
#include "ui_mpopupmessage.h"
class MSettings;

class MPopupMessage : public QWidget, public Ui_MPopupMessage
{
    Q_OBJECT

public:
    MPopupMessage(QWidget *parent = 0);
    void setPosition(int coutPopup);
    void setTextPopupMessage(QString name, QString message);
public slots:
	void closePopupMessage();
	void editPosition(int coutPopup);
signals:
	void closePop();
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    QPoint dragPosition;
    MSettings *mainSettings;
    QTimer *popupTimer;

};

#endif // MPOPUPMESSAGE_H
