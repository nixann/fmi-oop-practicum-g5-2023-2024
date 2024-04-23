#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person {
  char* name;
  unsigned age;

  void do_copy(Person const& other);
  void do_delete();
public:
  Person();
  Person(Person const& other);
  Person& operator=(Person const& other);

  char* get_name() const;
  void set_name(char* name);

  void read_name(std::istream& is);

  unsigned get_age() const;
  void set_age(int age);

  ~Person();
};

#endif