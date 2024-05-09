#include <iostream>
#include "Rectangle.h"
#include "Colorable.h"

Rectangle::Rectangle(float a, float b, const char* color) : Colorable(color) {
  this->a = a;
  this->b = b;
}

float Rectangle::area() const {
  return this->a * this->b;
}

void Rectangle::print() const {
  std::cout << "Форма: правоъгълник, цвят: " << this->get_color() << ", лице: " << this->area() << std::endl;
}
