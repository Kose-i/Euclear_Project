#include <iostream>
#include <vector>

constexpr int ten {10};

#define rep(i,n) for(auto i = 0;i < n;++i)

int main(int argc, char** argv) {
  std::vector<int> number(ten);
  rep(i, ten) {
    number[i] = i*i*i*i*i;
  }
}
