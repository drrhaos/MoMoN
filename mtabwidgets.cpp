#include "mserver.h"
#include "mclient.h"
#include "mtabwidgets.h"

MTabWidgets::MTabWidgets(QString& userNameTemp, MServer * mainServerTemp,
		QString ipClient, QString myIpString, QWidget *parent)
    : QWidget(parent)
{
	setupUi(this);

	QStringList colorNames;
	strHost = ipClient;
    colorNames = QColor::colorNames();   //Если нужны не ВСЕ цвета, присутствущие в системе, разремируем данную строчку и ремируем следующую. Иначе, используем только те цвета, которые указаны строчкой ниже
    //colorNames <<"darkGreen"<<"green"<<"gray"<<"red"<<"white"<<"blue"<<"cyan"<<"darkMagenta"<<"yellow"<<"darkRed"<<"black"<<"magenta";

    comboBoxColor->setFocusPolicy(Qt::NoFocus);
    int size = comboBoxColor->style()->pixelMetric(QStyle::PM_SmallIconSize);
    QPixmap pixmap(size,size-5);

    int con=0;
    foreach (const QString &colorName, colorNames) {
        comboBoxColor->addItem(colorName);
        pixmap.fill(QColor(colorName));

        QRect rBorder(0,0,size-1,size-6);
        QPainter p(&pixmap);
        QPen pen(Qt::lightGray, 1, Qt::SolidLine);
        p.setPen(pen);
        p.drawRect(rBorder);

        comboBoxColor->setItemData(con, pixmap, Qt::DecorationRole);
        con=con+1;
    }
    comboBoxColor->setCurrentIndex(7);

	mainSettings = new MSettings(this);
	mSettings = new QSettings("DrHaos", "qlocmes");
	mainServer = mainServerTemp;
	mainClient = new MClient(this);
	mainClient->slotConnectToHost(ipClient, mSettings->value("Number Port", 1024).toInt(), myIpString);
	userName = userNameTemp;

	frame->setVisible(FALSE);
//отправка сообщения при нажатии на кнопку "отправить"
	connect(pushButtonSend, SIGNAL(clicked()), this, SLOT(slotSendMesseges()));
//отправка сообщения при нажатии на кнопку "Enter"
	connect(textEditOutgoing, SIGNAL(returnPressed()), this, SLOT(slotSendMesseges()));
	connect(textEditOutgoing, SIGNAL(signalsEnter()), this, SLOT(slotSendMesseges()));
//при наличии текста окнопка отправить становится активной
	connect(textEditOutgoing, SIGNAL(textChanged()), this, SLOT(enabledSendPuchButton()));
//
	connect(mainServer, SIGNAL(signalsNewEntering(QString , QString )),
			this, SLOT(slotNewEntering(QString , QString )));
	connect(pushButtonSendToFile, SIGNAL(clicked()), this, SLOT(slotSendToFile()));
	connect(comboBoxColor, SIGNAL(currentIndexChanged(const QString &)),
			this, SLOT(slotSetColorText(const QString &)));
	connect(comboBoxFont, SIGNAL(currentIndexChanged(const QString &)),
			this, SLOT(slotSetFontText(const QString &)));
	connect(pushButtonBold, SIGNAL(toggled(bool )),
			this, SLOT(slotSetBoldText(bool )));
	connect(pushButtonItalic, SIGNAL(toggled(bool )),
			this, SLOT(slotSetItalicText(bool )));
	connect(pushButtonUnderline, SIGNAL(toggled(bool )),
			this, SLOT(slotSetUnderlineText(bool )));
	connect(pushButtonClearHistory, SIGNAL(clicked()), this, SLOT(slotClearHistory()));

	textEditEntering->verticalScrollBar()->setValue(textEditEntering->verticalScrollBar()->maximum());
}
//----------------------------------------------------------------------------------------
void MTabWidgets::slotSendMesseges()
{
	if ((textEditOutgoing->toPlainText()).length()) {
		QTime realTime;
		QString messag = "<table width=100% bgcolor=#b4fff0><tr><td align=left><b><font color=blue>" +
				mSettings->value("Name User", "").toString() +
				"</font></b></td><td align=right><div align=right><font color=gray>" +
				realTime.currentTime().toString() +
				"</font></div></td></tr></table>" +
				textEditOutgoing->toHtml();

		mainClient->slotSendToMessage("CS_MESSAGE", mSettings->value("Name User", "").toString() ,
				textEditOutgoing->toHtml());
		textEditEntering->append(messag);


//запись в историю
       	QString home = QDir::homePath() + "/.qlocmes";
       	QDir(home).mkdir(home);
       	QFile fileHistory(home + "/" + userName +".txt");
       	if (!fileHistory.open(QIODevice::Append | QIODevice::Text))
       		return;
       	fileHistory.write(messag.toUtf8());

       	fileHistory.close();
       	textEditOutgoing->clear();
	}
	textEditEntering->verticalScrollBar()->setValue(textEditEntering->verticalScrollBar()->maximum());
	textEditOutgoing->setFocus();
}
//----------------------------------------------------------------------------------------
void MTabWidgets::slotNewEntering(QString nameUserEntering, QString newEnteringMesseges)
{
	QTime realTime;

	if (nameUserEntering == userName) {
		QString messag = "<table width=100% bgcolor=#b4fff0><tr><td align=left><b><font color=red>" +
				nameUserEntering +
				"</font></b></td><td align=right><div align=right><font color=gray>" +
				realTime.currentTime().toString() +
				"</font></div></td></tr></table>" +
				newEnteringMesseges;
		textEditEntering->append(messag);
	}
	textEditEntering->verticalScrollBar()->setValue(textEditEntering->verticalScrollBar()->maximum());
}
//------------------------------------------------------------------------------------------
void MTabWidgets::enabledSendPuchButton()
{
	if ((textEditOutgoing->toPlainText()).length()) {
		pushButtonSend->setEnabled(TRUE);
	} else {
		pushButtonSend->setEnabled(FALSE);
	}
}
//--------------------------------------------------------------------------------------
bool MTabWidgets::slotSendToFile()
{
	QString fileName = QFileDialog::getOpenFileName(this,
			QObject::trUtf8("Выбор файла для отправки"), "",
			QObject::trUtf8("(*.*)"));
	if (fileName.isEmpty()) {
		return false;
	}
	frame->setVisible(TRUE);

	mainClient->slotSendToFile(fileName, mSettings->value("Name User", "").toString());

	textEditEntering->append(QObject::trUtf8("<b><font color=blue>Файл: </b></font>")
							 + fileName + QObject::trUtf8("<b><font color=blue> отправлен.</b></font>"));

	QFileInfo fi(fileName);
	progressBarSendToFile->setMaximum(fi.size());

	frame->setVisible(false);
	return true;
}
//---------------------------------------------------------------------------------------
void MTabWidgets::slotSetColorText(const QString & text)
{
	QTextCharFormat textCharFormat = textEditOutgoing->currentCharFormat();
	textCharFormat.setForeground(QBrush(QColor(text)));
	textEditOutgoing->setCurrentCharFormat(textCharFormat);
	textEditOutgoing->setFocus();
}
//---------------------------------------------------------------------------------------
void MTabWidgets::slotSetFontText(const QString & text)
{
	QTextCharFormat textCharFormat = textEditOutgoing->currentCharFormat();
	textCharFormat.setFont(QFont(text));
	textEditOutgoing->setCurrentCharFormat(textCharFormat);
	textEditOutgoing->setFocus();
}
//---------------------------------------------------------------------------------------
void MTabWidgets::slotSetBoldText(bool index)
{
	QTextCharFormat textCharFormat = textEditOutgoing->currentCharFormat();
	if (index) {
		textCharFormat.setFontWeight(QFont::Bold);
	} else {
		textCharFormat.setFontWeight(QFont::Normal);
	}
	textEditOutgoing->setCurrentCharFormat(textCharFormat);
	textEditOutgoing->setFocus();
}
//--------------------------------------------------------------------------------------
void MTabWidgets::slotSetItalicText(bool index)
{
	QTextCharFormat textCharFormat = textEditOutgoing->currentCharFormat();
	textCharFormat.setFontItalic(index);
	textEditOutgoing->setCurrentCharFormat(textCharFormat);
	textEditOutgoing->setFocus();
}
//--------------------------------------------------------------------------------------
void MTabWidgets::slotSetUnderlineText(bool index)
{
	QTextCharFormat textCharFormat = textEditOutgoing->currentCharFormat();
	textCharFormat.setFontUnderline(index);
	textEditOutgoing->setCurrentCharFormat(textCharFormat);
	textEditOutgoing->setFocus();
}
//---------------------------------------------------------------------------------------
void MTabWidgets::slotClearHistory()
{
	textEditEntering->clear();

	QString home = QDir::homePath() + "/.qlocmes";
   	QDir(home).mkdir(home);
   	QFile fileHistory(home + "/" + userName +".txt");
   	if (!fileHistory.open(QIODevice::Append | QIODevice::Text))
   		return;
   	fileHistory.remove();

   	fileHistory.close();
}
//---------------------------------------------------------------------------------------
MTabWidgets::~MTabWidgets()
{
    delete [] mainSettings;
}
