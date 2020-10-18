/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :CCC.cpp
 * @Created Time:2020-09-06 19:34:39
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
typedef long long ll;
int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    if (k < 1)
        return 0;
    unordered_map<string, int> msi;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        msi[s]++;
    }
    map<int, set<string>> mis;
    for (auto p : msi)
        mis[p.second].insert(p.first);
    for (int i = 0; i < k; i++) {
    }
    auto ri = mis.rbegin();
    int cnt = 0;
    bool f = false;
    while (ri != mis.rend()) {
        int time = ri->first;
        for (auto s : ri->second) {
            cout << s << " " << time << endl;
            if (++cnt == k) {
                f = true;
                break;
            }
        }
        if (f)
            break;
        ri++;
    }
    auto li = mis.begin();
    cnt = 0;
    f = false;
    while (li != mis.end()) {
        int time = li->first;
        for (auto s : li->second) {
            cout << s << " " << time << endl;
            if (++cnt == k) {
                f = true;
                break;
            }
        }
        if (f)
            break;
        ri++;
    }
    return 0;
}