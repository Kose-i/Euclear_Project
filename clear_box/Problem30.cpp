#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <numeric>

#include <iostream>

namespace prob30{
  bool is_in_Range(const unsigned& target) {
    return (10000 <= target) && (target < 100000);
  }
  struct Num_Data {
    unsigned number;
    std::vector<unsigned> num_box;
  };
  bool is_answer(const struct Num_Data& t) {
    //std::assert(t.num_box.size() == 5);
    if (is_in_Range(t.number) == false) {
      return false;
    } else {
      std::vector<unsigned> number_vec(5);
      number_vec[0] = (t.number/10000);
      number_vec[1] = (t.number/1000)%10;
      number_vec[2] = (t.number/100)%10;
      number_vec[3] =  (t.number/10)%10;
      number_vec[4] =     (t.number)%10;
      std::sort(number_vec.begin(), number_vec.end());
      std::vector<unsigned> number_check = t.num_box;
      std::sort(number_check.begin(), number_check.end());
      for (auto i = 0;i < 5;++i) {
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
    std::vector<struct Num_Data> ans_candidate;
    for (auto i = 0;i < 10;++i) {
      std::vector<unsigned> num_box_(5);
      num_box_[0] = i;
      for (auto j = i;j < 10;++j) {
        num_box_[1] = j;
        for (auto k = j;k < 10;++k) {
          num_box_[2] = k;
          for (auto l = k;l < 10;++l) {
            num_box_[3] = l;
            for (auto m = l;m < 10;++m) {
              num_box_[4] = m;
              unsigned sum = number[i] + number[j] + number[k] + number[l] + number[m];
              struct Num_Data t;
              t.num_box = num_box_;
              t.number = sum;
              if (is_answer(t)) {
                ans_candidate.push_back(t);
              }
            }
          }
        }
      }
    }
    //std::cout << ans_candidate.size() << '\n';
    //Conbination
    std::vector<unsigned> ans;
    for (auto e : ans_candidate) {
      ans.push_back(e.number);
    }
    return ans;
  }
}

int main(int argc, char** argv) {
  std::vector<unsigned> answers = prob30::answer();
  std::cout << std::accumulate(answers.begin(), answers.end(), 0) << '\n';
}
