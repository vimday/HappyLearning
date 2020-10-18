/*
 * @Author      :vimday
 * @Desc        :https://leetcode-cn.com/circle/article/g1bTxa/
 * @Url         :https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edc/00000000001864bc
 * @File Name   :B_teach-me.cpp
 * @Created Time:2020-10-07 15:49:09
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
const long long rd = 1001;
long long solve() {
    int n, s;
    cin >> n >> s;
    vector<long long> mhash(n);
    unordered_map<long long, int> mcnt;
    for (int i = 0; i < n; i++) {
        int cnt;
        cin >> cnt;
        vector<int> skills(cnt);
        for (int j = 0; j < cnt; j++)
            cin >> skills[j];
        sort(skills.begin(), skills.end());
        long long hash = 0;
        for (int k = 0; k < (1 << cnt); k++) {
            hash = 0;
            for (int idx = 0; idx < cnt; idx++)
                if (k & 1 << idx) {
                    hash = hash * rd + skills[idx];
                }
            mcnt[hash]++;
        }
        mhash[i] = hash;
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += n - mcnt[mhash[i]];
    }
    return res;
}
int bf() {
    int n, s;
    cin >> n >> s;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int c;
            cin >> c;
            g[i].push_back(c);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            bool f = true;
            for (int &a : g[i]) {
                for (int &b : g[j]) {
                    if (b == a)
                        f = false;
                }
                if (f) {
                    res++;
                    break;
                }
                f = true;
            }
        }
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

// #include <algorithm>
// #include <iostream>
// #include <unordered_map>
// #include <vector>

// using namespace std;

// typedef long long ll;
// const ll radix = 1001;

// void solve(int case_num) {
//     int n, s;
//     cin >> n >> s;
//     vector<ll> a;
//     unordered_map<ll, int> cnt;
//     for (int i = 0; i < n; ++i) {
//         int skill_count;
//         cin >> skill_count;
//         vector<int> skills(skill_count);
//         for (int j = 0; j < skill_count; ++j) scanf("%d", &skills[j]);
//         sort(skills.begin(), skills.end());
//         ll hash = 0;
//         for (const int &skill : skills) hash = hash * radix + skill;
//         a.emplace_back(hash);
//         for (int j = 0; j < (1 << skill_count); ++j) {
//             ll hash = 0;
//             for (int k = 0; k < skill_count; ++k)
//                 if (j & (1 << k)) hash = hash * radix + skills[k];
//             cnt[hash]++;
//         }
//     }
//     ll ans = 0;
//     for (int i = 0; i < n; ++i) {
//         ans += n - cnt[a[i]];
//     }
//     cout << "Case #" << case_num << ": " << ans << endl;
// }

// int main() {
//     int t;
//     cin >> t;
//     for (int i = 1; i <= t; ++i) {
//         solve(i);
//     }
//     return 0;
// }