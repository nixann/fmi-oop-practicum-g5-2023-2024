#ifndef VINYL_H
#define VINYL_H

#include "LibraryItem.h"

class Vinyl: public LibraryItem {
  char singer[127];
  unsigned length;

public:
  Vinyl(int identifier, const char* title, bool available, const char* singer, unsigned length);

  const char* get_singer() const;
  const unsigned get_length() const;

  void print_details() override;
  LibraryItem* clone() override;
};

#endif
