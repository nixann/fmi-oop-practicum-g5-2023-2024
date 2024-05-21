#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

class LibraryItem {
  int identifier;
  char title[127];
  bool available;

public:
  LibraryItem(int identifier, const char* title, bool available);

  int get_identifier() const;
  const char* get_title() const;
  bool is_available() const;
  void set_available(bool available);

  virtual void print_details() = 0;
  virtual LibraryItem* clone() = 0;

  virtual ~LibraryItem() {}
};

#endif
