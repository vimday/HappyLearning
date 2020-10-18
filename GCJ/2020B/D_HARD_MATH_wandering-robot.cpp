/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :D_wandering-robot.cpp
 * @Created Time:2020-10-09 17:23:10
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
const int MAXN = 200005;
int dcmp(double a, double b) {
    if (fabs(a - b) < eps) return 0;
    return a < b ? -1 : 1;
}
void printAns(int caseNum, double ans) {
    printf("Case #%d: %f\n", caseNum, ans);
}
int w, h, l, u, r, d;
bool inZero(int x, int y) {
    if (x >= l && x <= r && y >= u && y <= d)
        return true;
    return false;
}
bool inSquare(int x, int y) {
    return x >= 1 && x <= w && y >= 1 && y <= h;
}
double bf() {
    if ((l == 1 && r == w) || (u == 1 && d == h))
        return 0;
    double dp[w + 1][h + 1];
    memset(dp, 0, sizeof dp);
    dp[1][1] = 1;
    for (int i = 2; i <= h; i++)
        if (!inZero(1, i))
            dp[1][i] = 0.5 * dp[1][i - 1];
    for (int i = 2; i <= w; i++)
        if (!inZero(i, 1))
            dp[i][1] = 0.5 * dp[i - 1][1];

    for (int i = 2; i <= w; i++)
        for (int j = 2; j <= h; j++) {
            if (inZero(i, j))
                continue;
            dp[i][j] += i == w ? dp[i][j - 1] : 0.5 * dp[i][j - 1];
            dp[i][j] += j == h ? dp[i - 1][j] : 0.5 * dp[i - 1][j];
        }
    return dp[w][h];
}
double LogFac[MAXN], lastRow[MAXN], lastCol[MAXN];
int Log[MAXN];
void computeLog() {
    // Log[1] = 0;
    // Log[2] = 1;
    // for (int i = 3; i < MAXN; i++)
    //     Log[i] = Log[i >> 1] + 1;
    LogFac[0] = 0;
    LogFac[1] = 0;
    for (int i = 2; i < MAXN; i++)
        LogFac[i] = log2(i) + LogFac[i - 1];
}
void computeLastRC() {
    lastRow[1] = pow(2, (-1) * (h - 1));
    for (int i = 2; i < w; i++)
        lastRow[i] = lastRow[i - 1] + 0.5 * pow(2, LogFac[i - 1 + h - 2] - LogFac[i - 1] - LogFac[h - 2] - (double)(i - 1 + h - 2));
    lastCol[1] = pow(2, (-1) * (w - 1));
    for (int i = 2; i < h; i++)
        lastCol[i] = lastCol[i - 1] + 0.5 * pow(2, LogFac[w - 2 + i - 1] - LogFac[w - 2] - LogFac[i - 1] - (double)(w - 2 + i - 1));
}
double solve() {
    cin >> w >> h >> l >> u >> r >> d;
    computeLastRC();
    int x = l - 1, y = d + 1;
    double res = 0;
    while (inSquare(x, y)) {
        if (y == h)
            res += lastRow[x];
        else {
            int n = x - 1 + y - 1, k = x - 1;
            //Cnk/2^n=2^(log2(Cnk/2^n))=2^(log2(n!/(k!*(n-k)!))/2^n)=2^(log2(n!)-log2(k!)-log2((n-k)!)-n)
            res += pow(2, LogFac[n] - LogFac[k] - LogFac[n - k] - (double)n);
        }
        --x;
        ++y;
    }
    x = r + 1;
    y = u - 1;
    while (inSquare(x, y)) {
        if (x == w)
            res += lastCol[y];
        else {
            int n = x - 1 + y - 1, k = x - 1;
            //Cnk/2^n=2^(log2(Cnk/2^n))=2^(log2(n!/(k!*(n-k)!))/2^n)=2^(log2(n!)-log2(k!)-log2((n-k)!)-n)
            res += pow(2, LogFac[n] - LogFac[k] - LogFac[n - k] - (double)n);
        }
        ++x;
        --y;
    }
    return res;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    computeLog();
    for (int i = 0; i < T;)
        printAns(++i, solve());
    return 0;
}