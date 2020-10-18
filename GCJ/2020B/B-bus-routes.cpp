/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83bf
 * @File Name   :B-bus-routes.cpp
 * @Created Time:2020-10-09 15:00:19
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
void printIntAns(int caseNum, ll ans) {
    printf("Case #%d: %ld\n", caseNum, ans);
}
int n;
ll d;
ll arr[1005];
vector<vector<ll>> vvl;
bool can(ll mi) {
    for (int i = 0; i < n; i++) {
        if (mi % arr[i] == 0)
            continue;
        ll cnt = mi / arr[i] + 1;
        mi = arr[i] * cnt;
        if (mi > d)
            return false;
        // if (vvl[i].empty())
        //     continue;
        // int idx = lower_bound(vvl[i].begin(), vvl[i].end(), mi) - vvl[i].begin();
        // if (idx == vvl[i].size())
        //     return false;
        // mi = vvl[i][idx];
    }
    return true;
}
ll solve2() {
    cin >> n >> d;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n - 1; ~i; i--) {
        ll t = arr[i];
        if (d % t == 0)
            continue;
        d = d / t * t;
    }
    return d;
}
ll solve() {
    cin >> n >> d;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll l = 1, h = d + 1;
    while (l < h) {
        ll mi = l + (h - l >> 1);
        can(mi) ? l = mi + 1 : h = mi;
    }

    return --l;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T;)
        printIntAns(++i, solve2());
    return 0;
}