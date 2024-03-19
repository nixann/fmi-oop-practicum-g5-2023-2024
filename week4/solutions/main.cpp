#include <iostream>
#include "Author.h"
#include "Book.h"
#include "Library.h"


int main() {
  Author a1 = Author("JON DOE");
  Author a2 = Author("DOE JON");

  Book b1 = Book("BOOK 1", "GENRE 1", 2023, a1);
  Book b2 = Book("BOOK 2", "GENRE 2", 2020, a2);

  Library l = Library();
  l.add_book(b1);
  l.add_book(b2);

  l.query_by_title("BOOK 1");
  l.query_by_title("BOOK 3");

  l.query_by_genre("GENRE 1");
  l.query_by_genre("GENRE 3");

  l.query_by_author_name("JON DOE");
  l.query_by_author_name("FOO BAR");

  l.query_by_year(2023);
  l.query_by_year(1999);

  /*
    OUTPUT:
    Title: BOOK 1, Author: JON DOE, Genre: GENRE 1, Year of publication: 2023
    Book with title: BOOK 3 was not found
    Title: BOOK 1, Author: JON DOE, Genre: GENRE 1, Year of publication: 2023
    Book with genre: GENRE 3 was not found
    Title: BOOK 1, Author: JON DOE, Genre: GENRE 1, Year of publication: 2023
    Book from author: FOO BAR was not found
    Title: BOOK 1, Author: JON DOE, Genre: GENRE 1, Year of publication: 2023
    Book for year: 1999 was not found
  */
}