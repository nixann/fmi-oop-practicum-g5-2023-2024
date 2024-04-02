#include <iostream>


int main() {
  char delimiter;

  std::cin >> delimiter;

  char str1[10], str2[10], str3[10];

  std::cin.getline(str1, 10, delimiter).getline(str2, 10, delimiter).getline(str3, 10, delimiter);


  std::cout << "STR1: " << str1 << std::endl;
  std::cout << "STR2: " << str2 << std::endl;
  std::cout << "STR3: " << str3 << std::endl;

  return 0;
}
