#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

std::vector<int> make_count(){
  std::vector<int> counter(10, 0);
  for (int i{};i < 10;++i) {
    counter[i] = std::tgamma(10 - i);
  }
  return counter;
}

std::vector<int> count_required(const std::vector<int>& counter)
{
  long long int required_count = 1000000 - 1;
  std::vector<int> box_count(10, 0);
  for (int i {};i < 10;++i) {
    box_count[i] = required_count / counter[i];
    required_count %= counter[i];
  }
  return box_count;
}

void swap(int& a , int& b) {
  int t = std::move(a);
  a = std::move(b);
  b = std::move(t);
}
std::vector<int> make_ans(const std::vector<int>& order){
  std::vector<int> answer(10, 0);
  std::iota(answer.begin(), answer.end(), 0);
  for (int i {};i < 10;++i) {
    swap(answer[i], answer[i + order[i]]);
    std::sort(answer.begin() + i + 1, answer.end());
  }
  return answer;
}
int main(int argc, char** argv){

  std::vector<int> counter = make_count();
  std::vector<int> box_count = count_required(counter);

  std::vector<int> answer = make_ans(box_count);

  for (const auto& e : answer) {
    std::cout << e;
  }
  std::cout << '\n';
}
