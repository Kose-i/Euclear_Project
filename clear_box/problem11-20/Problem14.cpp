#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;

constexpr ll cnt {1000000+1};

ll search(const ll& index, std::vector<ll>& dp) {
  if (index == 1) return 0;
  if (index < cnt) {
    if (dp[index] != -1) return dp[index];
    if (index % 2 == 0) return dp[index] = search(index/2, dp)+1;
    else return dp[index] = search(index*3+1, dp)+1;
  } else {
    if (index % 2 == 0) return search(index/2, dp)+1;
    else return search(index*3+1, dp)+1;
  }
}

int main(int argc, char** argv) {
  std::vector<ll> dp(cnt, -1);
  int answer {};
  ll answer_value {};
  for (auto i = 1;i < cnt;++i) {
    if (answer_value < search(i, dp)) {
      answer = i;
      answer_value = search(i, dp);
    }
  }
  std::cout << answer << '\n';
}
