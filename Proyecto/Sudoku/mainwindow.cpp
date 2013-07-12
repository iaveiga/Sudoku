#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sudoku.h"
#include "cell.h"
#include "sudokugenerator.h"
#include <QMainWindow>
#include <QLineEdit>
#include <QGridLayout>
#include <QColor.h>
#include <QDebug>
#include <iostream>

#include <QLCDNumber>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /**
    *   @brief constructor de la clase mainwindow
    *   @author Kevin Campuzano, Iván Aveiga
    */

    ui->setupUi(this);
    connect(ui->btnVerificar,SIGNAL(clicked()),this,SLOT(verificar()));


    //Formato del Tiempo
    time = new QTime;
    time->setHMS(0,0,0,0);

    //Creamos temporizador
    timer = new QTimer(this);

    // Realizamos la conexión para que el método(Slot) showTime sea llamado cada segundo
    connect(timer, SIGNAL(timeout()), this, SLOT(MuestraTiempo()));

    //iniciamos los segundos igual a cero
    seconds=0;

    // convertimos el formato tiempo a cadena(horas,min,sec) y le damos estilos (color, fondo)
         QString text = time->toString("mm:ss");
         this->ui->lcdTiempo->display(text);
         this->ui->lcdTiempo->setStyleSheet("* { background-color:rgb(128,64,0);color:rgb(255,255,255);}}");
         this->ui->lcdTiempo->setSegmentStyle(QLCDNumber::Filled);
}

MainWindow::~MainWindow()
{
    /**
    *   @brief Destructor de la clase mainwindow
    *   @author Qt
    */
    delete ui;
}
void MainWindow::ComienzaCronometro()
{
    /**
    *   @brief inicia el cronómetro desde que es llamado el formulario mainwindow
    *   @author Kevin Campuzano
    */
    // iniciamos el cronómetro en milisegundos
    timer->start(1000);
}
void MainWindow::MuestraTiempo()
{
    /**
    *   @brief muestra el tiempo de juego
    *   @author Kevin Campuzano
    */

    // incrementamos los segundos de 1 en 1 y lo agregamos el tiempo
    QTime newtime;
    seconds = seconds + 1;
    newtime = time->addSecs(seconds);

    // convertimos el tiempo a cadena para mostrar
    QString text = newtime.toString("mm:ss");
    ui->lcdTiempo->display(text);
}

void MainWindow::loadLE(int dificultad,QString nombre)
{
    /**
    *   @brief carga en la interfaz el tablero a jugar con las celdas y el nombre del jugador.
    *   @param dificultad, dificultad a jugar.
    *   @paran nombre, nombre del jugador.
    *   @author Iván Aveiga
    */

    int i,j,num;
    QString var = "";
    Sudoku s = Sudoku();
    Sudoku board = Sudoku();
    s.loadSudoku();
    this->tablero = s;
    board = this->generator.generate(s,dificultad);
    this->juego = board;
    qDebug() << this->juego.isValid();
    ui->txt_nombreJugador->setText(nombre);

    for(i = 0; i <9 ; i++)
    {
        for(j = 0; j < 9; j++)
        {
            var = var + QString(i) + QString(j);
            QLineEdit *var = new QLineEdit();
            if(this->juego.getCell(i,j).getValue() != 0)
            {
                num = this->juego.getCell(i,j).getValue(); //obtengo valor no vacío
                QString text = QString();    //creo un text
                text.setNum(num);           //setea el line edit
                var->setText(text);
                var->setEnabled(false);
                QPalette palette;
                QColor color= Qt::cyan;
                palette.setColor(var->backgroundRole(),color);
                var->setPalette(palette);

            }
            ui->gridLayout->addWidget(var,i,j);
            var->setMaxLength(1);
            var->setInputMask("0");
            var->setFixedSize(30,30);
            var->show();
        }
    }

}

void MainWindow::verificar()
{
    /**
     *  @brief Verifica si el tablero está correctamente resuelto, si no lo está marca las celdas
     *   erróneas
     *  @author Iván Aveiga, Kevin Campuzano
    **/

    MainWindow::parse();
    int i,j;
    for(i = 0; i <9; i++)
    {
        for(j=0; j <9; j++)
        {
            bool x;
            x = ui->gridLayout->itemAtPosition(i,j)->widget()->isEnabled();
            if(x)
                MainWindow::pintarCell(i,j,Qt::white);
        }
    }


    list<Cell> error;
    error.clear();
    error = this->juego.compare(this->tablero);
    if(error.empty())
        {
            ui->lblM->setText(QString("Ganó"));
            timer->stop();
        }
     else
         MainWindow::pintar(error);

}

void MainWindow::pintar(list<Cell> e)
{
    /**
     *  @brief Pinta las celdas erróneas
     *  @param e lista de celdas erróneas.
     *  @author Ivan Aveiga
     */


    int x, y;
    while(!e.empty())
    {
        Cell aux = e.front();
        x = aux.getX();
        y = aux.getY();
        MainWindow::pintarCell(x,y,Qt::magenta);
        e.pop_front();
    }
}

void MainWindow::pintarCell(int x, int y,QColor color)
{

    /**
    *   @brief Pinta una celda de color
    *   @param x coordenada en x de la celda
    *   @param y coordenada en y de la celda
    *   @color color ha ser pintado.
    */
    QPalette palette;
    palette.setColor(ui->gridLayout->itemAtPosition(x,y)->widget()->backgroundRole(),color);
    ui->gridLayout->itemAtPosition(x,y)->widget()->setPalette(palette);

}


void  MainWindow::parse()
{
    /**
    *   @brief obtiene los valores de la interfaz y los pasa al sudoku juego.
    *   @author Iván Aveiga
    */


    int i,j, val;
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j <9; j++)
        {
            if(dynamic_cast<QLineEdit*>(ui->gridLayout->itemAtPosition(i,j)->widget())->isEnabled())
            {
                val = (dynamic_cast<QLineEdit*>(ui->gridLayout->itemAtPosition(i,j)->widget())->text().toInt());
                Cell aux = Cell(i,j,val);
                this->juego.setCell(i,j,aux);
            }
        }
    }
}
