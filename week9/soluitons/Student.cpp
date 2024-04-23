#include "Student.h"

Student::Student() { }

unsigned Student::get_grade() const {
  return this->grade;
}

void Student::set_grade(unsigned grade) {
  if (grade < 2 || grade > 6) {
    throw "Invalid value for grade. The student's grade must be in the interval [2, 6]";
  }

  this->grade = grade;
}

std::ostream& operator<<(std::ostream& os, Student const& s) {
  os << s.get_name() << "," << s.get_age() << "," << s.fn << "," << s.grade << std::endl;

  return os;
}

std::istream& operator>>(std::istream& is, Student& s) {
  s.read_name(is);

  // skip the ','
  is.ignore();
  int age;

  is >> age;
  s.set_age(age);
  is.ignore();

  is >> s.fn;
  is.ignore();

  int grade;
  is >> grade;

  s.set_grade(grade);
  return is;
}