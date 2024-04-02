#include <iostream>
#include <fstream>

int main() {
  char filename[30];

  std::cin.getline(filename, 30);


  std::ifstream i_file;

  i_file.open(filename);

  if (!i_file.is_open()) {
    throw "An error occured while openning the file";
  }

  char c;

  while (i_file.get(c)) {
    std::cout << c;
  }

  i_file.close();

  return 0;
}
