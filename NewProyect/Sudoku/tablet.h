#ifndef TABLE_H
#define TABLE_H

#include "cell.h"
#include<QWidget>

class QGridLayout;
class QPushButton;

class tablet : public QWidget
{
    Q_OBJECT
public:
    explicit tablet(QWidget *parent = 0);
    ~tablet();

signals:
    void numeroseleccionado(int numero);
    void modoCambio(Cell::Mode);
public slots:
    void activar();
private slots:
    void seleccionar();
    void setmode_final();
    void setmode_anotacion();
private:
    QGridLayout *tablet;
    Cell *CeldasSeleccionadas;
};

#endif // TABLE_H
