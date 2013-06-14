#include "sudoku.h"
#include <fstream.h>
#include <list>
#include <math.h>
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
list<Cell> checkRow(list<Cell> fila)
{
    list<Cell> imaginario;
    list<Cell> reales;

    reales.add(fila[0]);

    for(int j = 0; j < fila.size(); j++)
    {
        for(int r=0; r< reales.size();r++){
            if(fila[j].getValue() == reales[r].getValue)
                imaginario.add(columna[i]);
            else
                reales.add(columna[i]);
        }
     }
    return imaginario;
}

//Retorna una lista de celdas erroneas, si el valor de c existe más de una vez en la columna
list<Cell> checkCol(list<Cell> columna)
{
    list<Cell> imaginarios;
    list<Cell> reales;

    reales.add(columna[0]);

    for(int i = 1; i<columna.size(); i++)
    {
        for(int r=0; r<reales.size(); r++){
            if(columna[i].getValue == reales[r].getValue)
                imaginarios.add(columna[i]);
            else
                reales.add(columna[i]);
        }
    }
    return imaginarios;
}

//Parcialmente implementado
Cell checkAll[]()
{

    /*
    list<Cell>::iterator itr = R.begin();
    list<Cell>::iterator itc = C.begin();

    while(R.isempty() || C.isempty()){
        Cell error[81];
        return error;
    }
    */

    int i,j;
    list<Cell> error;
    for(i=0; i< 9; i++)
    {
        for(j=0;j,9;j++)
        {
            //Revisa si el valor de matriz[i][j] está repetido en la columna
            list<Cell> auxC = checkCol(matriz[i][j]);
            if(!auxC.empty())
                mergeLists(error,auxC);
            //Revisa si el valor de matriz[i][j] está repetido en la fila
            list<Cell> auxF = checkRow(matriz[i][j]);
            if(!auxF.empty())
                mergeLists(error,auxF);
            //Revisa si el valor de matriz[i][j] está repetido en la submatriz
        }
    }
}

void mergeLists(list<Cell> a, list<Cell> b)
{
    int i;
    for(i = 0; i < b.size(); i++)
    {
        a.push_back(b.pop_back());
    }
}

void initializeCenters()
{
    Cell c;
    c->setX = 1; c->setY = 1; c->setValue = -1; centros[0] = c;
    c->setX = 1; c->setY = 4; c->setValue = -1; centros[1] = c;
    c->setX = 1; c->setY = 7; c->setValue = -1; centros[2] = c;
    c->setX = 4; c->setY = 1; c->setValue = -1; centros[3] = c;
    c->setX = 4; c->setY = 4; c->setValue = -1; centros[4] = c;
    c->setX = 4; c->setY = 7; c->setValue = -1; centros[5] = c;
    c->setX = 7; c->setY = 1; c->setValue = -1; centros[6] = c;
    c->setX = 7; c->setY = 4; c->setValue = -1; centros[7] = c;
    c->setX = 7; c->setY = 7; c->setValue = -1; centros[8] = c;
}

//Calcula la distancia entre dos celdas
double distance(Cell c, Cell d)
{
    double answer = 0.0;
    answer = sqrt( pow((d->getX - c->getX),2.0) + pow((d->getY - c->getY),2.0));
    return answer;
}

Cell getCenter(Cell c)
{
   // minimum = distance(matriz[1][1],c);
    double min = 100.0;
    Cell answer() ;

    for(int i = 1; i <= 7 ; i+3)
    {
        for(int j = 1; j<=7; j+3)
        {

            if( distance(matriz[i][j],c) < min)
            {
                answer->setX = i;
                answer->setY = j;
             }
        }
    }
    return answer;
}
