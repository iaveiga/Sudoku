#include "sudokugui.h"
#include "ui_sudokugui.h"

SudokuGUI::SudokuGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SudokuGUI)
{
    ui->setupUi(this);
}

SudokuGUI::~SudokuGUI()
{
    delete ui;
}
