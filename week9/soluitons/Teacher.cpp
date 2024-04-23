#include "Teacher.h"
#include "Student.h"

void Teacher::do_copy(Teacher const& other) {
  this->course_name = new char[strlen(other.course_name) + 1];
  strcpy(this->course_name, other.get_course_name());
  this->students = new Student[other.get_students_count()];

  for (int i = 0; i < other.get_students_count(); i++) {
    this->students[i] = other.get_student_at(i);
  }
  
  this->students_count = other.get_students_count();
}

void Teacher::do_delete() {
  delete[] this->course_name;
  delete[] this->students;
}

void Teacher::resize_students() {
  this->students_capacity *= 2;
  Student* new_students = new Student[this->students_capacity];

  for (int i = 0; i < this->students_count; ++i) {
    new_students[i] = this->students[i];
  }

  delete[] students;
  this->students = new_students;

}

Teacher::Teacher() {
  this->students = new Student[10];
  this->course_name = new char[1];
  strcpy(this->course_name, "");
  this->students_count = 0;
  this->students_capacity = 10;
}

Teacher::Teacher(Teacher const& other) {
  this->do_copy(other);
}

Teacher& Teacher::operator=(Teacher const& other) {
  if (this != &other) {
    this->do_delete();
    this->do_copy(other);
  }

  return *this;
}

char* Teacher::get_course_name() const {
  return this->course_name;
}

void Teacher::set_course_name(char* course_name) {
  delete[] this->course_name;

  this->course_name = new char[strlen(course_name) + 1];
  strcpy(this->course_name, course_name);
}

int Teacher::get_students_count() const {
  return this->students_count;
}

const Student& Teacher::get_student_at(unsigned index) const {
  if (index >= this->students_count) {
    throw "Invalid index";
  }

  return this->students[index];
}

void Teacher::push_back_student(Student const& student) {
  if (this->students_count >= this->students_capacity) {
    this->resize_students();
  }

  this->students[this->students_count++] = student;
}

void Teacher::sort_students_by_grade() {
  // bubble sort в намаляващ ред
  for (int i = 0; i < this->students_count - 1; i++) {
    for (int j = i; j < this->students_count - i - 1; j++) {
      if (this->students[j].get_grade() < this->students[j + 1].get_grade()) {
        Student temp = this->students[j];
        this->students[j] = this->students[j + 1];
        this->students[j + 1] = temp;
      }
    }
  }
}

Teacher::~Teacher() {
  this->do_delete();
}

std::ostream& operator<<(std::ostream& os, Teacher const& t) {
  os << "Учител: " << t.get_name() << "," << t.get_age() << std::endl;
  os << "Курс: " << t.get_course_name() << std::endl;

  os << "Суденти:" << std::endl;

  for (int i = 0; i < t.get_students_count(); i++) {
    os << "- " << t.get_student_at(i);
  }

  return os;
}
std::istream& operator>>(std::istream& is, Teacher& t) {
  t.read_name(is);

  // skip the ','
  is.ignore();

  int age;
  is >> age;
  t.set_age(age);

  // skip the '\n'
  is.ignore();

  // аналогично на четенето на името
  char course_name[100];
  is.get(course_name, 100, '\n');
  t.set_course_name(course_name);

  // skip the '\n'
  is.ignore();

  // четем студентите
  char line_start[3];
  
  while (is.get(line_start, 3) && strcmp(line_start, "- ") == 0) {
    Student s;

    is >> s;

    // skip the '\n'
    is.ignore();
    t.push_back_student(s);
  }

  return is;

}