#include <iostream>
#include <string>

using namespace std;

int main() {
    constexpr int n {1000000};
    std::string s{"0"};
    for (int i=1;;++i) {
        s += to_string(i);
        if (n < s.size()) break;
    }
    int ans {1};
    for (int i=1;i<=n;i*=10) {
        ans *= s[i] - '0';
        //cout << s[i] << '\n';
    }
    cout << ans << '\n';
}
