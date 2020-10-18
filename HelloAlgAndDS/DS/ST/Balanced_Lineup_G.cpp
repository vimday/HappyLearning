/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Balanced_Lineup_G.cpp
 * @Created Time:2020-10-10 21:35:16
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
const int N = 50004, LN = 21;
int fmx[N][LN], fmn[N][LN], logn[N];
int n, q;
void preCompute() {
    logn[1] = 0;
    for (int i = 2; i <= n; i++)
        logn[i] = logn[i >> 1] + 1;
    for (int j = 1; j < LN; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            fmx[i][j] = max(fmx[i][j - 1], fmx[i + (1 << (j - 1))][j - 1]);
            fmn[i][j] = min(fmn[i][j - 1], fmn[i + (1 << (j - 1))][j - 1]);
        }
}
int getRes(int l, int r) {
    int s = logn[r - l + 1];
    int mx = max(fmx[l][s], fmx[r - (1 << s) + 1][s]);
    int mn = min(fmn[l][s], fmn[r - (1 << s) + 1][s]);
    //cout << l << " - " << r << ".... " << mx << " *** " << mn << endl;
    return mx - mn;
}
int main(int argc, char const *argv[]) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        fmn[i][0] = fmx[i][0] = t;
    }
    preCompute();
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << getRes(l, r) << endl;
    }
    return 0;
}
