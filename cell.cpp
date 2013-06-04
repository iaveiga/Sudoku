#include "cell.h"

Cell::Cell()
{
public:
    //getters
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }
    int getValue()
    {
        return value;
    }

    //setters
    void setX(int x) const
    {
        this-> x = x;
    }
    void setY(int y)
    {
        this-> y = y;
    }
    void setValue(int value)
    {
        this->value = value;
    }
}
