/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :CCC.cpp
 * @Created Time:2020-08-29 16:22:31
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
int main(int argc, char const *argv[]) {
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> g(n + 1);
    int tx, ty;
    for (int i = 0; i < n - 1; i++) {
        cin >> tx >> ty;
        g[tx].push_back(ty);
        g[ty].push_back(tx);
    }
    bool mx[n + 1];
    memset(mx, 0, sizeof mx);
    int mtx[n + 1];
    memset(mtx, 0x3f, sizeof mtx);

    queue<int> qx;
    qx.push(x);
    mx[x] = true;
    mtx[x] = 0;
    int cnt = 1, res = 0;
    while (qx.size()) {
        int n = qx.size();
        while (n--) {
            int t = qx.front();
            qx.pop();
            for (int nb : g[t]) {
                if (!mx[nb]) {
                    mx[nb] = true;
                    mtx[nb] = cnt;
                    qx.push(nb);
                    if (nb == y)
                        res = cnt;
                }
            }
        }
        cnt++;
    }
    bool my[n + 1];
    memset(my, 0, sizeof my);
    int mty[n + 1];
    memset(mty, 0x3f, sizeof mty);

    queue<int> qy;
    qy.push(y);
    my[y] = true;
    mty[y] = 0;
    cnt = 1;
    while (qy.size()) {
        int n = qy.size();
        while (n--) {
            int t = qy.front();
            qy.pop();
            for (int nb : g[t]) {
                if (!my[nb] && cnt < mtx[nb]) {
                    my[nb] = true;
                    mty[nb] = cnt;
                    qy.push(nb);
                    res = max(res, mtx[nb]);
                }
            }
        }
        cnt++;
    }
    cout << res << endl;
    return 0;
}
