#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{

private:
    Sudoku();
    Cell matriz[9][9];
    Cell centros[9]  ;
public:
    Cell();

    //Retorna verdadero si el valor de c existe más de una vez en la fila
    list<Cell> checkCol(Cell c);

    list<Cell> checkRow(Cell c);

    //Parcialmente implementado
    Cell checkAll[]();

    //Carga un sudoku resuelto correctamente desde un archivo de texto para revisarlo con el método checkAll
    void loadSudoku();

    Cell getCenter(Cell c);

    void initializeCenters();
};

#endif // SUDOKU_H
