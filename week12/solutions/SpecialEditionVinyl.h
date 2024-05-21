#ifndef SPECIAL_EDITION_VINYL_H
#define SPECIAL_EDITION_VINYL_H

#include "Vinyl.h"
#include "Collectible.h"

class SpecialEditionVinyl: public Vinyl, Collectible {
public:
  SpecialEditionVinyl(
    int identifier,
    const char* title,
    bool available,
    const char* singer,
    unsigned length,
    unsigned rarity
  );

  void print_details() override;
  LibraryItem* clone() override;
};

#endif
