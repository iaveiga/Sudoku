#include "sudok.h"

#include<ctime>
#include<cstdlib>

#include<QDebug>

sudok::sudok(QObject *parent):
    QObject(parent)
{
}
void sudok::generar(int e){
    srand(time(NULL));
    for(int i=0; i<TAMANO_TABLERO *TAMANO_TABLERO; i++)
        cell[i]="-1";

}
void sudok::CambioCelda(int indice, int valor)
{
    if(cell[indice] != valor)
    {
        cell[indice] = valor;
        emit CambioCelda(indice,valor);
    }
}
