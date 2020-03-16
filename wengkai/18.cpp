#include <iostream>
using namespace std;

class A {
public:
  /*
      A() : i(0){}    静态变量不可以使用初始化列表的方式初始化
  */
  A() : k("hello") { i = 0; }
  void print() { cout << i << endl; }
  void set(int i) { this->i = i; }
  static void say(int ii) {
    cout << ii << endl;
  } // 静态的函数只可以访问静态的成员变量，因为没有this
private:	
	int k;
  static int i;
  /* 这是声明而不是定义，由于静态意味着它在全局数据区里面，但是从未定义过 */
};

int A::i = 20;
/*
这里初始化没有意义，因为存在构造函数；不可以再加static，因为这样这个变量只可以在这个cpp里面访问和类的访问属性不同
*/

int main() {
  A a, b;
  b.set(10);
  a.print();
  // cout << A::i << endl; //当静态成员变量是public的，那么这个事情是可以做的

  a.say(10);
  A::say(20);
  return 0;
}
