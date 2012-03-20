/*
 * mtextedit.h
 *
 *  Created on: 26.02.2011
 *      Author: drhaos
 */

#ifndef MTEXTEDIT_H_
#define MTEXTEDIT_H_

#include <QtGui>

class QTextEdit;

class MTextEdit : public QTextEdit
{
	Q_OBJECT

public:
	MTextEdit(QWidget *parent = 0);
	MTextEdit(const QString & text, QWidget *parent = 0);
	~MTextEdit();

protected:
	void keyPressEvent(QKeyEvent * e);

signals:
		void signalsEnter();

private:
};

#endif /* MTEXTEDIT_H_ */
