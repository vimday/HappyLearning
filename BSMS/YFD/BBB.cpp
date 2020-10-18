/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-08-22 20:08:32
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
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> data(n, vector<long long>(2 * m - 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> data[i][j];
        for (int j = 0; j < m - 1; j++)
            data[i][j + m] = data[i][j];
    }
    vector<vector<long long>> ps(n, vector<long long>(2 * m - 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2 * m - 1; j++) {
            if (i == 0 && j == 0)
                ps[i][j] = data[i][j];
            else if (j == 0)
                ps[i][j] = ps[i - 1][j] + data[i][j];
            else if (i == 0)
                ps[i][j] = ps[i][j - 1] + data[i][j];
            else {
                ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + data[i][j];
            }
        }
    long long res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int r = i; r < n; r++)
                for (int c = j; c < 2 * m - 1 && c < j + m; c++) {
                    if (i == 0 && j == 0)
                        res = max(res, ps[r][c]);
                    else if (i == 0) {
                        res = max(res, ps[r][c] - ps)
                    }
                }

    return 0;
}
