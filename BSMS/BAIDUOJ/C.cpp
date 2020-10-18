/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :C.cpp
 * @Created Time:2020-03-29 20:23:59
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

int help(vector<int> &mv, vector<vector<int>> &g, int idx, vector<int> &me) {
    if (me[idx] > 0)
        return me[idx];
    me[idx] = 1;
    vector<int> &gn = g[idx];
    int cm = 0;
    for (int &nb : gn) {
        if (mv[nb] > mv[idx]) {
            cm = max(cm, help(mv, g, nb, me));
        }
    }
    return me[idx] += cm;
}
int n;
int main(int argc, char const *argv[]) {
    cin >> n;
    vector<int> mval(n + 1), me(n + 1, -1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> mval[i];
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int res = 1;
    for (int i = 1; i <= n; i++) {
        int cm = help(mval, g, i, me);
        if (cm > res)
            res = cm;
    }
    cout << res << endl;

    return 0;
}
