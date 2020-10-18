/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :D.cpp
 * @Created Time:2020-04-12 16:50:30
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
     * 获取最大可同事办公员工数
     * @param pos char字符型vector<vector<>> 工位分布
     * @return int整型
     */
    bool canpos(int i, int idx, vector<vector<char> >& pos) {
        if ((i & (i >> 1)) || (i & (i >> 1)))
            return false;
        int n = pos[idx].size();
        for (int k = 0; k < n; k++) {
            if (pos[idx][k] == '*' && ((i >> k) & 1))
                return false;
        }
        return true;
    }
    int helpcnt(int i) {
        int res = 0;
        while (i) {
            res += i & 1;
            i >>= 1;
        }
        return res;
    }
    int GetMaxStaffs(vector<vector<char> >& pos) {
        // write code here
        int m = pos.size(), n = pos[0].size();
        int sz = 1 << n;
        int dp[m][sz];
        memset(dp, 0, sizeof dp);
        for (int j = 0; j < sz; j++)
            if (canpos(j, 0, pos))
                dp[0][j] = helpcnt(j);
        for (int i = 1; i < m; i++)
            for (int j = 0; j < sz; j++) {
                if (canpos(j, i, pos)) {
                    for (int pj = 0; pj < sz; pj++) {
                        if ((pj & j) == 0)
                            dp[i][j] = max(dp[i][j], dp[i - 1][pj] + helpcnt(j));
                    }
                }
            }
        int res = 0;
        for (int i = 0; i < sz; i++)
            res = max(res, dp[m - 1][i]);
        return res;
    }
};