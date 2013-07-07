#include "SudokuSolver.h"
#include "Sudoku.h"
#include "Cell.h"
#include <list>


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

	bool SudokuSolver::solve(Sudoku s)
	{
		
	
	
	
		return false;
	}