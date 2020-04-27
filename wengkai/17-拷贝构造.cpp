#include <cstring> // C语言中关于字符串处理的函数
#include <iostream>
#include <stdio.h>
using namespace std;

class Person {
public:
  Person(const char *s);
  ~Person();
  // more reasonable method:
  Person(const Person &w);

  // private:
  char *name;
};

Person::Person(const char *s) {
  name = new char[::strlen(s) + 1];
  ::strcpy(name, s);
}
Person::Person(const Person &w) {
  name = new char[::strlen(w.name) + 1];
  ::strcpy(name, w.name);
}
Person::~Person() { delete[] name; }

int main(void) {
  Person p1("John");
  Person p2(p1); // or Person p2 = p1;

  printf("p1.name = %p\n", p1.name);
  printf("p2.name = %p\n", p2.name);

  return 0;
}