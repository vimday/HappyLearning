/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :B.cpp
 * @Created Time:2020-09-01 19:33:07
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
int m, n;
vector<vector<int>> g, me;
int mm[160007];
int d[5] = {-1, 0, 1, 0, -1};
int getMax(int i, int j) {
    // int mm[m][n];
    memset(mm, 0, sizeof mm);
    queue<int> q;
    //int ret = 0;
    q.push(i * n + j);
    mm[i * n + j] = 1;
    int res = 0;
    while (q.size()) {
        int sz = q.size();
        res += sz;
        while (sz--) {
            int t = q.front();
            q.pop();
            int r = t / n, c = t % n;
            for (int k = 0; k < 4; k++) {
                int x = r + d[k], y = c + d[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] == 1 && mm[x * n + y] == 0) {
                    q.push(x * n + y);
                    mm[x * n + y] = 1;
                }
            }
        }
    }
    return res;
}
int main(int argc, char const *argv[]) {
    cin >> m >> n;
    g = vector<vector<int>>(m, vector<int>(n));
    //me = g;
    int mx = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            if (g[i][j])
                mx++;
        }

    //bf
    int res = 0;
    // for (int i = 0; i < m; i++)
    //     for (int j = 0; j < n; j++)
    //         if (g[i][j] && me[i][j] == 0) {
    //             res = max(res, getMax(i, j));
    //             me[i][j] = 1;
    //         }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (g[i][j] == 0)
                res = max(res, getMax(i, j));
    // for (int i = 0; i < m; i++)
    //     for (int j = 0; j < n; j++)
    //         if (g[i][j])
    //             for (int r = 0; r < m; r++)
    //                 for (int c = 0; c < n; c++)
    //                     if ((r != i || j != c) && g[r][c] == 0) {
    //                         g[i][j] = 0;
    //                         res = max(res, getMax(r, c));
    //                         g[i][j] = 1;
    //                     }
    cout << min(res, mx) << endl;
    return 0;
}
