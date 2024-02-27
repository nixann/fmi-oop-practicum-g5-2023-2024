#include <iostream>
#include <cmath>

struct Point {
  int x;
  int y;

  void read();

  float dist_to(Point& point) const;
  float dist_to_center() const;
};


void Point::read() {
  std::cout << "x: " << std::endl;
  std::cin >> this->x;

  std::cout << "y: " << std::endl;
  std::cin >> this->y;
}


float Point::dist_to(Point& point) const {
  return sqrt(pow(point.x - this->x, 2) + pow(point.y - this->y, 2));
}

float Point::dist_to_center() const {
  Point center = { 0, 0 };
  return this->dist_to(center);
}

struct Rectangle {
  Point p1;
  Point p2;

  void read();

  bool contains(Point& p) const;
  bool intersects_with(Rectangle& rect) const;
};

void Rectangle::read() {
  this->p1.read();
  this->p2.read();
}

bool Rectangle::contains(Point& p) const{
  // тук се налага използването на min и max, защото не знаем взаимното разположение на точките p1 и p2
  return p.x >= std::min(this->p1.x, this->p2.x) &&
         p.x <= std::max(this->p1.x, this->p2.x) &&
         p.y >= std::min(this->p1.y, this->p2.y) &&
         p.y <= std::max(this->p1.y, this->p2.y);
}

bool Rectangle::intersects_with(Rectangle& rect) const {
  // правоъгълниците са един под друг (тук отново се налага използването на min и max, поради същата причина, като в contains)
  if (std::max(this->p1.y, this->p2.y) < std::min(rect.p1.y, rect.p2.y) || std::max(rect.p1.y, rect.p2.y) < std::min(this->p1.y, this->p2.y)) {
    return false;
  }
  // правоъгълниците са един до друг
  if (std::max(this->p1.x, this->p2.x) < std::min(rect.p1.x, rect.p2.x) || std::max(rect.p1.x, rect.p2.x) < std::min(this->p1.x, this->p2.x)) {
    return false;
  } 

  return true;
}

int main() {
  return 0;
}