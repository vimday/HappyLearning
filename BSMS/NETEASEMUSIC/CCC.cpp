/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :CCC.cpp
 * @Created Time:2020-09-12 15:46:10
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
int n, k;
vector<vector<int>> g;
vector<bool> me;
bool mm[1005][1005];
int res;
void dfs(int idx, int k, int cur) {
    if (k < 0)
        return;
    if (!me[idx]) {
        me[idx] = true;
        if (++cur > res)
            res = cur;
        for (int nb : g[idx]) {
            if (!mm[idx][nb]) {
                mm[idx][nb] = true;
                dfs(nb, k - 1, cur);
                mm[idx][nb] = false;
            }
        };
        me[idx] = false;
    } else {
        for (int nb : g[idx]) {
            if (!mm[idx][nb]) {
                mm[idx][nb] = true;
                dfs(nb, k - 1, cur);
                mm[idx][nb] = false;
            }
        }
    }
}
int main(int argc, char const *argv[]) {
    cin >> n >> k;
    g.resize(n);
    me.resize(n);
    memset(mm, 0, sizeof mm);
    for (int i = 1; i < n; i++) {
        int nb;
        cin >> nb;
        g[i].push_back(nb);
        g[nb].push_back(i);
    }
    res = 0;
    queue<array<int, 3>> q;
    q.push({0, k, 0});

    dfs(0, k, 0);
    cout << res << endl;
    return 0;
}