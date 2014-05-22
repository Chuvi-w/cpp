#include "game.h"
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <assert.h>

Game::Game()
{
    newGame();
}

// Новая игра
void Game::newGame(){
    state = X_MOVE;
    // Заполняем поле пустыми клетками, без крестиков и ноликов
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            Map[i][j] = ' ';
}

QString Game::getStateString(){
    switch(state){
    case X_MOVE:
        return QString("Ход крестиков");
    case O_MOVE:
        return QString("Ход ноликов");
    case X_WIN:
        return QString("Крестики выйграли!");
    case O_WIN:
        return QString("Нолики выйграли!");
    case DRAW:
        return QString("Ничья! :)");
    default:
        assert(false);
    }
    return QString("Непредусмотренное состояние игры!");
}

// Совершаем ход
QString Game::makeMove(int row, int col){
    if(Map[row][col] != ' '){
        return QString("!");
    }

    switch (state) {
    case X_MOVE:
        Map[row][col] = 'X';
        state = O_MOVE;
        break;
    case O_MOVE:
        Map[row][col] = 'O';
        state = X_MOVE;
        break;
    default:
        return QString(" ");
    }
    checkGameOver();
    return QString(Map[row][col]);
}

// Три крестика или три нолика
void Game::line(char a, char b, char c){
    // Если не три равных => не подходит
    bool equals = (a == b) && (b == c);
    if (!equals) return;
    // Кто-то выйграл :)
    switch(a){
    case 'X':
        state = X_WIN;
        break;
    case 'O':
        state = O_WIN;
        break;
    default:
        break; // Если не крестики и не нолики, то не подходит
    }
}

void Game::checkGameOver(){
    // Проверяем диагонали
    line(Map[0][0], Map[1][1], Map[2][2]);
    line(Map[2][0], Map[1][1], Map[0][2]);
    // Вертикальные и горизонтальные линии
    for(int i = 0; i < 3; i++){
        line(Map[0][i], Map[1][i], Map[2][i]);
        line(Map[i][0], Map[i][1], Map[i][2]);
    }
    // Проверяем что крестики или нолики выйграли
    // и выходим
    switch(state){
       case X_WIN:
       case O_WIN:
         return;
       default:
         ; // Do nothing
    }

    // Ничья = все клетки заполнены и никто не выйграл
    int cnt = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(Map[i][j] == 'X' || Map[i][j] == 'O')
                cnt++;
    qDebug() << "cnt = " << cnt;
    if(cnt == 3*3)
        state = DRAW;
}

void Game::save(QString fileName){ // Сохранение игры
    QFile f(fileName); // QFile позволяет работать с файлами
    f.open(QIODevice::WriteOnly);
    // Сохраняем данные
    QTextStream out(&f);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            out << Map[i][j];
        out << endl;
    }
    f.close();
}

void Game::load(QString fileName){ // Загрузка игры
    QFile f(fileName); // Создаем объект - файл
    f.open(QIODevice::ReadOnly | QIODevice::Text); // Открываем его для чтения
    // Читаем данные
    QTextStream in(&f);
    int x_cnt = 0, o_cnt = 0; // Количество крестиков и ноликов
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            in >> Map[i][j]; // Очередной символ
            switch(Map[i][j]){
            case 'X':
                x_cnt++;
                break;
            case 'O':
                o_cnt++;
                break;
            case ' ': // Пробелы просто пропускаем
                break;
            default:
                throw QString("Ошибка при чтении файла %1\n: строка %2 столбец %3 символ '%4' вместо X или O")
                        .arg(fileName).arg(i).arg(j).arg(Map[i][j]);
            }
        }
        in.readLine(); // Строчка должна была закончиться
    }
    f.close();

    if((x_cnt >= 2) && (o_cnt == 0))
        throw QString("Все крестики!");
    if((o_cnt >= 2) && (x_cnt == 0))
        throw QString("Все нолики!");
    if(x_cnt > (o_cnt+1))
        throw QString("Слишком много крестиков в файле :)");
    if(o_cnt > (x_cnt+1))
        throw QString("Слишком много ноликов в файле :)");

    if(x_cnt > o_cnt)
        state = O_MOVE;
    else
        state = X_MOVE;

    checkGameOver();
}

const char *Game::getCell(int i, int j){
    static char buf[2];
    sprintf(buf,"%c",Map[i][j]);
    return buf;
}

