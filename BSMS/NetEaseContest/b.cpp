/*
 * @Author      :vimday
 * @Desc        :wangyi b
 * @Url         :
 * @File Name   :b.cpp
 * @Created Time:2020-03-29 13:14:11
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

int bf(int ct, int n, int t, vector<int> &lv, vector<int> &ev) {
    int cm = 0;
    for (int i = 1; i <= n; i++) {
        if (lv[i] > 0 && lv[i] >= ct) {
            int pl = lv[i];
            lv[i] = -1;
            cm = max(cm, ev[i] + bf(ct + t, n, t, lv, ev));
            lv[i] = pl;
        }
    }
    return cm;
}
//10w  O(n)
int solve(int n, int t, vector<int> &lv, vector<int> &ev) {
    //bf(n2)
    vector<bool> me(n + 1);
    //t*n
    int res = 0;
    int tmax = t * n;
    for (int i = 1; i <= n; i++) {
        if (lv[i] >= tmax) {
            res += ev[i];
            me[i] = true;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int cm = 0, cj = -1;
        for (int j = 1; j <= n; j++) {
            if (lv[j] >= i * t && me[j] == false && ev[j] > cm) {
                cm = ev[j];
                cj = j;
            }
        }
        if (cj != -1) {
            res += cm;
            me[cj] = true;
        }
    }
    return res;
    // vector<pair<int, int>> data;
    // for (int i = 1; i <= n; i++)
    //     data.push_back({ev[i], lv[i]});
    // auto cmp = [](pair<int, int> a, pair<int, int> b) { return a.first == b.first ? a.second > b.second : a.first < b.first; };

    // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    // for (auto &p : data)
    //     pq.push(p);
    // int ct = 0, res = 0;
    // while (!pq.empty()) {
    //     auto p = pq.top();
    //     if (p.second < ct) {
    //         pq.pop();
    //         continue;
    //     }
    //     if (p.second < ct + t) {
    //         res += p.first;
    //         ct += t;
    //         pq.pop();
    //         continue;
    //     }
    //     vector<pair<int, int>> tmp;
    //     while (!pq.empty() && p)
    // }
    // vector<int> dp;
    return 0;
}
int main(int argc, char const *argv[]) {
    int n, t;
    cin >> n >> t;
    vector<int> lv(n + 1), ev(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> lv[i] >> ev[i];

    //cout << bf(0, n, t, lv, ev) << endl;
    cout << solve(n, t, lv, ev) << endl;
    return 0;
}
