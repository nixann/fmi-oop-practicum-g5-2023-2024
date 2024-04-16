#ifndef VECTOR_H
#define VECTOR_H

class Vector {
  static const int RESIZE_FACTOR = 2;

  int* elements;
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

  void push_back(const int value);
  void pop_back();

  const int& operator[](int index) const;
  void insert_at(unsigned index, const int value);
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

  friend std::ostream& operator<<(std::ostream& os, Vector const& v);
  friend std::istream& operator>>(std::istream& is, Vector& v);
  friend int scalar(const Vector& v1, const Vector& v2);
};

#endif
