#ifndef AUTHOR_H
#define AUTHOR_H
class Author {
  char name[30];

public:
  Author();
  Author(const char* name);

  const char* get_name() const;  
  void set_name(const  char* name);  
};

#endif