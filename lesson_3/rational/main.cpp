#include <iostream>
#include <assert.h>

using namespace std;

// Рациональная дробь: p/q
class Rational {
  long p,q; // p - числитель, q - знаменатель
  // НОД
  long GCD(long a, long b){
    return (b == 0) ? a : GCD(b, a % b);
  }
  // Сокращение дроби
  void normalize(){
    long d = GCD(p,q);
    p /= d;
    q /= d;
  }
public:
  Rational(long pi, long qi){
    p = pi;
    q = qi;
    assert(q != 0);
    //if(q == 0){
    //  cout << "q == 0" << endl;
    //  halt(1);
    //}
  }
  Rational(const char *message){
    cout << message << " ";
    cout << "p = ";
    cin >> p;
    cout << "q = ";
    cin >> q;
  }
  void show(){
    // Сокращаем дробь если надо
    normalize();

    if(q == 1){
      cout << p << endl;
    } else {
      long whole = p/q;
      if(whole != 0)
        cout << whole << " ";
      cout << (p % q) << "/" << q << endl;
    }
  }
  void add(Rational& right){
    //  p/q + right.p/right.q
    long pNew = p * right.q + right.p * q;
    //   ----   --------------------------
    long qNew = q * right.q;
    p = pNew;
    q = qNew;
  }
  Rational& operator+(Rational& right){
    Rational res = *this;
    res.add(right);
    return res;
  }
  void sub(Rational& right){
    long pNew = p * right.q - right.p * q;
    //   ----   --------------------------
    long qNew = q * right.q;
    p = pNew;
    q = qNew;
  }
  Rational(Rational &r){
    p = r.p;
    q = r.q;
    cout << "Copy contructor " << endl;
  }
};

int main()
{
  Rational a(4,6), b(10, 2);
  a.show();
  b.show();
  Rational c = b + a;
  a.show();
  b.show();
  c.show();

 /* Rational x(4,6), y(1,3);
  x.add(y);
  x.show();

  Rational yy("Vvedite:");
  yy.show(); */

  return 0;
}
