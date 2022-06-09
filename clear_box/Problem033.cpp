#include <iostream>
#include <vector>

using ll = long long;

ll func(ll num, const std::vector<ll>& fac) {
    ll ans {};
    for (;num!=0;num/=10) {
        ans += fac[num%10];
    }
    return ans;
}

int main() {

    constexpr int m {10};
    constexpr ll n {1000000};
    std::vector<ll> fac(m);
    fac[0] = 1;
    for (ll i=1;i<m;++i) fac[i] = fac[i-1]*i;
    //for (const auto& e : fac) std::cout << e << '\n';

    ll ans {};
    for (ll i=3;i<n;++i) {
        if (func(i, fac) == i) {
            //std::cout << i << '\n';
            ans += i;
        }
    }
    std::cout << ans << '\n';
}
