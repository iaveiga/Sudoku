#ifndef SUDOKU_H
#define SUDOKU_H
#include "Cell.h"

using namespace std;

class Sudoku
{

private:
    Sudoku();

    Cell centros[9];
public:

    Cell matriz[9][9];
    //Retorna verdadero si el valor de c existe más de una vez en la fila
    list<Cell> checkCol(Cell c);

    list<Cell> checkRow(Cell c);
    //Parcialmente implementado
    list<Cell> checkAll;

    //Carga un sudoku resuelto correctamente desde un archivo de texto para revisarlo con el método checkAll
    void loadSudoku();

    Cell getCenter(Cell c);

    void initializeCenters();

    void mergeLists (list<Cell> A, list<Cell> B);
};

#endif // SUDOKU_H
