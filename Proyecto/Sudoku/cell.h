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
        Cell(int x, int y, int value);

        //getters
        int getX() const;
        int getY() const ;
        int getValue() const;

        //setters
        void setX(int x);
        void setY(int y);
        void setValue(int value);
        bool equals(Cell d);
};
#endif // CELL_H
