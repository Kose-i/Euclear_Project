#include <iostream>
#include <vector>

using ull = unsigned long long;
constexpr int max_num {28123+1};

int main(int argc, char** argv) {
  std::vector<int> kajosuu;
  std::vector<int> prime_box;

  for (int i = 2;i < max_num;++i) {
    int tmp = i;
    int sum_divisor {1};
    for (const auto& prime : prime_box) {
      int k = 1;
      int c = 1;
      while (tmp % prime == 0) {
        c *= prime;
        k += c;
        tmp /= prime;
      }
      sum_divisor *= k;
    }
    if (tmp == i) prime_box.push_back(tmp);
    if (sum_divisor-i > i) {
      kajosuu.push_back(i);
    }
  }

  std::vector<char> is_kajousuu_wa(max_num, 1);
  int kajosuu_size = kajosuu.size();
  for (auto i = 0;i < kajosuu_size;++i) {
    for (auto j = i;j < kajosuu_size;++j) {
      int c = kajosuu[i] + kajosuu[j];
      if (c < max_num) {
        is_kajousuu_wa[c] = 0;
      } else {
        break;
      }
    }
  }

  ull ans {};
  for (auto i = 0;i < max_num;++i) {
    if (is_kajousuu_wa[i] == 1) {
      ans += i;
    }
  }
  std::cout << ans << '\n';
}
