#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cell.h"
#include "sudoku.h"
#include "sudokugenerator.h"

#include "QTime"
#include "QTimer"
#include "QLCDNumber"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void loadLE(int dificultad,QString nombre);
    void ComienzaCronometro();
    void pintar(list<Cell> e);
    void pintarCell(int x,int y, QColor c);


    Sudoku tablero; //sudoku completo
    Sudoku juego;   //sudoku a jugar
    SudokuGenerator generator; //genera el sudoku a jugar
private:
    Ui::MainWindow *ui;

    //Atributos del Cronometro
    QTime *time;
    QTimer *timer;

    QLCDNumber *num;

    int minutes;
    int seconds;

private slots:
    void verificar();
    void parse();
    void MuestraTiempo();
};
#endif // MAINWINDOW_H
