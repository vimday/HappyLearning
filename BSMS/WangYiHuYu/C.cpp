/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :C.cpp
 * @Created Time:2020-04-11 20:12:16
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
//20! tle
//贪心
//：如果是暴力方式，就是把A的所有错排都列出来，然后一一计算，算出最短的后就是结果。
//那么这样做显然是TLE的。该怎么办呢？考虑题目的意思，每个位置安排了一个权重，
//要求最后和最小。那么显然权重最大的安排位置偏移较小，最小的安排偏移位置较大就是最佳答案。
//但是这样可能会形成一个结果就是至少有一个数字不得不呆在原来的位置上。
//那么就不是错排了。所以题目的意思实际上是在保证错排的基础上，
//怎样安排能让distance最小。因此可设dp[i]为前i个数所形成的最小distance.
//对于第i+1个数，由于它不能呆在i+1位置上，那么必须要跟之前的某个数交换。
//由于被换过来的数呆在i+1位置上，那么这样形成的排列能保证也是错排。
//那么只需要遍历一下找找此时换哪个数过来distance最小就行。

//这个 要是偶数个数的话 可以贪心成每两个成对的交换位置 这样是最小的

//要是奇数个的话 保证权重最大的前偶数个 互相交换 剩下最小的跟前面的遍历交换 这样复杂度就nlogn了  如果你那个思路是对的 这个就应该也对吧
//奇数个的话 按权重排序  ，取前n-1个两两交换 最小的权重那个遍历后面每个个交换取最小（也可能直接最权重最小的三个交换就是最优解 ）

//有负数的情况
//dp[i][j]

int dfs(int ci, vector<int> &arr, vector<int> &val, vector<int> &pos, vector<int> &newarr, vector<int> &me, vector<int> &mval) {
    int n = arr.size();
    if (ci >= n - 1) return 0;
    int res = 0x3f3f3f3f;

    int t = mval[ci];

    int ppos = pos[t];
    if (ppos + 1 < n && newarr[ppos + 1] == 0) {
        newarr[ppos + 1] = t;
        me[t] = 1;
        res = min(res, val[t] + dfs(ci + 1, arr, val, pos, newarr, me, mval));
        newarr[ppos + 1] = 0;
        me[t] = 0;
    }

    if (ppos - 1 > 0 && newarr[ppos - 1] == 0) {
        newarr[ppos - 1] = t;
        me[t] = 1;
        res = min(res, val[t] + dfs(ci + 1, arr, val, pos, newarr, me, mval));
        newarr[ppos - 1] = 0;
        me[t] = 0;
    }

    // for (int i = 1; i < n; i++) {
    //     if (pre[ci] != i && me[i] == 0) {
    //         cur[ci] = i;
    //         me[i] = 1;
    //         res = min(res, abs(val[i] * (pos[i] - ci)) + dfs(ci + 1, pre, val, pos, cur, me, mval));
    //         me[i] = 0;
    //     }
    // }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1), val(n + 1), pos(n + 1);
    vector<int> mval(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i + 1];
        pos[arr[i + 1]] = i + 1;
    }

    for (int i = 0; i < n; i++)
        cin >> val[i + 1];
    int res = INT_MAX;
    vector<int> newarr(n + 1), me(n + 1);
    sort(mval.begin(), mval.end(), [&val](int a, int b) { return val[a] > val[b]; });
    for (int i = 0; i < 1; i++) {
        int t = mval[i];
        int ppos = pos[t];
        if (ppos + 1 <= n) {
            newarr[ppos + 1] = t;
            me[t] = 1;
            res = min(res, val[t] + dfs(1, arr, val, pos, newarr, me, mval));
            newarr[ppos + 1] = 0;
            me[t] = 0;
        }

        if (ppos - 1 > 0) {
            newarr[ppos - 1] = t;
            me[t] = 1;
            res = min(res, val[t] + dfs(1, arr, val, pos, newarr, me, mval));
            newarr[ppos - 1] = 0;
            me[t] = 0;
        }
    }

    //bf

    // for (int i = 1; i <= n; i++) {
    //     if (arr[1] != i) {
    //         newarr[1] = i;
    //         me[i] = 1;
    //         res = min(res, abs(val[i] * (pos[i] - 1)) + dfs(2, arr, val, pos, newarr, me));
    //         me[i] = 0;
    //     }
    // }
    cout << res << endl;
}
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
