/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :A.cpp
 * @Created Time:2020-04-11 19:01:33
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
//bf
int getd(int i, int j, int r, int c) {
    return (i - r) * (i - r) + (j - c) * (j - c);
}

void solve() {
    int M, L;
    cin >> M >> L;
    vector<vector<int>> g(M, vector<int>(M));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            cin >> g[i][j];
    int X, Y;
    cin >> X >> Y;
    int pre = 0;
    for (int k = L; k <= L;) {
        bool f = true;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < M; j++)
                if (g[i][j]) {
                    int d = getd(i, j, X, Y);
                    if (d > pre * pre && d <= k * k) {
                        L += g[i][j];
                        f = false;
                    }
                }
        pre = k;
        k = L;
        if (f) {
            cout << L << endl;
            return;
        }
    }
    cout << L << endl;
    return;
}

int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
