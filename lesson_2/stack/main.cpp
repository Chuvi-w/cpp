#include <iostream>

using namespace std;

class StackElement {
 public:
  int value; // Значение элемента стека
  StackElement* next; // Указатель на следующий элемент стека
};

class Stack { //struct
  StackElement* root;

 public:

  // Конструктор
  //  - называется как класс
  //  - нет возвращаемого значения
  //  - параметры как у обычных методов
  Stack() : root(NULL) { }

  // Деструктор - очистка памяти
  ~Stack() {
    while(root != NULL) {
      StackElement* saveForDelete = root;
      root = root->next;
      delete saveForDelete;
    }
  }

  // Поместить на вершину стека
  void push(int newValue) {
    // Создали новый элемент стека с новым значением
    StackElement* newElement = new StackElement;
    newElement->value = newValue;
    // "Подвешиваем" root к новому элементу
    newElement->next = root;
    // Делаем новый элемент первым в списке
    root = newElement;
  }

  // Получить значение с вершины стека
  int pop() {
    if(root == NULL) {
      cout << "Stack is empty!" << endl;
      return 0;
    }

    // Получаем верхний элемент
    StackElement* topElement = root;
    // Получаем значение верхнего элемента
    int value = topElement->value;
    // Переставим корень списка на след. элемент
    root = topElement->next;
    // Очистим память
    delete topElement;
    // Вернём значение
    return value;
  }

  // Показать все элементы
  void show() {
    for(StackElement* cur = root;
        cur != NULL;
        cur = cur->next)
      cout << cur->value << endl;
  }
};


int main() {
  Stack s;
  s.push(2);
  s.push(4);
  s.push(5);
  s.show();
  cout << "pop result = " << s.pop() << endl;
  s.show();


  return 0;
}

// Д.з. однонаправленный список
