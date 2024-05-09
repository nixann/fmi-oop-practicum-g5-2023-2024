#ifndef SHAPE_H
#define SHAPE_H

#include "Printable.h"

class Shape: public Printable {
public:
  virtual float area() const = 0;
  virtual ~Shape() {}
};

#endif
