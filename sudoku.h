#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{

private:
    Sudoku();
    Cell matriz[9][9];

public:
    Cell();

    bool checkRow(Cell c)
    {
        //Retorna verdadero si el valor de c existe más de una vez en la fila

        int i = c->getX();
        int cont = 0;
        for(int j = 0; j < 9; j++)
        {
            if(matriz[i][j]->getValue() == c->getValue())
                cont++;

        }
        return cont==1;
    }

    bool checkCol(Cell c)
    {
        //Retorna verdadero si el valor de c existe más de una vez en la columna
        int j = c->getY();
        for(int i = 0; i<9; i++)
        {
            if(matriz[i][j]->getValue() == c->getValue())
                cont++;
        }
        return cont == 1;

    }

    //Parcialmente implementado
    Cell checkAll[]()
    {
        Cell error[81];

        return error;
    }

};

#endif // SUDOKU_H
