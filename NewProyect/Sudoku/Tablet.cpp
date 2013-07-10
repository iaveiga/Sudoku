#include "tablet.h"
#include "cell.h"

#include <QGridLayout>
#include <QTextEdit>

tablet::tablet(QWidget *parent):
    QWidget(parent, Qt::Popup),
    CeldasSeleccionadas(NULL)
{
    setFixedHeight(200);
    setFixedWidth(200);

    tablet = new QGridLayout(this);
    tablet->setSpacing(1);
    for(int i=1;i<=10;i++){
        number[i] = new QTextEdit();
        tablet->addWidget( number[i],3-(i+2)/3, (i+2)%3 );
        }
    show();
}
tablet::~tablet()
{
    delete tablet;
}
