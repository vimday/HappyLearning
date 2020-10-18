/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-09-16 19:43:53
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
int n, k;
bool can(vector<vector<int>> &data, int t) {
    bool me[k];
    memset(me, false, sizeof me);
    for (vector<int> &arr : data) {
        for (int i = 0; i < k; i++) {
            if (arr[i] >= t && me[i])
                return true;
                }
    }
}
int main(int argc, char const *argv[]) {
    cin >> n >> k;
    vector<vector<int>> data(n, vector<int>(k, 0));
    int res = 0;
    for (int i = 0; i < n; i++) {
        int cm = INT_MAX;
        for (int j = 0; j < k; j++) {
            cin >> data[i][j];
            cm = min(cm, data[i][j]);
        }
        res = max(res, cm);
    }
    int l = res, h = 100001;
    while (l < h) {
        int mi = l + (h - l >> 1);
        can(data, mi) ? l = mi + 1 : h = mi;
    }
    cout << --l << endl;
    //bf
    // for (int i = 0; i < n; i++)
    //     for (int j = i + 1; j < n; j++) {
    //         int cm = INT_MAX;
    //         for (int x = 0; x < k; k++)
    //             cm = min(cm, max(data[i][x], data[j][x]));
    //         res = max(res, cm);
    //     }
    // cout << res << endl;
    return 0;
}
