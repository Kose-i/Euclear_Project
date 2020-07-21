#include <iostream>
#include <vector>

constexpr int ten {10};

#define rep(i,n) for(auto i = 0;i < n;++i)
using ull = unsigned long long;

int main(int argc, char** argv) {
  std::vector<int> number(ten);
  rep(i, ten) {
    number[i] = i*i*i*i*i;
  }

  ull answer {};
  for (auto a = 0;a < ten;++a) {
    ull ans0 = number[a];
    for (auto b = 0;b < ten;++b) {
      ull ans1 = ans0 + number[b];
      for (auto c = 0; c < ten;++c) {
        ull ans2 = ans1 + number[c];
        for (auto d = 0;d < ten;++d) {
          ull ans3 = ans2 + number[d];
          for (auto e = 0;e < ten;++e) {
            ull ans4 = ans3 + number[e];
            for (auto f = 0;f < ten;++f) {
              if (100000*a+10000*b+1000*c+100*d+10*e+f==ans4+number[f]) {
                answer += ans4+number[f];
              }
            }
          }
        }
      }
    }
  }
  std::cout << answer-1 << '\n';
}
