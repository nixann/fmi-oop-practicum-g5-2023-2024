#include <iostream>

int main() {
  char delimiter;

  std::cin >> delimiter;

  char str[10];

  std::cin.get(str, 10, delimiter);


  std::cout << "STR: " << str << std::endl;
  return 0;
}
