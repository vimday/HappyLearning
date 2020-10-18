/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :C_Perfect-Subarry.cpp
 * @Created Time:2020-10-11 20:19:37
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

ll solve() {
    int n;
    cin >> n;
    int ps = 0, pm = 0;
    ll res = 0;
    unordered_map<int, int> mi;
    mi[0] = 1;
    for (int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        ps += tmp;
        int t = ps;
        int j = 0;
        while (t >= pm) {
            t = ps - j * j;
            ++j;
            if (mi.count(t))
                res += mi[t];
        }
        ++mi[ps];
        pm = min(pm, ps);
    }
    return res;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    //getpa();
    int T;
    cin >> T;

    for (int i = 0; i < T;)
        printAns(++i, solve());
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 1e5;
int n, a[mxN], c[2 * 100 * mxN + 1];

void solve1() {
    cin >> n;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0)
            s1 -= a[i];
        else
            s2 += a[i];
    }
    int t = 0;
    ll ans = 0;
    ++c[s1];
    for (int i = 0; i < n; ++i) {
        t += a[i];
        for (int j = 0; j * j <= s2; ++j) {
            if (s1 + (t - j * j) >= 0)
                ans += c[s1 + (t - j * j)];
        }
        ++c[s1 + t];
    }
    cout << ans << "\n";
    memset(c, 0, 4 * (s1 + s2 + 1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve1();
    }
}