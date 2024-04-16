#include <iostream>
#include <cmath>
#include "Vector.h"

Vector::Vector() {
  this->capacity = 10;
  this->number_of_elements = 0;
  this->elements = new int[this->capacity];
}

Vector::Vector(Vector const& other) {
  this->do_copy(other);
}

Vector& Vector::operator=(Vector const& other) {
  if (this != &other) {
    this->do_delete();
    this->do_copy(other);
  }
  return *this;
}

void Vector::push_back(const int value) {
  if (this->number_of_elements >= this->capacity) {
    this->resize_up();
  }
  
  this->elements[this->number_of_elements++] = value;
}

void Vector::pop_back() {
  if (this->number_of_elements == 0) {
    return;
  }

  this->number_of_elements--;

  if (this->number_of_elements * 2 <= this->capacity) {
    this->resize_down();
  }
}

const int& Vector::operator[](int index) const {
  if (std::abs(index) >= this->number_of_elements) {
    throw "Invalid index";
  }

  if (index < 0) {
    return this->elements[this->number_of_elements + index];
  }

  return this->elements[index];
}

void Vector::insert_at(unsigned index, const int value) {
  if (index >= this->number_of_elements) {
    throw "Invalid index";
  }

  if (this->number_of_elements >= this->capacity) {
    this->resize_up();
  }

  for (int i = this->number_of_elements - 1; i >= index; i--) {
    this->elements[i + 1] =  this->elements[i];
  }

  this->elements[index] = value;
  this->number_of_elements++;
}

void Vector::delete_at(unsigned index) {
  if (index >= this->number_of_elements) {
    throw "Invalid index";
  }

  if (this->number_of_elements == 0) {
    return;
  }

  for (int i = index; i < this->number_of_elements - 1; i++) {
    this->elements[i] =  this->elements[i + 1];
  }

  this->number_of_elements--;

  if (this->number_of_elements * 2 <= this->capacity) {
    this->resize_down();
  }
}

bool Vector::operator==(const Vector& other) {
  if (this->number_of_elements != other.get_number_of_elements()) {
    return false;
  }

  for (int i = 0; i < this->number_of_elements; i++) {
    if (this->elements[i] != other[i]) {
      return false;
    }
  }

  return true;
}

bool Vector::operator!=(const Vector& other) {
  return !(*this == other);
}

bool Vector::operator<(const Vector& other) {
  for (int i = 0; i < this->number_of_elements; i++) {
    for (int j = 0; j < other.get_number_of_elements(); j++) {
      if (this->elements[i] >= other[j]) {
        return false;
      }
    }
  }

  return true;
}

bool Vector::operator>(const Vector& other) {
  for (int i = 0; i < this->number_of_elements; i++) {
    for (int j = 0; j < other.get_number_of_elements(); j++) {
      if (this->elements[i] <= other[j]) {
        return false;
      }
    }
  }

  return true;
}

void Vector::sort() {
  // bubble sort
  for (int i = 0; i < this->number_of_elements - 1; i++) {
    for (int j = i; j < this->number_of_elements - i - 1; j++) {
      if (this->elements[j] > this->elements[j + 1]) {
        int temp = this->elements[j];
        this->elements[j] = this->elements[j + 1];
        this->elements[j + 1] = temp;
      }
    }
  }
}

void Vector::operator+=(const Vector& other) {
  for (int i = 0; i < other.get_number_of_elements(); i++) {
    this->push_back(other[i]);
  }
}

void Vector::slice(const unsigned start, const unsigned end) {
  if (start >= this->number_of_elements || end >= this->number_of_elements) {
    throw "Invalid index";
  }

  int* new_elements = new int[this->capacity];

  int number_of_sliced = end - start + 1;

  for (int i = 0; i < number_of_sliced; i++) {
    new_elements[i] = this->elements[start + i];
  }

  this->number_of_elements = number_of_sliced;

  delete[] this->elements;
  this->elements = new_elements;

  if (this->number_of_elements * 2 <= this->capacity) {
    this->resize_down();
  }
}

void Vector::reverse() {
  for (int i = 0; i <= (this->number_of_elements / 2) - 1; i++) {
    int temp = this->elements[i];
    this->elements[i] = this->elements[this->number_of_elements - i - 1];
    this->elements[this->number_of_elements - i - 1] =  temp;
  }
}

const int Vector::get_number_of_elements() const {
  return this->number_of_elements;
}

const int Vector::get_capacity() const {
  return this->capacity;
}

void Vector::print() const {
  for (int i = 0; i < this->number_of_elements; i++) {
    std::cout << this->elements[i] << " ";
  }
  std::cout << std::endl;
}

void Vector::resize_up() {
  this->capacity *= Vector::RESIZE_FACTOR;
  int* new_elements = new int[this->capacity];

  for (int i = 0; i < this->number_of_elements; ++i) {
    new_elements[i] = this->elements[i];
  }

  delete[] elements;
  this->elements = new_elements;
}

void Vector::resize_down() {
  this->capacity /= Vector::RESIZE_FACTOR;
  int* new_elements = new int[this->capacity];

  for (int i = 0; i < this->number_of_elements; ++i) {
    new_elements[i] = this->elements[i];
  }

  delete[] elements;
  this->elements = new_elements;
}

void Vector::do_copy(Vector const& other) {
  this->elements = new int[other.get_number_of_elements()];

  for (int i = 0; i < other.get_number_of_elements(); i++) {
    this->elements[i] = other[i];
  }
  
  this->number_of_elements = other.get_number_of_elements();
  this->capacity = other.get_capacity();
}

void Vector::do_delete() {
  delete[] this->elements;
}

Vector::~Vector() {
  this->do_delete();
}

std::ostream& operator<<(std::ostream& os, Vector const& v) {
  for (int i = 0; i < v.get_number_of_elements(); i++) {
    os << v[i];

    if (i < v.get_number_of_elements() -  1) {
      os << ", ";
    }
  }
  os << std::endl;
  return os;
}
std::istream& operator>>(std::istream& is, Vector& v) {
  char c;
  int current_num = 0;
  int sign = 1;
  bool accumulating = false;

  if (v.elements != nullptr) {
    v =  Vector();
  }

  while (is.get(c) && c != '\n') {
    if (c == '-') {
      sign = -1;
    }
    else if (c >= '0' && c <= '9') {
      accumulating = true;
      current_num = 10 * current_num + (c - '0');
    }
    else if (c == ',') {
      v.push_back(current_num * sign);
      current_num = 0;
      sign = 1;
      accumulating = false;
    }
  }

  // последният символ от редицата не е бил запетая
  if (accumulating) {
    v.push_back(current_num * sign);
  }

  return is;
}

int scalar(const Vector& v1, const Vector& v2) {
  int min_size = std::min(v1.get_number_of_elements(), v2.get_number_of_elements());

  int result = 0;

  for (int i = 0; i < min_size; i++) {
    result += v1[i] * v2[i];
  }

  return result;
}
