/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb
 * @File Name   :B_plates.cpp
 * @Created Time:2020-10-08 14:30:32
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
void printIntAns(int caseNum, int ans) {
    printf("Case #%d: %d\n", caseNum, ans);
}
int solve() {
    int n, k, p;
    cin >> n >> k >> p;
    int sk[n][k];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
            cin >> sk[i][j];
    int ps[n][k + 1];
    for (int i = 0; i < n; i++)
        ps[i][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= k; j++)
            ps[i][j] = ps[i][j - 1] + sk[i][j - 1];
    int dp[n][p + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= min(p, k); i++)
        dp[0][i] = ps[0][i];
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= min(p, (i + 1) * k); j++) {
            for (int c = 0; c <= min(j, k); c++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - c] + ps[i][c]);
        }
    return dp[n - 1][p];
}
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    for (int i = 0; i < T;)
        printIntAns(++i, solve());
    return 0;
}
