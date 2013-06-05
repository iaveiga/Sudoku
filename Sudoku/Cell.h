#ifndef CELL_H
#define CELL_H

class Cell
{

private:
    int x;
    int y;
    int value;

public:
    Cell();

    //getters
    int getX();
    int getY();
    int getValue();

    //setters
    void setX(int x);
    void setY(int y);
    void setValue(int value);

};

#endif // CELL_H
