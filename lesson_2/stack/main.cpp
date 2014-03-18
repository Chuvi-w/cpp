#include <iostream>

using namespace std;

class StackElement {
public:
  int value; // �������� �������� �����
  StackElement* next; // ��������� �� ��������� ������� �����
};

class Stack { //struct
public:
  StackElement* root;

  Stack() : root(NULL) { }

  // ��������� �� ������� �����
  void push(int newValue){
    // ������� ����� ������� ����� � ����� ���������
    StackElement* newElement = new StackElement;
    newElement->value = newValue;
    // "�����������" root � ������ ��������
    newElement->next = root;
    // ������ ����� ������� ������ � ������
    root = newElement;
  }

  // �������� �������� � ������� �����
  int pop(){
    if(root == NULL){
      cout << "Stack is empty!" << endl;
      return 0;
    }
    // �������� ������� �������
    StackElement* topElement = root;
    // �������� �������� �������� ��������
    int value = topElement->value;
    // ���������� ������ ������ �� ����. �������
    root = topElement->next;
    // ������� ������
    delete topElement;
    // ����� ��������
    return value;
  }

  // �������� ��� ��������
  void show(){
    for(StackElement *cur = root;
          cur != NULL;
          cur = cur->next)
      cout << cur->value << endl;
  }
};


int main()
{
  Stack s;
  s.push(2);
  s.push(4);
  s.push(5);
  s.show();
  cout << "pop result = " << s.pop() << endl;
  s.show();
  return 0;
}

// �.�. ���������������� ������
