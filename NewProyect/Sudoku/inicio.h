#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>

namespace Ui {
class Inicio;
}

class Inicio : public QDialog
{
    Q_OBJECT
    
public:
    /**
     * @brief Inicio, Constructor
     * @param QWidget
     */
    explicit Inicio(QWidget *parent = 0);
   /**
     *Destructor
     *Destructor de Inicio
     */
    ~Inicio();
    
private slots:
    void jugar_clicked();
    void salir_clicked();
private:
    Ui::Inicio *ui;
};

#endif // INICIO_H
