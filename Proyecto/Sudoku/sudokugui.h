#ifndef SUDOKUGUI_H
#define SUDOKUGUI_H

#include <QMainWindow>

namespace Ui {
class SudokuGUI;
}

class SudokuGUI : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SudokuGUI(QWidget *parent = 0);
    ~SudokuGUI();
    
private:
    Ui::SudokuGUI *ui;
};

#endif // SUDOKUGUI_H
