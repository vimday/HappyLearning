/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :C_workout.cpp
 * @Created Time:2020-10-08 15:15:52
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
int n, k;
vector<int> arr;
bool can(int mi) {
    int ck = k;
    for (int i = 1; i < n; i++) {
        int d = arr[i] - arr[i - 1];
        if (d <= mi)
            continue;
        ck -= d / mi - 1 + ((d % mi) != 0);
        if (ck < 0)
            return false;
    }
    return true;
}
int solve() {
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mx = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] - arr[i - 1] > mx)
            mx = arr[i] - arr[i - 1];
    int l = 1, h = mx;
    while (l < h) {
        int mi = l + (h - l >> 1);
        can(mi) ? h = mi : l = mi + 1;
    }
    return l;
}
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    for (int i = 0; i < T;)
        printIntAns(++i, solve());
    return 0;
}