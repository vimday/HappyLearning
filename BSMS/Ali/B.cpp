/*
 * @Author      :vimday
 * @Desc        :ali b
 * @Url         :
 * @File Name   :B.cpp
 * @Created Time:2020-03-30 18:56:13
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}

// 思路：单调栈 + 动态规划，时间复杂度O(n)

// 在序列x中，长度为1的子序列有n个，长度为2的子序列有n-1个...长度为n-1的子序列有2个，长度为n的子序列有1个，总的序列数：c = n+(n-1)+...+2+1 = n*(n+1)/2 个，每个出现的概率相同;

// 考虑以x[i]为结尾的子序列，这些子序列中有两种情况，一种是最大值为x[i]，两一种是最大值不为x[i]；最大值不为x[i]的相当于x[i]没有加入，可以借助之前的状态求解；最大值为x[i]的情况只需记录有多少个。

// 用单调栈的思路，从大到小存放出现的元素，并记录值对应的index值。
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000006;
double dp[N];  //dp[i]表示前i个数中的最大值期望
int main() {
    int n, t;
    scanf("%d", &n);
    ll c = (ll)n * (n + 1) / 2;
    dp[0] = 0;  //无意义
    stack<PII> m;
    double res = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        while (!m.empty() && m.top().first <= t) {
            m.pop();
        }
        int d = m.empty() ? i + 1 : i - m.top().second;
        dp[i + 1] = 1.0 * t * d / c + dp[i + 1 - d];
        res += dp[i + 1];
        m.emplace(t, i);
    }
    printf("%.6f\n", res);
}