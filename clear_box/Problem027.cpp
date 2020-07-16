#include <iostream>
#include <vector>
#include <cmath>

constexpr int max_num {1000};

bool check(const int& num, const std::vector<char>& is_prime) {
  if (num <= 1) return false;
  else if (num < max_num) return (is_prime[num]==1);
  else {
    for (auto i = 0;i < max_num;++i) {
      if (is_prime[i]==0)continue;
      else if (num%i == 0)return false;
    }
    return true;
  }
}

int count_double_prime(const int& a, const int& b, const std::vector<char>& is_prime) {
  int ans {};
  for (auto n = 0;n < max_num;++n) {
    if (check(n*n + a*n + b, is_prime)) ++ans;
    else return ans;
  }
  return max_num+1;//TODO
}
int main(int argc, char** argv) {
  std::vector<char> is_prime(max_num, 1);
  is_prime[0] = is_prime[1] = 0;
  {
    unsigned int sqrt_max_num {static_cast<unsigned int>(std::sqrt(max_num)) + 1};
    for (auto i = 2;i < sqrt_max_num;++i) {
      if (is_prime[i] == 0) continue;
      for (auto j = i*2;j < max_num;j += i) {
        is_prime[j] = 0;
      }
    }
  }
//  std::cout << count_double_prime(1, 41, is_prime) << '\n';

  std::vector<int> prime_num;
  for (auto i = 0;i < max_num;++i) {
    if (is_prime[i] == 1) prime_num.push_back(i);
  }

  int now_max_double_prime {};
  int seki_a_b {};

  for (auto a = -max_num + 1;a < max_num;++a) {
    for (const auto& b : prime_num) {
      int cnt_double_prime = count_double_prime(a,b,is_prime);
      if (cnt_double_prime > now_max_double_prime) {
        seki_a_b = a*b;
        now_max_double_prime = cnt_double_prime;
      }
    }
  }
//  std::cout << now_max_double_prime << '\n';
  std::cout << seki_a_b << '\n';
}
