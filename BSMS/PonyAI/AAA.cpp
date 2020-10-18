/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-09-20 14:57:34
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
const int mod = 1e9 + 7;
int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    int n = s.size();

    int res = 0;
    vector<vector<ll>> me(n + 1, vector<ll>(n + 1));
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            me[i][j] = me[i][j - 1] * 26 + s[j - 1] - 'a' + 1;
            me[i][j] %= mod;
        }
    for (int k = 1; k <= n / 2; k++)
        for (int i = 0; i < n - 2 * k + 1; i++)
            if (me[i][i + k] == me[i + k][i + 2 * k])
                res++;
    cout << res << endl;
    //bf;
    // for (int k = 1; k <= n / 2; k++)
    //     for (int i = 0; i < n - 2 * k + 1; i++)
    //         if (s.substr(i, k) == s.substr(i + k, k))
    //             res++;
    // cout << res << endl;
    // 字符串hash
    // vector<ll> arr(n + 1), ps(n + 1);
    // //arr[0] = s[0] - 'a' + 1;
    // ps[0] = 1;
    // for (int i = 0; i < n; i++) {
    //     arr[i + 1] = 26 * arr[i] + s[i] - 'a' + 1;
    //     arr[i + 1] %= mod;
    //     ps[i + 1] = ps[i] * 26;
    //     ps[i + 1] %= mod;
    // }
    // for (int k = 1; k <= n / 2; k++)
    //     for (int i = 0; i < n - 2 * k + 1; i++) {
    //         // ll sa = (arr[i + k] - arr[i] * ps[k]) % mod;
    //         // ll sb = (arr[i + 2 * k] - arr[i + k] * ps[k]) % mod;
    //         ll sa = arr[i + k] % ps[k];
    //         ll sb = arr[i + 2 * k] % ps[k];
    //         if (sa == sb)
    //             res++;
    //         // if (s.substr(i, k) == s.substr(i + k, k))
    //         //     res++;
    //     }

    return 0;
}
