#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

class Book: public LibraryItem {
  char author[127];
  unsigned pages;

public:
  Book(int identifier, const char* title, bool available, const char* author, unsigned pages);

  const char* get_author() const;
  const unsigned get_pages() const;

  void print_details() override;
  LibraryItem* clone() override;
};

#endif
