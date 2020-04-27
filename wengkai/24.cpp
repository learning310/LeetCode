template <class T> class Vector {
public: //所有的函数都是函数模板
  Vector(int);
  ~Vector();
  Vector(const Vector &);
  Vector &operator=(const Vector &);
  T &operator[](int);

private:
  T *m_elements;
  int m_size;
};

template <class T> Vector<T>::Vector(int size) : m_size(size) {
  m_elements = new T[m_size];
}

template <class T> Vector<T>::~Vector() { delete m_elements; }

template <class T> T &Vector<T>::operator[](int index) {
  if (index < m_size && index > 0) {
    return m_elements[index];
  } else {
  }
};

template <class T> Vector<T> &Vector<T>::operator=(const Vector<T> &that) {
  if (this != &that) {
    *this = T(that);
  }
  return *this;
}
class Complex {
public:
  Complex(int i) { real = i; vir = 0;}
  Complex() : real(0), vir(0){}
private:
  int real;
  int vir;
};

int main() {
  Vector<int> v1(100);
  Vector<Complex> v2(256);

  v1[20] = 10;
  v2[20] = v1[20]; 
}
