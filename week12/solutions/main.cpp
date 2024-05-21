#include <iostream>
#include "LibraryItem.h"
#include "Book.h"
#include "Vinyl.h"
#include "SpecialEditionBook.h"
#include "SpecialEditionVinyl.h"
#include "Library.h"

int main() {
  Book* book = new Book(1, "book1", true, "author1", 100);
  Vinyl* vinyl = new Vinyl(2, "vinyl2", true, "singer2", 180);
  SpecialEditionBook* special_book = new SpecialEditionBook(3, "special book", true, "special author", 120, 1);
  SpecialEditionVinyl* special_vinyl = new SpecialEditionVinyl(4, "special vinyl", true, "special singer", 200, 2);

  LibraryItem* items[4] = { book, vinyl, special_book, special_vinyl};

  Library lib = Library(items, 4);

  lib.print_all();

  // output:
  // Book title: book1, Author: author1, Number of pages: 100
  // Record title: vinyl2, Singer: singer2, Length in seconds: 180
  // Book title: special book, Author: special author, Number of pages: 120
  // This is a special edition book with rarity: 1
  // Record title: special vinyl, Singer: special singer, Length in seconds: 200
  // This is a special edition record with rarity: 2

  lib.find(1)->print_details();
  // output:
  // Book title: book1, Author: author1, Number of pages: 100

  lib.checkout(1);
  lib.print_available();
  // output
  // Record title: vinyl2, Singer: singer2, Length in seconds: 180
  // Book title: special book, Author: special author, Number of pages: 120
  // This is a special edition book with rarity: 1
  // Record title: special vinyl, Singer: special singer, Length in seconds: 200
  // This is a special edition record with rarity: 2

  lib.remove(1);
  Book* new_book = new Book(5, "book5", true, "author5", 300);
  lib.add(new_book);

  lib.print_all();
  // output
  // Record title: vinyl2, Singer: singer2, Length in seconds: 180
  // Book title: special book, Author: special author, Number of pages: 120
  // This is a special edition book with rarity: 1
  // Record title: special vinyl, Singer: special singer, Length in seconds: 200
  // This is a special edition record with rarity: 2
  // Book title: book5, Author: author5, Number of pages: 300
  return 0;
}