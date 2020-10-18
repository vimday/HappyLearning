/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :B.cpp
 * @Created Time:2020-08-01 19:42:41
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
ll mod = 1e9 + 3;
vector<array<ll, 2>> va;
vector<vector<int>> ms;
vector<ll> m;
vector<bool> me;
int n;
ll res = -1e9;
ll dfs(int root) {
    if (me[root])
        return m[root];
    me[root] = true;
    m[root] = va[root][0];
    for (int nb : ms[root]) {
        if (nb != root) {
            m[root] += max(dfs(nb), 0ll);
        }
    }
    res = max(res, m[root]);
    if (m[root] > 0)
        return m[root];
    return 0;
}
int main(int argc, char const *argv[]) {
    cin >> n;
    va.clear();
    va.resize(n + 1);
    ms.clear();
    ms.resize(n + 1);
    m.resize(n + 1);
    me.resize(n + 1);
    int root = 1;
    for (int i = 1; i <= n; i++) {
        cin >> va[i][0] >> va[i][1];
        if (va[i][1] == 0) {
            root = i;
            ms[i].clear();
            for (int j = 1; j <= n; j++)
                ms[i].push_back(j);
        } else {
            ms[va[i][1]].push_back(i);
        }
    }
    dfs(root);
    cout << res % mod << endl;
    return 0;
}
