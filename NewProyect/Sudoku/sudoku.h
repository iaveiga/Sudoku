#ifndef SUDOKU_H
#define SUDOKU_H

#include <QMainWindow>
#include "cell.h"
#include "sudok.h"

namespace Ui {
class Sudoku;
}
/**
 *La clase time representa el tiempo del cronometro
 *@autor Kevin Campuzano
 */
class tablet;
class Sudoku : public QMainWindow
{
    Q_OBJECT
    
public:
    /**
     * @brief Constructor
     * @param parent argumento QWidget
     * Una descripcion del constructor
     */
    explicit Sudoku(QWidget *parent = 0);
    /**
      *Destructor
      *Descripcion del Destructor
      */
    ~Sudoku();
signals:
    void CambioValorCelda(int indice, int valor);
private slots:
    void salir_Sudoku();
private:
    Ui::Sudoku *ui;
    Cell *cell[TAMANO_TABLERO * TAMANO_TABLERO];
    Sudok *sudok;
    void initTablero();

};

#endif // SUDOKU_H
