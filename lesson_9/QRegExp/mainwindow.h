#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    // Применение регулярного выражения к тексту
    // с выводом результата обратно на форму
    void applyRegExp();

    void saveText();
    void loadText();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
