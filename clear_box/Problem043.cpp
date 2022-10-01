#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>


bool have_feature(const std::vector<int>& a) {
  if ((a[1]*100 + a[2]*10 + a[3]) % 2 != 0)  return false;
  if ((a[2]*100 + a[3]*10 + a[4]) % 3 != 0)  return false;
  if ((a[3]*100 + a[4]*10 + a[5]) % 5 != 0)  return false;
  if ((a[4]*100 + a[5]*10 + a[6]) % 7 != 0)  return false;
  if ((a[5]*100 + a[6]*10 + a[7]) % 11 != 0) return false;
  if ((a[6]*100 + a[7]*10 + a[8]) % 13 != 0) return false;
  if ((a[7]*100 + a[8]*10 + a[9]) % 17 != 0) return false;
  return true;
}

long long calc(const std::vector<int>& a) {
  long long t {};
  for (const int& e : a) {
    t *= 10;
    t += e;
  }
  return t;
}

int main() {
  int n {10};
  std::vector<int> a(n);
  //a[0] = 1;
  //a[1] = 4; a[2] = 0; a[3] = 6;
  //a[4] = 3; a[5] = 5; a[6] = 7;
  //a[7] = 2; a[8] = 8; a[9] = 9;
  //if (have_feature(a)) std::cout << "Yes\n";
  std::iota(a.begin(), a.end(), 0);

  std::swap(a[0], a[1]); // 1023456789
  long long ans {};

  do {
    if (have_feature(a)) {
      ans += calc(a);
    }
  } while (std::next_permutation(a.begin(), a.end()));
  std::cout << ans << '\n';
}
