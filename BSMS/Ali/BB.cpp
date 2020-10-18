/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BB.cpp
 * @Created Time:2020-08-12 08:57:30
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
typedef long long ll;
string n;
string tobs() {
    // 十进制转成二进制
    string res;
}
string get(string a, string b) {
    stack<char> s;
    int sa = a.size() - 1, sb = b.size() - 1;
    int ad = 0;
    while (sa >= 0 || sb >= 0 || ad > 0) {
        int t = ad;
        if (sa >= 0) {
            t += a[sa] - '0';
            sa--;
        }
        if (sb >= 0) {
            t += b[sb] - '0';
            sb--;
        }
        s.push(t % 10 + '0');
        ad = t / 10;
    }
    string res;
    while (s.size()) {
        res += s.top();
        s.pop();
    }
    return res;
}
string douds(string s) {
    return get(s, s);
}
string tods(string bs) {
    // 二进制转成十进制

    string res;
    int sz = bs.size();
    for (int i = 0; i < sz; i++) {
        if (bs[i] == '1')
            res = get(douds(res), "1");
        else {
            res = douds(res);
        }
    }
}
void solve() {
    // 12 1100 1011
    // 48 110000 101111
    // 转换为二进制 k位 k-1个 1，从低到高
    // 偶数 0->1
    string bs = tobs();
    int sz = bs.size();
    bool f = false;
    for (int i = 1; i < sz; i++)
        if (!f && bs[i] == '0')
            f = true;
        else if (f)
            bs[i] = '1';
    cout << tods(bs) << endl;
}
int main(int argc, char const *argv[]) {
    int T;
    while (T--) {
        cin >> n;
        solve();
    }
    return 0;
}
