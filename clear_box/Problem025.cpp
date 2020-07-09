#include <iostream>
#include <vector>

std::vector<int> plus(const std::vector<int>& f1, const std::vector<int>& f2) {
  int f1_size = f1.size();
  int f2_size = f2.size();
  std::vector<int> f3;
  int tmp {};
  for (auto i = 0;i < f2_size;++i) {
    if (i < f1_size) {
      f3.push_back((f1[i]+f2[i]+tmp)%10);
      tmp = (f1[i]+f2[i]+tmp)/10;
    } else {
      f3.push_back((f2[i]+tmp)%10);
      tmp = (f2[i]+tmp)/10;
    }
  }
  if (tmp != 0) f3.push_back(tmp);
  return f3;
}
int main(int argc, char** argv) {

  std::vector<int> f1;
  std::vector<int> f2;
  std::vector<int> f3;
  f1.push_back(1); f2.push_back(1);

  int number = 2;

  int f3_size = f3.size();
  for (;f3_size<1000;++number) {
    f3 = plus(f1, f2);
    f3_size = f3.size();
    f1 = f2;
    f2 = f3;
  }
  std::cout << number << '\n';
}
