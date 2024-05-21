#include "LibraryItem.h"
#include <cstring>

LibraryItem::LibraryItem(int identifier, const char* title, bool available) : identifier(identifier), available(available) {
  if (strlen(title) >= 127) {
    throw "The length of the title must be less than 127";
  }

  strcpy(this->title, title);
}

int LibraryItem::get_identifier() const {
  return this->identifier;
}

const char* LibraryItem::get_title() const {
  return this->title;
}

bool LibraryItem::is_available() const {
  return this->available;
}

void LibraryItem::set_available(bool available) {
  this->available = available;
}
