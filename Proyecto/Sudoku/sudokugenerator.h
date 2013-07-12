#ifndef SUDOKUGENERATOR_H
#define SUDOKUGENERATOR_H

#include "Sudoku.h"


using namespace std;
/*
    Genera un tablero con celdas removidas según la dificultad,
    los tableros se encuentrana alojados en texto plano.
*/



class SudokuGenerator
{
    private:
        Sudoku boardGame;
    public:
        //Constructor
        SudokuGenerator();

        //Getters y Setters
        Sudoku getBoardGame();
        void setBoardGame(Sudoku s);
        Sudoku generate(Sudoku s, int dificulty);

};
#endif // SUDOKUGENERATOR_H}
