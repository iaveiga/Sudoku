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
            matriz[i][j].setValue(-1);
            matriz[i][j].setX(i);
            matriz[i][j].setY(j);
        }
    }
}

//Carga un sudoku resuelto correctamente desde un archivo de texto para revisarlo con el método checkAll
void Sudoku:: loadSudoku()
{
    ifstream archivo;
    archivo.open("/sudoku.txt",ios::in);
    int i,j;
    int aux;
    for(i = 0; i< 9; i++)
    {
        for(j=0; j<9 ; j++)
        {
            archivo>> aux;
            matriz[i][j].setValue(aux) ;
        }
    }
}

//Retorna una lista de celdas erroneas, si el valor de c existe más de una vez en la fila
list<Cell> checkR(Cell a)
{
    list<Cell> reales;
    list<Cell> imaginarios;
    int i = a.getX();
    for(int j = 0; j < 9; j++)
    {
        if(inList(reales,matriz[i][j]))
        {
            imaginarios.push_back(matriz[i][j]);
        }
        else
        {
            reales.push_back(matriz[i][j]);
        }
    }
    return imaginarios;
}

//Retorna una lista de celdas erroneas, si el valor de c existe más de una vez en la columna
list<Cell> checkC(Cell a)
{
    list<Cell> reales;
    list<Cell> imaginarios;
    int j = a.getY();
    for(int i = 0; i < 9; i++)
    {
        if(inList(reales, matriz[i][j]))
        {
            imaginarios.push_back( Sudoku::matriz[i][j]);
        }
        else
        {
            reales.push_back(Sudoku::matriz[i][j]);
        }
    }
    return imaginarios;
}

list<Cell> checkSubmatriz(Cell a)
{
    list<Cell> reales;
    list<Cell> imaginarios;
    Cell center = getCenter(a);
    int i = center.getX();
    int j = center.getY();
    for( i-1; i+1; i++)
    {
        for(j-1;j+1;j++)
        {
            if(inList(reales, matriz[i][j]))
            {
                imaginarios.push_back(matriz[i][j]);
            }
            else
            {
                reales.push_back(matriz[i][j]);
            }
        }
    }
    return imaginarios;

}


//Implementado CheckAll, chequea todas las listas
list<Cell> checkAll ()
{
    list<Cell> erroneos ;
    erroneos.clear();
    for (int i = 0; i < 9; i++)
    {
        for(int j = 0; j< 9; j++)
        {
            list<Cell> auxR = checkRow(Sudoku::matriz[i][j]);
            list<Cell> auxC = checkCol(Sudoku::matriz[i][j]);
            list<Cell> auxS = checkSubmatriz(Sudoku::matriz[i][j]);
            if( ! auxR.empty())
                mergeLists(erroneos,auxR);
            if( ! auxC.empty())
                mergeLists(erroneos,auxC);
            if(! auxS.empty())
                mergeLists(erroneos,auxS);
        }
    }
    return erroneos;
}

void isValid()
{

    list<Cell> valid;
    valid = checkAll();
    if (! valid.empty()) //Diferente de vacío
        cout << "Es un sudoku valido";
    else
        cout << "Es un sudoku no valido";

}


bool inList(list<Cell> a, Cell b )
{
    if(a.is_empty())
        return false;

    for(int i = 0; i < a.size(); i++)
        if(a[i]->getValue() == b->getValue())
            return true;
    return false;
}

void mergeLists(list<Cell> A, list<Cell> B)
{
    int flag = 0;
    for(int i = 0; i< B.size(); i++)
    {
        for(int j = 0; j < A.size(); j++)
        {
            if(!(A[i]->getX() == B[j]-> getX() && A[i]->getY() == B[j]-> getY() && A[i]-> getValue() == B[j]->getValue()))
                A.push_back(B[j]);
        }
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
                answer.setX = i;
                answer.setY = j;
             }
        }
    }
    return answer;
}
