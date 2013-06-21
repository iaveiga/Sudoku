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
    int getX() const;
    int getY() const ;
    int getValue() const;

    //setters
    void setX(const int x);
    void setY(const int y);
    void setValue(const int value);

};

#endif // CELL_H
