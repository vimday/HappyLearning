/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-09-12 15:13:29
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
    int n = s.size();
    for (char &c : s) {
        if (c == 'a')
            c = '1';
        else if (c == 'b')
            c = '2';
        else if (c == 'c')
            c = '3';
        else if (c == 'x')
            c = '4';
        else if (c == 'y')
            c = '5';
        else if (c == 'z')
            c = '6';
    }
    int sz = 1 << 6;
    int dp[sz];
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    int cur = 0, res = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c > '0' && c < '7') {
            cur ^= (1 << (c - '1'));
            if (dp[cur] == -1)
                dp[cur] = i + 1;
            else {
                int j = i + 1;
                while (j < n && s[j] > '0' && s[j] < '7') j++;
                res = max(res, j - dp[cur]);
            }
            // cout << c << " " << cur << " " << dp[cur] << endl;
        }
        if (cur == 0)
            res = i + 1;
    }

    cout << res << endl;
    return 0;
}
