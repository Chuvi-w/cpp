#include <iostream>

using namespace std;

// Элемент стека и очереди
struct E {
  int value; // Значение элемента
  E* next; // Указатель на следующий элемент
};


struct Stack {
  E* top; // Вершина стека
  // Конструктор
  Stack() : top(NULL) {}
  // Значение поместить на вершину стека
  void push(int value){
    E* e = new E;
    e->value = value;
    e->next = top;
    top = e;
  }
  // Взять значение с вершины стека
  int pop(){
    E* e = top;
    int value = e->value;
    top = top->next;
    delete e;

    return value;
  }
};

struct Queue {
  E* start;
  // Конструктор
  Queue() : start(NULL) {};
  // В конец очереди
  void put(int value){
    // Создаём новый элемент
    E *e = new E;
    e->value = value;
    e->next = NULL;
    // Если очередь пуста
    if(start = NULL){
      start = e;
    } else {
      E *last = start;
      while(last->next != NULL)
        last = last->next;
      // К последнему элементу добавляем
      // новый элемент
      last->next = e;
    }
  }
  // Забрать первый элемент из очереди
  int get(){
  }
};


int main() {
  Stack s;
  s.push(2);
  s.push(3);
  cout << s.pop() << endl;

  Queue q;
  q.put(10);
  q.put(14);
  cout << q.get() << endl;

  return 0;
}
