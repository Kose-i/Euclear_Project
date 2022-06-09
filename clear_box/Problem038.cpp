#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int n {1000000000};

int pan(int num, int num_n) {
    std::string s;
    for (int i=1;i<=num_n;++i) {
        s += to_string(num*i);
    }

    if (9<s.size()) return n;
    return stoi(s);
}
bool is_pandigital(int num) {
    std::string s = to_string(num);
    sort(s.begin(), s.end());
    return (s == "123456789");
}

int main() {

    int ans {};

    for (int i=2;i<=9;++i) {
        for (int j=1;j<=n;++j) {
            int c = pan(j,i);
            if (ans < c && c < n && is_pandigital(c)) ans = c;
            if (n <= c) break;
        }
    }
    cout << ans << '\n';
}
