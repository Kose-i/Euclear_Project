#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>

#include <iostream>

namespace prob30{
  bool is_in_Range(const unsigned& target) {
    return (1000 <= target) && (target < 10000);
  }
  bool is_answer(const unsigned& number, const std::vector<unsigned>& num_box) {
    //std::assert(num_box.size() == 4);
    if (is_in_Range(number) == false) {
      return false;
    } else {
      std::vector<unsigned> number_vec(4);
      number_vec[0] = number/1000;
      number_vec[1] = (number/100)%10;
      number_vec[2] =  (number/10)%10;
      number_vec[3] =     (number)%10;
      std::sort(number_vec.begin(), number_vec.end());
      std::vector<unsigned> number_check = num_box;
      std::sort(number_check.begin(), number_check.end());
      for (auto i = 0;i < 4;++i) {
        if (number_vec[i] != number_check[i]) return false;
      }
      return true;
    }
  }
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
