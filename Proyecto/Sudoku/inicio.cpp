#include "inicio.h"
#include "mainwindow.h"
#include "time.h"
#include "stdlib.h"
#include "ui_inicio.h"
#include <QMessageBox>

Inicio::Inicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inicio)
{
    /**
    *   @brief constructor de la clase inicio
    *   @author Kevin Campuzano
    */
    ui->setupUi(this);
    connect(ui->btn_Salir,SIGNAL(clicked()),this,SLOT(cerrarVentana()));
    connect(ui->btn_jugar,SIGNAL(clicked()),this,SLOT(sudoku_play()));
}

void Inicio::cerrarVentana()
{
    /**
    *   @brief cierra la ventana.
    *   @author Kevin Campuzano
    */
    this->close();
}

void Inicio::sudoku_play()
{
    /**
    *   @brief Valida las opciones de juego en la ventana de inicio
    *   @author Kevin Campuzano
    */

    QMessageBox mensajeenBox;
    MainWindow *h;
    QString nom;



    bool chequeartodoafuera = ui->rbt_facil->isChecked()| ui->rbt_normal->isChecked() | ui->rbt_azanzado->isChecked() | ui->rbt_experto->isChecked();
    if(chequeartodoafuera == false){
        mensajeenBox.setText("No ha Ingresado el nivel de dificultad o el nombre del usuario");
     }
    else if(ui->rbt_facil->isChecked()){
        this->setVisible(false);
        h = new MainWindow();
        srand(time(NULL));
        h->ComienzaCronometro();
        h->loadLE(1,ui->txt_nombre->text());
        h->show();
    }
    else if(ui->rbt_normal->isChecked()){
        this->setVisible(false);
        h = new MainWindow();
        srand(time(NULL));
        h->ComienzaCronometro();
        h->loadLE(2,ui->txt_nombre->text());
        h->show();
    }
    else if(ui->rbt_azanzado->isChecked()){
        this->setVisible(false);
        h = new MainWindow();
        srand(time(NULL));
        h->ComienzaCronometro();
        h->loadLE(3,ui->txt_nombre->text());
        h->show();
    }
    else{
        this->setVisible(false);
        h = new MainWindow();
        srand(time(NULL));
        h->ComienzaCronometro();
        h->loadLE(4,ui->txt_nombre->text());
        h->show();
    }
}
Inicio::~Inicio()
{
    delete ui;
}
