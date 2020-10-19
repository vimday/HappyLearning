/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :http://acm.hdu.edu.cn/showproblem.php?pid=2586
 * @File Name   :beizeng.cpp
 * @Created Time:2020-10-19 14:39:54
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
const int MXN = 40004;
const int LN = 21;
vector<int> g[MXN], v[MXN];
int f[MXN][LN], c[MXN][LN], d[MXN];
int n;
void dfs(int s, int p) {
    f[s][0] = p;
    d[s] = d[p] + 1;
    for (int i = 1; i < LN; ++i) {
        f[s][i] = f[f[s][i - 1]][i - 1];
        c[s][i] = c[f[s][i - 1]][i - 1] + c[s][i - 1];
    }
    int sz = g[s].size();
    vector<int> &t = g[s];
    for (int i = 0; i < sz; ++i) {
        if (t[i] == p)
            continue;
        c[t[i]][0] = v[s][i];
        dfs(t[i], s);
    }
}
int lca(int a, int b) {
    if (d[a] > d[b])
        swap(a, b);
    int tmp = d[b] - d[a], res = 0;
    for (int j = 0; tmp; ++j, tmp >>= 1)
        if (tmp & 1)
            res += c[b][j], b = f[b][j];
    if (a == b)
        return res;
    for (int j = 20; a != b && ~j; --j) {
        if (f[a][j] != f[b][j]) {
            res += c[a][j] + c[b][j];
            a = f[a][j];
            b = f[b][j];
        }
    }
    // lca is f[a][0]
    res += c[a][0] + c[b][0];
    return res;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int q, a, b, w;
        cin >> n >> q;
        for (int i = 0; i <= n; ++i) {
            g[i].clear();
            v[i].clear();
        }
        //memset(d, 0, (n + 1) << 2);
        d[0] = 0;
        memset(f, 0, sizeof f[0]);
        memset(c, 0, LN << 3);
        dfs(1, 0);
        for (int i = 1; i < n; ++i) {
            cin >> a >> b >> w;
            g[a].push_back(b);
            g[b].push_back(a);
            v[a].push_back(w);
            v[b].push_back(w);
        }
        dfs(1, 0);
        while (q--) {
            cin >> a >> b;
            cout << lca(a, b) << endl;
        }
    }
    return 0;
}