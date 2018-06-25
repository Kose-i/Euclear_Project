#include <iostream>
#include <vector>


void setup(std::vector<int>& t){
  for (int i {};i < t.size();++i) {
    int k = t[i] % 10;
    t[i] /= 10;
    t[i + 1] = k;
  }
}
void operator+=(std::vector<int>& a, const std::vector<int>& b) {
  for (auto& e : a){
    for (auto& f : b) {
      e += f;
    }
  }
  setup(a);
}

int main(int argc, char** argv){
  std::vector<int> t(1000, 0);
  t[0] = 1;
  std::vector<int> k(1000, 0);
  k[0] = 1;

  int i {};
  for (;;++i) {
    t += k;
    k += t;
    if (t[999] > 0)break;
    else if (k[999] > 0)break;
  }
  std::cout << i + 2 << '\n';
}
