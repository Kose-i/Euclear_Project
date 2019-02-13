#include <cmath>
#include <vector>

#include <iostream>

namespace prob30{
  unsigned long max_size(const unsigned& size) {
    return std::pow(9, 5)*size;
  }

  unsigned to_unsigned(const std::vector<unsigned>& vec) {
    unsigned answer{};
    for (auto i = 0;i < vec.size();++i) {
      answer *= 10;
      answer += vec[i];
    }
    return answer;
  }
  void next_pos(std::vector<unsigned>& vec, const unsigned& now_pos, const unsigned& now_sum, std::vector<unsigned>& vec_box) {
    if (now_pos == vec.size()) {
      unsigned data = to_unsigned(vec);
      if (data == now_sum) {
        vec_box.push_back(data);
      }
      return;
    }
    for (auto i = 0;i < 10;++i) {
      vec[now_pos] = i;
      next_pos(vec, now_pos + 1, now_sum + std::pow(i, 5), vec_box);
    }
  }

  void make_answer(const unsigned& size, std::vector<unsigned>& vec) {
    std::vector<unsigned> tmp(size, 0);
    std::vector<unsigned> vec_box;
    for (auto i = 1;i < 10;++i) {//1桁目
      std::cout << i << '\n';
      tmp[0] = i;
      unsigned sum = std::pow(i,5);
      next_pos(vec, 1, sum, vec_box);
    }
  }

  std::vector<unsigned> answer() {
    std::vector<unsigned> ans(1);
    for (auto i = 1;true;++i,ans.push_back(0)) {//桁数
      if (max_size(i) <= std::pow(10, i)) {
        continue;
      } else {
        make_answer(i, ans);
      }
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
