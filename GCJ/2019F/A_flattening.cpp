/*
 * @Author      :vimday
 * @Desc        :https://leetcode-cn.com/circle/article/g1bTxa/
 * @Url         :https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edc/000000000018666c#analysis
 * @File Name   :A_flattening.cpp
 * @Created Time:2020-10-06 22:17:34
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
int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    unordered_set<int> si;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        si.insert(arr[i]);
    }
    vector<int> nums(si.begin(), si.end());
    int m = nums.size();
    int dp[n + 1][k + 1][m];
    memset(dp, 0x3f, sizeof dp);
    int mdp[n][k + 1];
    memset(mdp, 0x3f, sizeof dp);
    for (int i = 0; i < m; ++i) {
        if (nums[i] != arr[0])
            dp[1][0][i] = 1;
        else {
            dp[1][0][i] = 0;
            mdp[1][0] = 0;
        }
    }
    for (int i = 2; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
            for (int ht = 0; ht < m; ++ht) {
                dp[i][j][ht] = dp[i - 1][j][ht];
                if (j)
                    dp[i][j][ht] = min(dp[i][j][ht], mdp[i - 1][j - 1]);
                dp[i][j][ht] += nums[ht] != arr[i - 1];
                mdp[i][j] = min(mdp[i][j], dp[i][j][ht]);
            }
    int res = INT_MAX;
    for (int i = 0; i <= k; i++)
        res = min(res, mdp[n][i]);
    return res;
}
int solve2() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int cc[n][n], me[n][n];
    memset(cc, 0, sizeof cc);
    for (int i = 0; i < n; i++) {
        int cm[1001];
        memset(cm, 0, sizeof cm);
        cm[arr[i]]++;
        me[i][i] = arr[i];
        int cnt = 1;
        for (int j = i + 1; j < n; j++) {
            if (++cm[arr[j]] > cnt)
                cnt = cm[arr[j]];
            cc[i][j] = j - i + 1 - cnt;
        }
    }
    int dp[n][k + 1];
    memset(dp, 0x3f, sizeof dp);
    memset(dp, 0, sizeof dp[0]);
    for (int i = 1; i < n; i++) {
        dp[i][0] = cc[0][i];
        for (int j = 1; j <= k; j++)
            for (int pre = 0; pre < i; pre++)
                dp[i][j] = min(dp[pre][j - 1] + cc[pre + 1][i], dp[i][j]);
    }
    int res = INT_MAX;
    for (int i = 0; i <= k; i++)
        res = min(res, dp[n - 1][i]);
    return res;
}
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}

#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

typedef long long ll;

using namespace std;

void solve(int case_num) {
    int n, k;
    cin >> n >> k;
    vector<ll> a;
    unordered_set<ll> nums_set;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        a.emplace_back(ai);
        nums_set.insert(ai);
    }
    vector<ll> nums(nums_set.begin(), nums_set.end());
    int t = nums.size();

    vector<vector<vector<ll>>> f(n + 1, vector<vector<ll>>(k + 1, vector<ll>(t, INT_MAX)));
    vector<vector<ll>> minf(n + 1, vector<ll>(k + 1, INT_MAX));

    for (int i = 0; i < t; ++i) {
        if (nums[i] != a[0]) {
            f[1][0][i] = 1;
        } else {
            f[1][0][i] = 0;
            minf[1][0] = 0;
        }
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= min(k, i - 1); ++j) {
            for (int m = 0; m < t; ++m) {
                f[i][j][m] = f[i - 1][j][m];
                if (j > 0) f[i][j][m] = min(f[i][j][m], minf[i - 1][j - 1]);
                if (a[i - 1] != nums[m]) f[i][j][m]++;
                if (f[i][j][m] < minf[i][j]) minf[i][j] = f[i][j][m];
            }
        }
    }

    ll ans = INT_MAX;
    for (int j = 0; j <= k; ++j)
        for (int m = 0; m < t; ++m)
            ans = min(ans, f[n][j][m]);

    cout << "Case #" << case_num << ": " << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}