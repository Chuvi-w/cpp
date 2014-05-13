#include <iostream>
#include <assert.h>

using namespace std;

// Стек заданной длины
//  T - тип элементов
//  Size - максимальное количество
//    (размер стека)
template <typename T, int Size>
class Stack{
    T data[Size];
    // Количество элементов
    int size;
public:
    typedef T value_type;

    int getSize(){
      return size;
    }

    Stack(){
      size = 0;
    }
    // Положить в стек значение
    void push(T value){
      assert(size < Size);
      data[size] = value;
      ++size;
    }
    // Извлечь с вершины стека значение
    T pop(){
      assert(size > 0);
      --size;
      return data[size];
    }

    T getFirst(){
      return pop();
    }
};

// Очередь заданной длины
template <typename T, int Size>
class Queue {
  T data[Size];
  // Голова и хвост очереди
  int head, tail;
public:
  typedef T value_type;
  // Количество элементов
  int getSize(){
    return tail - head + 1;
  }

  Queue(){
    head = 0;
    tail = -1;
  }
  // Положить в конец очереди
  void put(T value){
    tail++;
    data[tail % Size] = value;
  }
  // Взять из начала очереди
  T get(){
    return data[head++ % Size];
  }

  T getFirst(){
    return get();
  }

};

// Шаблонная функция для печати любой коллекции
template <template<typename, int I> class T>
void show(typename T<class X, I> t){
  cout << "size = " << t.getSize() << endl;
  typename T::value_type temp = t.getFirst();
  cout << "First element: " << temp << endl;
};

/*
template <template<typename,int> class T>
  void show2(T< <typename X, int I> > t){
    cout << "size = " << t.getSize() << endl;
    typename T::value_type temp = t.getFirst();
    cout << "First element: " << temp << endl;
  };*/



int main()
{
    Stack<int,3> s;
    s.push(1);
    s.push(2);
    s.push(3);
    show(s);

    Queue<double,4> q;
    q.put(2.2);
    show(q);

    Shower<Stack<int, 3> > ss;
    return 0;
}
