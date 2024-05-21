#ifndef SPECIAL_EDITION_BOOK_H
#define SPECIAL_EDITION_BOOK_H

#include "Book.h"
#include "Collectible.h"

class SpecialEditionBook: public Book, public Collectible {
public:
  SpecialEditionBook(
    int identifier,
    const char* title,
    bool available,
    const char* author,
    unsigned pages,
    unsigned rarity
  );

  void print_details() override;
  LibraryItem* clone() override;
};

#endif