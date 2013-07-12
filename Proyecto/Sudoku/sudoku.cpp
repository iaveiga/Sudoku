#include "sudoku.h"
#include <fstream>
#include <list>
#include <math.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <QDebug>
#include <iostream>
#include "cell.h"

using namespace std;

    Sudoku::Sudoku()
    {
        /**
        *	@brief Constructor de la clase Sudoku, las celdas se inicializan con un valor de 0.
        *	@author Iván Aveiga.
        */
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                Cell aux = Cell(i,j,0);
                setCell(i,j,aux);
            }
        }
        Sudoku::initializeCenters();
    }

    Cell Sudoku::getCell(int i, int j)
    /**
    *	@brief Ingresa la posicion y devuelve la celda.
    *	@param i posicion de la celda en x(columna).
    *	@param j posicion de la celda en y(fila).
    *	@return retorna la celda ij de la matriz.
    *	@author Iván Aveiga.
    */
    {
        return this->matriz[i][j];
    }

    void Sudoku::setCell(int i, int j, Cell c)
    /*!
    *	@brief Ingresa la celda c en la posición ij
    *	@param i posicion de la celda en x(fila)
    *	@param j posicion de la celda en y(columna)
    *	@param c celda a ser almacenada en la posición ij
    *	@author Iván Aveiga
    */
    {
        this->matriz[i][j] = c;
    }

    double Sudoku::distance(Cell c, Cell d)
    /*!
    *	@brief Calcula la distancia que hay de una celda a otra.
    *	@param c celda inicial.
    *	@param d celda final.
    *	@return distancia de una celda a otra.
    *	@author Iván Aveiga.
    */
    {
        double answer = 0.0;
        answer = sqrt( pow((c.getX() - d.getX()),2.0) + pow((c.getY() - d.getY()),2.0));
        return answer;
    }

    void Sudoku::loadSudoku()
    {
        /**
        *	@brief Carga un sudoku aleatorio de un archivo de texto plano.
        *	@author Iván Aveiga
        */
        ifstream archivo;
        char c[4][10];
        strcpy(c[0],"/s1.txt");
        strcpy(c[1],"/s2.txt");
        strcpy(c[2],"/s3.txt");
        strcpy(c[3],"/s4.txt");
        /*
        strcpy(c[0],"C:/s1.txt");
        strcpy(c[1],"C:/s2.txt");
        strcpy(c[2],"C:/s3.txt");
        strcpy(c[3],"C:/s4.txt");
        */
        int num = rand()%4;

        archivo.open(c[num],ios::in);
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

    void Sudoku::initializeCenters()
    {
        /**
        *	@brief Inicializa el vector de centros para determinar a que submatriz pertenece una celda
        *	@author Iván Aveiga
        */
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

    list<Cell> Sudoku::checkCol(Cell c)
    {
                /**
        *	@brief Retorna las celdas repetidas en la fila de c.
        *	@param c Celda a buscar en la filaa c.x.
        *	@return lista de celdas repetidas a c.
        *	@author Iván Aveiga
        */
        list<Cell> reales;
        reales.clear();
        list<Cell> imaginarios;
        imaginarios.clear();
        int j = c.getY();
        for(int i = 0; i <9; i++)
        {
            Cell aux1 = Sudoku::getCell(i,j);
            if(Sudoku::inList(reales,aux1))
                imaginarios.push_back(aux1);
            else
                reales.push_back(aux1);
        }
        return imaginarios;
    }

    list<Cell> Sudoku::checkRow(Cell c)
    {
        /**
        *	@brief Retorna las celdas repetidas en la columna de c.
        *	@param c Celda a buscar en la columna c.y.
        *	@return lista de celdas repetidas a c.
        *	@author Iván Aveiga
        */
        list<Cell> reales;
        reales.clear();
        list<Cell> imaginarios;
        imaginarios.clear();
        int i = c.getX();
        for(int j = 0; j <9; j++)
        {
            Cell aux1 = Sudoku::getCell(i,j);
            if(Sudoku::inList(reales,aux1))
                imaginarios.push_back(aux1);
            else
                reales.push_back(aux1);
        }
        return imaginarios;
    }

    list<Cell> Sudoku::checkSubmatrix(Cell c)
    {

        int i, j;
        int minX, minY, maxX, maxY;
        list<Cell> reales;
        reales.clear();
        list<Cell> imaginarios;
        imaginarios.clear();
        Cell d = Sudoku::getCenter(c);
        minX = d.getX() -1; maxX = d.getX() + 1;
        minY = d.getX() -1; maxY = d.getY() + 1;
        for( i = minX; i == maxX; i++)
        {
            for ( j = minY; j == maxY; j++)
            {
                Cell aux = Sudoku::getCell(i,j);
                if(Sudoku::inList(reales,aux))
                    imaginarios.push_back(aux);
                else
                    reales.push_back(aux);
            }
        }
        return imaginarios;
    }

    list<Cell> Sudoku::checkAll()
    {
        /**
        *	@brief retorna todas las celdas conflictivas de un tablero de sudoku
        *	@return lista de celdas conflictivas
        *	@author Iván Aveiga
        *	Based in an idea of Nathalie Tejena.
        */
        list<Cell> error;
        error.clear();
        for(int i = 0; i <9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                Cell aux = Sudoku::getCell(i,j);
                list<Cell> auxR =  Sudoku::checkRow(aux);
                list<Cell> auxC = Sudoku::checkCol(aux);
                list<Cell> auxS = Sudoku::checkSubmatrix(aux);
                if(!(auxR.empty()))
                    error.insert(error.end(),auxR.begin(), auxR.end());
                    //cout<<"La lista no es vacia" ;//error = Sudoku::mergeLists(error,auxR);
                if(!(auxC.empty()))
                    error.insert(error.end(),auxC.begin(), auxC.end());
                if(!(auxS.empty()))
                    error.insert(error.end(),auxS.begin(), auxS.end());
            }
        }
        return error;
    }

    bool Sudoku::inList(list<Cell> a, Cell b )
    {
        /**
        *	@brief Devuelve verdadero si la celda b se encuentra en la lista de celdas a.
        *	@param a : Lista de Celdas.
        *	@param b : Celda a buscar si se encuentra en a.
        *	@return un valor booleano dependiendo si se encuentra o no b en a.
        *	@author Iván Aveiga.
        */
        if(a.empty())
            return false;

        list<Cell>::const_iterator iterator;
        for(iterator = a.begin(); iterator != a.end(); ++iterator)
        {
            Cell aux = a.front();
            if(aux.getValue() == b.getValue())
                return true;
        }
        return false;
    }

    Cell Sudoku::getCenter(Cell c)
    {
        /*!
        *	@brief obtiene la celda central de la submatriz perteneciente a c.
        *	@param c Celda a calcular a que submatriz pertenece.
        *	@return retorna celda central correspondiente a la submatriz donde c pertenece.
        *	@author Iván Aveiga
        */
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

    list<Cell> Sudoku::mergeLists(list<Cell> A, list<Cell> B)
    {
        //usar iterators
        list<Cell> toReturn;
        toReturn.clear();
        if(A.empty())
            toReturn = B;
        else
        {
            list<Cell>::const_iterator i;
            list<Cell>::const_iterator j;
            for(j = B.begin(); i != B.end(); ++j)
            {
                for(i = A.begin(); i != A.end(); ++i)
                {
                    Cell b = *j;
                    Cell a = *i;
                    if(  !((b.getX() == a.getX()) && (b.getY() == a.getY()) && (b.getValue() == a.getValue())))
                        toReturn.push_back(b);
                }
            }
        }
        return toReturn;
    }

    list<Cell> Sudoku::compare(Sudoku t)
    {
        /**
        *	@brief Compara dos sudokus y devuelve la lista de celdas distintas del sudoku.
        *   @param t Sudoku que servirá como base a comparar celdas (Cell).
        *	@return la lista de celdas que no coinciden entre this y t, tomando como base t.
        *   @author Iván Aveiga
        */

        list<Cell> error;
        error.clear();
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j <9; j++)
            {
                //
              if(t.getCell(i,j).getValue() != this->getCell(i,j).getValue()) //Si la celda ij de Sudoku es distinta a la celda ij de
                error.push_front(this->getCell(i,j));			   //Sudoku t (sudoku completo) se agrega una lista de erróneos

            }
        }
        Cell aux = Cell();
        list<Cell>::const_iterator i ;
        return error;
    }

    bool Sudoku::isValid()
    {

        /**
        *	@brief Retorna verdadero si un tablero Sudoku es válido, falso si es inválido.
        *	@return Un valor booleano.
        *	@author Iván Aveiga
        */
        list<Cell> valid;
        valid = Sudoku::checkAll();
        return(valid.empty());
    }
