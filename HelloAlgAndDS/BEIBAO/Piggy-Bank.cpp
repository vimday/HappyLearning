/*
 * @Author      :vimday
 * @Desc        :完全背包装满的最小价值
 * @Url         :http://acm.hdu.edu.cn/showproblem.php?pid=1114
 * @File Name   :Piggy-Bank.CPP
 * @Created Time:2020-10-10 20:36:16
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
const int INF = 0xffffff;
int dp[10004], p[501], w[501];
int solve() {
    int a, b;
    cin >> a >> b;
    int tt = b - a;
    for (int i = 1; i <= tt; ++i)
        dp[i] = INF;
    dp[0] = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &p[i], &w[i]);
    for (int i = 1; i <= n; i++)
        for (int j = w[i]; j <= tt; j++)
            if (dp[j - w[i]] + p[i] < dp[j])
                dp[j] = dp[j - w[i]] + p[i];
    return dp[tt] == INF ? -1 : dp[tt];
}
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    while (T--) {
        int res = solve();
        if (res == -1)
            cout << "This is impossible." << endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << res << "." << endl;
    }
    return 0;
}
