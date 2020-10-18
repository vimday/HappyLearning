/*
 * @Author      :vimday
 * @Desc        : 树状数组的区间修改查询
 * @Url         :
 * @File Name   :treeArrayModel.cpp
 * @Created Time:2020-10-12 20:16:28
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
inline void in() {}
template <typename T, typename... Tail>
inline void in(T &x, Tail &... y) {
    x = 0;
    T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
    in(y...);
}
#define iout(x) printf("%d\n", x)
#define lout(x) printf("%lld\n", x)
typedef long long ll;
const int maxn = 1000006;
ll df[maxn], idf[maxn], n, t;
inline int lowbit(int x) { return x & (-x); }

// 将差分数组的第idx位增加val位
void _add(int idx, ll val) {
    ll val2 = idx * val;
    while (idx <= n) {
        df[idx] += val;
        idf[idx] += val2;
        idx += lowbit(idx);
    }
}
// 区间修改,增加val
void add(int l, int r, ll val) {
    // 将区间加差分为两个前缀和
    // 在开始位置的差分增加 val(相当于把原始数组从开始位置到最后都增加 val) 结束位置的差分减去val(后面多加的减掉)
    _add(l, val);
    _add(r + 1, -val);
}
void init_data() {
    memset(df + 1, 0, n << 3);
    memset(idf + 1, 0, n << 3);
    ll pre = 0;
    for (ll i = 1; i <= n; i++) {
        //cin >> t;  // _add(i, t - pre);
        in(t);
        //trick O(n)建树
        ll d = t - pre;
        //cout << d << " \n"[i == n];
        df[i] += d;
        idf[i] += i * d;
        ll j = i + lowbit(i);
        if (j <= n) {
            df[j] += df[i];
            idf[j] += idf[i];
        }
        pre = t;
    }
}
// 查询差分数组的前缀和
// 相当于查找 a[i] 的值 querry(df,idx);
ll _getDiffPreSum(int idx) {
    ll res = 0;
    while (idx) {
        res += df[idx];
        idx -= lowbit(idx);
    }
    return res;
}
// 查询 i*d[i] 数组的前缀和
ll _getMulPreSum(int idx) {
    ll res = 0;
    while (idx) {
        res += idf[idx];
        idx -= lowbit(idx);
    }
    return res;
}
// 单点查询idx的值
ll querry(int idx) {
    return _getDiffPreSum(idx);
}
ll getPreSum(int idx) {
    return (1ll + idx) * _getDiffPreSum(idx) - _getMulPreSum(idx);
}
ll querry(int l, int r) {
    // q(l,r)=ps[r]-ps[l-1];
    return getPreSum(r) - getPreSum(l - 1);
}

int main(int argc, char const *argv[]) {
    debug();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, op;
    //cin >> n >> q;
    scanf("%lld%d", &n, &q);
    init_data();
    ll l, r, val;
    while (q--) {
        //cin >> op;
        scanf("%d", &op);
        if (op == 1) {
            //cin >> l >> r >> val;
            //in(l), in(r), in(val);
            in(l, r, val);
            add(l, r, val);
        } else {
            //cin >> l >> r;
            //in(l), in(r);
            in(l, r);
            //cout << querry(l, r) << endl;
            lout(querry(l, r));
        }
    }
    return 0;
}
// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #define Maxn 1000010
// using namespace std;
// typedef long long ll;
// ll n, m;
// ll a[Maxn], tree1[Maxn], tree2[Maxn];
// namespace DY {
// ll lowbit(ll x) {
//     return x & (~x + 1);
// }
// void Updata(ll x, ll k) {
//     for (ll i = x; i <= n; i += lowbit(i)) {
//         tree1[i] += k;
//         tree2[i] += (k * x);
//     }
// }
// ll Sum(ll x) {
//     ll sum = 0;
//     for (ll i = x; i > 0; i -= lowbit(i)) {
//         sum += (x + 1) * tree1[i] - tree2[i];
//     }
//     return sum;
// }
// void main() {
//     scanf("%lld%lld", &n, &m);
//     for (ll i = 1; i <= n; i++)
//         scanf("%lld", &a[i]);
//     for (ll i = 1; i <= n; i++) {
//         Updata(i, a[i] - a[i - 1]);
//     }
//     while (m--) {
//         ll flag;
//         scanf("%lld", &flag);
//         if (flag == 1) {
//             ll u, v, num;
//             scanf("%lld%lld%lld", &u, &v, &num);
//             Updata(u, num);
//             Updata(v + 1, -num);
//         } else {
//             ll u, v;
//             scanf("%lld%lld", &u, &v);
//             printf("%lld\n", Sum(v) - Sum(u - 1));
//         }
//     }
// }
// };  // namespace DY
// int main() {
//     DY::main();
//     return 0;
// }