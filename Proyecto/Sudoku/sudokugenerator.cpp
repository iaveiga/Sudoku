#include "SudokuGenerator.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

    SudokuGenerator::SudokuGenerator()
    {
        /**
        *	@brief Crea un SudokuGenerator.
        *	@author	Iván Aveiga.
        */
        this->boardGame = Sudoku();
    }

    Sudoku SudokuGenerator::getBoardGame()
    {
        /**
        *	@brief Devuelve el atributo boardGame.
        *	@return atributo boardGame.
        *	@author	Iván Aveiga.
        */
        return SudokuGenerator::boardGame;
    }

    void SudokuGenerator::setBoardGame(Sudoku s)
    {
        /**
        *	@brief Setea el atributo boardGame con el sudoku s.
        *	@param s , sudoku.
        *	@author	Iván Aveiga.
        */
        SudokuGenerator::boardGame = s;
    }

    Sudoku SudokuGenerator::generate(Sudoku s, int dificulty)
    {
        /**
        *	@brief Devuelve un sudoku para jugar según la dificultad.
        *	@param s , sudoku del cuál se obtendrá las celdas para armar el sudoku.
        *	@param dificulty, dificultad para generar el tablero, se basa en las celdas a elegir
        *	@return un sudoku parcialmente completado para jugar.
        *	@author	Iván Aveiga.
        */

        /**
        *	Genera un tablero nuevo a partir de s, dificultades:
        *	1: Fácil    | 41 - 36 Fichas
        *	2: Normal   | 35 - 32 Fichas
        *	3: Avanzado | 31 - 28 Fichas
        *	4: Experto  | 27 - 23 Fichas
        *   Obtenido de Programming Sudoku, Meng Lee.
        */

        Sudoku g = Sudoku();
        int cont = 0, cells;
        int x, y;
        if(dificulty == 1) // 36
            cells = rand() % 6 + 36; // [0,1,2,3,4,5] + 36
        else if(dificulty == 2)
            cells = rand() % 4 + 32; // [0,1,2,3] + 32
        else if (dificulty == 3)
            cells = rand() % 4 + 28; // [0,1,2,3] + 28
        else
            cells = rand() % 5 + 23; // [0,1,2,3,4] + 23

        //Genera un camino aleatorio de cells pasos
        do{
                //Genera coordenadas x y siempre que la casilla x y del sudoku a retornar no esté vacía (valor -1)
                do{
                    x = rand() % 9; y = rand()% 9;
            }while(g.getCell(x,y).getValue() == s.getCell(x,y).getValue());
                g.setCell(x,y,s.getCell(x,y));
            cont++;
        }while(cont != cells);
        return g;
    }
