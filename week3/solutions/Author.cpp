#include <cstring>
#include "Author.h"

Author::Author() { }

Author::Author(const char* name) {
  this->set_name(name);
}

void Author::set_name(const char* name) {
  if (strlen(name) >= 30) {
    throw "The name of the author must not be longer than 30 characters";
  }

  strcpy(this->name, name);
}

const char* Author::get_name() const{
  return this->name;
}