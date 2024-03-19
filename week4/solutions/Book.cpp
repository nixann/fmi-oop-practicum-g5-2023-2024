#include <iostream>
#include <cstring>
#include "Book.h"

Book::Book() : title(nullptr), genre(nullptr) { }

Book::Book(const char* title, const char* genre, const int year, const Author author) : title(nullptr), genre(nullptr){
  this->set_title(title);
  this->set_genre(genre);
  this->set_year(year);
  this->set_author(author);
}

Book::Book(Book const& other) {
  this->do_copy(other);
}

const char* Book::get_title() const {
  return this->title;
}

void Book::set_title(const char* title) {
  if (this->title != nullptr) {
    delete[] this->title;
  }

  this->title = new char[strlen(title) + 1];
  strcpy(this->title, title);
}

const char* Book::get_genre() const {
  return this->genre;
}

void Book::set_genre(const char* genre) {
  if (this->genre != nullptr) {
    delete[] this->genre;
  }

  this->genre = new char[strlen(genre) + 1];
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

Book& Book::operator=(Book const& other) {
  if (this != &other) {
    this->do_delete();
    this->do_copy(other);
  }
  return *this;
}

void Book::do_copy(Book const& other) {
  this->title = new char[strlen(other.get_title()) + 1];
  strcpy(this->title, other.get_title());

  this->genre = new char[strlen(other.get_genre()) + 1];
  strcpy(this->genre, other.get_genre());

  this->year = other.get_year();
  
  this->author = other.get_author();
}

void Book::do_delete() {
  delete[] this->title;
  delete[] this->genre;
}

Book::~Book() {
  this->do_delete();
}
