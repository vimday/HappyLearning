/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :D.cpp
 * @Created Time:2020-08-08 16:00:01
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
vector<int> g[1005][1005];
int n, m, mx, mn;

int help() {
    if (m == n - 1)
        return mx - mn;
    return 0;
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    int r, c;
    mx = 0, mn = INT_MAX;
    memset(g, 0, sizeof g);
    for (int i = 0; i < m; i++) {
        cin >> r >> c;
        if (r > c)
            swap(r, c);
        int t;
        cin >> t;
        mx = max(mx, t);
        mn = min(mn, t);

        g[r][c].push_back(t);
    }
    cout << help() << endl;
    return 0;
}
