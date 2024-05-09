#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Colorable.h"
#include "Shape.h"

class Rectangle: public Shape, public Colorable {
private:
  float a;
  float b;

public:
  Rectangle(float a, float b, const char* color);
  float area() const;
  void print() const;
};

#endif