/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-09-03 19:32:44
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
    int n;
    cin >> n;
    vector<int> arr(n);
    int five = 0, zero = 0, t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t)
            five++;
        else {
            zero++;
        }
    }
    if (zero == 0) {
        cout << -1 << endl;
        return 0;
    }
    // 9个5能除尽
    if (five < 9) {
        cout << 0 << endl;
        return 0;
    }
    string res;
    while (five >= 9) {
        res += "555555555";
        five -= 9;
    }
    res += string(zero, '0');
    cout << res << endl;
    return 0;
}
