#include <iostream>
using namespace std;

class A {
public:
    A(int i) {}
    A() {} //和前面关于构造函数的讨论一样。如果没有这句话，编译就会出错，因为没有default constructor
};

class B {
private:
    A a;
public:
    B(){
        a = 0;
        cout << "here" << endl;
    }
};
int main()
{
    B b;
    return 0;
}