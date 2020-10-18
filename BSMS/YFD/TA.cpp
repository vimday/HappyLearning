/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :TA.cpp
 * @Created Time:2020-08-29 10:03:05
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
     * @param trees: the positions of trees.
     * @param d: the minimum beautiful interval.
     * @return: the minimum number of trees to remove to make trees beautiful.
     */
    int treePlanning(vector<int> &trees, int d) {
        // write your code here.
        int n = trees.size();
        int dp[n][2];
        memset(dp, 0x7f, sizeof dp);
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
            if (trees[i] >= trees[i - 1] + d) {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
            } else {
                int pre = upper_bound(trees.begin(), trees.begin() + i, trees[i] - d) - trees.begin();
                //pre--;
                if (pre == 0) {
                    dp[i][0] = i - pre;
                } else {
                    dp[i][0] = min(dp[pre - 1][0], dp[pre - 1][1]) + (i - pre);
                }
            }
        }
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};
class Solution {
public:
    /**
     * @param lengths: the lengths of sticks at the beginning.
     * @return: return the minimum number of cuts.
     */
    int makeEquilateralTriangle(vector<int> &lengths) {
        // write your code here.
        int n = lengths.size();
        if (n == 1) {
            return n % 3 == 0 ? 2 : 3;
        }
        unordered_map<int, int> m;
        int mn = INT_MAX, mx = INT_MIN;
        int res = 3;
        for (int i : lengths) {
            m[i]++;
            if (m[i] > 2)
                return 0;
            mn = min(mn, i);
            mx = max(mx, i);
            if (i > 2 * mn) {
                res = min(res, 2);
            } else if (i == 2 * mn)
                res = min(res, 1);
        }
        for (auto &p : m) {
            if (p.second >= 2) {
                if (mx > p.first) {
                    res = min(res, 1);
                }
            }
        }
        if (n > 2)
            res = min(res, 2);
        return res;
    }
};
class Solution {
public:
    /**
     * @param s: a string.
     * @return: return the values of all the intervals.
     */
    long long suffixQuery(string &s) {
        int n = s.size();
        long long res = 0;
        long long ps = 0, pd = 0;
        for (int i = 0; i < n; i++) {
            if (i && s[i] == s[i - 1]) {
                res += ps - pd;
                ps -= pd;
                pd--;

            } else {
                ps = 0;
                pd = 0;
                for (int j = i; j < n; j++) {
                    int k = 0;
                    for (; k < j - i + 1; k++)
                        if (s[i + k] != s[j - k])
                            break;
                    if (k) {
                        res += k;
                        pd++;
                        ps += k;
                    }
                }
            }
        }

        return res;
        // write your code here
    }
};

int main(int argc, char const *argv[]) {
    Solution *s = new Solution();
    vector<int> t = {1, 2, 3, 5, 6};
    cout << s->treePlanning(t, 2) << endl;
    return 0;
}
