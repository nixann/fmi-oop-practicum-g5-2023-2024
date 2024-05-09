#ifndef PRINTABLE_H
#define PRINTABLE_H

class Printable {
public:
  virtual void print() const = 0;
  virtual ~Printable() {}
};

#endif
