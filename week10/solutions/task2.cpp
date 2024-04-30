#include <iostream>

template <typename T>
class Logger {
public:
  void log(T data);
};

class Point {
public:
  int x, y;
};

class Rat {
public:
  int nom, denom;
};

template<>
void Logger<Point>::log(Point p) {
  std::cout << "(" << p.x << "," << p.y << ")" << std::endl;
}

template<>
void Logger<Rat>::log(Rat r) {
  std::cout << r.nom << "/" <<  r.denom << std::endl;
}

int main() {
  Logger<Point> l;

  l.log({ 1, 2 });
  // output: (1,2)

  Logger<Rat> l1;

  l1.log({ 1, 2 });
  // output: 1/2
}