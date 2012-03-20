/********************************************************************************
** Form generated from reading UI file 'qlocmes.ui'
**
** Created: Mon 19. Mar 11:14:46 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLOCMES_H
#define UI_QLOCMES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QFormLayout>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qlocmes
{
public:
    QAction *actionOnLine;
    QAction *actionOffLIne;
    QAction *actionSettings;
    QAction *actionQuit;
    QAction *actionHelpQt;
    QAction *actionHelpQlocmessege;
    QAction *actionHelp;
    QAction *actionDeleteUser;
    QAction *actionSendMessage;
    QAction *actionSendFile;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTreeView *treeView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu;
    QMenu *menuHelp;
    QDockWidget *dockWidgetData;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QGraphicsView *graphicsViewFoto;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelSurname;
    QLineEdit *lineEditSurname;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelPatronymic;
    QLineEdit *lineEditPatronymic;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPost;
    QLineEdit *lineEditPost;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *qlocmes)
    {
        if (qlocmes->objectName().isEmpty())
            qlocmes->setObjectName(QString::fromUtf8("qlocmes"));
        qlocmes->resize(437, 405);
        qlocmes->setWindowTitle(QString::fromUtf8("MoMoN"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tray/icon/online.png"), QSize(), QIcon::Normal, QIcon::Off);
        qlocmes->setWindowIcon(icon);
        qlocmes->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionOnLine = new QAction(qlocmes);
        actionOnLine->setObjectName(QString::fromUtf8("actionOnLine"));
        actionOnLine->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/actions/icon/online.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOnLine->setIcon(icon1);
        actionOffLIne = new QAction(qlocmes);
        actionOffLIne->setObjectName(QString::fromUtf8("actionOffLIne"));
        actionOffLIne->setCheckable(true);
        actionOffLIne->setChecked(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/actions/icon/offline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOffLIne->setIcon(icon2);
        actionSettings = new QAction(qlocmes);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/actions/icon/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon3);
        actionQuit = new QAction(qlocmes);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/actions/icon/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon4);
        actionHelpQt = new QAction(qlocmes);
        actionHelpQt->setObjectName(QString::fromUtf8("actionHelpQt"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/actions/icon/logo_qt.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelpQt->setIcon(icon5);
        actionHelpQlocmessege = new QAction(qlocmes);
        actionHelpQlocmessege->setObjectName(QString::fromUtf8("actionHelpQlocmessege"));
        actionHelpQlocmessege->setIcon(icon1);
        actionHelp = new QAction(qlocmes);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/actions/icon/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon6);
        actionDeleteUser = new QAction(qlocmes);
        actionDeleteUser->setObjectName(QString::fromUtf8("actionDeleteUser"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/actions/icon/delete_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteUser->setIcon(icon7);
        actionSendMessage = new QAction(qlocmes);
        actionSendMessage->setObjectName(QString::fromUtf8("actionSendMessage"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/actions/icon/messege.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSendMessage->setIcon(icon8);
        actionSendFile = new QAction(qlocmes);
        actionSendFile->setObjectName(QString::fromUtf8("actionSendFile"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/button/icon/send_to_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSendFile->setIcon(icon9);
        centralwidget = new QWidget(qlocmes);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(treeView);

        qlocmes->setCentralWidget(centralwidget);
        menubar = new QMenuBar(qlocmes);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 437, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menu = new QMenu(menuFile);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setIcon(icon1);
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuHelp->setSeparatorsCollapsible(false);
        qlocmes->setMenuBar(menubar);
        dockWidgetData = new QDockWidget(qlocmes);
        dockWidgetData->setObjectName(QString::fromUtf8("dockWidgetData"));
        dockWidgetData->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidgetData->sizePolicy().hasHeightForWidth());
        dockWidgetData->setSizePolicy(sizePolicy);
        dockWidgetData->setMinimumSize(QSize(250, 300));
        dockWidgetData->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetMovable);
        dockWidgetData->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        graphicsViewFoto = new QGraphicsView(dockWidgetContents_3);
        graphicsViewFoto->setObjectName(QString::fromUtf8("graphicsViewFoto"));
        graphicsViewFoto->setMinimumSize(QSize(90, 120));
        graphicsViewFoto->setMaximumSize(QSize(90, 120));

        formLayout->setWidget(0, QFormLayout::LabelRole, graphicsViewFoto);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelSurname = new QLabel(dockWidgetContents_3);
        labelSurname->setObjectName(QString::fromUtf8("labelSurname"));

        gridLayout->addWidget(labelSurname, 0, 0, 1, 1);

        lineEditSurname = new QLineEdit(dockWidgetContents_3);
        lineEditSurname->setObjectName(QString::fromUtf8("lineEditSurname"));
        lineEditSurname->setReadOnly(true);

        gridLayout->addWidget(lineEditSurname, 0, 1, 1, 1);

        labelName = new QLabel(dockWidgetContents_3);
        labelName->setObjectName(QString::fromUtf8("labelName"));

        gridLayout->addWidget(labelName, 1, 0, 1, 1);

        lineEditName = new QLineEdit(dockWidgetContents_3);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setReadOnly(true);

        gridLayout->addWidget(lineEditName, 1, 1, 1, 1);

        labelPatronymic = new QLabel(dockWidgetContents_3);
        labelPatronymic->setObjectName(QString::fromUtf8("labelPatronymic"));

        gridLayout->addWidget(labelPatronymic, 2, 0, 1, 1);

        lineEditPatronymic = new QLineEdit(dockWidgetContents_3);
        lineEditPatronymic->setObjectName(QString::fromUtf8("lineEditPatronymic"));
        lineEditPatronymic->setReadOnly(true);

        gridLayout->addWidget(lineEditPatronymic, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelPost = new QLabel(dockWidgetContents_3);
        labelPost->setObjectName(QString::fromUtf8("labelPost"));
        labelPost->setFrameShape(QFrame::NoFrame);

        horizontalLayout_2->addWidget(labelPost);

        lineEditPost = new QLineEdit(dockWidgetContents_3);
        lineEditPost->setObjectName(QString::fromUtf8("lineEditPost"));
        lineEditPost->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEditPost);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 26, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        dockWidgetData->setWidget(dockWidgetContents_3);
        qlocmes->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetData);
#ifndef QT_NO_SHORTCUT
        labelSurname->setBuddy(lineEditSurname);
        labelName->setBuddy(lineEditName);
        labelPatronymic->setBuddy(lineEditPatronymic);
        labelPost->setBuddy(lineEditPost);
#endif // QT_NO_SHORTCUT

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(menu->menuAction());
        menuFile->addAction(actionSettings);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menu->addAction(actionOnLine);
        menu->addAction(actionOffLIne);
        menuHelp->addAction(actionHelpQt);
        menuHelp->addAction(actionHelpQlocmessege);
        menuHelp->addSeparator();
        menuHelp->addAction(actionHelp);

        retranslateUi(qlocmes);

        QMetaObject::connectSlotsByName(qlocmes);
    } // setupUi

    void retranslateUi(QMainWindow *qlocmes)
    {
        actionOnLine->setText(QApplication::translate("qlocmes", "\320\222 \321\201\320\265\321\202\320\270", 0, QApplication::UnicodeUTF8));
        actionOffLIne->setText(QApplication::translate("qlocmes", "\320\235\320\265 \320\262 \321\201\320\265\321\202\320\270", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("qlocmes", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("qlocmes", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        actionHelpQt->setText(QApplication::translate("qlocmes", "\320\236 Qt", 0, QApplication::UnicodeUTF8));
        actionHelpQlocmessege->setText(QApplication::translate("qlocmes", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("qlocmes", "\320\237\320\276\320\274\320\276\321\211\321\214", 0, QApplication::UnicodeUTF8));
        actionDeleteUser->setText(QApplication::translate("qlocmes", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\276\320\275\321\202\320\260\320\272\321\202", 0, QApplication::UnicodeUTF8));
        actionSendMessage->setText(QApplication::translate("qlocmes", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        actionSendFile->setText(QApplication::translate("qlocmes", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("qlocmes", "\320\234\320\265\320\275\321\216", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("qlocmes", "\320\241\321\202\320\260\321\202\321\203\321\201", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("qlocmes", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        dockWidgetData->setWindowTitle(QApplication::translate("qlocmes", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\272\320\276\320\275\321\202\320\260\320\272\321\202\320\260", 0, QApplication::UnicodeUTF8));
        labelSurname->setText(QApplication::translate("qlocmes", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", 0, QApplication::UnicodeUTF8));
        labelName->setText(QApplication::translate("qlocmes", "\320\230\320\274\321\217", 0, QApplication::UnicodeUTF8));
        labelPatronymic->setText(QApplication::translate("qlocmes", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", 0, QApplication::UnicodeUTF8));
        labelPost->setText(QApplication::translate("qlocmes", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(qlocmes);
    } // retranslateUi

};

namespace Ui {
    class qlocmes: public Ui_qlocmes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLOCMES_H
