#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;
vector<string> split(string& aa) {
    vector<string> ans;
    auto start_it = std::find(aa.begin(), aa.end(), '\"');
    auto end_it = std::find(start_it+1, aa.end(), '\"');

    for (;end_it != aa.end();) {
        string c(start_it+1, end_it);
        ans.push_back(c);
        start_it = std::find(end_it+1,   aa.end(), '\"');
        end_it   = std::find(start_it+1, aa.end(), '\"');
    }
    return ans;
}
int is_eql(const string& s) {
    int ans {};
    for (const auto& e : s) ans += e-'A' + 1;
    return ans;
}

int main() {
    std::ifstream ifs("Problem042.txt");
    string tmp_s;
    ifs >> tmp_s;
    vector<string> filelist = split(tmp_s);

    map<int, int> mp;
    for (int i=1;i<=10000;++i) mp[i*(i+1)/2] = 1;

    int ans {};
    for (auto& e : filelist) {
        if (mp[is_eql(e)] == 1) ++ans;
    }
    cout << ans << '\n';
}
