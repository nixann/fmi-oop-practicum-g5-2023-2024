#include <iostream>
#include <fstream>

int main() {

  char o_filename[30];
  std::cin.getline(o_filename, 30);

  std::ofstream o_file;
  o_file.open(o_filename);

  if (!o_file.is_open()) {
    throw "An error occured while openning the file";
  }


  char str[20];

  while (true) {
    std::cin.getline(str, 20);
    
    if (strcmp(str, "stop") == 0) {
      break;
    }

    o_file << str << std::endl;
  }

  o_file.close();

  return 0;
}
