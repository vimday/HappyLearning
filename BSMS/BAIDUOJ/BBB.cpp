/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-09-03 19:47:42
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
int n, m;
int arr[1005];
void solve() {
    memset(arr, 0, sizeof arr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        while (t--) {
            int l, r;
            cin >> l >> r;
            for (int j = l; j <= r; j++)
                arr[j]++;
        }
    }
    vector<int> res;
    for (int i = 1; i <= n; i++)
        if (arr[i] == m)
            res.push_back(i);
    cout << res.size() << endl;
    int sz = res.size();
    for (int i = 0; i < sz; i++)
        cout << res[i] << " \n"[i == sz - 1];
}
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
