/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-09-16 18:57:59
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
const ll mod = 1e9 + 7;
ll me[805][805];
ll dfs(vector<int> &arr, int l, int r) {
    if (me[l][r])
        return me[l][r];
    if (l >= r - 1) {
        me[l][r] = 1;
        return 1;
    }

    ll ret = 0;
    for (int i = l; i < r; i++) {
        //[l,i) [i+1,r)
        if (i == l || arr[i] != arr[i - 1])
            ret += dfs(arr, l, i) * dfs(arr, i + 1, r);
    }
    me[l][r] = max(ret % mod, 1ll);
    return me[l][r];
}
int main(int argc, char const *argv[]) {
    /* code */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    memset(me, 0, sizeof me);
    // for (int i = 0; i <= n; i++) {
    //     me[i][i] = 1;
    //     me[i][i + 1] = 1;
    // }

    // for (int l = 2; l <= n; l++) {
    //     for (int i = 0; i < n - l; i++) {
    //         int j = i + l;
    //         for (int k = i; k < j; k++)
    //             if (k == i || arr[k] != arr[k - 1])
    //                 me[i][j] += me[i][k] * me[k + 1][j];
    //         me[i][j] %= mod;
    //     }
    // }
    //cout << me[0][n] << endl;
    cout << dfs(arr, 0, n) % mod << endl;
    return 0;
}
