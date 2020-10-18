/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-10-10 19:17:54
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
const int inf = 0x3f3f3f3f;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param cars int整型一维数组 车辆数量
     * @param carsLen int cars数组长度
     * @param num int整型 出游总人数
     * @return int整型
     */
    int carsTrans(int* cars, int carsLen, int num) {
        // write code here
        sort(cars, cars + carsLen);
        int dp[num + 1];
        for (int i = 1; i <= num; i++)
            dp[i] = inf;
        dp[0] = 0;
        for (int i = 0; i < carsLen; i++)
            for (int j = cars[i]; j <= num; j++)
                dp[j] = min(dp[j], dp[j - cars[i]] + 1);
        return dp[num] == inf ? -1 : dp[num];
        // int mx = cars[carsLen - 1];
        // if (mx >= num)
        //     return 1;
        // if (num % mx == 0)
        //     return num / mx;
        // unordered_map<int, int> m;
        // int res = INT_MAX;
        // for (int i = 0; i < carsLen; i++) {
        //     int cp = cars[i];
        //     if (num % cp == 0)
        //         res = min(res, num / cp);
        //     m[cp] = 1;
        // }
        // m[0] = 0;
        // for (int i = carsLen - 1; i >= 0; --i) {
        //     int cp = cars[i];
        //     int t = num / cp, nd = num % cp;
        //     if (m.count(nd))
        //         res = min(res, t + m[nd]);
        // }
        // return res == INT_MAX ? -1 : res;
        //
        //return mx / num + mx % num != 0;
    }
};