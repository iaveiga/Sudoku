#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{

private:
    Sudoku();
    Cell matriz[9][9];

public:
    Cell();

    //Retorna verdadero si el valor de c existe más de una vez en la fila
    bool checkRow(Cell c);

    //Retorna verdadero si el valor de c existe más de una vez en la columna
    bool checkCol(Cell c);

    //Parcialmente implementado
    Cell checkAll[]();

    //Carga un sudoku resuelto correctamente desde un archivo de texto para revisarlo con el método checkAll
    void loadSudoku();

};

#endif // SUDOKU_H
