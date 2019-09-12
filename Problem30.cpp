#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>

#include <iostream>

namespace prob30{
  bool is_in_Range(const unsigned& target) {
    return (1000 <= target) && (target < 10000);
  }
  struct Num_Data {
    unsigned number;
    std::vector<unsigned> num_box;
  };
  bool is_answer(const struct Num_Data& t) {
    //std::assert(num_box.size() == 4);
    if (is_in_Range(t.number) == false) {
      return false;
    } else {
      std::vector<unsigned> number_vec(4);
      number_vec[0] = t.number/1000;
      number_vec[1] = (t.number/100)%10;
      number_vec[2] =  (t.number/10)%10;
      number_vec[3] =     (t.number)%10;
      std::sort(number_vec.begin(), number_vec.end());
      std::vector<unsigned> number_check = t.num_box;
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
    std::vector<unsigned> ans;
    for (auto i = 0;i < 10;++i) {
      for (auto j = 0;j < 4;++j) {
      }
    }
    //Conbination
    unsigned t_num = 1000;
    std::vector<unsigned> t_num_box {1,0,0,0};
    struct Num_Data t;
    t.number = t_num;
    t.num_box = t_num_box;
    if (is_answer(t) == true) {
      ans.push_back(t_num);
    }
    return ans;
  }
}

int main(int argc, char** argv) {
  std::vector<unsigned> answers = prob30::answer();
  for (auto e: answers) {
    std::cout << e << '\n';
  }
}
