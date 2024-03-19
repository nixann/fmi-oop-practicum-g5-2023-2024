#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

class Library {
  static const int RESIZE_FACTOR = 2;

  Book* books;
  int number_of_books;
  int capacity;

  void resize();

  void do_copy(Library const& other);
  void do_delete();
public:
  Library();
  Library(Library const& other);

  Library& operator=(Library const& other);
  void add_book(const Book book);

  const Book& get_book_at(unsigned index) const;

  const int get_number_of_books() const;
  const int get_capacity() const;


  void query_by_title(const char* title) const;
  void query_by_genre(const char* genre) const;
  void query_by_year(const int year) const;
  void query_by_author_name(const char* author_name) const;

  ~Library();
};

#endif