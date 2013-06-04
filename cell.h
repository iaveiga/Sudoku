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
    /*
    //getters
    int getX() const {return x;}
    int getY() const {return y;}
    int getValue() const {return value;}

    //setters
    void setX(int x){this->x = x;}
    void setY(int y) {this-> y = y;}
    void setValue(int value) {this->value = value;}
    */

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
