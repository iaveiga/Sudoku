#include "sudoku.h"
#include <fstream.h>
#include <list>
#include <math.h>
using namespace std;

//Constructor
Sudoku::Sudoku()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            Cell aux = Cell(i,j,-1);
            setCell(i,j,aux);
        }
    }
}

//Obtiene la ij celda
Cell Sudoku::getCell(int i, int j)
/*!
  *@brief Ingresa la posicion y devuelve la celda
  *@param i posicion de la celda en x(columnas)
  *@param j posicion de la celda en y(filas)
  *@return retorna la celda de la matriz
*/
{
    return matriz[i][j];
}

//Almacena la celda en la posicioón ij
void Sudoku::setCell(int i, int j, Cell c)
/*!
  *@brief Ingresa la posicion y cambia el valor a la celda
  *@param i posicion de la celda en x(columnas)
  *@param j posicion de la celda en y(filas)
*/
{
    matriz[i][j] = c;
}

//Carga un sudoku resuelto correctamente desde un archivo de texto para revisarlo con el método checkAll
void Sudoku::loadSudoku()
/*!
  *@brief Carga un tablero desde un archivo de texto plano
*/
{
    ifstream archivo;
    archivo.open("C:/sudoku.txt",ios::in);
    int i,j,aux;
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            archivo >> aux;
            Cell caux = Cell(i,j,aux);
            setCell(i,j,caux);
        }
    }
}


/*métodos erróneos asociados a listas
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
*/


void Sudoku::initializeCenters()
/*!
  *@brief Inicializa los centros, centro se le denomina a la celda que se ubica en el centro de las demas celdas
  *@return retorna celdas de centros inicializados
*/
{
    Cell c0 = Cell(1,1,-1); centros[0] = c0;
    Cell c1 = Cell(1,4,-1); centros[1] = c1;
    Cell c2 = Cell(1,7,-1); centros[2] = c2;
    Cell c3 = Cell(4,1,-1); centros[3] = c3;
    Cell c4 = Cell(4,4,-1); centros[4] = c4;
    Cell c5 = Cell(4,7,-1); centros[5] = c5;
    Cell c6 = Cell(7,1,-1); centros[6] = c6;
    Cell c7 = Cell(7,4,-1); centros[7] = c7;
    Cell c8 = Cell(7,7,-1); centros[8] = c8;
}

//Calcula la distancia entre dos celdas
double Sudoku::distance(Cell c, Cell d)
/*!
  *@brief Calcula la distancia que hay de una celda a otra
  *@param c celda inicial
  *@param d celda final o celda de destino
  *@return distancia de una celda a otra
*/
{
    double answer = 0.0;
    answer = sqrt( pow((c.getX() - d.getX()),2.0) + pow((c.getY() - d.getY()),2.0));
    return answer;
}

//Devuelve las coordenadas x,y del centro de la submatriz a la que pertenece c
Cell Sudoku::getCenter(Cell c)
/*!
  *@brief obtiene la celda central de la celda C que es ingresada
  *@param c Celda a calcular su centro
  *@return retorna celda central.
*/
{
    Cell answer = Cell(-1,-1,100);
    double min = 100.0, d;
    for(int i = 1; i <= 7 ; i = i+3)
        {
            for(int j = 1; j<=7; j = j+3)
            {
                d = distance(getCell(i,j),c);
                if( d < min)
                {
                    answer.setX(i); answer.setY(j);
                    min = d;
                }
            }
    }
    return answer;
}
