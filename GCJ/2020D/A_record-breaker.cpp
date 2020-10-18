/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :A_record-breaker.cpp
 * @Created Time:2020-10-13 19:04:45
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
const int mxn = 200005;
int n, arr[mxn];

ll solve() {
    cin >> n;
    ll res = 0;
    for (int i = 0; i < n;)
        cin >> arr[++i];
    int pm = -1;
    arr[n + 1] = -1;
    for (int i = 1; i <= n; i++)
        if (arr[i] > pm) {
            pm = arr[i];
            if (arr[i] > arr[i + 1])
                res++;
        }

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