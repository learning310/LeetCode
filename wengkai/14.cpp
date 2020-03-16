#include <iostream>
using namespace std;

class A {
public:
  A() : i(10) {}
  virtual void f() { cout << "A::f()" << i << endl; }
  int i;
};

class B : public A {
public:
  B() : j(20) {}
  virtual void f() { cout << "B::f()" << j << endl; }
  void change() {
    cout << i << endl;
    i = 30;
    cout << i << endl;
  }

private:
  int j;
};

int main() {
  A a, b;
  a.f();
  cout << sizeof(a) << endl;

  int *p = (int *)&a;
  int *q = (int *)&b;
  cout
      << *p << endl
      << *q
      << endl; // q指向的是a这个对象，所以*q也就是存放着vptr里面的地址，指向A类的virtual函数
  int *x = (int *)*p;
  cout
      << x << endl
      << *x
      << endl; // x是将virtual函数的地址拿过来，从而*x也就是vtable里面的第一项的内容是什么
  int *o =
      (int *)*x; // o指向函数，o里面放的是函数的地址，因为vtable里面放的是virtual函数的地址

  A a1;
  B b1;

  A *p1 = &b1;
  p1->f();

  b1.change();
  a1 = b1; // 只是指的传递，而不会发生vptr的改变
  A *y = &a1;
  y->f();

  int *r = (int *)&a1;
  int *t = (int *)&b1;
  *r = *t;
  A *p2 = &a1; 
  p2->f();

  A *aa = new A;
  B *bb = new B;
  aa = bb;
  aa->f();

  return 0;
}
