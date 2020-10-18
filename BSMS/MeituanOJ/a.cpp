/*
 * @Author      :vimday
 * @Desc        :meituan  a
 * @Url         :
 * @File Name   :a.cpp
 * @Created Time:2020-03-26 19:03:05
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
    string s;
    cin >> s;
    int m[10];
    memset(m, 0, sizeof m);
    for (int i = 0; i < 9; i++)
        cin >> m[i + 1];
    for (char &c : s)
        if (c > '0' && c <= '9')
            c = m[c - '0'] + '0';
    cout << s << endl;

    return 0;
}
