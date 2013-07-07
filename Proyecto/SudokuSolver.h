#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H
#include "Sudoku.h"
#include "Cell.h"

using namespace std;

class SudokuSolver
{
	private:
		Sudoku board;

	public:
		SudokuSolver();
		bool solve(Sudoku s);
		
		bool findUnassignedLocation(Sudoku s, Cell c);
		bool isSafe(Sudoku s, Cell c);
		bool usedInRow(Sudoku s, Cell c);
		bool usedInCol(Sudoku s, Cell c);
		bool usedInBox(Sudoku s, Cell c);
		Sudoku getBoard();
		/* 
		//bool findUnassignedLocation(Sudoku s, int row, int col);
		//bool isSafe(Sudoku s, int row, int col, int num);
		//bool usedInRow(Sudoku s, int row, int num);
		//bool usedInCol(Sudoku s, int col, int num);
		//bool usedInBox(Sudoku s, int boxStartRow, int boxStartCol, int num);
		*/
		

};
#endif //SUDOKUSOLVER_H
