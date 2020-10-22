/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :DDD.cpp
 * @Created Time:2020-10-21 19:29:30
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
vector<int> getVec(string &s) {
    int n = s.size();
    int t = 0;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ',') {
            res.push_back(t);
            t = 0;
            continue;
        }
        t = 10 * t + s[i] - '0';
    }
    res.push_back(t);
    return res;
}
int main(int argc, char const *argv[]) {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin >> n;
    string s;
    vector<vector<int>> g;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        g.push_back(getVec(s));
    }
    // for (int j = 0; j < n; ++j) {
    //     cin >> g[i][j];
    // }

    //o(1) space
    int sz = n >> 1;
    for (int k = 0; k < sz; ++k) {
        int b = k, e = n - k - 1;
        for (int j = b; j < e; ++j) {
            // g[b][j] -> g[j][e]
            // g[j][e] -> g[e][n-j-1]
            // g[e][n-j-1] -> g[n-j-1][b]
            // g[n-j-1][b] -> g[b][j]
            int t = g[b][j];
            g[b][j] = g[n - j - 1][b];
            g[n - j - 1][b] = g[e][n - j - 1];
            g[e][n - j - 1] = g[j][e];
            g[j][e] = t;
            //cout << g[b][j] << endl;
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cout << g[i][j] << ",\n"[i == n - 1 && j == n - 1];
    return 0;
}