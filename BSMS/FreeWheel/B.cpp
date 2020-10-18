/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :B.cpp
 * @Created Time:2020-09-19 16:26:49
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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 对输入集合做hash join，输出关联后的下标的二元组集合
     * @param setA int整型一维数组 输入集合1
     * @param setALen int setA数组长度
     * @param setB int整型一维数组 输入集合2
     * @param setBLen int setB数组长度
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> hashJoin(int* setA, int setALen, int* setB, int setBLen) {
        // write code here
        // 实现hash join setB设计为小的数据集  一重指针直接swap就行
        if (setALen < setBLen) {
            swap(setALen, setBLen);
            swap(setA, setB);
        }
        unordered_map<int, vector<int>> mValtoIdxs;
        for (int i = 0; i < setBLen; i++)
            mValtoIdxs[*(setB + i)].push_back(i);
        vector<vector<int>> ret;
        for (int i = 0; i < setALen; i++) {
            int t = *(setA + i);
            if (mValtoIdxs.count(t)) {
                for (int j : mValtoIdxs[t])
                    ret.push_back({i, j});
            }
        }
        return ret;
    }
};