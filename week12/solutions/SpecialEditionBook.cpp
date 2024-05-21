#include "SpecialEditionBook.h"
#include "Book.h"
#include "Collectible.h"
#include "LibraryItem.h"

#include <iostream>

SpecialEditionBook::SpecialEditionBook(
  int identifier,
  const char* title,
  bool available,
  const char* author,
  unsigned pages,
  unsigned rarity
) : Book(identifier, title, available, author, pages), Collectible(rarity) { }

void SpecialEditionBook::print_details() {
  Book::print_details();
  std::cout << "This is a special edition book with rarity: " << this->get_rarity() << std::endl;
}

LibraryItem* SpecialEditionBook::clone() {
  return new SpecialEditionBook(
    this->get_identifier(),
    this->get_title(),
    this->is_available(),
    this->get_author(),
    this->get_pages(),
    this->get_rarity()
  );
}