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

  int lines_count = 0;

  char c;

  while(i_file.get(c)) {
    if (c == '\n') {
      lines_count++;
    }
  }

  // ако файлът не е празен и не завъшрва със символ за нов ред, добавяме 1 към lines_count
  if (i_file.eof() && c && c != '\n') {
    lines_count++;
  }

  std::cout << "LINES COUNT: " << lines_count;

  i_file.close();
  return 0;
}
