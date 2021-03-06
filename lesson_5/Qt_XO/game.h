#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QFile>

// Состояние игры
enum State {
  X_MOVE, // Ход крестиков
  O_MOVE, // Ход ноликов
  X_WIN,  // Крестики выйграли
  O_WIN,  // Нолики выйграли
  DRAW    // Ничья
};

// Размер поля игры
const int MapSize = 4;

/*enum E {
    a = 1,
    b = 20
};*/

// Все что происодит на поле и логика игрового мира
// Ходы, выйгрыш/проигрыш
class Game {
  State state; // Текущее состояние игры
  char Map[MapSize][MapSize]; // Игровое поле
  // Проверка выйгрыша
  void line(char a[MapSize]);
 public:
  // Конструктор
  Game();
  // Новая игра без пересоздания объекта
  void newGame();
  // Получаем строку, соответствующую состоянию игры
  QString getStateString();
  // Совершаем ход, возвращает строку для клетки на форме
  QString makeMove(int row, int col);
  // Проверяем на окончание игры
  void checkGameOver();
  // Сохранение игры
  void save(QString fileName);
  // Загрузка игры
  void load(QString fileName);
  // Состояние ячейки
  const char* getCell(int i, int j);
};

#endif // GAME_H
