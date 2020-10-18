/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :CCC.cpp
 * @Created Time:2020-09-21 21:18:15
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
    int n, k;
    cin >> n >> k;
    vector<int> me(n + 1);
    int cc[n + 1][n + 1];
    memset(cc, 0, sizeof cc);
    for (int i = 1; i <= n; i++) {
        int a;
        int b;
        cin >> a >> b;
        me[a]++;
        me[b]++;
        cc[a][b]++;
    }
    vector<array<int, 2>> va;
    for (int i = 1; i <= n; i++) {
        va.push_back({me[i], i});
    }
    sort(va.begin(), va.end());
    //reverse(va.begin(), va.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (va[i][0] + va[j][0] >= k) {
                int a = va[i][1], b = va[j][1];
                if (me[a] + me[b] - cc[a][b] >= k)
                    res++;
            } else {
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
