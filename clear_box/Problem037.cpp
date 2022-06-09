#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
    constexpr int n {1000000};
    vector<char> is_prime(n+1, 1);
    is_prime[0] = is_prime[1] = 0;

    for (int i=0;i<=n;++i) {
        if (is_prime[i] == 0) continue;
        for (int j=i+i;j<=n;j+=i) is_prime[j] = 0;
    }

    map<int, int> mp;
    map<int, int> mp_l;
    for (int i=0;i<=n;++i) if (is_prime[i] == 1) mp[i] = 1;
    {
        queue<int> left;
        for (int i=0;i<10;++i) {
            if (mp[i] == 1) {
                left.push(i);
            }
        }
        for (;!left.empty();) {
            int l = left.front(); left.pop();
            for (int i=1;i<10;++i) {
                int num = stoi(to_string(i) + to_string(l));
                if (mp[num] == 1) {
                    mp_l[num] = 1;
                    left.push(num);
                }
            }
        }
    }
    map<int, int> mp_r;
    {
        queue<int> right;
        for (int i=0;i<10;++i) {
            if (mp[i] == 1) {
                right.push(i);
            }
        }
        for (;!right.empty();) {
            int r = right.front(); right.pop();
            for (int i=1;i<10;++i) {
                int num = stoi(to_string(r) + to_string(i));
                if (mp[num] == 1) {
                    mp_r[num] = 1;
                    right.push(num);
                }
            }
        }
    }
    int ans {};
    for (const auto& e : mp_l) {
        if (mp_r[e.first] == 1) {
            ans += e.first;
        }
    }
    cout << ans << '\n';

}
