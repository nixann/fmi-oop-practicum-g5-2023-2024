#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

class Collectible {
  unsigned rarity;

public:
  Collectible(unsigned rarity);

  unsigned get_rarity() const;
};

#endif