#include <cmath>
#include <iostream>
#include "Circle.h"
#include "Colorable.h"

Circle::Circle(float radius, const char* color) : Colorable(color) {
  this->radius = radius;
}

float Circle::area() const {
  return 3.14 * pow(this->radius, 2);
}

void Circle::print() const {
  std::cout << "Форма: кръг, цвят: " << this->get_color() << ", лице: " << this->area() << std::endl;
}