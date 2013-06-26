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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sudoku
{
public:
    QAction *actionNuevo;
    QAction *actionSalir;
    QAction *actionCreadores;
    QAction *actionSudoku_Qt_Creator;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_3;
    QVBoxLayout *verticalLayout_6;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuAyuda;
    QMenu *menuAcerca_de;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Sudoku)
    {
        if (Sudoku->objectName().isEmpty())
            Sudoku->setObjectName(QStringLiteral("Sudoku"));
        Sudoku->setEnabled(true);
        Sudoku->resize(659, 532);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(240, 212, 125, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 251, 238, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(247, 231, 181, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(120, 106, 62, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(160, 141, 83, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(247, 233, 190, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Sudoku->setPalette(palette);
        Sudoku->setWindowOpacity(0);
        Sudoku->setAnimated(true);
        actionNuevo = new QAction(Sudoku);
        actionNuevo->setObjectName(QStringLiteral("actionNuevo"));
        actionSalir = new QAction(Sudoku);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionCreadores = new QAction(Sudoku);
        actionCreadores->setObjectName(QStringLiteral("actionCreadores"));
        actionSudoku_Qt_Creator = new QAction(Sudoku);
        actionSudoku_Qt_Creator->setObjectName(QStringLiteral("actionSudoku_Qt_Creator"));
        centralWidget = new QWidget(Sudoku);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(480, 80, 111, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoFillBackground(true);

        verticalLayout->addWidget(pushButton_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        verticalLayout->addLayout(verticalLayout_5);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));

        verticalLayout->addLayout(verticalLayout_6);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 80, 381, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(280, 10, 160, 41));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(60, 10, 181, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        Sudoku->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Sudoku);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 659, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        menuAcerca_de = new QMenu(menuBar);
        menuAcerca_de->setObjectName(QStringLiteral("menuAcerca_de"));
        Sudoku->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Sudoku);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Sudoku->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Sudoku);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Sudoku->setStatusBar(statusBar);
        toolBar = new QToolBar(Sudoku);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        Sudoku->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuBar->addAction(menuAcerca_de->menuAction());
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionNuevo);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);
        menuAcerca_de->addAction(actionCreadores);
        menuAcerca_de->addAction(actionSudoku_Qt_Creator);

        retranslateUi(Sudoku);

        QMetaObject::connectSlotsByName(Sudoku);
    } // setupUi

    void retranslateUi(QMainWindow *Sudoku)
    {
        Sudoku->setWindowTitle(QApplication::translate("Sudoku", "Sudoku", 0));
        actionNuevo->setText(QApplication::translate("Sudoku", "Nuevo", 0));
        actionSalir->setText(QApplication::translate("Sudoku", "Salir", 0));
        actionCreadores->setText(QApplication::translate("Sudoku", "Creadores", 0));
        actionSudoku_Qt_Creator->setText(QApplication::translate("Sudoku", "Sudoku Qt Creator", 0));
        pushButton->setText(QApplication::translate("Sudoku", "Verificar", 0));
        pushButton_2->setText(QApplication::translate("Sudoku", "Solucion", 0));
        pushButton_3->setText(QApplication::translate("Sudoku", "Salir", 0));
        label->setText(QApplication::translate("Sudoku", "Tiempo:", 0));
        label_2->setText(QApplication::translate("Sudoku", "00:00", 0));
        menuArchivo->setTitle(QApplication::translate("Sudoku", "Archivo", 0));
        menuAyuda->setTitle(QApplication::translate("Sudoku", "Ayuda", 0));
        menuAcerca_de->setTitle(QApplication::translate("Sudoku", "Acerca de...", 0));
        toolBar->setWindowTitle(QApplication::translate("Sudoku", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class Sudoku: public Ui_Sudoku {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUGUI_H
