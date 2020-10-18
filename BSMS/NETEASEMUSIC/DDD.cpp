/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :DDD.cpp
 * @Created Time:2020-09-12 16:31:47
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
int v[10005];
const int N = 2e5 + 10;
int n, m, e;
vector<int> G[N];
int match[N], vis[N];
bool dfs(int u) {
    int len = G[u].size();
    for (int i = 0; i < len; i++) {
        int v = G[u][i];
        if (vis[v]) continue;
        vis[v] = 1;
        if (!match[v] ||
            dfs(match[v])) {
            match[v] = u;
            match[u] = v;
            return 1;
        }
    }
    return 0;
}
int main(int argc, char const *argv[]) {
    string sm;
    m = 1, n = 1;
    getline(cin, sm);
    istringstream is(sm);
    string t;
    while (is >> t) {
        v[stoi(t)] = 1;
        n++;
    }
    getline(cin, sm);
    istringstream is2(sm);
    while (is2 >> t) {
        v[stoi(t)] = 2;
        m++;
    }
    cin >> e;
    for (int i = 1; i <= e; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a++;
        b++;
        if (a > n) continue;
        G[a].push_back(n + b);
        G[n + b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {  //对每一个点尝试匹配
        for (int j = 1; j <= n + m; j++) vis[j] = 0;
        if (dfs(i)) ans++;
    }
    printf("%d", ans);
    return 0;
}
