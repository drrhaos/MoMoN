/********************************************************************************
** Form generated from reading UI file 'mpopupmessage.ui'
**
** Created: Mon 19. Mar 11:14:45 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MPOPUPMESSAGE_H
#define UI_MPOPUPMESSAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MPopupMessage
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *MPopupMessage)
    {
        if (MPopupMessage->objectName().isEmpty())
            MPopupMessage->setObjectName(QString::fromUtf8("MPopupMessage"));
        MPopupMessage->resize(210, 60);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(25, 182, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MPopupMessage->setPalette(palette);
        verticalLayout = new QVBoxLayout(MPopupMessage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 3, 2, 6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, 0, -1, -1);
        label_2 = new QLabel(MPopupMessage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(20, 16777215));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/button/icon/onlinepop.png")));

        horizontalLayout->addWidget(label_2);

        label = new QLabel(MPopupMessage);
        label->setObjectName(QString::fromUtf8("label"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe Script"));
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(MPopupMessage);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setEnabled(true);
        textBrowser->setMaximumSize(QSize(16777215, 31));
        QPalette palette2;
        QBrush brush3(QColor(224, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        textBrowser->setPalette(palette2);
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        textBrowser->setFont(font1);
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setLineWidth(0);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setAutoFormatting(QTextEdit::AutoAll);
        textBrowser->setTabChangesFocus(true);
        textBrowser->setUndoRedoEnabled(false);
        textBrowser->setTextInteractionFlags(Qt::TextBrowserInteraction);

        verticalLayout->addWidget(textBrowser);


        retranslateUi(MPopupMessage);

        QMetaObject::connectSlotsByName(MPopupMessage);
    } // setupUi

    void retranslateUi(QWidget *MPopupMessage)
    {
        MPopupMessage->setWindowTitle(QApplication::translate("MPopupMessage", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        MPopupMessage->setToolTip(QApplication::translate("MPopupMessage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_2->setText(QString());
        label->setText(QApplication::translate("MPopupMessage", "\320\232\320\276\320\275\321\202\320\260\320\272\321\202", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("MPopupMessage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:9pt;\"></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MPopupMessage: public Ui_MPopupMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MPOPUPMESSAGE_H
