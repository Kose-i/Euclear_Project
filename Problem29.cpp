#include <iostream>
#include <utility>
#include <vector>

using Pair = std::pair<int, int>;

constexpr int max_num {100};

int main(int argc, char** argv) {
  std::vector<char> is_prime(max_num+1, 1);
  is_prime[0] = is_prime[1] = 0;
  for (auto i = 0;i <= max_num;++i) {
    if (is_prime[i]==1) {
      for (auto j = i+i;j <= max_num;j += i) is_prime[j] = 0;
    }
  }
  std::vector<int> prime_num;
  for (auto i = 0;i <= max_num;++i) {
    if (is_prime[i] == 1) prime_num.push_back(i);
  }
}
