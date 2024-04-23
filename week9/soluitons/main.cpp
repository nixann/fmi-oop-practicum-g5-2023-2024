#include <iostream>
#include "Teacher.h"

int main() {
  Teacher t;

  // input:

  // Georgi Georgiev,40 
  // OOP
  // - Petar Petrov,20,123,4
  // - Ivan Ivanov,20,321,6
  std::cin >> t;

  t.sort_students_by_grade();

  std::cout << t;

  // output:

  // Учител: Georgi Georgiev,40
  // Курс: OOP
  // Суденти:
  // - Ivan Ivanov,20,321,6
  // - Petar Petrov,20,123,4

  return 0;

}