#include <iostream>

using namespace std;

struct Stack {
  // Значение поместить на вершину стека
  void push(int value){
  }
  // Взять значение с вершины стека
  int pop(){
  }
};

struct Queue {
  // В конец очереди
  void put(int value){
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
