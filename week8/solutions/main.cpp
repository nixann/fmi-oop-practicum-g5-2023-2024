#include <iostream>
#include "Vector.h"

int main() {
  Vector v1;

  // input: -1,10,20,-40
  std::cin >> v1;

  // output: -1, 10, 20, -40
  std::cout << v1;

  Vector v2 = v1;

  // output: "Are equal?: 1"  
  std::cout << "Are equal?: " << (v1 == v2) << std::endl;


  // input: 30, 31, 32
  std::cin >> v2;

  std::cout << "V2 " << v2 << std::endl;

  // output: "v2 > v1?: 1"  
  std::cout << "v2 > v1?: " << (v2 > v1) << std::endl;

  // output: "v1 < v2?: 1"  
  std::cout << "v1 < v2?: " << (v1 < v2) << std::endl;

  // output: "<v1, v2>: 920"
  std::cout << "<v1, v2>: " << scalar(v1, v2) << std::endl;
  return 0;
}
