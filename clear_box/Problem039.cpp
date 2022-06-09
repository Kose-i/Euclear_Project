#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n {1000};
    map<int, int> mp_square;
    for (int i=1;i<=n;++i) mp_square[i*i] = i;

    map<int, int> mp;
    for (int a=1;a<=n;++a) {
        for (int b=1;b<=n;++b) {
            if (n*n < a*a + b*b) break;
            if (mp_square[a*a + b*b] == 0) continue;
            if (a + b + mp_square[a*a + b*b] <= n) ++mp[a+b+mp_square[a*a+b*b]];
        }
    }
    int ans {};
    int ans_max {};
    for (const auto& e : mp) {
        if (ans_max < e.second) {
            ans = e.first;
            ans_max = e.second;
        }
    }
    cout << ans << '\n';
}
