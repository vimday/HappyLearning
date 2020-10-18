/*
 * @Author      :vimday
 * @Desc        :wangyi a
 * @Url         :
 * @File Name   :a.cpp
 * @Created Time:2020-03-29 13:02:24
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
    string f1, f2;
    cin >> f1 >> f2;

    vector<int> v1(26), v2(26);
    for (char &c : f1)
        v1[c - 'a']++;
    for (char &c : f2)
        v2[c - 'a']++;
    if (n == 1) {
        for (int i = 0; i < 26; i++)
            if (v1[i] > 0) {
                char c = i + 'a';
                cout << c << ":" << v1[i] << endl;
            }
        return 0;
    }
    for (int i = 3; i <= n; i++) {
        vector<int> tmp(26);
        for (int j = 0; j < 26; j++)
            tmp[j] = v1[j] + v2[j];
        v1 = v2;
        v2 = tmp;
    }
    for (int i = 0; i < 26; i++)
        if (v2[i] > 0) {
            char c = i + 'a';
            cout << c << ":" << v2[i] << endl;
        }
    return 0;
}
