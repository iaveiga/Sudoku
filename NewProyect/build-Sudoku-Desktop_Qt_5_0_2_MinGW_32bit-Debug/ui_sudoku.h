/********************************************************************************
** Form generated from reading UI file 'sudoku.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKU_H
#define UI_SUDOKU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sudoku
{
public:
    QAction *actionGuadar_Partida;
    QAction *action;
    QAction *actionSalir;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *tablet;
    QLabel *label;
    QPushButton *btn_Chequear;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Sudoku)
    {
        if (Sudoku->objectName().isEmpty())
            Sudoku->setObjectName(QStringLiteral("Sudoku"));
        Sudoku->resize(500, 457);
        Sudoku->setAutoFillBackground(false);
        actionGuadar_Partida = new QAction(Sudoku);
        actionGuadar_Partida->setObjectName(QStringLiteral("actionGuadar_Partida"));
        action = new QAction(Sudoku);
        action->setObjectName(QStringLiteral("action"));
        actionSalir = new QAction(Sudoku);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        centralWidget = new QWidget(Sudoku);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 471, 331));
        tablet = new QGridLayout(gridLayoutWidget);
        tablet->setSpacing(6);
        tablet->setContentsMargins(11, 11, 11, 11);
        tablet->setObjectName(QStringLiteral("tablet"));
        tablet->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 360, 61, 21));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        btn_Chequear = new QPushButton(centralWidget);
        btn_Chequear->setObjectName(QStringLiteral("btn_Chequear"));
        btn_Chequear->setGeometry(QRect(330, 360, 75, 23));
        Sudoku->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Sudoku);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        Sudoku->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Sudoku);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Sudoku->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Sudoku);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Sudoku->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionGuadar_Partida);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);

        retranslateUi(Sudoku);

        QMetaObject::connectSlotsByName(Sudoku);
    } // setupUi

    void retranslateUi(QMainWindow *Sudoku)
    {
        Sudoku->setWindowTitle(QApplication::translate("Sudoku", "Sudoku", 0));
        actionGuadar_Partida->setText(QApplication::translate("Sudoku", "Guadar Partida", 0));
        action->setText(QApplication::translate("Sudoku", "_", 0));
        actionSalir->setText(QApplication::translate("Sudoku", "Salir", 0));
        label->setText(QApplication::translate("Sudoku", "Tiempo :", 0));
        btn_Chequear->setText(QApplication::translate("Sudoku", "Chequear", 0));
        menuArchivo->setTitle(QApplication::translate("Sudoku", "Archivo", 0));
    } // retranslateUi

};

namespace Ui {
    class Sudoku: public Ui_Sudoku {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKU_H
