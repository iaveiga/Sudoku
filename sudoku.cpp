#include "sudoku.h"
#include <fstream.h>

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

//Retorna verdadero si el valor de c existe más de una vez en la fila
bool Sudoku::checkRow(Cell c)
{


    int i = c->getX();
    int cont = 0;
    for(int j = 0; j < 9; j++)
    {
        if(matriz[i][j]->getValue() == c->getValue())
            cont++;

    }
    return cont==1;
}

//Retorna verdadero si el valor de c existe más de una vez en la columna
bool Sudoku::checkCol(Cell c)
{

    int j = c->getY();
    for(int i = 0; i<9; i++)
    {
        if(matriz[i][j]->getValue() == c->getValue())
            cont++;
    }
    return cont == 1;

}

//Parcialmente implementado
Cell Sudoku::checkAll[]()
{
    Cell error[81];

    return error;
}
