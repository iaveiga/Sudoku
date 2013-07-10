#ifndef CELL_H
#define CELL_H
#include<QWidget>

#define N_POSIBILIDADES 9

class tablet;
class QGridLayout;
class QTextEdit;
class QpushButton;
/**
 * @brief La clase Cell representa las celdas del tablero
 *@autor Kevin Campuzano
 */

class Cell :public QWidget
{
    Q_OBJECT
public:

    enum Mode{
        Anotacion,
        final
    };
    /**
     * @brief Contructor de Cell
     * @param argumento de QWidget
     */

    explicit Cell(QWidget *parent = 0);
    ~Cell();
    void settablet(tablet *tablet);
    int getValue();
    void setText(QString t);
    QString text();

signals:
    void clicked();

public slots:
    void setValue(int value);
    void setMode(Mode mode);
private:
    Mode mode;
    QGridLayout *layout;
    QLabel *anotaciones[N_POSIBILIDADES];
    tablet *tablet;
};

#endif // CELL_H
