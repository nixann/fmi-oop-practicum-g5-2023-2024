#include <iostream>
#include <cstring>
#include "Book.h"

Book::Book() { }

Book::Book(const char* title, const char* genre, const int year, const Author author) {
  this->set_title(title);
  this->set_genre(genre);
  this->set_year(year);
  this->set_author(author);
}

const char* Book::get_title() const {
  return this->title;
}

void Book::set_title(const char* title) {
  if (strlen(title) >= 30) {
    throw "The title of the book must not be longer than 30 characters";
  }

  strcpy(this->title, title);
}

const char* Book::get_genre() const {
  return this->genre;
}

void Book::set_genre(const char* genre) {
  if (strlen(genre) >= 30) {
    throw "The genre of the book must not be longer than 30 characters";
  }

  strcpy(this->genre, genre);
}

const int Book::get_year() const {
  return this->year;
}

void Book::set_year(const int year) {
  this->year = year;
}

const Author Book::get_author() const {
  return this->author;
}

void Book::set_author(const Author author) {
  this->author = author;
}

void Book::view_details() const {
  std::cout << "Title: " << this->get_title() << ", Author: " << this->get_author().get_name() << ", Genre: " << this->get_genre() << ", Year of publication: " << this->get_year() << std::endl;
}
