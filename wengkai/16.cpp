// some mistakes will happen here
//: C11:HowMany.cpp
#include <iostream>
#include <string>
using namespace std;

class HowMany {
  static int objectCount;

public:
  HowMany() {
    objectCount++;
    print("HowMany()");
  }
  HowMany(int i) {
    objectCount++;
    print("HowMany(int)");
  }
  static void print(const string &msg = "") {
    if (msg.size() != 0)
      cout << msg << ": ";
    cout << "objectCount = " << objectCount << endl;
  }
  ~HowMany() {
    objectCount--;
    print("~HowMany()");
  }
};

int HowMany::objectCount = 0;

// Pass and return BY VALUE:
HowMany f(HowMany x) {
  cout << "begin of f" << endl;
  x.print("x argument inside f()");
  cout << "end of f" << endl;
  return x;
}

int main() {
  HowMany h;
  HowMany::print("after construction of h");
  HowMany h2 = f(h);
  HowMany::print("after call to f()");
}