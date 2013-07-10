#include "inicio.h"
#include "ui_inicio.h"
#include "sudoku_ui.h"

Inicio::Inicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);
}


void jugar_clicked()
{
    Sudoku_ui *su;//Esto hace referencia a la ventana Sudoku para empezar a jugar
    su = new Sudoku_ui();
    bool isnotCheck = Ui_Inicio.rbt_intermedio->isChecked() | Ui_Inicio->rbt_intermedio->isChecked() | Ui_Inicio->rbt_facil->isChecked();
          if(isnotCheck == false){
              this->setVisible(false);
              su->show();
              su->dificultad=0;
          }
          else if (Ui_Inicio.rbt_intermedio->isChecked()){
               this->setVisible(false);
               su->show();
               su->dificultad=1;
          }
          else{
               this->setVisible(false);
               su->show();
               su->dificultad=2;
          }
    su->show();
    this->setVisible(false);
}

void salir_clicked()
{
    this.close();
}
Inicio::~Inicio()
{
    delete ui;
}

