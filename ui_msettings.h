/********************************************************************************
** Form generated from reading UI file 'msettings.ui'
**
** Created: Mon 16. Apr 23:23:02 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSETTINGS_H
#define UI_MSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableView>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MSettingsClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelStyle;
    QComboBox *comboBoxStyle;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelLanguage;
    QComboBox *comboBoxLanguage;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_14;
    QRadioButton *radioButtonSavePos;
    QRadioButton *radioButtonCenterPos;
    QRadioButton *radioButtonRightPos;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QGraphicsView *graphicsView;
    QGridLayout *gridLayout;
    QLabel *labelUser;
    QLineEdit *lineEditUser;
    QLabel *labelSurname;
    QLineEdit *lineEditSurname;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelPatronymic;
    QLineEdit *lineEditPatronymic;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelPost;
    QLineEdit *lineEditPost;
    QSpacerItem *verticalSpacer;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QTreeView *treeViewSounds;
    QHBoxLayout *horizontalLayout_15;
    QLabel *labelEvent;
    QLineEdit *lineEditEvent;
    QHBoxLayout *horizontalLayout_16;
    QLabel *labelPath;
    QLineEdit *lineEditPathSounds;
    QPushButton *pushButtonPath;
    QPushButton *pushButtonPlay;
    QPushButton *pushButtonClearSounds;
    QFrame *line_3;
    QLabel *labelPopMessage;
    QCheckBox *checkBoxOnLineClient;
    QCheckBox *checkBoxOffLineClient;
    QCheckBox *checkBoxNewMessageCloseForm;
    QCheckBox *checkBoxNewMessageOpenForm;
    QSpacerItem *verticalSpacer_5;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelNumberPort;
    QSpinBox *spinBoxNumberPort;
    QLabel *labelInquiryStatus;
    QSpinBox *spinBoxInquiryStatus;
    QLabel *labelInquiryStatusSec;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelMyIp;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *checkBoxMyIp;
    QLineEdit *lineEditMyIp;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButtonAddMyIp;
    QPushButton *pushButtonEditMyIp;
    QPushButton *pushButtonDeleteMyIp;
    QPushButton *pushButtonSaveMyIp;
    QSpacerItem *verticalSpacer_4;
    QTableView *tableViewMyIp;
    QFrame *frame;
    QVBoxLayout *verticalLayout_6;
    QFrame *line;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelNetFilter;
    QComboBox *comboBoxNetFilter;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelIpFrom;
    QLineEdit *lineEditIpFrom;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelIpTo;
    QLineEdit *lineEditIpTo;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonAddAdress;
    QPushButton *pushButtonEditAress;
    QPushButton *pushButtonDelAdress;
    QPushButton *pushButtonSaveAress;
    QTableView *tableViewNetFilter;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxExpert;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonApply;
    QPushButton *pushButtonSave;

    void setupUi(QDialog *MSettingsClass)
    {
        if (MSettingsClass->objectName().isEmpty())
            MSettingsClass->setObjectName(QString::fromUtf8("MSettingsClass"));
        MSettingsClass->resize(588, 462);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/actions/icon/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        MSettingsClass->setWindowIcon(icon);
        horizontalLayout_2 = new QHBoxLayout(MSettingsClass);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        listWidget = new QListWidget(MSettingsClass);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(MSettingsClass);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        labelStyle = new QLabel(page);
        labelStyle->setObjectName(QString::fromUtf8("labelStyle"));

        horizontalLayout_9->addWidget(labelStyle);

        comboBoxStyle = new QComboBox(page);
        comboBoxStyle->setObjectName(QString::fromUtf8("comboBoxStyle"));

        horizontalLayout_9->addWidget(comboBoxStyle);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        labelLanguage = new QLabel(page);
        labelLanguage->setObjectName(QString::fromUtf8("labelLanguage"));

        horizontalLayout_9->addWidget(labelLanguage);

        comboBoxLanguage = new QComboBox(page);
        comboBoxLanguage->setObjectName(QString::fromUtf8("comboBoxLanguage"));
        comboBoxLanguage->setEnabled(false);

        horizontalLayout_9->addWidget(comboBoxLanguage);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        radioButtonSavePos = new QRadioButton(page);
        radioButtonSavePos->setObjectName(QString::fromUtf8("radioButtonSavePos"));
        radioButtonSavePos->setChecked(false);
        radioButtonSavePos->setAutoRepeat(false);

        horizontalLayout_14->addWidget(radioButtonSavePos);

        radioButtonCenterPos = new QRadioButton(page);
        radioButtonCenterPos->setObjectName(QString::fromUtf8("radioButtonCenterPos"));
        radioButtonCenterPos->setChecked(true);

        horizontalLayout_14->addWidget(radioButtonCenterPos);

        radioButtonRightPos = new QRadioButton(page);
        radioButtonRightPos->setObjectName(QString::fromUtf8("radioButtonRightPos"));
        radioButtonRightPos->setEnabled(true);
        radioButtonRightPos->setChecked(false);

        horizontalLayout_14->addWidget(radioButtonRightPos);


        verticalLayout_3->addLayout(horizontalLayout_14);

        verticalSpacer_2 = new QSpacerItem(20, 306, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        graphicsView = new QGraphicsView(page_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(90, 120));
        graphicsView->setMaximumSize(QSize(90, 120));

        horizontalLayout_4->addWidget(graphicsView);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelUser = new QLabel(page_2);
        labelUser->setObjectName(QString::fromUtf8("labelUser"));

        gridLayout->addWidget(labelUser, 0, 0, 1, 1);

        lineEditUser = new QLineEdit(page_2);
        lineEditUser->setObjectName(QString::fromUtf8("lineEditUser"));

        gridLayout->addWidget(lineEditUser, 0, 1, 1, 1);

        labelSurname = new QLabel(page_2);
        labelSurname->setObjectName(QString::fromUtf8("labelSurname"));

        gridLayout->addWidget(labelSurname, 1, 0, 1, 1);

        lineEditSurname = new QLineEdit(page_2);
        lineEditSurname->setObjectName(QString::fromUtf8("lineEditSurname"));

        gridLayout->addWidget(lineEditSurname, 1, 1, 1, 1);

        labelName = new QLabel(page_2);
        labelName->setObjectName(QString::fromUtf8("labelName"));

        gridLayout->addWidget(labelName, 2, 0, 1, 1);

        lineEditName = new QLineEdit(page_2);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        gridLayout->addWidget(lineEditName, 2, 1, 1, 1);

        labelPatronymic = new QLabel(page_2);
        labelPatronymic->setObjectName(QString::fromUtf8("labelPatronymic"));

        gridLayout->addWidget(labelPatronymic, 3, 0, 1, 1);

        lineEditPatronymic = new QLineEdit(page_2);
        lineEditPatronymic->setObjectName(QString::fromUtf8("lineEditPatronymic"));

        gridLayout->addWidget(lineEditPatronymic, 3, 1, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelPost = new QLabel(page_2);
        labelPost->setObjectName(QString::fromUtf8("labelPost"));

        horizontalLayout_3->addWidget(labelPost);

        lineEditPost = new QLineEdit(page_2);
        lineEditPost->setObjectName(QString::fromUtf8("lineEditPost"));

        horizontalLayout_3->addWidget(lineEditPost);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 198, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        verticalLayout_7 = new QVBoxLayout(page_4);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label = new QLabel(page_4);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_7->addWidget(label);

        treeViewSounds = new QTreeView(page_4);
        treeViewSounds->setObjectName(QString::fromUtf8("treeViewSounds"));

        verticalLayout_7->addWidget(treeViewSounds);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        labelEvent = new QLabel(page_4);
        labelEvent->setObjectName(QString::fromUtf8("labelEvent"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelEvent->sizePolicy().hasHeightForWidth());
        labelEvent->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(labelEvent);

        lineEditEvent = new QLineEdit(page_4);
        lineEditEvent->setObjectName(QString::fromUtf8("lineEditEvent"));
        QPalette palette;
        QBrush brush(QColor(240, 240, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        lineEditEvent->setPalette(palette);
        lineEditEvent->setFrame(false);
        lineEditEvent->setDragEnabled(false);
        lineEditEvent->setReadOnly(true);

        horizontalLayout_15->addWidget(lineEditEvent);


        verticalLayout_7->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        labelPath = new QLabel(page_4);
        labelPath->setObjectName(QString::fromUtf8("labelPath"));

        horizontalLayout_16->addWidget(labelPath);

        lineEditPathSounds = new QLineEdit(page_4);
        lineEditPathSounds->setObjectName(QString::fromUtf8("lineEditPathSounds"));
        lineEditPathSounds->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditPathSounds->sizePolicy().hasHeightForWidth());
        lineEditPathSounds->setSizePolicy(sizePolicy1);
        lineEditPathSounds->setReadOnly(false);

        horizontalLayout_16->addWidget(lineEditPathSounds);

        pushButtonPath = new QPushButton(page_4);
        pushButtonPath->setObjectName(QString::fromUtf8("pushButtonPath"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonPath->sizePolicy().hasHeightForWidth());
        pushButtonPath->setSizePolicy(sizePolicy2);
        pushButtonPath->setMaximumSize(QSize(30, 16777215));
        pushButtonPath->setChecked(false);

        horizontalLayout_16->addWidget(pushButtonPath);

        pushButtonPlay = new QPushButton(page_4);
        pushButtonPlay->setObjectName(QString::fromUtf8("pushButtonPlay"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButtonPlay->sizePolicy().hasHeightForWidth());
        pushButtonPlay->setSizePolicy(sizePolicy3);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button/icon/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonPlay->setIcon(icon1);

        horizontalLayout_16->addWidget(pushButtonPlay);

        pushButtonClearSounds = new QPushButton(page_4);
        pushButtonClearSounds->setObjectName(QString::fromUtf8("pushButtonClearSounds"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/button/icon/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonClearSounds->setIcon(icon2);

        horizontalLayout_16->addWidget(pushButtonClearSounds);


        verticalLayout_7->addLayout(horizontalLayout_16);

        line_3 = new QFrame(page_4);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_3);

        labelPopMessage = new QLabel(page_4);
        labelPopMessage->setObjectName(QString::fromUtf8("labelPopMessage"));
        labelPopMessage->setFont(font);

        verticalLayout_7->addWidget(labelPopMessage);

        checkBoxOnLineClient = new QCheckBox(page_4);
        checkBoxOnLineClient->setObjectName(QString::fromUtf8("checkBoxOnLineClient"));

        verticalLayout_7->addWidget(checkBoxOnLineClient);

        checkBoxOffLineClient = new QCheckBox(page_4);
        checkBoxOffLineClient->setObjectName(QString::fromUtf8("checkBoxOffLineClient"));

        verticalLayout_7->addWidget(checkBoxOffLineClient);

        checkBoxNewMessageCloseForm = new QCheckBox(page_4);
        checkBoxNewMessageCloseForm->setObjectName(QString::fromUtf8("checkBoxNewMessageCloseForm"));

        verticalLayout_7->addWidget(checkBoxNewMessageCloseForm);

        checkBoxNewMessageOpenForm = new QCheckBox(page_4);
        checkBoxNewMessageOpenForm->setObjectName(QString::fromUtf8("checkBoxNewMessageOpenForm"));

        verticalLayout_7->addWidget(checkBoxNewMessageOpenForm);

        verticalSpacer_5 = new QSpacerItem(20, 140, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_5);

        stackedWidget->addWidget(page_4);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_8 = new QVBoxLayout(page_3);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labelNumberPort = new QLabel(page_3);
        labelNumberPort->setObjectName(QString::fromUtf8("labelNumberPort"));

        horizontalLayout_7->addWidget(labelNumberPort);

        spinBoxNumberPort = new QSpinBox(page_3);
        spinBoxNumberPort->setObjectName(QString::fromUtf8("spinBoxNumberPort"));
        spinBoxNumberPort->setMaximum(999999);
        spinBoxNumberPort->setValue(2323);

        horizontalLayout_7->addWidget(spinBoxNumberPort);

        labelInquiryStatus = new QLabel(page_3);
        labelInquiryStatus->setObjectName(QString::fromUtf8("labelInquiryStatus"));
        labelInquiryStatus->setEnabled(true);

        horizontalLayout_7->addWidget(labelInquiryStatus);

        spinBoxInquiryStatus = new QSpinBox(page_3);
        spinBoxInquiryStatus->setObjectName(QString::fromUtf8("spinBoxInquiryStatus"));
        spinBoxInquiryStatus->setMinimum(30);
        spinBoxInquiryStatus->setMaximum(99999);
        spinBoxInquiryStatus->setValue(3600);

        horizontalLayout_7->addWidget(spinBoxInquiryStatus);

        labelInquiryStatusSec = new QLabel(page_3);
        labelInquiryStatusSec->setObjectName(QString::fromUtf8("labelInquiryStatusSec"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(labelInquiryStatusSec->sizePolicy().hasHeightForWidth());
        labelInquiryStatusSec->setSizePolicy(sizePolicy4);

        horizontalLayout_7->addWidget(labelInquiryStatusSec);


        verticalLayout_8->addLayout(horizontalLayout_7);

        line_2 = new QFrame(page_3);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_2);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        labelMyIp = new QLabel(page_3);
        labelMyIp->setObjectName(QString::fromUtf8("labelMyIp"));

        verticalLayout_5->addWidget(labelMyIp);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        checkBoxMyIp = new QCheckBox(page_3);
        checkBoxMyIp->setObjectName(QString::fromUtf8("checkBoxMyIp"));
        checkBoxMyIp->setEnabled(false);

        horizontalLayout_12->addWidget(checkBoxMyIp);


        verticalLayout_5->addLayout(horizontalLayout_12);

        lineEditMyIp = new QLineEdit(page_3);
        lineEditMyIp->setObjectName(QString::fromUtf8("lineEditMyIp"));
        lineEditMyIp->setEnabled(false);

        verticalLayout_5->addWidget(lineEditMyIp);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButtonAddMyIp = new QPushButton(page_3);
        pushButtonAddMyIp->setObjectName(QString::fromUtf8("pushButtonAddMyIp"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButtonAddMyIp->sizePolicy().hasHeightForWidth());
        pushButtonAddMyIp->setSizePolicy(sizePolicy5);
        pushButtonAddMyIp->setMaximumSize(QSize(23, 16777215));

        horizontalLayout_8->addWidget(pushButtonAddMyIp);

        pushButtonEditMyIp = new QPushButton(page_3);
        pushButtonEditMyIp->setObjectName(QString::fromUtf8("pushButtonEditMyIp"));
        sizePolicy5.setHeightForWidth(pushButtonEditMyIp->sizePolicy().hasHeightForWidth());
        pushButtonEditMyIp->setSizePolicy(sizePolicy5);

        horizontalLayout_8->addWidget(pushButtonEditMyIp);

        pushButtonDeleteMyIp = new QPushButton(page_3);
        pushButtonDeleteMyIp->setObjectName(QString::fromUtf8("pushButtonDeleteMyIp"));
        sizePolicy5.setHeightForWidth(pushButtonDeleteMyIp->sizePolicy().hasHeightForWidth());
        pushButtonDeleteMyIp->setSizePolicy(sizePolicy5);
        pushButtonDeleteMyIp->setMaximumSize(QSize(23, 16777215));

        horizontalLayout_8->addWidget(pushButtonDeleteMyIp);


        verticalLayout_5->addLayout(horizontalLayout_8);

        pushButtonSaveMyIp = new QPushButton(page_3);
        pushButtonSaveMyIp->setObjectName(QString::fromUtf8("pushButtonSaveMyIp"));
        pushButtonSaveMyIp->setEnabled(false);

        verticalLayout_5->addWidget(pushButtonSaveMyIp);

        verticalSpacer_4 = new QSpacerItem(149, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);


        horizontalLayout_13->addLayout(verticalLayout_5);

        tableViewMyIp = new QTableView(page_3);
        tableViewMyIp->setObjectName(QString::fromUtf8("tableViewMyIp"));
        tableViewMyIp->setShowGrid(false);
        tableViewMyIp->verticalHeader()->setDefaultSectionSize(19);

        horizontalLayout_13->addWidget(tableViewMyIp);


        verticalLayout_8->addLayout(horizontalLayout_13);

        frame = new QFrame(page_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelNetFilter = new QLabel(frame);
        labelNetFilter->setObjectName(QString::fromUtf8("labelNetFilter"));

        verticalLayout_4->addWidget(labelNetFilter);

        comboBoxNetFilter = new QComboBox(frame);
        comboBoxNetFilter->setObjectName(QString::fromUtf8("comboBoxNetFilter"));
        comboBoxNetFilter->setEnabled(false);

        verticalLayout_4->addWidget(comboBoxNetFilter);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        labelIpFrom = new QLabel(frame);
        labelIpFrom->setObjectName(QString::fromUtf8("labelIpFrom"));

        horizontalLayout_10->addWidget(labelIpFrom);

        lineEditIpFrom = new QLineEdit(frame);
        lineEditIpFrom->setObjectName(QString::fromUtf8("lineEditIpFrom"));
        lineEditIpFrom->setEnabled(false);
        lineEditIpFrom->setFrame(true);

        horizontalLayout_10->addWidget(lineEditIpFrom);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labelIpTo = new QLabel(frame);
        labelIpTo->setObjectName(QString::fromUtf8("labelIpTo"));

        horizontalLayout_6->addWidget(labelIpTo);

        lineEditIpTo = new QLineEdit(frame);
        lineEditIpTo->setObjectName(QString::fromUtf8("lineEditIpTo"));
        lineEditIpTo->setEnabled(false);

        horizontalLayout_6->addWidget(lineEditIpTo);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButtonAddAdress = new QPushButton(frame);
        pushButtonAddAdress->setObjectName(QString::fromUtf8("pushButtonAddAdress"));
        sizePolicy5.setHeightForWidth(pushButtonAddAdress->sizePolicy().hasHeightForWidth());
        pushButtonAddAdress->setSizePolicy(sizePolicy5);
        pushButtonAddAdress->setMinimumSize(QSize(23, 0));
        pushButtonAddAdress->setMaximumSize(QSize(23, 16777215));

        horizontalLayout_5->addWidget(pushButtonAddAdress);

        pushButtonEditAress = new QPushButton(frame);
        pushButtonEditAress->setObjectName(QString::fromUtf8("pushButtonEditAress"));
        sizePolicy5.setHeightForWidth(pushButtonEditAress->sizePolicy().hasHeightForWidth());
        pushButtonEditAress->setSizePolicy(sizePolicy5);

        horizontalLayout_5->addWidget(pushButtonEditAress);

        pushButtonDelAdress = new QPushButton(frame);
        pushButtonDelAdress->setObjectName(QString::fromUtf8("pushButtonDelAdress"));
        sizePolicy5.setHeightForWidth(pushButtonDelAdress->sizePolicy().hasHeightForWidth());
        pushButtonDelAdress->setSizePolicy(sizePolicy5);
        pushButtonDelAdress->setMinimumSize(QSize(23, 0));
        pushButtonDelAdress->setMaximumSize(QSize(23, 16777215));

        horizontalLayout_5->addWidget(pushButtonDelAdress);


        verticalLayout_4->addLayout(horizontalLayout_5);

        pushButtonSaveAress = new QPushButton(frame);
        pushButtonSaveAress->setObjectName(QString::fromUtf8("pushButtonSaveAress"));
        pushButtonSaveAress->setEnabled(false);

        verticalLayout_4->addWidget(pushButtonSaveAress);


        horizontalLayout_11->addLayout(verticalLayout_4);

        tableViewNetFilter = new QTableView(frame);
        tableViewNetFilter->setObjectName(QString::fromUtf8("tableViewNetFilter"));

        horizontalLayout_11->addWidget(tableViewNetFilter);


        verticalLayout_6->addLayout(horizontalLayout_11);


        verticalLayout_8->addWidget(frame);

        verticalSpacer_3 = new QSpacerItem(17, 9, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_3);

        stackedWidget->addWidget(page_3);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBoxExpert = new QCheckBox(MSettingsClass);
        checkBoxExpert->setObjectName(QString::fromUtf8("checkBoxExpert"));
        checkBoxExpert->setEnabled(false);

        horizontalLayout->addWidget(checkBoxExpert);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonApply = new QPushButton(MSettingsClass);
        pushButtonApply->setObjectName(QString::fromUtf8("pushButtonApply"));
        pushButtonApply->setEnabled(false);

        horizontalLayout->addWidget(pushButtonApply);

        pushButtonSave = new QPushButton(MSettingsClass);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        horizontalLayout->addWidget(pushButtonSave);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        QWidget::setTabOrder(listWidget, comboBoxStyle);
        QWidget::setTabOrder(comboBoxStyle, comboBoxLanguage);
        QWidget::setTabOrder(comboBoxLanguage, radioButtonSavePos);
        QWidget::setTabOrder(radioButtonSavePos, radioButtonCenterPos);
        QWidget::setTabOrder(radioButtonCenterPos, radioButtonRightPos);
        QWidget::setTabOrder(radioButtonRightPos, lineEditUser);
        QWidget::setTabOrder(lineEditUser, lineEditSurname);
        QWidget::setTabOrder(lineEditSurname, lineEditName);
        QWidget::setTabOrder(lineEditName, lineEditPatronymic);
        QWidget::setTabOrder(lineEditPatronymic, lineEditPost);
        QWidget::setTabOrder(lineEditPost, pushButtonPath);
        QWidget::setTabOrder(pushButtonPath, pushButtonPlay);
        QWidget::setTabOrder(pushButtonPlay, checkBoxOnLineClient);
        QWidget::setTabOrder(checkBoxOnLineClient, checkBoxOffLineClient);
        QWidget::setTabOrder(checkBoxOffLineClient, checkBoxNewMessageCloseForm);
        QWidget::setTabOrder(checkBoxNewMessageCloseForm, checkBoxNewMessageOpenForm);
        QWidget::setTabOrder(checkBoxNewMessageOpenForm, spinBoxNumberPort);
        QWidget::setTabOrder(spinBoxNumberPort, pushButtonAddMyIp);
        QWidget::setTabOrder(pushButtonAddMyIp, pushButtonEditMyIp);
        QWidget::setTabOrder(pushButtonEditMyIp, pushButtonDeleteMyIp);
        QWidget::setTabOrder(pushButtonDeleteMyIp, checkBoxMyIp);
        QWidget::setTabOrder(checkBoxMyIp, lineEditMyIp);
        QWidget::setTabOrder(lineEditMyIp, pushButtonSaveMyIp);
        QWidget::setTabOrder(pushButtonSaveMyIp, pushButtonAddAdress);
        QWidget::setTabOrder(pushButtonAddAdress, pushButtonEditAress);
        QWidget::setTabOrder(pushButtonEditAress, pushButtonDelAdress);
        QWidget::setTabOrder(pushButtonDelAdress, comboBoxNetFilter);
        QWidget::setTabOrder(comboBoxNetFilter, lineEditIpFrom);
        QWidget::setTabOrder(lineEditIpFrom, lineEditIpTo);
        QWidget::setTabOrder(lineEditIpTo, pushButtonSaveAress);
        QWidget::setTabOrder(pushButtonSaveAress, pushButtonApply);
        QWidget::setTabOrder(pushButtonApply, pushButtonSave);
        QWidget::setTabOrder(pushButtonSave, graphicsView);
        QWidget::setTabOrder(graphicsView, treeViewSounds);
        QWidget::setTabOrder(treeViewSounds, lineEditEvent);
        QWidget::setTabOrder(lineEditEvent, lineEditPathSounds);
        QWidget::setTabOrder(lineEditPathSounds, tableViewNetFilter);
        QWidget::setTabOrder(tableViewNetFilter, checkBoxExpert);
        QWidget::setTabOrder(checkBoxExpert, tableViewMyIp);

        retranslateUi(MSettingsClass);
        QObject::connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(checkBoxExpert, SIGNAL(clicked(bool)), frame, SLOT(setVisible(bool)));

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MSettingsClass);
    } // setupUi

    void retranslateUi(QDialog *MSettingsClass)
    {
        MSettingsClass->setWindowTitle(QApplication::translate("MSettingsClass", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MSettingsClass", "\320\223\320\273\320\260\320\262\320\275\321\213\320\265", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MSettingsClass", "\320\243\321\207\320\265\321\202\320\275\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MSettingsClass", "\320\243\320\262\320\265\320\264\320\276\320\274\320\273\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MSettingsClass", "\320\241\320\265\321\202\321\214", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

        labelStyle->setText(QApplication::translate("MSettingsClass", "\320\241\321\202\320\270\320\273\321\214", 0, QApplication::UnicodeUTF8));
        comboBoxStyle->clear();
        comboBoxStyle->insertItems(0, QStringList()
         << QApplication::translate("MSettingsClass", "\320\241\320\270\321\201\321\202\320\265\320\274\320\275\321\213\320\271", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MSettingsClass", "Plastique", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MSettingsClass", "Cleanlooks", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MSettingsClass", "Windows", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MSettingsClass", "CDE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MSettingsClass", "Common", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MSettingsClass", "Gtk", 0, QApplication::UnicodeUTF8)
        );
        labelLanguage->setText(QApplication::translate("MSettingsClass", "\320\257\320\267\321\213\320\272", 0, QApplication::UnicodeUTF8));
        comboBoxLanguage->clear();
        comboBoxLanguage->insertItems(0, QStringList()
         << QApplication::translate("MSettingsClass", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MSettingsClass", "English", 0, QApplication::UnicodeUTF8)
        );
        radioButtonSavePos->setText(QApplication::translate("MSettingsClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\277\320\276\320\267\320\270\321\206\320\270\321\216", 0, QApplication::UnicodeUTF8));
        radioButtonCenterPos->setText(QApplication::translate("MSettingsClass", "\320\237\320\276 \321\206\320\265\320\275\321\202\321\200\321\203", 0, QApplication::UnicodeUTF8));
        radioButtonRightPos->setText(QApplication::translate("MSettingsClass", "\320\237\320\276 \320\277\321\200\320\260\320\262\320\276\320\274\321\203 \320\272\321\200\320\260\321\216", 0, QApplication::UnicodeUTF8));
        labelUser->setText(QApplication::translate("MSettingsClass", "\320\235\320\270\320\272", 0, QApplication::UnicodeUTF8));
        labelSurname->setText(QApplication::translate("MSettingsClass", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", 0, QApplication::UnicodeUTF8));
        labelName->setText(QApplication::translate("MSettingsClass", "\320\230\320\274\321\217", 0, QApplication::UnicodeUTF8));
        labelPatronymic->setText(QApplication::translate("MSettingsClass", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", 0, QApplication::UnicodeUTF8));
        labelPost->setText(QApplication::translate("MSettingsClass", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MSettingsClass", "\320\227\320\262\321\203\320\272\320\276\320\262\321\213\320\265 \321\203\320\262\320\265\320\264\320\276\320\274\320\273\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        labelEvent->setText(QApplication::translate("MSettingsClass", "\320\241\320\276\320\261\321\213\321\202\320\270\320\265", 0, QApplication::UnicodeUTF8));
        labelPath->setText(QApplication::translate("MSettingsClass", "\320\237\321\203\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonPath->setText(QApplication::translate("MSettingsClass", "...", 0, QApplication::UnicodeUTF8));
        pushButtonPlay->setText(QString());
        pushButtonClearSounds->setText(QString());
        labelPopMessage->setText(QApplication::translate("MSettingsClass", "\320\222\321\201\320\277\320\273\321\213\320\262\320\260\321\216\321\211\320\270\320\265 \321\203\320\262\320\265\320\264\320\276\320\274\320\273\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        checkBoxOnLineClient->setText(QApplication::translate("MSettingsClass", "\320\232\320\276\320\275\321\202\320\260\320\272\321\202 \320\262\320\276\321\210\320\265\320\273", 0, QApplication::UnicodeUTF8));
        checkBoxOffLineClient->setText(QApplication::translate("MSettingsClass", "\320\232\320\276\320\275\321\202\320\260\320\272\321\202 \320\262\321\213\321\210\320\265\320\273", 0, QApplication::UnicodeUTF8));
        checkBoxNewMessageCloseForm->setText(QApplication::translate("MSettingsClass", "\320\222\321\205\320\276\320\264\321\217\321\211\320\265\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 (\320\276\320\272\320\275\320\276 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\271 \320\267\320\260\320\272\321\200\321\213\321\202\320\276)", 0, QApplication::UnicodeUTF8));
        checkBoxNewMessageOpenForm->setText(QApplication::translate("MSettingsClass", "\320\222\321\205\320\276\320\264\321\217\321\211\320\265\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 (\320\276\320\272\320\275\320\276 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\271 \320\276\321\202\320\272\321\200\321\213\321\202\320\276)", 0, QApplication::UnicodeUTF8));
        labelNumberPort->setText(QApplication::translate("MSettingsClass", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\276\321\200\321\202\320\260", 0, QApplication::UnicodeUTF8));
        labelInquiryStatus->setText(QApplication::translate("MSettingsClass", "\320\227\320\260\320\277\321\200\320\276\321\201 \321\201\321\202\320\260\321\202\321\203\321\201\320\260 \320\272\320\260\320\266\320\264\321\213\320\265", 0, QApplication::UnicodeUTF8));
        labelInquiryStatusSec->setText(QApplication::translate("MSettingsClass", "\321\201\320\265\320\272.", 0, QApplication::UnicodeUTF8));
        labelMyIp->setText(QApplication::translate("MSettingsClass", "\320\241\320\262\320\276\320\271 \320\260\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
        checkBoxMyIp->setText(QApplication::translate("MSettingsClass", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        lineEditMyIp->setInputMask(QApplication::translate("MSettingsClass", "000.000.000.000; ", 0, QApplication::UnicodeUTF8));
        lineEditMyIp->setText(QApplication::translate("MSettingsClass", "255.255.255.255", 0, QApplication::UnicodeUTF8));
        pushButtonAddMyIp->setText(QApplication::translate("MSettingsClass", "+", 0, QApplication::UnicodeUTF8));
        pushButtonEditMyIp->setText(QApplication::translate("MSettingsClass", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonDeleteMyIp->setText(QApplication::translate("MSettingsClass", "-", 0, QApplication::UnicodeUTF8));
        pushButtonSaveMyIp->setText(QApplication::translate("MSettingsClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        labelNetFilter->setText(QApplication::translate("MSettingsClass", "\320\241\320\265\321\202\320\265\320\262\320\276\320\271 \321\204\320\270\320\273\321\214\321\202\321\200", 0, QApplication::UnicodeUTF8));
        comboBoxNetFilter->clear();
        comboBoxNetFilter->insertItems(0, QStringList()
         << QApplication::translate("MSettingsClass", "\320\227\320\260\320\277\321\200\320\265\321\202\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MSettingsClass", "\320\240\320\260\320\267\321\200\320\265\321\210\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8)
        );
        labelIpFrom->setText(QApplication::translate("MSettingsClass", "\320\236\321\202", 0, QApplication::UnicodeUTF8));
        lineEditIpFrom->setInputMask(QApplication::translate("MSettingsClass", "000.000.000.000; ", 0, QApplication::UnicodeUTF8));
        lineEditIpFrom->setText(QApplication::translate("MSettingsClass", "255.255.255.255", 0, QApplication::UnicodeUTF8));
        labelIpTo->setText(QApplication::translate("MSettingsClass", "\320\224\320\276", 0, QApplication::UnicodeUTF8));
        lineEditIpTo->setInputMask(QApplication::translate("MSettingsClass", "000.000.000.000; ", 0, QApplication::UnicodeUTF8));
        lineEditIpTo->setText(QApplication::translate("MSettingsClass", "255.255.255.255", 0, QApplication::UnicodeUTF8));
        pushButtonAddAdress->setText(QApplication::translate("MSettingsClass", "+", 0, QApplication::UnicodeUTF8));
        pushButtonEditAress->setText(QApplication::translate("MSettingsClass", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonDelAdress->setText(QApplication::translate("MSettingsClass", "-", 0, QApplication::UnicodeUTF8));
        pushButtonSaveAress->setText(QApplication::translate("MSettingsClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        checkBoxExpert->setText(QApplication::translate("MSettingsClass", "\320\255\320\272\321\201\320\277\320\265\321\200\321\202", 0, QApplication::UnicodeUTF8));
        pushButtonApply->setText(QApplication::translate("MSettingsClass", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonSave->setText(QApplication::translate("MSettingsClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MSettingsClass: public Ui_MSettingsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSETTINGS_H
