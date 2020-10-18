/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :A_count-down.cpp
 * @Created Time:2020-10-10 22:32:55
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
    printf("Case #%d: %ld\n", caseNum, ans);
}
const int maxn = 200005;
int arr[maxn];
ll solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bool f = arr[n - 1] == 1;
    int res = 0;
    for (int i = n - 2; ~i; i--) {
        f = f & (arr[i] == arr[i + 1] + 1);
        if (f && arr[i] == k)
            res++;
        if (arr[i] == 1)
            f = true;
    }
    return res;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T;)
        printAns(++i, solve());
    return 0;
}