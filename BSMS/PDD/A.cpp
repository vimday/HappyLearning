/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :A.cpp
 * @Created Time:2020-09-01 19:01:03
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
    int n;
    cin >> n;
    int t = n / 2;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || (i + j == n - 1))
                continue;
            if ((n & 1) && (i == t || j == t))
                continue;
            if (i < t && j < t) {
                if (i < j)
                    g[i][j] = 2;
                else if (i > j) {
                    g[i][j] = 3;
                }
            } else if (i < t && j >= t) {
                if (i + j < n - 1)
                    g[i][j] = 1;
                else if (i + j > n - 1) {
                    g[i][j] = 8;
                }
            } else if (i >= t && j < t) {
                if (i + j < n - 1)
                    g[i][j] = 4;
                else if (i + j > n - 1) {
                    g[i][j] = 5;
                }
            } else if (i >= t && j >= t) {
                if (i < j)
                    g[i][j] = 7;
                else if (i > j) {
                    g[i][j] = 6;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << g[i][j] << " \n"[j == n - 1];
    return 0;
}
