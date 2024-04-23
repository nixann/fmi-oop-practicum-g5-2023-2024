#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>

class Student: public Person {
  unsigned fn;
  unsigned grade;

  friend std::ostream& operator<<(std::ostream& os, Student const& s);
  friend std::istream& operator>>(std::istream& is, Student& s);

public:
  Student();

  unsigned get_grade() const;
  void set_grade(unsigned grade);
};

#endif