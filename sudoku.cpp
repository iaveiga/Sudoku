#include "sudoku.h"
#include <fstream.h>
#include <list>

using namespace std;

//Constructor
Sudoku::Sudoku()
{
    for(int i = 0; i <9 ; i++)
    {
        for(int j = 0; j <9 ; j++)
        {
            matriz[i][j]->setValue = -1 ;
            matriz[i][j]->setX = i;
            matriz[i][j]->setY = j;
        }
    }
}

//Carga un sudoku resuelto correctamente desde un archivo de texto para revisarlo con el método checkAll
void Sudoku:: loadSudoku()
{
    ifstream archivo;
    archivo.open("/sudoku.txt",ios::in);
    int i,j;
    for(i = 0; i< 9; i++)
    {
        for(j=0; j<9 ; j++)
        {
            archivo>> matriz[i][j] ->setValue ;
        }

    }
}

//Retorna una lista de celdas erroneas, si el valor de c existe más de una vez en la fila
list<Cell> Sudoku::checkRow(Cell c)
{
    list<Cell> listaErroneaRow;
    int i = c->getX();
    for(int j = 0; j < 9; j++)
    {
        if(matriz[i][j]->getValue() == c->getValue())
            listaErroneaRow.push_back(c);
     }
    return listaErronea;
}

//Retorna una lista de celdas erroneas, si el valor de c existe más de una vez en la columna
list<Cell> Sudoku::checkCol(Cell c)
{
    list<Cell> listaErroneaCol;
    int j = c->getY();
    for(int i = 0; i<9; i++)
    {
        if(matriz[i][j]->getValue() == c->getValue())
            listaErroneaCol.push_back(c);
    }
    return listaErroneaCol;

}

//Parcialmente implementado
Cell Sudoku::checkAll[](list<Cell> R, list<Cell> C)
{
    list<Cell>::iterator itr = R.begin();
    list<Cell>::iterator itc = C.begin();

    while(R.isempty() || C.isempty()){
        Cell error[81];
        return error;
    }
}
