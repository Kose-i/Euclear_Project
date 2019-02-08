#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

constexpr int target_number = 1000000 - 1;

int factorial(const int& size) {
  int sum = 1;
  for (int i = 1;i <= size;++i) {
    sum *= i;
  }
  return sum;
}
template<typename T>
void swap(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}

void print_ans(const std::vector<int>& answer) {
  for (auto& e : answer) {
    std::cout << e;
  }
  std::cout << '\n';
}
void define_perm(std::vector<int>& number_permutation, const int& define_number, const int& rest) {
  if (rest == 0)return;
  int number_one_plus = factorial(number_permutation.size() - define_number - 1);
  int pos = define_number + rest/number_one_plus;
  swap(number_permutation[define_number], number_permutation[pos]);
  const int next_rest = rest % number_one_plus;
  const int next_define_number = define_number + 1;

  std::sort(number_permutation.begin() + next_define_number, number_permutation.end());

  std::cout << "number_one_plus:" << number_one_plus << "  rest:" << rest << '\n';
  print_ans(number_permutation);

  define_perm(number_permutation, next_define_number, next_rest);
}

int main(int argc, char** argv) {
  std::vector<int> answer(10);
  std::iota(answer.begin(), answer.end(), 0);
  define_perm(answer, 0, target_number);
  for (auto& e : answer) {
    std::cout << e;
  }
  std::cout << '\n';
}
