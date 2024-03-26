#include "Vector.h"

int main() {
  Vector v;

  for (int i = 0; i < 15; i++) {
    v.push_back(i);
  }

  v.print();
  // Output: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14

  v.pop_back();
  v.pop_back();
  v.pop_back();
  v.pop_back();
  v.pop_back();

  v.print();
  // Output: 0 1 2 3 4 5 6 7 8 9

  v.insert_at(8, 10);
  v.print();
  // Output: 0 1 2 3 4 5 6 7 10 8 9

  v.delete_at(3);
  v.print();
  // Output: 0 1 2 4 5 6 7 10 8 9

  Vector v2 = v;

  v2.sort();
  v2.print();
  // Output: 0 1 2 4 5 6 7 8 9 10 

  v2.reverse();
  v2.print();
  // Output: 10 9 8 7 6 5 4 2 1 0

  v2.slice(3, 7);
  v2.print();
  // Output: 7 6 5 4 2
}
