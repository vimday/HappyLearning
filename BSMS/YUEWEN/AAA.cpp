/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-10-21 19:16:45
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
     * 计算int对应二进制中1的个数
     * @param n int整型 数字
     * @return int整型
     */
    int countBit(int n) {
        // write code here
        int res = 0;
        while (n) {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};