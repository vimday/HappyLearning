/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :c.cpp
 * @Created Time:2020-03-26 19:27:52
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
const long long mod = 998244353;
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    //vector<vector<long long>> dp(n, vector<long long>(n));
    vector<long long> dp(n + 1, -1);
    unordered_map<int, vector<int>> m;
    // vector<int> vb(v.begin(), v.end());
    // sort(vb.begin(), vb.end());
    for (int i = n - 1; i >= 0; i--) {
        int t = v[i];
        if (m.count(t) == 0) {
            for (int j = min(i + 1, t); j >= 1; j--) {
                if (t % j == 0)
                    m[t].push_back(j);
            }
        }
    }

    dp[0] = 1;
    dp[1] = 1;
    long long res = 1;
    for (int i = 1; i < n; i++) {
        int t = v[i];
        vector<int> &vb = m[t];
        int sz = vb.size();
        for (int pj = 0; pj < sz; pj++) {
            int j = vb[pj];
            if (dp[j - 1] != -1) {
                if (dp[j] == -1)
                    dp[j] = 0;
                dp[j] += dp[j - 1];
                dp[j] %= mod;
                res += dp[j - 1];
                res %= mod;
            }
        }
    }
    res %= mod;
    cout << res << endl;
    return 0;
}
