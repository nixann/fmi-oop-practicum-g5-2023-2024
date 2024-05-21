#include "Library.h"

Library::Library() {
  this->items_count = 0;
  this->capacity = 8;
  this->items = new LibraryItem*[this->capacity];
}

Library::Library(LibraryItem** items, unsigned items_count) : items_count(items_count), capacity(items_count) {
  this->items = new LibraryItem*[this->capacity];

  for (int i = 0; i < items_count; i++) {
    this->items[i] = items[i]->clone();
  }
}

Library::Library(Library const& other) {
  this->do_copy(other);
}

Library& Library::operator=(Library const& other) {
  if (this != &other) {
    this->do_delete();
    this->do_copy(other);
  }

  return *this;
}

Library::~Library() {
  this->do_delete();
}

void Library::do_copy(Library const& other) {
  this->items_count = other.get_items_count();
  this->capacity = this->items_count;

  for (int i = 0; i < this->items_count; i++) {
    this->items[i] = other[i]->clone();
  }
}

void Library::do_delete() {
   for (int i = 0; i < this->items_count; i++) {
    delete this->items[i];
   }

  delete[] this->items;
}

void Library::resize(ResizeDir resize_dir) {
  if (resize_dir == ResizeDir::UP) {
    this->capacity *= 2;
  }
  else {
    this->capacity /= 2;
  }
  
  LibraryItem** new_items = new LibraryItem*[this->capacity];
  for (int i = 0; i < this->items_count; i++) {
    new_items[i] = this->items[i]->clone();
  }

  for (int i = 0; i < this->items_count; i++) {
    delete this->items[i];
  }

  this->items = new_items;
}

const unsigned Library::get_items_count() const {
  return this->items_count;
}

void Library::add(LibraryItem* item) {
  if (this->items_count >= this->capacity) {
    this->resize(ResizeDir::UP);
  }

  this->items[this->items_count++] = item;
}

LibraryItem* Library::operator[](unsigned index) const {
  if (index >= this->capacity) {
    throw "Index out of range";
  }

  return this->items[index];
}

LibraryItem* Library::find(int identifier) const{
  for (int i = 0; i < this->items_count; i++) {
    if (this->items[i]->get_identifier() == identifier) {
      return this->items[i];
    }
  }

  return nullptr;
}

bool Library::remove(int identifier) {
  int item_index = -1;


  for (int i = 0; i < this->items_count; i++) {
    if (this->items[i]->get_identifier() == identifier) {
      item_index = i;
    }
  }

  if (item_index == -1) {
    return false;
  }

  for (int i = item_index; i < this->items_count - 1; i++) {
    this->items[i] = this->items[i + 1];
  }

  this->items_count--;

  if (this->items_count * 2 < this->capacity) {
    this->resize(ResizeDir::DOWN);
  }

  return true;
}

bool Library::checkout(int identifier) {
  for (int i = 0; i < this->items_count; i++) {
    if (this->items[i]->get_identifier() == identifier) {
      this->items[i]->set_available(false);

      return true;

    }
  }
  return false;
}

bool Library::return_item(int identifier) {
  for (int i = 0; i < this->items_count; i++) {
    if (this->items[i]->get_identifier() == identifier) {
      this->items[i]->set_available(true);

      return true;
    }
  }
  return false;
}

void Library::print_all() const {
  for (int i = 0; i < this->items_count; i++) {
    this->items[i]->print_details();
  }
}

void Library::print_available() const {
  for (int i = 0; i < this->items_count; i++) {
    if (this->items[i]->is_available()) {
      this->items[i]->print_details();
    }
  }
}

