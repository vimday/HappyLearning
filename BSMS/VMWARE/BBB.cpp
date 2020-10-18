/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-09-21 20:58:18
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
void solve() {
    int n;
    cin >> n;
    vector<int> old(n), tt(n);
    for (int i = 0; i < n; i++)
        cin >> old[i];
    for (int i = 0; i < n; i++)
        cin >> tt[i];
    while (true) {
        bool f = false;
        for (int i = 0; i < n; i++) {
            if (old[i] == tt[i])
                continue;
            if ((i > 0 && old[i - 1] == tt[i]) || (i < n - 1 && old[i + 1] == tt[i])) {
                old[i] = tt[i];
                f = true;
            }
        }
        if (!f)
            break;
    }
    while (true) {
        bool f = false;
        for (int i = n - 1; i >= 0; i--) {
            if (old[i] == tt[i])
                continue;
            if ((i > 0 && old[i - 1] == tt[i]) || (i < n - 1 && old[i + 1] == tt[i])) {
                old[i] = tt[i];
                f = true;
            }
        }
        if (!f)
            break;
    }
    if (old == tt)
        cout << "YES" << endl;
    else {
        cout << "NO" << endl;
    }
}
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
