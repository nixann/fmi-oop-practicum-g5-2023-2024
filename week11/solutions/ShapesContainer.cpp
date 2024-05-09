#include "ShapesContainer.h"
#include "Shape.h"

ShapesContainer::ShapesContainer(Shape* shapes[], unsigned shapes_count) {
  this->shapes_count = shapes_count;

  this->shapes = new Shape*[this->shapes_count];
  for (int i = 0; i < this->shapes_count; i++) {
    this->shapes[i] = shapes[i];
  }
}

ShapesContainer::ShapesContainer(ShapesContainer const& other) {
  this->do_copy(other);
}
ShapesContainer& ShapesContainer::operator=(ShapesContainer const& other) {
  if (this != &other) {
    this->do_delete();
    this->do_copy(other);
  }

  return *this;
}

ShapesContainer::~ShapesContainer() {
  this->do_delete();
}

void ShapesContainer::do_copy(ShapesContainer const& other) {
  this->shapes_count = other.get_shapes_count();
  this->shapes = new Shape*[this->shapes_count];
  for (int i = 0; i < this->shapes_count; i++) {
    this->shapes[i] = other.get_shape_at(i);
  }
}

void ShapesContainer::do_delete() {
  delete[] this->shapes;
}

unsigned ShapesContainer::get_shapes_count() const {
  return this->shapes_count;
}

Shape* ShapesContainer::get_shape_at(unsigned index) const {
  if (index >= this->shapes_count) {
    throw "Invalid index";
  }

  return this->shapes[index];
}

void ShapesContainer::print_largest() const {
  if (this->shapes_count == 0) {
    return;
  }

  int max_idx = 0;

  for (int i = 1; i < this->shapes_count; i++) {
    if (this->shapes[i]->area() >= this->shapes[max_idx]->area()) {
      max_idx = i;
    }
  }

  this->shapes[max_idx]->print();
}