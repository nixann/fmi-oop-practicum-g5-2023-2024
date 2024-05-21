#ifndef LIBRARY_H
#define LIBRARY_H

#include "LibraryItem.h"

enum ResizeDir {
  UP,
  DOWN
};

class Library {
  LibraryItem** items;
  unsigned items_count;
  unsigned capacity;

  void do_copy(Library const& other);
  void do_delete();

  void resize(ResizeDir resize_dir);

public:
  Library();
  Library(LibraryItem** items, unsigned items_count);

  Library(Library const& other);
  Library& operator=(Library const& other);

  ~Library();

  const unsigned get_items_count() const;

  void add(LibraryItem* item);
  LibraryItem* operator[](unsigned index) const;
  LibraryItem* find(int identifier) const;
  bool remove(int identifier);
  bool checkout(int identifier);
  bool return_item(int identifier);
  void print_all() const;
  void print_available() const;

};

#endif