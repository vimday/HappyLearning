/*
 * @Author      :vimday
 * @Desc        :meituan b
 * @Url         :
 * @File Name   :b.cpp
 * @Created Time:2020-03-26 19:13:00
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
const double PI = atan(1) * 4;
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> me(n);
    for (int i = 0; i < n; i++)
        cin >> me[i];
    sort(me.begin(), me.end(), [](int a, int b) { return a > b; });
    double res = 0;
    for (int i = 0; i < n; i++)
        if (i & 1)
            res -= PI * me[i] * me[i];
        else {
            res += PI * me[i] * me[i];
        }
    res = floor(100000.0000f * res + 0.5) / 100000.0000f;
    printf("% .5f\n", res);
    cout << res << endl;
    return 0;
}
