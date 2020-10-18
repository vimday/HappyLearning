/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :D.cpp
 * @Created Time:2020-09-19 17:05:03
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
     * 
     * @param n int整型 视频长度
     * @param cuePoints int整型vector cue points列表
     * @return int整型
     */
    int minCost(int n, vector<int>& cuePoints) {
        // write code here
        // 贪心 尽量均分
        int sz = cuePoints.size();
        if (sz == 0)
            return 0;
        int ret = 0;
        sort(cuePoints.begin(), cuePoints.end());
        queue<array<int, 2>> q;
        vector<bool> me(sz);
        q.push({0, n});
        int rem = sz;
        while (q.size() && rem > 0) {
            auto p = q.front();
            q.pop();
            int b = p[0], e = p[1];
            int tt = b + (e - b >> 1);
            int t = -1;
            for (int i = 0; i < sz; i++)
                if (!me[i] && cuePoints[i] >= b && cuePoints[i] <= e && (t == -1 || abs(cuePoints[i] - tt) < abs(cuePoints[t] - tt))) {
                    t = i;
                }
            if (t != -1) {
                int d = cuePoints[t];
                ret += e - b;
                me[t] = true;
                rem--;
                q.push({b, d});
                q.push({d, e});
            }
        }
        return ret;
    }
};

// import java.util.*;

// public class Solution {
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * @param n int整型 视频长度
//      * @param cuePoints int整型一维数组 cue points列表
//      * @return int整型
//      */
//     private static int[][] mem;
//     public int minCost (int n, int[] cuePoints) {
//         // write code here
//         mem = new int[cuePoints.length][cuePoints.length];
//         Arrays.sort(cuePoints);
//         for (int i = 0; i < mem.length; i++) {
//             Arrays.fill(mem[i],-1);
//         }
//         return dfs(cuePoints,0,cuePoints.length -1,0,n);
//     }
//     private int dfs(int[] cuePoints, int l,int r, int small,int large) {
//         if(l>r)
//             return 0;
//         if(mem[l][r] != -1) {
//             return mem[l][r];
//         }
//         int nowCost = large - small;
//         int min = Integer.MAX_VALUE;
//         for(int index = l;index <= r;index++) {
//             min = Math.min(min,dfs(cuePoints,l,index-1,small,cuePoints[index]) + dfs(cuePoints,index+1,r,cuePoints[index],large));
//         }
//         mem[l][r] = nowCost+min;
//         return mem[l][r];
//     }

//     public static void main(String[] args) {
//         Solution s = new Solution();
//         System.out.println(s.minCost(9,new int[]{5,6,1,4,2}));;
//     }
// }