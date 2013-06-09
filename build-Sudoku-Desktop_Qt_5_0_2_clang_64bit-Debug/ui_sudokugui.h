/********************************************************************************
** Form generated from reading UI file 'sudokugui.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKUGUI_H
#define UI_SUDOKUGUI_H

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

class Ui_SudokuGUI
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SudokuGUI)
    {
        if (SudokuGUI->objectName().isEmpty())
            SudokuGUI->setObjectName(QStringLiteral("SudokuGUI"));
        SudokuGUI->resize(400, 300);
        menuBar = new QMenuBar(SudokuGUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SudokuGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SudokuGUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SudokuGUI->addToolBar(mainToolBar);
        centralWidget = new QWidget(SudokuGUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SudokuGUI->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SudokuGUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SudokuGUI->setStatusBar(statusBar);

        retranslateUi(SudokuGUI);

        QMetaObject::connectSlotsByName(SudokuGUI);
    } // setupUi

    void retranslateUi(QMainWindow *SudokuGUI)
    {
        SudokuGUI->setWindowTitle(QApplication::translate("SudokuGUI", "SudokuGUI", 0));
    } // retranslateUi

};

namespace Ui {
    class SudokuGUI: public Ui_SudokuGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUGUI_H
