#include <iostream>
#include <assert.h>

using namespace std;

// Один элемент списка
struct ListElement {
  int value;
  ListElement *next;
};

struct List {
  ListElement *root;
  // Конструктор
  List(){
    root = NULL;
  }
  // Деструктор (очистка памяти)
  ~List(){
    while(root != NULL){
      ListElement *cur = root->next;
      delete root;
      root = cur;
    }
  }
  // Показать список
  void show(){
    ListElement *cur = root;
    while(cur != NULL){
      // cur->value <-> (*cur).value
      cout << cur->value << endl;
      cur = cur->next;
    }
  }
  // Добавить элемент в начало
  void addToBegin(int value){
    ListElement *newElement = new ListElement;
    newElement->value = value;
    // Подвешиваем к новому элементу старый список
    newElement->next = root;
    // Теперь root должен ссылаться на новый элемент
    root = newElement;
  }
  // Добавить элемент в конец
  void addToEnd(int value){
    if(root == NULL){
        addToBegin(value);
        return;
    }
    // Ищем последний элемент
    ListElement *cur = root;
    while(cur->next != NULL){
      cur = cur->next;
    }
    // Убеждаемся в том, что это последний элемент
    // списка
    assert(cur->next == NULL);

    // Заводим новый элемент
    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->next = NULL;
    // Подвешиваем новый элемент в конец списка
    cur->next = newElement;
  }
};

int main()
{
  List l,list2;
  l.addToBegin(2);
  l.addToBegin(10);
  l.addToBegin(-1);
  l.addToEnd(33);
  l.show();
  return 0;
}
