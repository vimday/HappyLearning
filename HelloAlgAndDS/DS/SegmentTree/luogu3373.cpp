/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :luogu3373.cpp
 * @Created Time:2020-10-15 23:36:28
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>

using namespace std;

#define iout(x) printf("%d\n", x)
#define lout(x) printf("%lld\n", x)
#define lowbit(x) ((x) & (-(x)))
#define ls (ind << 1)
#define rs (ind << 1 | 1)
#define mid ((l + r) >> 1)
#define lson l, mid, ls
#define rson mid + 1, r, rs

typedef long long ll;

inline void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}

const int MaxN = 100005;
ll arr[MaxN], st[MaxN << 2], addLazy[MaxN << 2], mulLazy[MaxN << 2];
int n, m, mod;
inline ll _getSum(int l, int r, int ind) {
    // 优先级 先乘后加 方便维护
    return (st[ind] * mulLazy[ind] % mod + addLazy[ind] * (r - l + 1)) % mod;
}

void _build(int l = 1, int r = n, int ind = 1) {
    addLazy[ind] = 0;
    mulLazy[ind] = 1;
    if (l == r) {
        st[ind] = arr[l] % mod;
        return;
    }
    _build(lson);
    _build(rson);
    st[ind] = (st[ls] + st[rs]) % mod;
}
void init_ST() {
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    _build();
}

