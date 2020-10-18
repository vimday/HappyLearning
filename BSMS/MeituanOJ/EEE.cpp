/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :EEE.cpp
 * @Created Time:2020-08-29 17:41:53
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
int main(int argc, char const *argv[]) {
    debug();
    int n;
    cin >> n;
    vector<int> va(n + 1), vb(n + 1, -1);
    for (int i = 0; i < n; i++)
        cin >> va[i + 1];
    int T;
    cin >> T;
    while (T--) {
        int op;
        cin >> op;
        if (op == 2) {
            int ct;
            cin >> ct;
            cout << vb[ct] << endl;
        } else {
            int i, k, j;
            cin >> i >> k >> j;
            for (int t = 0; t < k; t++)
                vb[j + t] = va[i + t];
        }
    }
    return 0;
}
