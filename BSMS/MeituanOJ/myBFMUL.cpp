/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :myBFMUL.cpp
 * @Created Time:2020-04-14 16:54:40
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

string mymul(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int tmp[m + n] = {};
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            tmp[i + j] += (num1[i] - '0') * (num2[j] - '0');
    int end = 0;
    for (int i = 1; i < m + n; i++) {
        int carry = tmp[i - 1] / 10;
        tmp[i - 1] %= 10;
        tmp[i] += carry;
        if (tmp[i]) end = i;
    }
    string res;
    for (int i = end; ~i; i--) res += tmp[i] + '0';
    return res;
}
int main(int argc, char const *argv[]) {
    cout << mymul("201", "987654321") << endl;
    return 0;
}
