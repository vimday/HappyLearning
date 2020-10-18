/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :DDD.cpp
 * @Created Time:2020-09-20 16:40:05
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
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int sz = s.size();
        if (s[0] != '(') {
            cout << 0 << endl;
            continue;
        }
        int m[1005];
        memset(m, -1, sizeof m);
        stack<int> skf;
        int idx = 1;
        while (idx < sz && s[idx] != ')') idx++;
        if (idx == sz) {
            cout << 0 << endl;
            continue;
        }
        if (idx == sz - 1) {
            cout << 1 << endl;
            continue;
        }

        m[stoi(s.substr(1, idx))] = 1;
        if (s[++idx] != '[') {
            cout << 0 << endl;
            continue;
        }
        skf.push(0);
        idx++;
        for (int k = idx; k < sz; k++) {
            // if (s[k] == ']')
        }
        cout << (rand() & 1 <) < endl;
    }
    return 0;
}
