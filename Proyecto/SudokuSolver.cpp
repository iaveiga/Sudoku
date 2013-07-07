#include "SudokuSolver.h"
#include "Sudoku.h"
#include "Cell.h"
#include <list>
#include <iostream>

using namespace std;

	SudokuSolver::SudokuSolver()
	{
		//Crea un nuevo Sudoku
		board = Sudoku::Sudoku();
	}

	Sudoku SudokuSolver::getBoard()
	{
		return SudokuSolver::board;
	
	}

	void SudokuSolver::setBoard(Sudoku s)
	{
		SudokuSolver::board = s;
	}

	bool SudokuSolver::findUnassignedLocation(Sudoku s, Cell c)
	{
		if(s.getCell(c.getX(), c.getY()).getValue() == 0)
			return true;
		else
			return false;
	}

	bool SudokuSolver::usedInCol(Sudoku s, Cell c)
	{
		return s.checkCol(c).empty();
	}

	bool SudokuSolver::usedInRow(Sudoku s, Cell c)
	{
		return s.checkRow(c).empty();
	}

	bool SudokuSolver::usedInBox(Sudoku s, Cell c)
	{
		return s.checkSubmatrix(c).empty();
	}

	bool SudokuSolver::isSafe(Sudoku s, Cell c)
	{
		return (!SudokuSolver::usedInCol(s,c) && !SudokuSolver::usedInRow(s,c) && !SudokuSolver::usedInBox(s,c));
	}

	bool SudokuSolver::solve(Sudoku s, Cell c)
	{
		
		c.setValue(100);
		cout<< "Estoy en la recursion";
		//Si no está ocupado estamos bien
		if(! SudokuSolver::findUnassignedLocation(s,c))
			return true;

		//Considera dígitos del 1 al 9
		for(int num = 1; num <= 9; num++) 
		{
			//Revisa si la celda está comprometida
			if(isSafe(s,c))
			{
				//Asignación tentativa
				s.setCell(c.getX(),c.getY(),c);
				cout<<"Intento cambiar valor";
				//retorna si es exitoso
				if(SudokuSolver::solve(s,c))
					return true;
			
				//Al fallar, deshace e intenta de nuevo
				Cell d = Cell(c.getX(),c.getY(),0);
				s.setCell(c.getX(),c.getY(),d);
			}
		}
		return false; //Esto lanza el backtracking
	}