/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-10-12 09:13:38
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
bool isCorI(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}
bool isSame(char a, char b) {
    if (a >= '0' && a <= '9')
        return b == a;
    return tolower(a) == tolower(b);
}
bool isPal(const string &s) {
    int n = s.size();
    if (n < 2)
        return true;
    int l = 0, h = n - 1;
    while (l < h) {
        while (l < h && !isCorI(s[l])) l++;
        while (l < h && !isCorI(s[h])) h--;
        if (l >= h)
            return true;
        if (isSame(s[l], s[h])) {
            ++l;
            --h;
        } else {
            return false;
        }
    }
    return true;
}