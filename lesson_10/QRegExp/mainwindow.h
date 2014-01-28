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
    void on_regExpEdit_textChanged(const QString &arg1);

    void on_srcText_textChanged();

private:
    Ui::MainWindow *ui;

    void applyRegExp();
};

#endif // MAINWINDOW_H
