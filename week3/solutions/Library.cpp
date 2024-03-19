#include <iostream>
#include <cstring>
#include "Library.h"

Library::Library() {
  this->number_of_books = 0;
}

void Library::add_book(Book book) {
  if (this->number_of_books >= 50) {
    throw "Library capacity exceeded. The library can contain no more than 50 books";
  }

  this->books[this->number_of_books++] = book;
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