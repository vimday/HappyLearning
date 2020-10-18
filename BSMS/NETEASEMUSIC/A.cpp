/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :A.cpp
 * @Created Time:2020-08-08 15:01:36
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
long long help(long long t) {
    long long res = t / 2;
    res += (t - res * 2) == 3 ? 1 : 0;
    return res;
}
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    long long res = 0, t = 0;
    for (int i = 0; i < n; i++) {
        cin >> t;
        res += help(t);
    }
    cout << res << endl;
    return 0;
}
