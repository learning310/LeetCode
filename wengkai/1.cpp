// 域的解析符
#include <iostream>
using namespace std;

class S{
    public: 
    void f();
};

void f(){
    cout << "This is global f()" << endl;
}

void S::f(){
    ::f();
    cout << "This is S::f()" << endl;
}

int main(int argc, char const *argv[])
{
    S s;
    s.f();
    return 0;
}