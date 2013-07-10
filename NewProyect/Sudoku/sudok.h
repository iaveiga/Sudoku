#ifndef SUDOK_H
#define SUDOK_H

#include<QObject>

#define TAMANO_TABLERO 9

class sudok : public QObject
{
    Q_OBJECT
public:
    explicit sudok(QObject *parent = 0);
    void generar(int e);

signals:
    void CambioCelda(int indice, int valor);

private:
    int cell[TAMANO_TABLERO * TAMANO_TABLERO];

};

#endif // SUDOK_H
