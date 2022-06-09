#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    // n=9 -> %3==0 (1+2+...+8+9) = 45
    // n=8 -> %3==0 (1+2+...+8) = 36
    constexpr int n {1000*1000*10};
    vector<char> is_prime(n+1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i=0;i<=n;++i) {
        if (is_prime[i] == 0) continue;
        for (int j=i+i;j<=n;j+=i) is_prime[j] = 0;
    }

    ll ans {};

    for (int i=7;1<=i;--i) {
        std::string s;
        for (int j=1;j<=i;++j) s += j + '0';
        for (;next_permutation(s.begin(), s.end());) {
            //cout << s << '\n';
            if (is_prime[stoll(s)]) ans = stoll(s);
        }
        if (ans != 0) break;
    }
    cout << ans << '\n';
}
