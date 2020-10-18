/*
 * @Author      :vimday
 * @Desc        :wangyi a
 * @Url         :
 * @File Name   :A.cpp
 * @Created Time:2020-04-07 19:24:06
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll res = arr[1] - arr[0];
    for (int i = 2; i < n; i++) {
        ll t = arr[i] - arr[i - 1];

        res = __gcd(t, res);
        if (res < 1 || t < 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << res << endl;
    return 0;
}
