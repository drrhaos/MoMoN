/********************************************************************************
** Form generated from reading UI file 'mtabwidgets.ui'
**
** Created: Mon 16. Apr 21:58:54 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MTABWIDGETS_H
#define UI_MTABWIDGETS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "mtextedit.h"

QT_BEGIN_NAMESPACE

class Ui_MTabWidgetsClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEditEntering;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *labelSendToFile;
    QProgressBar *progressBarSendToFile;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_4;
    QFontComboBox *comboBoxFont;
    QComboBox *comboBoxColor;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonBold;
    QPushButton *pushButtonItalic;
    QPushButton *pushButtonUnderline;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClearHistory;
    MTextEdit *textEditOutgoing;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSendToFile;
    QPushButton *pushButtonSmile;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonSend;

    void setupUi(QWidget *MTabWidgetsClass)
    {
        if (MTabWidgetsClass->objectName().isEmpty())
            MTabWidgetsClass->setObjectName(QString::fromUtf8("MTabWidgetsClass"));
        MTabWidgetsClass->resize(444, 327);
        MTabWidgetsClass->setAcceptDrops(false);
        verticalLayout_2 = new QVBoxLayout(MTabWidgetsClass);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textEditEntering = new QTextEdit(MTabWidgetsClass);
        textEditEntering->setObjectName(QString::fromUtf8("textEditEntering"));
        QPalette palette;
        QBrush brush(QColor(216, 255, 254, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        textEditEntering->setPalette(palette);
        textEditEntering->setReadOnly(true);

        verticalLayout_2->addWidget(textEditEntering);

        frame = new QFrame(MTabWidgetsClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(true);
        frame->setMinimumSize(QSize(0, 20));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelSendToFile = new QLabel(frame);
        labelSendToFile->setObjectName(QString::fromUtf8("labelSendToFile"));

        horizontalLayout->addWidget(labelSendToFile);

        progressBarSendToFile = new QProgressBar(frame);
        progressBarSendToFile->setObjectName(QString::fromUtf8("progressBarSendToFile"));
        progressBarSendToFile->setMaximumSize(QSize(16777215, 15));
        progressBarSendToFile->setValue(0);
        progressBarSendToFile->setAlignment(Qt::AlignCenter);
        progressBarSendToFile->setTextVisible(true);

        horizontalLayout->addWidget(progressBarSendToFile);


        verticalLayout_2->addWidget(frame);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_2 = new QFrame(MTabWidgetsClass);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        comboBoxFont = new QFontComboBox(frame_2);
        comboBoxFont->setObjectName(QString::fromUtf8("comboBoxFont"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxFont->sizePolicy().hasHeightForWidth());
        comboBoxFont->setSizePolicy(sizePolicy);
        comboBoxFont->setEditable(false);
        comboBoxFont->setFrame(false);

        horizontalLayout_4->addWidget(comboBoxFont);

        comboBoxColor = new QComboBox(frame_2);
        comboBoxColor->setObjectName(QString::fromUtf8("comboBoxColor"));
        sizePolicy.setHeightForWidth(comboBoxColor->sizePolicy().hasHeightForWidth());
        comboBoxColor->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(comboBoxColor);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButtonBold = new QPushButton(frame_2);
        pushButtonBold->setObjectName(QString::fromUtf8("pushButtonBold"));
        pushButtonBold->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/icon/font_bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonBold->setIcon(icon);
        pushButtonBold->setCheckable(true);

        horizontalLayout_3->addWidget(pushButtonBold);

        pushButtonItalic = new QPushButton(frame_2);
        pushButtonItalic->setObjectName(QString::fromUtf8("pushButtonItalic"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button/icon/font_Italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonItalic->setIcon(icon1);
        pushButtonItalic->setCheckable(true);

        horizontalLayout_3->addWidget(pushButtonItalic);

        pushButtonUnderline = new QPushButton(frame_2);
        pushButtonUnderline->setObjectName(QString::fromUtf8("pushButtonUnderline"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/button/icon/font_underlining.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonUnderline->setIcon(icon2);
        pushButtonUnderline->setCheckable(true);

        horizontalLayout_3->addWidget(pushButtonUnderline);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButtonClearHistory = new QPushButton(frame_2);
        pushButtonClearHistory->setObjectName(QString::fromUtf8("pushButtonClearHistory"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/button/icon/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonClearHistory->setIcon(icon3);

        horizontalLayout_4->addWidget(pushButtonClearHistory);


        verticalLayout->addWidget(frame_2);

        textEditOutgoing = new MTextEdit(MTabWidgetsClass);
        textEditOutgoing->setObjectName(QString::fromUtf8("textEditOutgoing"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(textEditOutgoing->sizePolicy().hasHeightForWidth());
        textEditOutgoing->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(textEditOutgoing);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButtonSendToFile = new QPushButton(MTabWidgetsClass);
        pushButtonSendToFile->setObjectName(QString::fromUtf8("pushButtonSendToFile"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/button/icon/send_to_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSendToFile->setIcon(icon4);

        horizontalLayout_2->addWidget(pushButtonSendToFile);

        pushButtonSmile = new QPushButton(MTabWidgetsClass);
        pushButtonSmile->setObjectName(QString::fromUtf8("pushButtonSmile"));
        pushButtonSmile->setContextMenuPolicy(Qt::CustomContextMenu);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/button/icon/smile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSmile->setIcon(icon5);

        horizontalLayout_2->addWidget(pushButtonSmile);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButtonSend = new QPushButton(MTabWidgetsClass);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setEnabled(false);

        horizontalLayout_2->addWidget(pushButtonSend);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(2, 1);

        retranslateUi(MTabWidgetsClass);

        comboBoxColor->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MTabWidgetsClass);
    } // setupUi

    void retranslateUi(QWidget *MTabWidgetsClass)
    {
        MTabWidgetsClass->setWindowTitle(QApplication::translate("MTabWidgetsClass", "MTabWidgets", 0, QApplication::UnicodeUTF8));
        labelSendToFile->setText(QApplication::translate("MTabWidgetsClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\236\321\202\320\277\321\200\320\260\320\262\320\272\320\260 \321\204\320\260\320\271\320\273\320\260:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButtonBold->setText(QString());
        pushButtonItalic->setText(QString());
        pushButtonUnderline->setText(QString());
        pushButtonClearHistory->setText(QString());
        pushButtonSendToFile->setText(QString());
        pushButtonSmile->setText(QString());
        pushButtonSend->setText(QApplication::translate("MTabWidgetsClass", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MTabWidgetsClass: public Ui_MTabWidgetsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MTABWIDGETS_H
