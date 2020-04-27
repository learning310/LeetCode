#include <cstring>
#include <iostream>
using namespace std;

class A { // 在这种情况下 a = a 就会出错
private:
  char *p;

public:
  A &operator=(const A &that) {
    delete p;
    p = new char[strlen(that.p) + 1];
    strcpy(p, that.p);
    return *this;
  }
};

int main() {
  A a;
  a = a;
}