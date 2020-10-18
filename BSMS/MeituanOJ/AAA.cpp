/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-08-29 16:05:34
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
    string s;
    cin >> s;
    bool m = false, t = false;
    int st, et;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'M') {
            m = true;
        } else if (m && s[i] == 'T') {
            t = true;
            st = i + 1;
            break;
        }
    }
    if (!t) {
        cout << "" << endl;
        return 0;
    }
    t = false;
    m = false;
    for (int j = n - 1; j >= st; j--) {
        if (s[j] == 'T') {
            t = true;
        } else if (t && s[j] == 'M') {
            m = true;
            et = j;
            break;
        }
    }
    if (!m || et <= st) {
        cout << "" << endl;
        return 0;
    }
    cout << s.substr(st, et - st) << endl;
    return 0;
}
