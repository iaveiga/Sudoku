//#include "mainwindow.h"
#include <QApplication>
#include "inicio.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    Inicio h;
    h.show();
    //w.show();

    
    return a.exec();
}
