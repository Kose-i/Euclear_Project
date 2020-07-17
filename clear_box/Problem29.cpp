#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <map>

using Pair = std::pair<int, int>;

//constexpr int max_num {100};
constexpr int max_num {5};

std::vector<int> make_prime() {
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
  return prime_num;
}

std::vector<Pair> make_pair_devision(int a, const std::vector<int>& prime_num) {
  std::vector<Pair> ans;
  for (const auto& e : prime_num) {
    int c {};
    if (a % e == 0) {
      Pair tmp;
      tmp.first = e;
      tmp.second = 0;
      while (a % e == 0) {
        ++tmp.second;
        a /= e;
      }
      ans.push_back(tmp);
    }
    if (a == 1) break;
  }
  return ans;
}
std::vector<Pair> make_double(const std::vector<Pair>& tmp_vec, const int& b) {
  std::vector<Pair> ans = tmp_vec;
  for (auto& e : ans) e.second *= b;
  return ans;
}

int main(int argc, char** argv) {
  std::vector<int> prime_num = make_prime();
  std::map<std::vector<Pair>, int> mp;

  int answer {};
  for (auto a = 2;a <= max_num;++a) {
    std::vector<Pair> tmp_a = make_pair_devision(a, prime_num);
    for (auto b = 2;b <= max_num;++b) {
      std::vector<Pair> tmp_b = make_double(tmp_a, b);
      if (mp[tmp_b]==0) {
        mp[tmp_b] = 1;
        ++answer;
      }
    }
  }
  std::cout << answer << '\n';
}
