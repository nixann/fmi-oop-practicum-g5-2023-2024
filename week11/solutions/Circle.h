#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Colorable.h"

class Circle: public Shape, public Colorable {
private:
  float radius;

public:
  Circle(float radius, const char* color);

  float area() const;
  void print() const;
};

#endif