/*
 * @Author      :vimday
 * @Desc        :baidu a
 * @Url         :
 * @File Name   :A.CPP
 * @Created Time:2020-03-29 18:56:47
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

ll gcd(ll a, ll b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return abs(a);
}
ll lcm(ll a, ll b) {
    ll gd = gcd(a, b);
    return a * b / gd;
}
int main(int argc, char const *argv[]) {
    ll n;
    cin >> n;
    //bf
    ll res = n - 1;
    for (int i = 2; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            ll gd = gcd(i, j);
            ll lm = i * j / gd;
            if (lm - gd > res)
                res = lm - gd;
        }
    cout << res << endl;
    return 0;
}
