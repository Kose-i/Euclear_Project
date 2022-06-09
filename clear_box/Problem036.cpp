#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string bit_string(int c) {
    string ans {};
    for (;c!=0;c >>= 1) {
        if (c&1) ans += '1';
        else ans += '0';
    }
    return ans;
}

int main() {
    constexpr int n {1000000};
    //constexpr int n {1000};
    long long ans {};
    for (int i=0;i<=n;++i) {
        std::string s = to_string(i);
        std::string reverse_s = s;
        reverse(reverse_s.begin(), reverse_s.end());
        if (s == reverse_s) {
            //cout << s << '\n';
            s = bit_string(i);
            reverse_s = s;
            reverse(reverse_s.begin(), reverse_s.end());
            if (s == reverse_s) {
                //cout << s << '\n';
                ans += i;
            }
        }
    }
    cout << ans << '\n';
}
