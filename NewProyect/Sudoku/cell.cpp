#include "cell.h"
#include "tablet.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
Cell::Cell(QWidget *parent):
    QWidget(parent),
    mode(Cell::Final),
    emptyAnnotation(0)
{
    this->backgroundRole();
    for (int i = 0; i < N_POSIBILIDADES; i++) {
            anotaciones[i] = new QLabel("__");
        }

        layout = new QGridLayout(this);

        setMode(Cell::Final);

}
Cell::~Cell()
{
    delete valor;
    for (int i = 0; i < N_POSIBILIDADES; i++)
        delete anotaciones[i];
    delete layout;
}
void Cell::setTablet(tablet *tablet)
{
    this->keyboard = keyboard;
    connect(this, &Cell::clicked, keyboard, &Keyboard::activate);
}

