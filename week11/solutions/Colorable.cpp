#include <cstring>
#include "Colorable.h"

Colorable::Colorable(const char* color) {
  this->color = new char[strlen(color) + 1];
  strcpy(this->color, color);
}

Colorable::Colorable(Colorable const& other) {
  this->color = new char[strlen(other.get_color()) + 1];
  strcpy(this->color, color);
}

Colorable& Colorable::operator=(Colorable const& other) {
  if (this != &other) {
    delete[] this->color;

    this->color = new char[strlen(other.get_color()) + 1];
    strcpy(this->color, color);
  }

  return *this;
}

Colorable::~Colorable() {
  delete[] this->color;
}

char* Colorable::get_color() const {
  return this->color;
}

void Colorable::set_color(char* color) {
  delete[] this->color;

  this->color = new char[strlen(color) + 1];
  strcpy(this->color, color);  
}