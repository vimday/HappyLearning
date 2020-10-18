/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :C.cpp
 * @Created Time:2020-04-12 16:39:14
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
     * 根据顾客属性计算出顾客排队顺序
     * @param a int整型vector 顾客a属性
     * @param b int整型vector 顾客b属性
     * @return int整型vector
     */
    vector<int> WaitInLine(vector<int>& a, vector<int>& b) {
        // write code here

        int n = a.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = i + 1;
        sort(res.begin(), res.end(), [&](int i, int j) { return (a[i - 1] - b[i - 1]) > (a[j - 1] - b[j - 1]); });
        return res;
    }
};