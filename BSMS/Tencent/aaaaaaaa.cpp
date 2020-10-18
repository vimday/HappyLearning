/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :aaaaaaaa.cpp
 * @Created Time:2020-04-19 10:28:16
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
    int minNumberOfFrogs(string cfs) {
        int n = cfs.size();
        if (n % 5) return -1;
        vector<int> cfi;
        for (char &c : cfs) {
            if (c == 'c')
                cfi.push_back(1);
            else if (c == 'r')
                cfi.push_back(2);
            else if (c == 'o')
                cfi.push_back(3);
            else if (c == 'a')
                cfi.push_back(4);
            else
                cfi.push_back(5);
        }
        vector<int> mt(6);
        for (int &i : cfi)
            mt[i]++;
        for (int i = 1; i <= 5; i++)
            if (mt[i] != n / 5)
                return -1;
        int res = 0;
        vector<int> m(6);
        for (int &i : cfi) {
            if (i == 1) {
                m[1]++;
                if (m[5] == 0)
                    res++;
                else
                    m[5]--;
            }

            else if (i == 2) {
                if (m[1] <= 0)
                    return -1;
                m[1]--;
                m[2]++;
            } else if (i == 3) {
                if (m[2] <= 0)
                    return -1;
                m[2]--;
                m[3]++;
            } else if (i == 4) {
                if (m[3] <= 0)
                    return -1;
                m[3]--;
                m[4]++;
            } else if (i == 5) {
                if (m[4] <= 0)
                    return -1;
                m[4]--;
                m[5]++;
            }
        }
        return res;
    }
};