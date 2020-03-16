#include <iostream>
using namespace std;

class A {
public:
  int i;
  A() : i(10) {}
};
A fun() {
  A a;
  return a;
}

void f(const int &i) { cout << i << endl; }

int main(void) {
  int tmp = 3;
  f(tmp * 3);

  fun().i = 10;
  A b;
  fun() = b;
  return 0;
}
