#include "cellbutton.h"

CellButton::CellButton(const char *text,
                       QWidget *parent,
                       int row, int col,
                       Game &game) :
    QPushButton(text, parent)
{
    this->row = row;
    this->col = col;
    this->game = &game;
    if(text[0] == 'X' || text[0] == 'O')
        setEnabled(false);
}

// При нажатии на клетку
void CellButton::slotCellClicked(){
    // Выводим координаты нажатия для отладки
    qDebug() << "row = " << row << "   col = " << col;
    // Делаем ход
    this->setText( game->makeMove(row, col) );
    // Больше не можем нажимать на эту кнопку
    setEnabled(false);
}
