// ���������� �������������� ��������
//   + - * /
// ���������� �������� ���������
//   > < >= <= == !=
// �������� ������ � �����, ����� � ����������
//   >> <<
#include <iostream>
#include <assert.h>
#include <cmath>

//#define DEBUG

using namespace std;

// ������������ �����: p/q
template <class T = int>
class Rational {
  T p,q; // p - ���������, q - �����������
  T GCD(T a, T b); // ��� (���������� ����� ��������)
  void normalize(); // ���������� �����
public:
  Rational(T pi = 0, T qi = 1);

  // Getters - ������ ������� � ������
  T getP(){ return p; }
  T getQ(){ return q; }
  // Setters
  void setP(T value){ p = value; }

  Rational operator +(Rational&); // ��������
  Rational operator -(Rational&); // ���������
  Rational operator *(Rational&); // ���������
  Rational operator /(Rational&); // �������

  template <class Q>
  friend istream& operator >>(istream& in, Rational<Q> &r);

  template <class Q>
  friend ostream& operator <<(ostream& os, Rational<Q> r);
};

// ���������� ����� ��������
template <class T>
T Rational<T>::GCD(T a, T b){
    return (b == 0) ? a : GCD(b, a % b);
}

// ���������� �����
template <class T>
void Rational<T>::normalize(){
    // ������� ��� ��������� � �����������
    T d = GCD(abs(p),abs(q));
#ifdef DEBUG
    cout << "p = " << p << " q = " << q <<
      "  GCD = " << d << endl;
#endif // DEBUG
    // ����� ��������� � ����������� �� ���
    p /= d;
    q /= d;
  }

template <class T>
Rational<T>::Rational(T pi, T qi){
    p = pi;
    q = qi;
    assert(q != 0);
    //if(q == 0){
    //  cout << "q == 0" << endl;
    //  halt(1);
    //}
}

template <class T>
Rational<T> Rational<T>::operator +(Rational<T>& right){
    //  p/q + right.p/right.q
    return Rational(
         p * right.q + right.p * q,
       //--------------------------
               q * right.q );
  }

template <class T>
Rational<T> Rational<T>::operator -(Rational& right){
    return Rational(
         p * right.q - right.p * q,
       //--------------------------
               q * right.q );
  }

template <class T>
Rational<T> Rational<T>::operator *(Rational<T>& right){
    return Rational (
           p * right.p,
         //------------
           q * right.q );
  }

template <class T>
Rational<T> Rational<T>::operator /(Rational& right){
    return Rational (
           p * right.q,
         //------------
           q * right.p );
  }

template <class T>
ostream& operator <<(ostream& os, Rational<T> r){
    // ��������� ����� ���� ����
    r.normalize();

    if(r.q == 1){
      os << r.p;
    } else {
#ifdef DEBUG
      os << "DEBUG: " << p << " " << q << endl;
#endif // DEBUG
      T whole = r.p / r.q;
      if(whole != 0)
        os << whole << " ";
      if(whole != 0)
        os << abs(r.p % r.q);
      else
        os << (r.p % r.q);

      os << "/" << r.q;
    }
    return os;
  }

template <class T>
istream& operator >>(istream& in, Rational<T> &r){
  cout << "p = ";
  in >> r.p;
  cout << "q = ";
  in >> r.q;
  assert(r.q != 0);
  return in;
}

template<class Type, template< class > class Container >
class MyClass {
public:
    void showND(Container<Type> r){
      if(r.getP() > r.getQ()){
        cout << r.getP() << " > " << r.getQ() << endl;
      } else {
        cout << r.getP() << " <= " << r.getQ() << endl;
      }
    }
};

int main()
{
  MyClass<int, Rational > ll;

  Rational<int> a(4,6), b(10, 2);

  ll.showND(a);
  cout << a << " + " << b << " = " << (a + b) << endl;

  Rational<long> x(-5,3), y(-3,3), z(5, 6);
  cout << x << " - " << y << " = " << (x - y) << endl;

  Rational<long> t = x + y + z;
  cout << x << " + " << y << " + " << z << " = " << t << endl;

  Rational<int> k(1,6), l(1,2);
  cout << k << " + " << l << " = " << (k+l) << endl;

  cout << "Vvedite: ";
  Rational<int> yy;
  cin >> yy;
  cout << yy;

  return 0;
}
