#include "cell.h"

Cell::Cell()
{

}

int Cell::getX()
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

