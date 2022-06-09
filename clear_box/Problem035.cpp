#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool rotate(int sc, map<int, int>& mp) {
    if (sc < 10) return true;
    for (int tmp=sc;;) {
        {
            string new_tmp1 = to_string(tmp/10);
            string new_tmp2 = to_string(tmp%10);
            tmp = stoi(new_tmp2 + new_tmp1);
        }
        if (tmp == sc) break;
        if (mp[tmp] == 0) return false;
    }
    return true;
}

int main() {
    constexpr int n {1000000};
    vector<char> is_prime(n, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i=0;i*i<=n;++i) {
        if (is_prime[i] == 0) continue;
        for (int j=i+i;j<=n;j+=i) {
            is_prime[j] = 0;
        }
    }

    //vector<int> prime;
    map<int, int> mp;
    for (int i=0;i<=n;++i) {
        //if (is_prime[i] == 1) prime.push_back(i);
        if (is_prime[i] == 1) mp[i] = 1;
    }
    //cout << prime.size() << '\n';//78498

    int ans {};
    for (auto& e : mp) {
        if (e.second == 1) {
            int sc = e.first;
            if (rotate(sc, mp)) {
                ans += 1;
                //cout << sc << '\n';
            }
        }
    }
    cout << ans << '\n';
}
