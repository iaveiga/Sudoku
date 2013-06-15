#include "sudoku.h"
#include <fstream.h>
#include <list>
#include <math.h>
using namespace std;

//Constructor
Sudoku::Sudoku()
{
    for(int i = 0; i <9 ; i++)
    {
        for(int j = 0; j <9 ; j++)
        {
            matriz[i][j]->setValue = -1 ;
            matriz[i][j]->setX = i;
            matriz[i][j]->setY = j;
        }
    }
}

//Carga un sudoku resuelto correctamente desde un archivo de texto para revisarlo con el método checkAll
void Sudoku:: loadSudoku()
{
    ifstream archivo;
    archivo.open("/sudoku.txt",ios::in);
    int i,j;
    for(i = 0; i< 9; i++)
    {
        for(j=0; j<9 ; j++)
        {
            archivo>> matriz[i][j] ->setValue ;
        }

    }
}

//Retorna una lista de celdas erroneas, si el valor de c existe más de una vez en la fila
list<Cell> checkRow(list<Cell> fila)
{
    list<Cell> imaginario;
    list<Cell> reales;

    reales.add(fila[0]);

    for(int j = 0; j < fila.size(); j++)
    {
        for(int r=0; r< reales.size();r++){
            if(fila[j].getValue() == reales[r].getValue)
                imaginario.add(columna[i]);
            else
                reales.add(columna[i]);
        }
     }
    return imaginario;
}

//Retorna una lista de celdas erroneas, si el valor de c existe más de una vez en la columna
list<Cell> checkCol(list<Cell> columna)
{
    list<Cell> imaginarios;
    list<Cell> reales;

    reales.add(columna[0]);

    for(int i = 1; i<columna.size(); i++)
    {
        for(int r=0; r<reales.size(); r++){
            if(columna[i].getValue == reales[r].getValue)
                imaginarios.add(columna[i]);
            else
                reales.add(columna[i]);
        }
    }
    return imaginarios;
}

//Implementado
list<Cell> checkAll[](list<Cell> ImaginariosRow, lis<Cell>ImaginariosColumn)
{
    int e=0;
    list<Cell> celdasE;//LISTA DE CELDAS ERRONEAS
    do{
        for(int i=0; i<17; i++){//For que contara las Columnas y las Filas
            if(i<=8){//de 0 a 8 es el numero de Columnas
                if(checkCol(ImaginariosColumn).empty()){//Proceso de Chequeo de Columnas
                    //mensaje que las Columnas estan correctas
                }
                else{
                    celdasE.add(ImaginariosColumn[i]); //Se agregan a celdasE las celdas Erronenas
                }
            }
            else{// de 9 a 17 es el numero de filas
                if(checkRow(ImaginariosRow).empty()){//Proceso de Chequeo de Filas
                    //mensaje que las filas estan de manera correcta
                }
                else{
                    celdasE.add(ImaginariosRow[i - 8]); // Se agregan a CelasE las celdas Erroneas
                }
            }
        }
        if (celdasE.empty()){//Compara si las Celdas erroneas es igual a vacio para decir que las celdas estan bien
            e=0;
            return celdasE;
        }
        else
            return celdasE;//En caso que esten mal algunas celdas el proceso devuelve las celdas erroneas
            e=1;

    }while (e=1); //Fin del metodo

    /*
    list<Cell>::iterator itr = R.begin();
    list<Cell>::iterator itc = C.begin();

    while(R.isempty() || C.isempty()){
        Cell error[81];
        return error;
    }
    */

    int i,j;
    list<Cell> error;
    for(i=0; i< 9; i++)
    {
        for(j=0;j,9;j++)
        {
            //Revisa si el valor de matriz[i][j] está repetido en la columna
            list<Cell> auxC = checkCol(matriz[i][j]);
            if(!auxC.empty())
                mergeLists(error,auxC);
            //Revisa si el valor de matriz[i][j] está repetido en la fila
            list<Cell> auxF = checkRow(matriz[i][j]);
            if(!auxF.empty())
                mergeLists(error,auxF);
            //Revisa si el valor de matriz[i][j] está repetido en la submatriz
        }
    }
}

void mergeLists(list<Cell> a, list<Cell> b)
{
    int i;
    for(i = 0; i < b.size(); i++)
    {
        a.push_back(b.pop_back());
    }
}

void initializeCenters()
{
    Cell c;
    c->setX = 1; c->setY = 1; c->setValue = -1; centros[0] = c;
    c->setX = 1; c->setY = 4; c->setValue = -1; centros[1] = c;
    c->setX = 1; c->setY = 7; c->setValue = -1; centros[2] = c;
    c->setX = 4; c->setY = 1; c->setValue = -1; centros[3] = c;
    c->setX = 4; c->setY = 4; c->setValue = -1; centros[4] = c;
    c->setX = 4; c->setY = 7; c->setValue = -1; centros[5] = c;
    c->setX = 7; c->setY = 1; c->setValue = -1; centros[6] = c;
    c->setX = 7; c->setY = 4; c->setValue = -1; centros[7] = c;
    c->setX = 7; c->setY = 7; c->setValue = -1; centros[8] = c;
}

//Calcula la distancia entre dos celdas
double distance(Cell c, Cell d)
{
    double answer = 0.0;
    answer = sqrt( pow((d->getX - c->getX),2.0) + pow((d->getY - c->getY),2.0));
    return answer;
}

Cell getCenter(Cell c)
{
   // minimum = distance(matriz[1][1],c);
    double min = 100.0;
    Cell answer() ;

    for(int i = 1; i <= 7 ; i+3)
    {
        for(int j = 1; j<=7; j+3)
        {

            if( distance(matriz[i][j],c) < min)
            {
                answer->setX = i;
                answer->setY = j;
             }
        }
    }
    return answer;
}
