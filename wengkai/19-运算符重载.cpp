#include <iostream>
using namespace std;

//: C12:OperatorOverloadingSyntax.cpp
class Integer {
  int i;

public:
  Integer(int ii) : i(ii) {}
  const Integer operator+(const Integer &rv) const {
    cout << "operator+" << endl;
    return Integer(i + rv.i);
  }
  Integer &operator+=(const Integer &rv) {
    cout << "operator+=" << endl;
    i += rv.i;
    return *this;
  }
  const Integer &operator++() {
    *this += 1;
    return *this;
  }
  const Integer operator++(int) {
    Integer old(*this);
    ++(*this);
    return old;
  }
  bool operator==(const Integer &rhs) const { return i == rhs.i; }
  bool operator!=(const Integer &rhs) const { return !(*this == rhs); }
  bool operator<(const Integer &rhs) const { return i < rhs.i; }
  bool operator>(const Integer &rhs) const { return rhs < *this; }
  bool operator<=(const Integer &rhs) const { return !(rhs < *this); }
  bool operator>=(const Integer &rhs) const { return !(*this < rhs); }
};

class Vector {
public:
  Vector(int size) : m_size(size) { m_array = new int[m_size]; }
  ~Vector() { delete m_array; }
  int &operator[](int index) { return m_array[index]; }

private:
  int m_size;
  int *m_array;
};

int main() {
  cout << "built-in types:" << endl;
  int i = 1, j = 2, k = 3;
  k += i + j;
  cout << "user-defined types:" << endl;
  Integer ii(1), jj(2), kk(3);
  kk += ii + jj;
  Vector v(10);
  cout << v[10] << endl;
} ///:~