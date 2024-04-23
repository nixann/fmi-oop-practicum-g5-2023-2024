#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"
#include "Student.h"
#include <iostream>

class Teacher: public Person {
  char* course_name;
  int students_count;
  int students_capacity;
  Student* students;

  void do_copy(Teacher const& other);
  void resize_students();
  void do_delete();

  friend std::ostream& operator<<(std::ostream& os, Teacher const& t);
  friend std::istream& operator>>(std::istream& is, Teacher& t);
public:
  Teacher();

  Teacher(Teacher const& other);

  Teacher& operator=(Teacher const& other);

  char* get_course_name() const;
  void set_course_name(char* course);

  int get_students_count() const;

  const Student& get_student_at(unsigned index) const;

  void push_back_student(Student const& student);

  void sort_students_by_grade();

  ~Teacher();
};

#endif