/*
 * @Author      :vimday
 * @Desc        :二维树状数组的区间操作
 * @Url         :https://www.cnblogs.com/dilthey/p/9366491.html
 * @File Name   :E_2d_lr.cpp
 * @Created Time:2020-10-13 18:39:38
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
typedef long long ll;
const int maxn = 2049;
const int maxm = maxn;

struct BIT_2D_LR_I {
    int n, m;
    ll C[maxn][maxm];
    int lowbit(int x) { return x & (-x); }
    void init(int n, int m)  //初始化n行m列矩阵
    {
        this->n = n;
        this->m = m;
        memset(C, 0, sizeof(C));
    }
    void add(int x, int y, ll val) {
        for (int i = x; i <= n; i += lowbit(i))
            for (int j = y; j <= m; j += lowbit(j)) C[i][j] += val;
    }
    void range_add(int x1, int y1, int x2, int y2, ll x)  //左上角为(x1,y1)右下角为(x2,y2)的矩阵全部加上x
    {
        add(x1, y1, x);
        add(x1, y2 + 1, -x);
        add(x2 + 1, y1, -x);
        add(x2 + 1, y2 + 1, x);
    }
    ll ask(int x, int y)  //查询点(x,y)的值
    {
        ll ret = 0;
        for (int i = x; i > 0; i -= lowbit(i))
            for (int j = y; j > 0; j -= lowbit(j)) ret += C[i][j];
        return ret;
    }
} BIT1;

struct BIT_2D_LR_LR {
    int n, m;
    ll C1[maxn][maxm], C2[maxn][maxm], C3[maxn][maxm], C4[maxn][maxm];
    int lowbit(int x) { return x & (-x); }
    void init(int n, int m)  //初始化n行m列矩阵
    {
        this->n = n;
        this->m = m;
        memset(C1, 0, sizeof(C1));
        memset(C2, 0, sizeof(C2));
        memset(C3, 0, sizeof(C3));
        memset(C4, 0, sizeof(C4));
    }
    void add(int x, int y, ll val) {
        for (int i = x; i <= n; i += lowbit(i)) {
            for (int j = y; j <= m; j += lowbit(j)) {
                C1[i][j] += val;
                C2[i][j] += val * x;
                C3[i][j] += val * y;
                C4[i][j] += val * x * y;
            }
        }
    }
    void range_add(int x1, int y1, int x2, int y2, ll x)  //左上角为(x1,y1)右下角为(x2,y2)的矩阵全部加上x
    {
        add(x1, y1, x);
        add(x1, y2 + 1, -x);
        add(x2 + 1, y1, -x);
        add(x2 + 1, y2 + 1, x);
    }
    ll ask(int x, int y)  //查询左上角为(1,1)右下角为(x,y)的矩阵和
    {
        ll ret = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                ret += (x + 1) * (y + 1) * C1[i][j];
                ret -= (y + 1) * C2[i][j] + (x + 1) * C3[i][j];
                ret += C4[i][j];
            }
        }
        return ret;
    }
    ll range_ask(int x1, int y1, int x2, int y2)  //查询左上角为(x1,y1)右下角为(x2,y2)的矩阵和
    {
        return ask(x2, y2) - ask(x1 - 1, y2) - ask(x2, y1 - 1) + ask(x1 - 1, y1 - 1);
    }
} BIT2;
int main(int argc, char const *argv[]) {
    int n, m, op, x, y, r, c, val;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    BIT2.init(n, m);
    while (cin >> op) {
        if (op == 1) {
            cin >> x >> y >> r >> c >> val;
            BIT2.range_add(x, y, r, c, val);
        } else {
            cin >> x >> y >> r >> c;
            cout << BIT2.range_ask(x, y, r, c) << endl;
        }
    }
    return 0;
}