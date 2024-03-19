#ifndef BOOK_H
#define BOOK_H

#include "Author.h"

class Book {
  char title[30];
  char genre[30];
  unsigned year;
  Author author;

public:
  Book();
  Book(const char* title, const char* genre, const int year, const Author author);

  const char* get_title() const;
  void set_title(const char* title);

  const char* get_genre() const;
  void set_genre(const char* genre);

  const int get_year() const;
  void set_year(const int year);

  const Author get_author() const;
  void set_author(const Author author);

  void view_details() const;
};

#endif