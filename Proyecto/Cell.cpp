#include "cell.h"

Cell::Cell()
{
    x = 0;
    y = 0;
    value = -1;
}

Cell::Cell(int x, int y, int value)
{
    this -> x = x;
    this -> y = y;
    this -> value = value;
}

int Cell::getX() const
{
    return x;
}

int Cell::getY() const
{
    return y;
}

int Cell::getValue() const
{
    return value;
}

void Cell::setX(int x)
{
    this-> x = x;
}

void Cell::setY(int y)
{
    this-> y = y;
}

void Cell::setValue(int value)
{
    this-> value = value;
}

