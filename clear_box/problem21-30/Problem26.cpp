#include <iostream>
#include <vector>
#include <algorithm>

int junkansetu(const int& Num) {
  std::vector<int> p(1, 1);
  for (auto i = 0;i != 10000;++i) {
    int tmp = (p[i]*10)%Num;
    if (tmp == 0) return 0;
    if (std::find(p.begin(), p.end(), tmp) != p.end()) {
      return i;
    } else {
      p.push_back(tmp);
    }
  }
  return 10000; // Error
}

int main(int argc, char** argv) {
  int max_value {};
  int answer {};
  //for (int i = 1; i < 1000;++i) {
  for (int i = 1; i < 1000;++i) {
    int tmp = junkansetu(i);
    if (tmp > max_value) {
      max_value = tmp;
      answer = i;
    }
  }
  std::cout << answer << '\n';
}
