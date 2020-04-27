class Orange;

class Apple {
public:
  operator Orange() const;
};

class Orange {
public:
  Orange(Apple);
};

void f(Orange) {}

int main() {
  Apple a;
  f(a); // ambigious conversion
}