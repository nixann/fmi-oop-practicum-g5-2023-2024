#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Shape.h"
#include "ShapesContainer.h"

int main() {
  Circle c1 = Circle(2, "red");
  Rectangle r1 = Rectangle(2, 3, "blue");
  Rectangle r2 = Rectangle(4, 5, "green");
  
  Shape* shapes[3] = { &c1, &r1, &r2 };

  ShapesContainer container = ShapesContainer(shapes, 3);

  container.print_largest();
  // Output: Форма: правоъгълник, цвят: green, лице: 20
  return 0;
}