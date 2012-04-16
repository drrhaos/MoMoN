/********************************************************************************
** Form generated from reading UI file 'mmessage.ui'
**
** Created: Mon 16. Apr 21:58:55 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MMESSAGE_H
#define UI_MMESSAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MMessageClass
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;

    void setupUi(QMainWindow *MMessageClass)
    {
        if (MMessageClass->objectName().isEmpty())
            MMessageClass->setObjectName(QString::fromUtf8("MMessageClass"));
        MMessageClass->setWindowModality(Qt::NonModal);
        MMessageClass->resize(490, 406);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/actions/icon/messege.png"), QSize(), QIcon::Normal, QIcon::Off);
        MMessageClass->setWindowIcon(icon);
        MMessageClass->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MMessageClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 3, 0, 0);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setMouseTracking(false);
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);

        verticalLayout->addWidget(tabWidget);

        MMessageClass->setCentralWidget(centralwidget);

        retranslateUi(MMessageClass);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MMessageClass);
    } // setupUi

    void retranslateUi(QMainWindow *MMessageClass)
    {
        MMessageClass->setWindowTitle(QApplication::translate("MMessageClass", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MMessageClass: public Ui_MMessageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MMESSAGE_H
