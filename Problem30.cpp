#include <cmath>
#include <vector>

#include <iostream>

namespace prob30{
  std::vector<unsigned> answer() {
    std::vector<unsigned> number(10);
    for (auto i = 0;i < 10;++i) {
      number[i] = std::pow(i, 5);
    }
    return number;
  }
}

int main(int argc, char** argv) {
  std::vector<unsigned> answers = prob30::answer();
  for (auto e: answers) {
    std::cout << e << '\n';
  }
}