void _pushDown(int l, int r, int ind) {
    mulLazy[ls] = (mulLazy[ls] * mulLazy[ind]) % mod;
    mulLazy[rs] = (mulLazy[rs] * mulLazy[ind]) % mod;
    addLazy[ls] = (addLazy[ls] * mulLazy[ind] + addLazy[ind]) % mod;
    addLazy[rs] = (addLazy[rs] * mulLazy[ind] + addLazy[ind]) % mod;
    // 严格定义只传递 lazy 防止无用计算
    st[ind] = _getSum(l, r, ind);
    mulLazy[ind] = 1;
    addLazy[ind] = 0;
}
void rangeAdd(int al, int ar, ll val, int l = 1, int r = n, int ind = 1) {
    if (al > r || ar < l)
        return;
    if (al <= l && r <= ar) {
        addLazy[ind] = (addLazy[ind] + val) % mod;
        return;
    }
    _pushDown(l, r, ind);
    rangeAdd(al, ar, val, lson);
    rangeAdd(al, ar, val, rson);
    st[ind] = (_getSum(lson) + _getSum(rson)) % mod;
}
void rangeMul(int ml, int mr, ll val, int l = 1, int r = n, int ind = 1) {
    if (ml > r || mr < l)
        return;
    if (ml <= l && r <= mr) {
        mulLazy[ind] = (mulLazy[ind] * val) % mod;
        addLazy[ind] = (addLazy[ind] * val) % mod;
        return;
    }
    _pushDown(l, r, ind);
    rangeMul(ml, mr, val, lson);
    rangeMul(ml, mr, val, rson);
    st[ind] = (_getSum(lson) + _getSum(rson)) % mod;
}
ll query(int ql, int qr, int l = 1, int r = n, int ind = 1) {
    if (ql > r || qr < l)
        return 0;
    if (ql <= l && qr >= r)
        return _getSum(l, r, ind);
    _pushDown(l, r, ind);
    return (query(ql, qr, lson) + query(ql, qr, rson)) % mod;
}
int main(int argc, char const *argv[]) {
    debug();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> mod;
    init_ST();
    int op, l, r;
    ll val;
    for (int i = 0; i < m; ++i) {
        cin >> op >> l >> r;
        if (op == 3) {
            lout(query(l, r));
        } else {
            cin >> val;
            if (op == 1)
                rangeMul(l, r, val);
            else
                rangeAdd(l, r, val);
        }
    }
    return 0;
}
//我只是在这里做个测试
//这位大佬卡常太神了
//我想看看是不是因为评测机性能波动导致的
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// using namespace std;
// const int mod = 571373, N = 1e5 + 5000;
// int tag1[N << 2], tag2[N << 2], a[N << 2], w[N];
// int n, m;
// void build(int rot, int lt, int rt) {
//     tag1[rot] = 1;
//     if (lt == rt) {
//         a[rot] = w[lt];
//         return;
//     }
//     int mid = (lt + rt) >> 1;
//     build(rot << 1, lt, mid), build(rot << 1 | 1, mid + 1, rt);
//     a[rot] = (a[rot << 1] + a[rot << 1 | 1]) % mod;
// }
// void upd1(int rot, int w) {
//     a[rot] = 1ll * a[rot] * w % mod, tag1[rot] = 1ll * tag1[rot] * w % mod, tag2[rot] = 1ll * tag2[rot] * w % mod;
// }
// void upd2(int rot, int len, int w) {
//     a[rot] = (a[rot] + 1ll * len * w) % mod, tag2[rot] = (tag2[rot] + w) % mod;
// }
// void pushdown(int rot, int lt, int rt) {
//     if (tag1[rot] != 1) {
//         int t = tag1[rot];
//         tag1[rot] = 1;
//         upd1(rot << 1, t), upd1(rot << 1 | 1, t);
//     }
//     if (tag2[rot] != 0) {
//         int t = tag2[rot];
//         tag2[rot] = 0;
//         int mid = (lt + rt) >> 1;
//         upd2(rot << 1, mid - lt + 1, t), upd2(rot << 1 | 1, rt - mid, t);
//     }
// }
// void update1(int rot, int lt, int rt, int lq, int rq, int w) {
//     if (lt >= lq && rt <= rq) {
//         upd1(rot, w);
//         return;
//     }
//     int mid = (lt + rt) >> 1;
//     pushdown(rot, lt, rt);
//     if (lq <= mid) update1(rot << 1, lt, mid, lq, rq, w);
//     if (rq > mid) update1(rot << 1 | 1, mid + 1, rt, lq, rq, w);
//     a[rot] = (a[rot << 1] + a[rot << 1 | 1]) % mod;
// }
// void update2(int rot, int lt, int rt, int lq, int rq, int w) {
//     if (lt >= lq && rt <= rq) {
//         upd2(rot, rt - lt + 1, w);
//         return;
//     }
//     int mid = (lt + rt) >> 1;
//     pushdown(rot, lt, rt);
//     if (lq <= mid) update2(rot << 1, lt, mid, lq, rq, w);
//     if (rq > mid) update2(rot << 1 | 1, mid + 1, rt, lq, rq, w);
//     a[rot] = (a[rot << 1] + a[rot << 1 | 1]) % mod;
// }
// int query(int rot, int lt, int rt, int lq, int rq) {
//     if (lt >= lq && rt <= rq) return a[rot];
//     int mid = (lt + rt) >> 1;
//     pushdown(rot, lt, rt);
//     if (rq <= mid) return query(rot << 1, lt, mid, lq, rq);
//     if (lq > mid) return query(rot << 1 | 1, mid + 1, rt, lq, rq);
//     return (query(rot << 1, lt, mid, lq, mid) + query(rot << 1 | 1, mid + 1, rt, mid + 1, rq)) % mod;
// }
// int getin() {
//     int x = 0;
//     char ch = getchar();
//     while (ch < '0' || ch > '9') ch = getchar();
//     while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
//     return x;
// }
// int main() {
//     n = getin(), m = getin();
//     w[1] = getin();
//     for (int i = 1; i <= n; i++) w[i] = getin();
//     build(1, 1, n);
//     for (int i = 1, opt, l, r; i <= m; i++) {
//         opt = getin(), l = getin(), r = getin();
//         switch (opt) {
//         case 1:
//             opt = getin(), update1(1, 1, n, l, r, opt);
//             break;
//         case 2:
//             opt = getin(), update2(1, 1, n, l, r, opt);
//             break;
//         case 3:
//             printf("%d\n", query(1, 1, n, l, r));
//             break;
//         }
//     }
// }