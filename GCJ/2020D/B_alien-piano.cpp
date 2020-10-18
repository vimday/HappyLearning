/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :B_alien-piano.cpp
 * @Created Time:2020-10-15 22:32:16
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
const double eps = 1e-10;
void printAns(int caseNum, ll ans) {
    printf("Case #%d: %lld\n", caseNum, ans);
}
int arr[10004];
ll solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    if (n < 5)
        return 0;
    int dp[n + 1][4];
    memset(dp, 0x3f, sizeof dp);
    memset(dp[1], 0, sizeof dp[1]);
    for (int i = 2; i <= n; i++) {
        if (arr[i] == arr[i - 1]) {
            for (int j = 0; j < 4; j++)
                dp[i][j] = dp[i - 1][j];
        } else if (arr[i] > arr[i - 1]) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++)
                    if (k < j)
                        dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                    else
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
                //cout << i << " " << j << " : " << dp[i][j] << endl;
            }
        } else {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++)
                    if (k > j)
                        dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                    else
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
                //cout << i << " " << j << " : " << dp[i][j] << endl;
            }
        }
    }
    int res = INT_MAX;
    for (int i = 0; i < 4; i++)
        if (dp[n][i] < res)
            res = dp[n][i];
    return res;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T;)
        printAns(++i, solve());
    return 0;
}