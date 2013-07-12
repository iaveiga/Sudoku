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

        void setCell(int i, int j, Cell c);

        Cell getCell(int i,int j);

        double distance(Cell c, Cell d);

        void loadSudoku();

        Cell getCenter(Cell c);

        void initializeCenters();

        list<Cell> checkCol(Cell c);

        list<Cell> checkRow(Cell c);

        bool inList(list<Cell> a, Cell b );

        list<Cell> mergeLists(list<Cell> A, list<Cell> B);

        list<Cell> checkSubmatrix(Cell c);

        list<Cell> checkAll();

        list<Cell> compare(Sudoku t);

        bool isValid();


};
#endif // SUDOKU_H
