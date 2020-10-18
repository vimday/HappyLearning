/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :aaaaaaaaaa.cpp
 * @Created Time:2020-08-09 10:08:14
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
    int n;
    vector<int> ft, sd;
    vector<vector<int>> g;
    long long getSecondDiameter(vector<vector<int>> &edge) {
        // write your code here
        n = edge.size() + 1;
        g.resize(n);
        ft.resize(n);
        sd.resize(n);
        for (vector<int> &v : edge) {
            g[v[0]].push_back(v[1]);
            g[v[0]].push_back(v[2]);
            g[v[1]].push_back(v[0]);
            g[v[1]].push_back(v[2]);
        }
    }
};