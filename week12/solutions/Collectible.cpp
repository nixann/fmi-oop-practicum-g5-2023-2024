#include "Collectible.h"

Collectible::Collectible(unsigned rarity) : rarity(rarity) { }

unsigned Collectible::get_rarity() const {
  return this->rarity;
}
