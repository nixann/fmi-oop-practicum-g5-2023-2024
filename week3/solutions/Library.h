#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

class Library {
  Book books[50];
  int number_of_books;
public:
  Library();
  void add_book(const Book book);

  void query_by_title(const char* title) const;
  void query_by_genre(const char* genre) const;
  void query_by_year(const int year) const;
  void query_by_author_name(const char* author_name) const;
};

#endif