/********************************************************************************
** Form generated from reading UI file 'game_window.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_WINDOW_H
#define UI_GAME_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game_windowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *game_windowClass)
    {
        if (game_windowClass->objectName().isEmpty())
            game_windowClass->setObjectName(QStringLiteral("game_windowClass"));
        game_windowClass->resize(600, 400);
        menuBar = new QMenuBar(game_windowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        game_windowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(game_windowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        game_windowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(game_windowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        game_windowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(game_windowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        game_windowClass->setStatusBar(statusBar);

        retranslateUi(game_windowClass);

        QMetaObject::connectSlotsByName(game_windowClass);
    } // setupUi

    void retranslateUi(QMainWindow *game_windowClass)
    {
        game_windowClass->setWindowTitle(QApplication::translate("game_windowClass", "game_window", 0));
    } // retranslateUi

};

namespace Ui {
    class game_windowClass: public Ui_game_windowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_WINDOW_H
