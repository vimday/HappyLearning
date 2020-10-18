/*
 * @Author      :vimday
 * @Desc        :线段树模板
 * @Url         :https://www.luogu.com.cn/problem/P3372
 * @File Name   :model.cpp
 * @Created Time:2020-10-13 23:03:42
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
#define lson (ind << 1)
#define rson (ind << 1 | 1)
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
const int MaxN = 400005;
typedef long long ll;
struct ST {
    int l, r;
    ll lazy, val, cnt;
} st[MaxN];

// 获取不下于cap的最大2的幂
inline int getLN(int cap) {
    int n = cap - 1;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}
int n, m, LN;
void build_Tree() {
    LN = getLN(n);
    // 赋值最后一层 st[LN] - st[LN+n-1] 代表原始节点值的arr[1] - arr[n]
    for (int i = 0; i < n; ++i) {
        cin >> st[i + LN].val;
        st[i + LN].cnt = 1;
        st[i + LN].l = st[i + LN].r = i + 1;
    }
    // 填充最后一层的空节点
    for (int i = LN + n; i < 2 * LN; ++i)
        st[i].l = st[i].r = i - LN + 1;  // 无用节点(st[LN+n] - st[2*LN-1])代表的值从[n+1,n+1]-[LN,LN]
    // 自底向上建树（堆)
    for (int ind = LN - 1; ind >= 1; --ind) {
        st[ind].l = st[lson].l;
        st[ind].r = st[rson].r;
        st[ind].cnt = st[lson].cnt + st[rson].cnt;
        st[ind].val = st[lson].val + st[rson].val;
    }
}
void pushDown(int ind) {
    st[lson].lazy += st[ind].lazy;
    st[rson].lazy += st[ind].lazy;
    // 清空 lazy 前要把其信息存入 val
    st[ind].val += st[ind].cnt * st[ind].lazy;
    st[ind].lazy = 0;
}
ll _getSum(int ind) {
    return st[ind].val + st[ind].lazy * st[ind].cnt;
}
void rangeAdd(int l, int r, int val, int ind = 1) {
    if (l == st[ind].l && r == st[ind].r) {
        st[ind].lazy += val;
        // lazy 与 val 只更新一个即可
        // st[ind].val += st[ind].cnt * val;
        return;
    }
    //if (st[ind].cnt > 1)
    pushDown(ind);
    if (st[lson].r >= r)
        rangeAdd(l, r, val, lson);
    else if (st[rson].l <= l)
        rangeAdd(l, r, val, rson);
    else {
        rangeAdd(l, st[lson].r, val, lson);
        rangeAdd(st[rson].l, r, val, rson);
    }
    st[ind].val = _getSum(lson) + _getSum(rson);
}
ll querry(int l, int r, int ind = 1) {
    if (st[ind].l == l && st[ind].r == r)
        return _getSum(ind);
    pushDown(ind);
    if (st[lson].r >= r)
        return querry(l, r, lson);
    else if (st[rson].l <= l)
        return querry(l, r, rson);
    return querry(l, st[lson].r, lson) + querry(st[rson].l, r, rson);
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    build_Tree();
    int op, l, r, val;
    while (m--) {
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> val;
            rangeAdd(l, r, val);
        } else {
            cout << querry(l, r) << endl;
        }
    }
    return 0;
}