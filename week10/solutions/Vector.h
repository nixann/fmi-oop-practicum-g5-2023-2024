#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>

template <typename T>
class Vector {
  static const int RESIZE_FACTOR = 2;

  T* elements;
  int number_of_elements;
  int capacity;

  void resize_up();
  void resize_down();

  void do_copy(Vector const& other);
  void do_delete();

public:
  Vector();
  Vector(Vector const& other);

  Vector& operator=(Vector const& other);

  void push_back(const T value);
  void pop_back();

  const T& operator[](int index) const;
  void insert_at(unsigned index, const T value);
  void delete_at(unsigned index);

  bool operator==(const Vector& other);
  bool operator!=(const Vector& other);
  bool operator<(const Vector& other);
  bool operator>(const Vector& other);

  void sort();

  void operator+=(const Vector& other);
  void slice(const unsigned start, const unsigned end);
  void reverse();

  const int get_number_of_elements() const;
  const int get_capacity() const;

  void print() const;

  ~Vector();

  // тук е нужно да декларираме приятелските функции като шаблонни, използвайки различен типов параметър от T
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, Vector<U> const& v);
  template <typename U>
  friend std::istream& operator>>(std::istream& is, Vector<U>& v);
  // тази ф-я е махаме, тъй като векторът вече не е ограничен само до числа
  // friend int scalar(const Vector& v1, const Vector& v2);
};

template <typename T>
Vector<T>::Vector() {
  this->capacity = 10;
  this->number_of_elements = 0;
  this->elements = new T[this->capacity];
}

template <typename T>
Vector<T>::Vector(Vector const& other) {
  this->do_copy(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector const& other) {
  if (this != &other) {
    this->do_delete();
    this->do_copy(other);
  }
  return *this;
}

template <typename T>
void Vector<T>::push_back(const T value) {
  if (this->number_of_elements >= this->capacity) {
    this->resize_up();
  }
  
  this->elements[this->number_of_elements++] = value;
}

template <typename T>
void Vector<T>::pop_back() {
  if (this->number_of_elements == 0) {
    return;
  }

  this->number_of_elements--;

  if (this->number_of_elements * 2 <= this->capacity) {
    this->resize_down();
  }
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
  if (std::abs(index) >= this->number_of_elements) {
    throw "Invalid index";
  }

  if (index < 0) {
    return this->elements[this->number_of_elements + index];
  }

  return this->elements[index];
}

template <typename T>
void Vector<T>::insert_at(unsigned index, const T value) {
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

template <typename T>
void Vector<T>::delete_at(unsigned index) {
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

template <typename T>
bool Vector<T>::operator==(const Vector& other) {
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

template <typename T>
bool Vector<T>::operator!=(const Vector& other) {
  return !(*this == other);
}

template <typename T>
bool Vector<T>::operator<(const Vector& other) {
  for (int i = 0; i < this->number_of_elements; i++) {
    for (int j = 0; j < other.get_number_of_elements(); j++) {
      if (this->elements[i] >= other[j]) {
        return false;
      }
    }
  }

  return true;
}

template <typename T>
bool Vector<T>::operator>(const Vector& other) {
  for (int i = 0; i < this->number_of_elements; i++) {
    for (int j = 0; j < other.get_number_of_elements(); j++) {
      if (this->elements[i] <= other[j]) {
        return false;
      }
    }
  }

  return true;
}

template <typename T>
void Vector<T>::sort() {
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

template <typename T>
void Vector<T>::operator+=(const Vector& other) {
  for (int i = 0; i < other.get_number_of_elements(); i++) {
    this->push_back(other[i]);
  }
}

template <typename T>
void Vector<T>::slice(const unsigned start, const unsigned end) {
  if (start >= this->number_of_elements || end >= this->number_of_elements) {
    throw "Invalid index";
  }

  T* new_elements = new T[this->capacity];

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

template <typename T>
void Vector<T>::reverse() {
  for (int i = 0; i <= (this->number_of_elements / 2) - 1; i++) {
    T temp = this->elements[i];
    this->elements[i] = this->elements[this->number_of_elements - i - 1];
    this->elements[this->number_of_elements - i - 1] =  temp;
  }
}

template <typename T>
const int Vector<T>::get_number_of_elements() const {
  return this->number_of_elements;
}

template <typename T>
const int Vector<T>::get_capacity() const {
  return this->capacity;
}

template <typename T>
void Vector<T>::print() const {
  for (int i = 0; i < this->number_of_elements; i++) {
    std::cout << this->elements[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void Vector<T>::resize_up() {
  this->capacity *= Vector::RESIZE_FACTOR;
  T* new_elements = new T[this->capacity];

  for (int i = 0; i < this->number_of_elements; ++i) {
    new_elements[i] = this->elements[i];
  }

  delete[] elements;
  this->elements = new_elements;
}

template <typename T>
void Vector<T>::resize_down() {
  this->capacity /= Vector::RESIZE_FACTOR;
  T* new_elements = new T[this->capacity];

  for (int i = 0; i < this->number_of_elements; ++i) {
    new_elements[i] = this->elements[i];
  }

  delete[] elements;
  this->elements = new_elements;
}

template <typename T>
void Vector<T>::do_copy(Vector const& other) {
  this->elements = new T[other.get_number_of_elements()];

  for (int i = 0; i < other.get_number_of_elements(); i++) {
    this->elements[i] = other[i];
  }
  
  this->number_of_elements = other.get_number_of_elements();
  this->capacity = other.get_capacity();
}

template <typename T>
void Vector<T>::do_delete() {
  delete[] this->elements;
}

template <typename T>
Vector<T>::~Vector() {
  this->do_delete();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Vector<T> const& v) {
  for (int i = 0; i < v.get_number_of_elements(); i++) {
    os << v[i];

    if (i < v.get_number_of_elements() -  1) {
      os << ", ";
    }
  }
  os << std::endl;
  return os;
}

// променяме импленетацията, за да не е ограничена само до цели числа
// забележете, че за да работят operator<< и operator>> то те трябва да са предефинирани и за съответния тип T, с който се инстанцира вектора
template <typename T>
std::istream& operator>>(std::istream& is, Vector<T>& v) {
  std::cout << "Enter number of elements: " << std::endl;
  int num_of_els;
  std::cin >> num_of_els;

  T current_element;
  for (int i = 0; i < num_of_els; i++) {
    is >> current_element;
    v.push_back(current_element);
  }

  return is;
}


#endif
