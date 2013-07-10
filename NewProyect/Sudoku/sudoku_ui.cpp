#include "sudoku_ui.h"
#include "ui_sudoku.h"
#include <QGridLayout>
#include<QPushButton>

Sudoku::Sudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sudoku_ui)
  /*
   *Constructor
   *Se inicia Constructor con 81 celdas que
   *se utilizaran para el tablero.
   *@autor Kevin Campuzano
   *@param las filas trabajaran como int i
   *@param las columnas trabajaran como int j
   *@param las Celdas del tablero seran QtextEdit
   */

{
    ui->setupUi(this);
    initTablero();

    //Hace visible al Tablero
    sudok = new Sudok();
    connect(sudok,&sudok::,this,&Sudoku_ui::CambioValorCelda);

}

Sudoku_ui::~Sudoku_ui()
{
    delete ui;
}
