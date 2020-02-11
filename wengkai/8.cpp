#include <iostream>
using namespace std;
class A
{
public:
    A() : i(0) { cout << "A::a()" << endl; }
    ~A() { cout << "A::~A()" << endl; }
    void print() { cout << "A::f()" << endl; }

protected:
    void set(int ii) { i = ii; }

private:
    int i;
};
class B : public A
{
public:
    void f()
    {
        set(20);
        i = 30; // error 子类也不可以操作父类的私有成员
        print();
    }
};
int main()
{
    B b;
    b.set(10); //error 父类的protected函数只可在子类内部调用
    b.print();
    return 0;
}