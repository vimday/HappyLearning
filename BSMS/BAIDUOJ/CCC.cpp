/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :CCC.cpp
 * @Created Time:2020-09-03 20:12:51
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
const ll mod = 1e9 + 7;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    ll dp[n + 1][m + 1][m + 1];
    memset(dp, 0, sizeof dp);
    for (int j = 1; j <= m; j++)
        dp[j][j][0] = 1;
    ll res = 0;
    for (int k = 1; k <= m; k++) {
        for (int i = k + 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int pre = 1; pre <= m; pre++) {
                    for (int ppre = 0; ppre <= m; ppre++) {
                        if (j == pre || j == ppre || pre == ppre)
                            continue;
                        dp[i][j][pre] += dp[i - j][pre][ppre];
                    }
                    if (i == j && pre == 0)
                        dp[i][j][pre] -= 1;
                    if (dp[i][j][pre] > mod)
                        dp[i][j][pre] %= mod;
                }
            }
        }
        for (int i = 1; i <= m; i++)
            for (int j = 0; j <= m; j++)
                res += dp[m][i][j];
    }

    cout << res % mod << endl;
    return 0;
}
