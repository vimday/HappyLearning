/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :DDD.cpp
 * @Created Time:2020-08-29 16:44:30
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
int m, n;
int mx = INT_MIN, mn = INT_MAX;
//bf
bool can(vector<int> &arr, int l, int r) {
    int pmn = INT_MIN;
    for (int &i : arr) {
        if (i >= l && i <= r)
            continue;
        if (i < pmn)
            return false;
        pmn = i;
    }
    return true;
}
int check(vector<int> &arr, int pl, int pr) {
    int h = pr + 1, l = pl;
    while (l < h) {
        int mi = l + (h - l >> 1);
        can(arr, pl, mi) ? h = mi : l = mi + 1;
        /* code */
    }
    return l;
}
int main(int argc, char const *argv[]) {
    debug();
    cin >> m >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }

    // 把[l,r]去掉 使得余下子序列单调不降
    // 15 14 13 12 25 24 45 44 34 35
    // 枚举 l 找到最小的 r n2
    // 二分 nlogn

    long long res = 0;
    int cr = mx;
    for (int i = 1; i <= m; i++) {
        int pl = check(arr, i, cr);

        //cr = min(cr, pl);
        //cout << i << " " << pl << endl;
        if (pl == mx + 1)
            break;
        res += m - pl + 1;
    }
    cout << res << endl;
    return 0;
}
