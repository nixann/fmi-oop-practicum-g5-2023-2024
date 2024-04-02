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

  i_file.seekg(0, std::ios::end);

  std::cout << "FILE SIZE: " << i_file.tellg();

  i_file.close();
  return 0;
}
