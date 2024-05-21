#include "Vinyl.h"
#include "LibraryItem.h"
#include <iostream>
#include <cstring>

Vinyl::Vinyl(int identifier, const char* title, bool available, const char* singer, unsigned length) : LibraryItem(identifier, title, available), length(length) {
  if (strlen(singer) >= 127) {
    throw "The length of the singer must be less than 127";
  }

  strcpy(this->singer, singer);
}

const char* Vinyl::get_singer() const {
  return this->singer;
}


const unsigned Vinyl::get_length() const {
  return this->length;
}

void Vinyl::print_details() {
  std::cout << "Record title: " << this->get_title() << ", Singer: " << this->singer << ", Length in seconds: " << this->length << std::endl;
}

LibraryItem* Vinyl::clone() {
  return new Vinyl(this->get_identifier(), this->get_title(), this->is_available(), this->singer, this->length);
}
