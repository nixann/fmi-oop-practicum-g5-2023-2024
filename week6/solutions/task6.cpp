#include <iostream>
#include <fstream>

int main() {
  char i_filename[30];
  std::cin.getline(i_filename, 30);

  char o_filename[30];
  std::cin.getline(o_filename, 30);


  std::ifstream i_file;
  i_file.open(i_filename);

  std::ofstream o_file;
  o_file.open(o_filename, std::ios::out | std::ios::app);

  if (!i_file.is_open() || !o_file.is_open()) {
    throw "An error occured while openning one of the files";
  }


  char c;

  while(i_file.get(c)) {
    o_file << c;  
  }

  i_file.close();
  o_file.close();

  return 0;
}
