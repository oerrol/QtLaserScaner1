/********************************************************************************
** Form generated from reading UI file 'QtLaserScaner.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTLASERSCANER_H
#define UI_QTLASERSCANER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtLaserScanerClass
{
public:
    QAction *action_about;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Set;
    QMenu *menu;
    QToolBar *toolBar;

    void setupUi(QMainWindow *QtLaserScanerClass)
    {
        if (QtLaserScanerClass->objectName().isEmpty())
            QtLaserScanerClass->setObjectName(QString::fromUtf8("QtLaserScanerClass"));
        QtLaserScanerClass->resize(805, 564);
        action_about = new QAction(QtLaserScanerClass);
        action_about->setObjectName(QString::fromUtf8("action_about"));
        centralWidget = new QWidget(QtLaserScanerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtLaserScanerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtLaserScanerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtLaserScanerClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(QtLaserScanerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 805, 26));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Set = new QMenu(menuBar);
        menu_Set->setObjectName(QString::fromUtf8("menu_Set"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        QtLaserScanerClass->setMenuBar(menuBar);
        toolBar = new QToolBar(QtLaserScanerClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QtLaserScanerClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Set->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addAction(action_about);

        retranslateUi(QtLaserScanerClass);

        QMetaObject::connectSlotsByName(QtLaserScanerClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtLaserScanerClass)
    {
        QtLaserScanerClass->setWindowTitle(QApplication::translate("QtLaserScanerClass", "QtLaserScaner", nullptr));
        action_about->setText(QApplication::translate("QtLaserScanerClass", "\345\205\263\344\272\216", nullptr));
        menu_File->setTitle(QApplication::translate("QtLaserScanerClass", "\346\226\207\344\273\266", nullptr));
        menu_Set->setTitle(QApplication::translate("QtLaserScanerClass", "\350\256\276\347\275\256", nullptr));
        menu->setTitle(QApplication::translate("QtLaserScanerClass", "\345\270\256\345\212\251", nullptr));
        toolBar->setWindowTitle(QApplication::translate("QtLaserScanerClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtLaserScanerClass: public Ui_QtLaserScanerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTLASERSCANER_H
