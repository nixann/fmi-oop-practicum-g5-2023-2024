#include <iostream>

template <typename T>
T add(T a, T b) {
  return a + b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << "RES: " << add(a, b) << std::endl;

  double c, d;
  std::cin >> c >> d;
  std::cout << "RES: " << add(c, d) << std::endl;
  
  // не може, тъй като сме декларирали ф-ята add да приема аргументи от един и същ тип T
  // std::cout << "RES: " << add(a, c) << std::endl;
}