/*
 * mtextedit.cpp
 *
 *  Created on: 26.02.2011
 *      Author: drhaos
 */
#include "mtextedit.h"

MTextEdit::MTextEdit(QWidget *parent)
: QTextEdit(parent)
{

}
//----------------------------------------------------------------------------------------------
MTextEdit::MTextEdit(const QString & text, QWidget *parent)
: QTextEdit(text, parent)
{

}
//----------------------------------------------------------------------------------------------
MTextEdit::~MTextEdit()
{

}
//----------------------------------------------------------------------------------------------
void MTextEdit::keyPressEvent(QKeyEvent *e)
{
	if (e->key() == Qt::Key_Return) {
		emit signalsEnter();
	} else {
		QTextEdit::keyPressEvent(e);
	}
}
