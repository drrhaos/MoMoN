/********************************************************************************
** Form generated from reading UI file 'mcreateuser.ui'
**
** Created: Mon 19. Mar 11:14:46 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MCREATEUSER_H
#define UI_MCREATEUSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mCreateUserClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelNumberPort_2;
    QSpinBox *spinBoxNumberPort;
    QHBoxLayout *horizontalLayout_4;
    QGraphicsView *graphicsView;
    QGridLayout *gridLayout;
    QLabel *labelSurname;
    QLineEdit *lineEditSurname;
    QLabel *labelUser;
    QLineEdit *lineEditUser;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelPatronymic;
    QLineEdit *lineEditPatronymic;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelPost;
    QLineEdit *lineEditPost;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonSave;

    void setupUi(QWidget *mCreateUserClass)
    {
        if (mCreateUserClass->objectName().isEmpty())
            mCreateUserClass->setObjectName(QString::fromUtf8("mCreateUserClass"));
        mCreateUserClass->setWindowModality(Qt::NonModal);
        mCreateUserClass->resize(335, 231);
        mCreateUserClass->setMaximumSize(QSize(335, 231));
        verticalLayout = new QVBoxLayout(mCreateUserClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelNumberPort_2 = new QLabel(mCreateUserClass);
        labelNumberPort_2->setObjectName(QString::fromUtf8("labelNumberPort_2"));

        horizontalLayout->addWidget(labelNumberPort_2);

        spinBoxNumberPort = new QSpinBox(mCreateUserClass);
        spinBoxNumberPort->setObjectName(QString::fromUtf8("spinBoxNumberPort"));
        spinBoxNumberPort->setMaximum(999999);
        spinBoxNumberPort->setValue(2323);

        horizontalLayout->addWidget(spinBoxNumberPort);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        graphicsView = new QGraphicsView(mCreateUserClass);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(90, 120));
        graphicsView->setMaximumSize(QSize(90, 120));

        horizontalLayout_4->addWidget(graphicsView);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelSurname = new QLabel(mCreateUserClass);
        labelSurname->setObjectName(QString::fromUtf8("labelSurname"));

        gridLayout->addWidget(labelSurname, 1, 0, 1, 1);

        lineEditSurname = new QLineEdit(mCreateUserClass);
        lineEditSurname->setObjectName(QString::fromUtf8("lineEditSurname"));

        gridLayout->addWidget(lineEditSurname, 1, 1, 1, 1);

        labelUser = new QLabel(mCreateUserClass);
        labelUser->setObjectName(QString::fromUtf8("labelUser"));

        gridLayout->addWidget(labelUser, 0, 0, 1, 1);

        lineEditUser = new QLineEdit(mCreateUserClass);
        lineEditUser->setObjectName(QString::fromUtf8("lineEditUser"));

        gridLayout->addWidget(lineEditUser, 0, 1, 1, 1);

        labelName = new QLabel(mCreateUserClass);
        labelName->setObjectName(QString::fromUtf8("labelName"));

        gridLayout->addWidget(labelName, 2, 0, 1, 1);

        lineEditName = new QLineEdit(mCreateUserClass);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        gridLayout->addWidget(lineEditName, 2, 1, 1, 1);

        labelPatronymic = new QLabel(mCreateUserClass);
        labelPatronymic->setObjectName(QString::fromUtf8("labelPatronymic"));

        gridLayout->addWidget(labelPatronymic, 3, 0, 1, 1);

        lineEditPatronymic = new QLineEdit(mCreateUserClass);
        lineEditPatronymic->setObjectName(QString::fromUtf8("lineEditPatronymic"));

        gridLayout->addWidget(lineEditPatronymic, 3, 1, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelPost = new QLabel(mCreateUserClass);
        labelPost->setObjectName(QString::fromUtf8("labelPost"));

        horizontalLayout_3->addWidget(labelPost);

        lineEditPost = new QLineEdit(mCreateUserClass);
        lineEditPost->setObjectName(QString::fromUtf8("lineEditPost"));

        horizontalLayout_3->addWidget(lineEditPost);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButtonSave = new QPushButton(mCreateUserClass);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setEnabled(false);

        horizontalLayout_2->addWidget(pushButtonSave);


        verticalLayout->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(spinBoxNumberPort, lineEditUser);
        QWidget::setTabOrder(lineEditUser, lineEditSurname);
        QWidget::setTabOrder(lineEditSurname, lineEditName);
        QWidget::setTabOrder(lineEditName, lineEditPatronymic);
        QWidget::setTabOrder(lineEditPatronymic, lineEditPost);
        QWidget::setTabOrder(lineEditPost, pushButtonSave);
        QWidget::setTabOrder(pushButtonSave, graphicsView);

        retranslateUi(mCreateUserClass);

        QMetaObject::connectSlotsByName(mCreateUserClass);
    } // setupUi

    void retranslateUi(QWidget *mCreateUserClass)
    {
        labelNumberPort_2->setText(QApplication::translate("mCreateUserClass", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\276\321\200\321\202\320\260", 0, QApplication::UnicodeUTF8));
        labelSurname->setText(QApplication::translate("mCreateUserClass", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", 0, QApplication::UnicodeUTF8));
        labelUser->setText(QApplication::translate("mCreateUserClass", "\320\235\320\270\320\272", 0, QApplication::UnicodeUTF8));
        labelName->setText(QApplication::translate("mCreateUserClass", "\320\230\320\274\321\217", 0, QApplication::UnicodeUTF8));
        labelPatronymic->setText(QApplication::translate("mCreateUserClass", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", 0, QApplication::UnicodeUTF8));
        labelPost->setText(QApplication::translate("mCreateUserClass", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonSave->setText(QApplication::translate("mCreateUserClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(mCreateUserClass);
    } // retranslateUi

};

namespace Ui {
    class mCreateUserClass: public Ui_mCreateUserClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MCREATEUSER_H
