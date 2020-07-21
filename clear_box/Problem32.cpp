#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> make_keta(int a) {
  std::vector<int> ans;
  while (a != 0) {
    ans.push_back(a%10);
    a /= 10;
  }
  return ans;
}

bool is_same(const std::vector<int>& number) {
  int size = number.size();
  for (auto i = 0;i < size;++i) {
    for (auto j = i+1;j < size;++j) {
      if (number[i]==number[j]) return true;
    }
  }
  return false;
}

bool is_pandegital(const std::vector<int>& a_num, const std::vector<int>& b_num, const int& a, const int& b) {
  int c = a*b;
  std::vector<int> c_num = make_keta(c);
  std::vector<int> number;
  for (const auto& e : a_num) {
    number.push_back(e);
  }
  for (const auto& e : b_num) {
    number.push_back(e);
  }
  for (const auto& e : c_num) {
    number.push_back(e);
  }
  if (number.size() == 9) {
    std::sort(number.begin(), number.end());
    for (auto i = 0;i < 9;++i) {
      if (number[i] != i+1) return false;
    }
    return true;
  }
  return false;
}

int main(int argc, char** argv) {
  int a, b, c;
  std::vector<long> answer_box;
  for (a = 2;a < 10;++a) { //1 * 4 = 5
    std::vector<int> a_num = make_keta(a);
    for (b = 1234;b <= 9876;++b) {
      std::vector<int> b_num = make_keta(b);
      if (is_same(b_num)) continue;
      if (is_pandegital(a_num, b_num, a, b)) {
        std::cout << a << '*' << b << '=' << a*b << '\n';
        answer_box.push_back(a*b);
      }
    }
  }
  for (a = 11;a < 987;++a) { //2 * 3 = 4
    std::vector<int> a_num = make_keta(a);
    if (is_same(a_num)) continue;
    for (b = a+1;b < 987;++b) {
      std::vector<int> b_num = make_keta(b);
      if (is_same(b_num)) continue;
      if (is_pandegital(a_num, b_num, a, b)) {
        std::cout << a << '*' << b << '=' << a*b << '\n';
        answer_box.push_back(a*b);
      }
    }
  }

  unsigned long long answer {};
  long tmp {};
  std::sort(answer_box.begin(), answer_box.end());
  for (const auto& e : answer_box) {
    if (e == tmp) continue;
    tmp = e;
    answer += e;
  }
  std::cout << answer << '\n';
}
