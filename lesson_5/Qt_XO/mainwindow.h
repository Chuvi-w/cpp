#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "game.h"
#include "cellbutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

  void exit_application();

 private slots:
  void slot1();
  void slot2();
  void updateWindow(); // Обновить поле
  void newGame(); // Новая игра
  void saveGame(); // Сохранить игру
  void loadGame(); // Загрузить игру

  void on_exitButton_clicked();

  // Новый слот
  void myNewSlot();

 private:
  Ui::MainWindow* ui;
  Game game; // Состояние игры
  CellButton* cells[MapSize][MapSize]; // Клетки поля (кнопки)
  void updateGameButtons(); // Обновляем кнопки - клетки поля
};

#endif // MAINWINDOW_H
