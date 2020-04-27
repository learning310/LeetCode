#include <iostream>
using namespace std;

struct XYPos {
  float x, y;
};

class Shape {
public:
  Shape() {}
  virtual ~Shape() {}
  virtual void resize() {}
  virtual void render() { cout << "in render of shape" << endl; }
  void move(const XYPos &recenter) { center = recenter; }

protected:
  XYPos center;
};

class Test : public Shape {};

class Ellipse : public Shape {
public:
  Ellipse(float maj, float minr) {
    major_axis = maj;
    minor_axis = minr;
  }
  virtual void render() { cout << "in render of ellipse" << endl; }

protected:
  float major_axis, minor_axis;
};

class Circle : public Ellipse {
public:
  Circle(float radius) : Ellipse(radius, radius) {}
  virtual void render() { cout << "in render of circle" << endl; }
};

void render(Shape *p) { p->render(); } // p是一个多态对象

int main() {
  Ellipse ell(10, 20);
  ell.render();
  Circle circ(40);
  circ.render();
  render(&ell); // upcast
  render(&circ);
  Test t;
  render(&t);
  return 0;
}
