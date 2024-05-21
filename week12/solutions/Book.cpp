#include "Book.h"
#include "LibraryItem.h"
#include <iostream>
#include <cstring>

Book::Book(int identifier, const char* title, bool available, const char* author, unsigned pages) : LibraryItem(identifier, title, available), pages(pages) {
  if (strlen(author) >= 127) {
    throw "The length of the author must be less than 127";
  }

  strcpy(this->author, author);
}

const char* Book::get_author() const {
  return this->author;
}

const unsigned Book::get_pages() const {
  return this->pages;
}

void Book::print_details() {
  std::cout << "Book title: " << this->get_title() << ", Author: " << this->author << ", Number of pages: " << this->pages << std::endl;
}

LibraryItem* Book::clone() {
  return new Book(this->get_identifier(), this->get_title(), this->is_available(), this->author, this->pages);
}
