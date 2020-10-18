/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :C.cpp
 * @Created Time:2020-09-19 16:43:29
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
//模拟题意
struct MyData {
    int val;
    int idx;
    int type;
    /* data */
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 实现Sort Merge Join
     * @param setA int整型一维数组 
     * @param setALen int setA数组长度
     * @param setB int整型一维数组 
     * @param setBLen int setB数组长度
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> sortMergeJoin(int* setA, int setALen, int* setB, int setBLen) {
        // write code here
        vector<MyData> arr;
        for (int i = 0; i < setALen; i++) {
            arr.push_back({*(setA + i), i, 0});
        }
        for (int i = 0; i < setBLen; i++) {
            arr.push_back({*(setB + i), i, 1});
        }
        sort(arr.begin(), arr.end(), [](MyData a, MyData b) { return a.val < b.val; });
        vector<vector<int>> ret;
        int n = arr.size();
        int pre = 0;
        for (int i = 1; i < n; i++) {
            while (i < n && arr[i].val == arr[pre].val) {
                i++;
            }
            for (int j = pre; j < i; j++) {
                for (int k = pre; k < i; k++)
                    if (arr[j].type == 0 && arr[k].type == 1)
                        ret.push_back({arr[j].idx, arr[k].idx});
            }
            pre = i;
        }
        return ret;
    }
};