#include <iostream>
#include <cstring>
#include "Library.h"

Library::Library() {
  this->capacity = 10;
  this->number_of_books = 0;
  this->books = new Book[this->capacity];
}

Library::Library(Library const& other) {
  this->do_copy(other);
}

void Library::add_book(Book book) {
  if (this->number_of_books >= this->capacity) {
    this->resize();
  }
  
  this->books[this->number_of_books++] = book;
}

const Book& Library::get_book_at(unsigned index) const {
  if (index >= this->number_of_books) {
    throw "Invalid index";
  }

  return this->books[index];
}

const int Library::get_number_of_books() const {
  return this->number_of_books;
}

const int Library::get_capacity() const {
  return this->capacity;
}

void Library::query_by_title(const char* title) const {
  for (int i = 0; i < this->number_of_books; i++) {
    if (strcmp(this->books[i].get_title(), title) == 0) {
      this->books[i].view_details();
      return;
    }
  }

  std::cout << "Book with title: " << title << " was not found" << std::endl;
}

void Library::query_by_genre(const char* genre) const {
  for (int i = 0; i < this->number_of_books; i++) {
    if (strcmp(this->books[i].get_genre(), genre) == 0) {
      this->books[i].view_details();
      return;
    }
  }

  std::cout << "Book with genre: " << genre << " was not found" << std::endl;
}

void Library::query_by_year(const int year) const {
  for (int i = 0; i < this->number_of_books; i++) {
    if (this->books[i].get_year() == year) {
      this->books[i].view_details();
      return;
    }
  }

  std::cout << "Book for year: " << year << " was not found" << std::endl;
}

void Library::query_by_author_name(const char* author_name) const {
  for (int i = 0; i < this->number_of_books; i++) {
    if (strcmp(this->books[i].get_author().get_name(), author_name) == 0) {
      this->books[i].view_details();
      return;
    }
  }

  std::cout << "Book from author: " << author_name << " was not found" << std::endl;
}

Library& Library::operator=(Library const& other) {
  if (this != &other) {
    this->do_delete();
    this->do_copy(other);
  }
  return *this;
}

void Library::resize() {
  this->capacity *= Library::RESIZE_FACTOR;
  Book* new_books = new Book[this->capacity];

  for (int i = 0; i < this->number_of_books; ++i) {
    new_books[i] = this->get_book_at(i);
  }

  delete[] books;
  books = new_books;
}

void Library::do_copy(Library const& other) {
  this->books = new Book[other.get_number_of_books()];

  for (int i = 0; i < other.get_number_of_books(); i++) {
    this->books[i] = other.get_book_at(i);
  }
  
  this->number_of_books = other.get_number_of_books();
  this->capacity = other.get_capacity();
}

void Library::do_delete() {
  delete[] this->books;
}

Library::~Library() {
  this->do_delete();
}
