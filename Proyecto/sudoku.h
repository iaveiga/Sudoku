#ifndef SUDOKU_H
#define SUDOKU_H
#include "Cell.h"
#include <list>

using namespace std;

class Sudoku
{
    private:
        Cell centros[9];
        Cell matriz[9][9];

    public:

        //Constructor
        Sudoku();

        void loadSudoku();

        Cell getCenter(Cell c);

        void initializeCenters();

        Cell getCell(int i, int j);

        void setCell(int i, int j, Cell c);

        double distance(Cell c, Cell d);

        void mergeLists(list<Cell> A, list<Cell> B);

        bool inList(list<Cell> a, Cell b );

        void isValid();

        list<Cell> checkCol(Cell c);

        list<Cell> checkRow(Cell c);

        list<Cell> checkAll(Cell c);

};
#endif // SUDOKU_H
