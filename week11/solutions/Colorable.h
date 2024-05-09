#ifndef COLORABLE_H
#define COLORABLE_H

class Colorable {
  char* color;

public:
  Colorable(const char* color);
  Colorable(Colorable const& other);
  Colorable& operator=(Colorable const& other);
  ~Colorable();

  char* get_color() const;
  void set_color(char* color);
};

#endif

