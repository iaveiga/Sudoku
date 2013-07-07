#include "cell.h"

Cell::Cell()
/*!
*@brief Clase constructora de una celda que no recibe parametros.
*/
{
    x = 0;
    y = 0;
    value = -1;
}

Cell::Cell(int x, int y, int value)
/*!
*@brief Constructor de la celda que recibe parametros
*/
{
    this -> x = x;
    this -> y = y;
    this -> value = value;
}

int Cell::getX() const
/*!
*@brief Obtiene la posicion de la fila de la celda
*@return devuelve el numero de la posicion de celda en X
*/
{
    return x;
}

int Cell::getY() const

/*!
*@brief Obtiene la posicion de la Columna de la celda
*@return devuelve el numero de la posicion de celda en Y
*/
{
    return y;
}

int Cell::getValue() const

/*!
*@brief Obtiene el valor de la fila de la celda
*@return devuelve el numero del valor que tiene de celda
*/
{
    return value;
}

void Cell::setX(int x)
/*!
*@brief Setea la posicion de la fila de la celda
*/
{
    this-> x = x;
}

void Cell::setY(int y)
/*!
*@brief Setea la posicion de la columna de la celda
*/
{
    this-> y = y;
}

void Cell::setValue(int value)
/*!
*@brief Setea el valor de la celda
*/
{
    this-> value = value;
}