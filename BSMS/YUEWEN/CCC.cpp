/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :CCC.cpp
 * @Created Time:2020-10-21 19:25:42
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
class Solution {
public:
    /**
     * 
     * @param str string字符串 
     * @return string字符串
     */
    string removeDuplicatedChars(string str) {
        string res;
        // sort / map
        bool m[256];
        memset(m, 0, sizeof m);
        for (char &c : str)
            if (!m[c]) {
                res.push_back(c);
                m[c] = true;
            }
        return res;

        // write code here
    }
};