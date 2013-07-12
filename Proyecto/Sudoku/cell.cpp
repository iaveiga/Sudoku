#include "cell.h"

    Cell::Cell()
        /**
        *	@brief Constructor de la clase Cell por defecto.
        *	@author Iván Aveiga.
        */
    {
        x = 0;
        y = 0;
        value = -1;
    }

    Cell::Cell(int x, int y, int value)
        /**
        *	@brief Constructor de la clase Cell con parámetros.
        *	@author Iván Aveiga.
        */
    {
        this -> x = x;
        this -> y = y;
        this -> value = value;
    }

    int Cell::getX() const
        /**
        *	@brief devuelve el atributo x.
        *	@return atributo x.
        *	@author Iván Aveiga.
        */
    {
        return x;
    }

    int Cell::getY() const
        /**
        *	@brief devuelve el atributo y.
        *	@return atributo y.
        *	@author Iván Aveiga.
        */
    {
        return y;
    }

    int Cell::getValue() const
        /**
        *	@brief devuelve el atributo value.
        *	@return atributo value.
        *	@author Iván Aveiga.
        */
    {
        return value;
    }

    void Cell::setX(int x)
        /**
        *	@brief Setter del atributo x.
        *	@param y valor a setear en el atributo x.
        *	@author Iván Aveiga.
        */
    {
        this-> x = x;
    }

    void Cell::setY(int y)
        /**
        *	@brief Setter del atributo y.
        *	@param y valor a setear en el atributo y.
        *	@author Iván Aveiga.
        */
    {
        this-> y = y;
    }

    void Cell::setValue(int value)
        /**
        *	@brief Setter del atributo Value.
        *	@param value valor a setear en el atributo value.
        *	@author Iván Aveiga.
        */
    {
        this-> value = value;
    }

    bool Cell::equals(Cell c)
    {
        /**
        *	@brief Retorna si this es igual a c en valor y posición.
        *	@param c Celda a comparar.
        *	@return booleano si son iguales.
        *	@author Iván Aveiga.
        */
        return ( (this->getX() == c.getX()) &&  (this->getY() == c.getY()) && (this->getValue() == c.getValue()));
    };
