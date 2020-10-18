/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-09-12 15:01:10
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
int res = 0;
vector<vector<int>> g;
bool dfs(int f) {
    if (g[f].empty())
        return true;
    int sz = g[f].size();
    bool l = dfs(g[f][0]);
    if (sz == 2) {
        bool r = dfs(g[f][1]);
        res += l & r;
    }
    return false;
}
int main(int argc, char const *argv[]) {
    int m, n;
    cin >> m >> n;
    g.resize(m + 1);
    for (int i = 0; i < n; i++) {
        string f;
        cin >> f;
        string op;
        cin >> op;
        string s;
        cin >> s;
        g[stoi(f)].push_back(stoi(s));
    }
    res = 0;
    dfs(1);
    cout << res << endl;
    return 0;
}
