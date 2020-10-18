/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :A.cpp
 * @Created Time:2020-04-12 16:01:18
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

    int n = s.size(), mc = 0, ml = 0, mr = 0;
    for (char &c : s) {
        if (c == '(') {
            ml++;
        } else if (c == ')') {
            if (ml > 0) {
                ml--;
                mc++;
            } else {
                mr++;
            }
        }
    }

    cout << mc << " " << ml << " " << mr << endl;
    return 0;
}
