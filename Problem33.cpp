#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  for (int a1 = 1;a1 < 10;++a1) {
    for (int a2 = 1;a2 < 10;++a2) {
      for (int a3 = 1;a3 < 10;++a3) {
        if (a3*(10*a1+a2) == a2*(10*a1+a3)) {
          // 10*a1 + a2 / 10*a1 + a3
          std::cout << "a";
        }
        if (a3*(10*a1 + a2) == a2*(10*a3+a1)) {
          // 10*a1 + a2 / 10*a3 + a1
          std::cout << "b";
        }
        if (a3*(10*a2 + a1) == a2*(10*a3 + a1)) {
          // 10*a2 + a1 / 10*a3 + a1
          std::cout << "c";
        }
      }
    }
  }
}
