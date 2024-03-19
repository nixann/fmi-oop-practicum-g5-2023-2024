#include <cstring>
#include "Author.h"

Author::Author() : name(nullptr) { }

Author::Author(const char* name) : name(nullptr) {
  this->set_name(name);
}

Author::Author(Author const& other) {
  this->do_copy(other);
}

void Author::set_name(const char* name) {
  if (this->name != nullptr) {
    delete[] this->name;
  }
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

const char* Author::get_name() const {
  return this->name;
}

Author& Author::operator=(Author const& other) {
  if (this != &other) {
    this->do_delete();
    this->do_copy(other);
  }
  return *this;
}

void Author::do_copy(Author const& other) {
  this->name = new char[strlen(other.get_name()) + 1];
  strcpy(this->name, other.get_name());
}

void Author::do_delete() {
  delete[] this->name;
}

Author::~Author() {
  this->do_delete();
}

