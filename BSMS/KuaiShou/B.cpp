/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :B.cpp
 * @Created Time:2020-04-12 16:05:33
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
     * 返回无重复幂因子的 N进制完美数之和的所有幂因子
     * @param R int整型 
     * @param N int整型 N进制
     * @return int整型vector
     */

    //即为 R的n进制表示中是否全为1
    vector<int> GetPowerFactor(int R, int N) {
        // write code here
        if (R == 1) return {0};
        if (N == 1 || R < N) return {};
        int mx = 0, cur = N;
        vector<int> res;
        while (R >= N) {
            mx = 0;
            cur = N;
            while (cur <= R) {
                cur *= N;
                mx++;
            }
            if (res.size() && res.back() == mx) return {};
            res.push_back(mx);
            R -= cur / N;
        }
        if (R) return {};
        sort(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const *argv[]) {
    debug();
    Solution sl = Solution();

    int R, N;
    while (cin >> R >> N) {
        vector<int> res = sl.GetPowerFactor(R, N);
        for (int &i : res)
            cout << i << " ";
        cout << endl;
        /* code */
    }

    return 0;
}
