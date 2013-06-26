#ifndef SUDOKU_H
#define SUDOKU_H
#include "Cell.h"
#include <list>

using namespace std;

class Sudoku
{
    private:
        static Cell centros[9];
        static Cell matriz[9][9];

    public:

        //Constructor
        Sudoku();

        void loadSudoku();

        static Cell getCenter(Cell c);

        static void initializeCenters();

        static Cell getCell(int i, int j);

        static void setCell(int i, int j, Cell c);

        static double distance(Cell c, Cell d);

        static void mergeLists(list<Cell> A, list<Cell> B);

        static bool inList(list<Cell> a, Cell b );

        static void isValid();

        list<Cell> checkCol(Cell c);

        list<Cell> checkRow(Cell c);

        list<Cell> checkAll(Cell c);

};
#endif // SUDOKU_H
