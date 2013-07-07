#include "sudoku.h"
#include <fstream>
#include <list>
#include <math.h>
#include <iostream>
using namespace std;

	//Constructor, 0 significa que es una posición vacía
	Sudoku::Sudoku()
	{
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

	//Devuelve la celda ij
	Cell Sudoku::getCell(int i, int j)
	/*!
	*@brief Ingresa la posicion y devuelve la celda
	*@param i posicion de la celda en x(columnas)
	*@param j posicion de la celda en y(filas)
	*@return retorna la celda de la matriz
	*/
	{
		return this->matriz[i][j];
	}

	//Almacena la celda en la posicioón ij
	void Sudoku::setCell(int i, int j, Cell c)
	/*!
	*@brief Ingresa la posicion y cambia el valor a la celda
	*@param i posicion de la celda en x(columnas)
	*@param j posicion de la celda en y(filas)
	*/
	{
		this->matriz[i][j] = c;
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

	//Carga un sudoku resuelto correctamente desde un archivo de texto para revisarlo con el método checkAll/*!
	/*
	@brief Carga un tablero desde un archivo de texto plano
	*/
	void Sudoku::loadSudoku()
	{
		ifstream archivo;
		archivo.open("C:/sudoku2.txt",ios::in);
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

	/*!
	*@brief Inicializa los centros, centro se le denomina a la celda que se ubica en el centro de las demas celdas
	*@return retorna celdas de centros inicializados
	*/
	void Sudoku::initializeCenters()
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

	list<Cell> Sudoku::checkCol(Cell c)
	{
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

	//Based in algorithm described by Nathalie Tejena
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
		*@brief obtiene la celda central de la celda C que es ingresada
		*@param c Celda a calcular su centro
		*@return retorna celda central.
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

	bool Sudoku::isValid()
	{
		list<Cell> valid;
		valid = Sudoku::checkAll();
		return(valid.empty());
	}