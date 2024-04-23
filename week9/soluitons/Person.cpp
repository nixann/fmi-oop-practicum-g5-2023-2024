#include "Person.h"
#include <cstring>

Person::Person() {
  this->name = new char[1];
  strcpy(this->name, "");
}

void Person::do_copy(Person const& other) {
  this->name = new char[strlen(other.get_name()) + 1];
  strcpy(this->name, other.get_name());
  this->age = other.get_age();
}

void Person::do_delete() {
  delete[] this->name;
}

Person::Person(Person const& other) {
  this->do_copy(other);
}

Person& Person::operator=(Person const& other) {
  if (this != &other) {
    this->do_delete();
    this->do_copy(other);
  }

  return *this;
}

char* Person::get_name() const {
  return this->name;
}

void Person::set_name(char* name) {
  delete[] this->name;

  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

void Person::read_name(std::istream& is) {
  // въпреки че името на човека може да има неограничена дъжлина, тук налагаме максимална дължина на прочетения низ, за да бъде възможно името да бъде прочетено само с една операция.
  // Ако все пак искаме да нямаме ограничение един вариант е да четем символ по символ, докато не се стигне до запетая, в низ, който да преоразмеряваме ръчно.
  char name[100];
  is.get(name, 100, ',');
  this->set_name(name);
}

unsigned Person::get_age() const {
  return this->age;
}

void Person::set_age(int age) {
  this->age = age;
}

Person::~Person() {
  this->do_delete();
}

