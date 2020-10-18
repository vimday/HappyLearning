/*
 * @Author      :vimday
 * @Desc        :wangyi c
 * @Url         :
 * @File Name   :D.cpp
 * @Created Time:2020-04-07 20:16:41
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
    int m, n;
    cin >> m >> n;

    vector<vector<int>> g(m, vector<int>(n)), res(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        // string s;
        // cin >> s;
        for (int j = 0; j < n; j++)
        //if (s[j] == '1')
        {
            cin >> g[i][j];
            if (g[i][j] == 1)
                res[i][j] = 20000;
        }
    }
    int d[5] = {-1, 0, 1, 0, -1};
    int me[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 1) {
                //bf
                memset(me, 0, sizeof me);
                queue<int> q;
                q.push(i * n + j);
                me[i][j] = 1;
                bool f = false;
                int cnt = 0;
                while (!q.empty() && f) {
                    int sz = q.size();
                    cnt++;
                    while (sz-- && f) {
                        int t = q.front();
                        q.pop();

                        int ci = t / n, cj = t % n;
                        for (int k = 0; k < 4; k++) {
                            int r = ci + d[k], c = cj + d[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && me[r][c] == 0) {
                                if (g[r][c] == 0) {
                                    res[i][j] = cnt;
                                    f = false;
                                    break;
                                } else {
                                    if (res[r][c] != 20000) {
                                        me[r][c] = 1;
                                        res[i][j] = min(res[i][j], res[r][c] + cnt);

                                    } else {
                                        me[r][c] = 1;
                                        q.push(r * n + c);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << res[i][j] << " ";
        }
        cout << res[i][n - 1] << endl;
    }

    return 0;
}
