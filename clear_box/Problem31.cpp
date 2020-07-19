#include <iostream>
#include <vector>

long long make_answer(const int& pr_money, const int& index, const std::vector<int>& coin) {
  if (index == 0) {
    return 1;
  }
  long long answer {};
  for (auto i = 0;i <= pr_money/coin[index];++i) {
    answer += make_answer(pr_money - coin[index]*i, index-1, coin);
  }
  return answer;
}

int main(int argc, char** argv) {
  std::vector<int> coin{1, 2, 5, 10, 20, 50, 100, 200};
  std::vector<int> dp(coin.size(), 1);

  std::cout << make_answer(200, coin.size()-1, coin) << '\n';
}
