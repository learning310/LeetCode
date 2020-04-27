#include <iostream>
using namespace std;

class Employee {
public:
  Employee(const std::string &name, const std::string &ssn);
  const std::string &get_name() const;
  void print(std::ostream &out) const;
  void print(std::ostream &out, const std::string &msg) const;

protected: // 这是一种偷懒的做法，应该做成私有的，只提供函数让子类访问
  std::string m_name;
  std::string m_ssn;
};
Employee::Employee(const string &name, const std::string &ssn)
    : m_name(name), m_ssn(ssn) {
  // initializer list sets up the values!
}
inline const std::string &Employee::get_name() const { return m_name; }

inline void Employee::print(std::ostream &out) const {
  out << m_name << endl;
  out << m_ssn << endl;
}
inline void Employee::print(std::ostream &out, const std::string &msg) const {
  out << msg << endl;
  print(out); // 尽量利用现有代码去实现，降低代码维护难度
}
class Manger : public Employee {
public:
  Manger(const std::string &name, const std::string &ssn,
         const std::string &title);
  const std::string title_name() const;
  const std::string &get_title() const;
  void print(std::ostream &out) const;

private:
  std::string m_title;
};
Manger::Manger(const std::string &name, const std::string &ssn,
               const std::string &title = "")
    : Employee(name, ssn), m_title(title) {}

inline void Manger::print(std::ostream &out) const {
  Employee::print(out); // call base class of print
  out << m_title << endl;
}
inline const std::string &Manger::get_title() const { return m_title; }
inline const std::string Manger::title_name() const {
  return string(m_title + ":" + m_name); // access base m_name
}
int main() {
  Employee bob("Bob jones", "555-44-0000");
  Manger bill("Bill Smith", "666-55-1234", "Important Person");
  string name = bill.get_name();  // okay Manger inherits Employee
  //string title = bob.get_title(); // Error -- bob is an Employee!
  cout << bill.title_name() << endl;
  bill.print(cout);
  bob.print(cout);
  bob.print(cout, "Employee:");
  //bill.print(cout, "Employee:"); // Error hidden!
  bill.Employee::print(cout, "Employee:");
}
