class One {
public:
  One() {}
};

class Two {
  explicit Two(const One& ) {} // 使用explicit禁止自动类型转换
};

void f(Two){}

int main(){
  One one;
  f(one);
}
