#include <iostream>
#include <fstream>

struct Student {
  char name[30];
  int fn;
};

int main() {
  Student s1 = { "Jon Doe", 1234 };

  std::ofstream o_file;
  o_file.open("student.data", std::ios::binary);

  o_file.write((char*)& s1, sizeof(s1));

  o_file.close();

  std::ifstream i_file;

  i_file.open("student.data", std::ios::binary);

  Student s2;

  i_file.read((char*)& s2, sizeof(s2));

  i_file.close();

  std::cout << "S2 name: " << s2.name << std::endl;
  std::cout << "S2 fn: " << s2.fn << std::endl;

  return 0;
}