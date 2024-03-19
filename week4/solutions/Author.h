#ifndef AUTHOR_H
#define AUTHOR_H
class Author {
  char* name;

  void do_copy(Author const& other);
  void do_delete();
public:
  Author();
  Author(const char* name);
  Author(Author const& other);
  
  Author& operator=(Author const& other);

  const char* get_name() const;  
  void set_name(const  char* name);  

  ~Author();
};

#endif