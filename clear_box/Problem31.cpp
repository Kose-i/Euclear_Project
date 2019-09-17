#include <iostream>

#include <vector>

namespace prob31{
  std::vector<unsigned> set_conbination(const std::vector<unsigned>& coin) {
    std::vector<unsigned> ans_conbination(coin.size(), 1);
    //ans_conbination[1] += (ans_conbination[0]) + (ans_conbination[0] - 1);
    //ans_conbination[2] += ((ans_conbination[1]) + (ans_conbination[1] - 1))*ans_conbination[0];
    const unsigned coin_size = coin.size();
    for (auto i = 1;i < coin_size; ++i) {
      if (coin[i] % coin[i - 1] != 0) {
        ans_conbination[i] += (2*ans_conbination[i - 1] - 1)*ans_conbination[i-2];
      } else {
        ans_conbination[i] += 2*ans_conbination[i -1] -1;
      }
    }
    return ans_conbination;
  }
  unsigned answer() {
    std::vector<unsigned> coin{1, 2, 5, 10, 20, 50, 100, 200};
    std::vector<unsigned> conbination = set_conbination(coin);
    for (const auto& e : conbination) {
      std::cout << e << '\n';
    }
    unsigned ans = conbination[coin.size() - 1];
    return ans;
  }
}

int main(int argc, char** argv) {
  unsigned ans = prob31::answer();
  std::cout << ans << '\n';
}
