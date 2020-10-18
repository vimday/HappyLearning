/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :A_allocation.cpp
 * @Created Time:2020-10-07 22:11:48
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;
typedef long long ll;
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ", x)
#define prn(x) printf("Case %d:\n", x)
#define prr(x) printf("Case #%d: ", x)
#define prrn(x) printf("Case #%d:\n", x)
#define lowbit(x) (x & (-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
int solve() {
    int n, t;
    cin >> n >> t;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int cs = 0;
    int i = 0;
    for (; i < n; i++) {
        cs += arr[i];
        if (cs > t)
            break;
    }
    return cs > t ? i : n;
    // int dp[n + 1][t + 1];
    // memset(dp, 0, sizeof dp);
    // int res = 0;
    // for (int i = 0; i < n;) {
    //     int ct = arr[i];
    //     i++;
    //     for (int j = 0; j <= t; j++) {
    //         if (j < ct)
    //             dp[i][j] = dp[i - 1][j];
    //         else {
    //             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - ct] + 1);
    //         }

    //         res = max(res, dp[i][j]);
    //     }
    // }
    //return res;
}
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        prr(i);
        cout << solve() << endl;
    }
    return 0;
}
