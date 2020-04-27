#include <iostream>
using namespace std;

class A {
private:
  const int i; // 成员是const的,就必须使用initializer_list初始化
public:
  A() : i(0) {}
  void f() { cout << "f()" << endl; }
  void f() const {
    cout << "f() const" << endl;
  } // 构成了overload的要件,因为this是不同的
};

int main() {
  const A a; // 对象是const的,那么成员必须要初始化
  a.f();
  return 0;
}
