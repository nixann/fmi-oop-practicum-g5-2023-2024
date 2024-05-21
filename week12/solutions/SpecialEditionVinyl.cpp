#include "SpecialEditionVinyl.h"
#include "Vinyl.h"
#include "Collectible.h"
#include "LibraryItem.h"

#include <iostream>

SpecialEditionVinyl::SpecialEditionVinyl(
  int identifier,
  const char* title,
  bool available,
  const char* singer,
  unsigned length,
  unsigned rarity
) : Vinyl(identifier, title, available, singer, length), Collectible(rarity) { }

void SpecialEditionVinyl::print_details() {
  Vinyl::print_details();
  std::cout << "This is a special edition record with rarity: " << this->get_rarity() << std::endl;
}

LibraryItem* SpecialEditionVinyl::clone() {
  return new SpecialEditionVinyl(
    this->get_identifier(),
    this->get_title(),
    this->is_available(),
    this->get_singer(),
    this->get_length(),
    this->get_rarity()
  );
}
