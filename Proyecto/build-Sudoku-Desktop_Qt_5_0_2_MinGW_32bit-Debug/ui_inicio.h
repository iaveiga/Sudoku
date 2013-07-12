/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Inicio
{
public:
    QPushButton *btn_jugar;
    QPushButton *btn_Salir;
    QRadioButton *rbt_facil;
    QRadioButton *rbt_normal;
    QRadioButton *rbt_azanzado;
    QLabel *lbl_Dificultad;
    QRadioButton *rbt_experto;
    QLabel *label;
    QLineEdit *txt_nombre;

    void setupUi(QDialog *Inicio)
    {
        if (Inicio->objectName().isEmpty())
            Inicio->setObjectName(QStringLiteral("Inicio"));
        Inicio->resize(337, 203);
        btn_jugar = new QPushButton(Inicio);
        btn_jugar->setObjectName(QStringLiteral("btn_jugar"));
        btn_jugar->setGeometry(QRect(130, 110, 75, 23));
        btn_Salir = new QPushButton(Inicio);
        btn_Salir->setObjectName(QStringLiteral("btn_Salir"));
        btn_Salir->setGeometry(QRect(130, 140, 75, 23));
        rbt_facil = new QRadioButton(Inicio);
        rbt_facil->setObjectName(QStringLiteral("rbt_facil"));
        rbt_facil->setGeometry(QRect(30, 80, 43, 17));
        rbt_normal = new QRadioButton(Inicio);
        rbt_normal->setObjectName(QStringLiteral("rbt_normal"));
        rbt_normal->setGeometry(QRect(90, 80, 56, 17));
        rbt_azanzado = new QRadioButton(Inicio);
        rbt_azanzado->setObjectName(QStringLiteral("rbt_azanzado"));
        rbt_azanzado->setGeometry(QRect(150, 80, 81, 17));
        lbl_Dificultad = new QLabel(Inicio);
        lbl_Dificultad->setObjectName(QStringLiteral("lbl_Dificultad"));
        lbl_Dificultad->setGeometry(QRect(20, 60, 46, 13));
        rbt_experto = new QRadioButton(Inicio);
        rbt_experto->setObjectName(QStringLiteral("rbt_experto"));
        rbt_experto->setGeometry(QRect(230, 80, 58, 17));
        label = new QLabel(Inicio);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 46, 13));
        txt_nombre = new QLineEdit(Inicio);
        txt_nombre->setObjectName(QStringLiteral("txt_nombre"));
        txt_nombre->setGeometry(QRect(20, 30, 281, 20));

        retranslateUi(Inicio);

        QMetaObject::connectSlotsByName(Inicio);
    } // setupUi

    void retranslateUi(QDialog *Inicio)
    {
        Inicio->setWindowTitle(QApplication::translate("Inicio", "Sudoku 0.3", 0));
        btn_jugar->setText(QApplication::translate("Inicio", "Jugar", 0));
        btn_Salir->setText(QApplication::translate("Inicio", "Salir", 0));
        rbt_facil->setText(QApplication::translate("Inicio", "Facil", 0));
        rbt_normal->setText(QApplication::translate("Inicio", "Normal", 0));
        rbt_azanzado->setText(QApplication::translate("Inicio", "Avanzado", 0));
        lbl_Dificultad->setText(QApplication::translate("Inicio", "Dificultad:", 0));
        rbt_experto->setText(QApplication::translate("Inicio", "Experto", 0));
        label->setText(QApplication::translate("Inicio", "Nombre:", 0));
    } // retranslateUi

};

namespace Ui {
    class Inicio: public Ui_Inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
