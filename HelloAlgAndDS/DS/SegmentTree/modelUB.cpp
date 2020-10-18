/*
 * @Author      :vimday
 * @Desc        :线段树模板 递归建树
 * @Url         :
 * @File Name   :modelUB.cpp
 * @Created Time:2020-10-14 14:54:19
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
#define lson (ind << 1)
#define rson (ind << 1 | 1)
typedef long long ll;

const int MAXN = 400005;
ll st[MAXN], lazy[MAXN], arr[100005];
int n, m;

void build_Tree(int l = 1, int r = n, int ind = 1) {
    if (l == r) {
        st[ind] = arr[l];
        //cin >> st[ind];
        //cout << "--" << ind << "---" << st[ind] << "---" << endl;
    } else {
        int mi = l + r >> 1;
        build_Tree(l, mi, lson);
        build_Tree(mi + 1, r, rson);
        st[ind] = st[lson] + st[rson];
    }
}
void pushDown(int l, int mi, int r, int ind) {
    lazy[lson] += lazy[ind];
    lazy[rson] += lazy[ind];
    st[lson] += (mi - l + 1) * lazy[ind];
    st[rson] += (r - mi) * lazy[ind];
    lazy[ind] = 0;
}
void rangeAdd(int l, int r, ll val, int cl = 1, int cr = n, int ind = 1) {
    if (cl > r || cr < l)
        return;
    else if (l <= cl && r >= cr) {
        st[ind] += (cr - cl + 1) * val;
        if (cr > cl)
            lazy[ind] += val;
    } else {
        int mi = cl + cr >> 1;
        pushDown(cl, mi, cr, ind);
        rangeAdd(l, r, val, cl, mi, lson);
        rangeAdd(l, r, val, mi + 1, cr, rson);
        st[ind] = st[lson] + st[rson];
    }
}
ll querry(int l, int r, int cl = 1, int cr = n, int ind = 1) {
    if (l > cr || r < cl)
        return 0;
    if (l <= cl && r >= cr)
        return st[ind];
    int mi = cl + cr >> 1;
    pushDown(cl, mi, cr, ind);
    return querry(l, r, cl, mi, lson) + querry(l, r, mi + 1, cr, rson);
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build_Tree();
    int op, l, r;
    ll val;
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
// #include <cstdio>
// int n, m, a, b, s;
// long long tree[1000005], lazy[1000005], k;
// long long query(int id, int ll, int rr, int l, int r) {
//     if (lazy[id]) {
//         lazy[id * 2] = (lazy[2 * id] + lazy[id]);
//         lazy[id * 2 + 1] = (lazy[2 * id + 1] + lazy[id]);
//         tree[id] = (tree[id] + lazy[id] * (rr - ll + 1));
//         lazy[id] = 0;
//     }
//     if (ll == l && rr == r) return tree[id];
//     int mid = (ll + rr) >> 1;
//     if (mid >= r) return query(id * 2, ll, mid, l, r);
//     if (mid < l) return query(id * 2 + 1, mid + 1, rr, l, r);
//     long long ans = 0;
//     ans += query(id * 2, ll, mid, l, mid);
//     ans += query(id * 2 + 1, mid + 1, rr, mid + 1, r);
//     return ans;
// }
// int add(int id, int ll, int rr, int l, int r, long long x) {
//     if (ll == l && rr == r) return lazy[id] = (lazy[id] + x);
//     tree[id] += (r - l + 1) * x;
//     int mid = (ll + rr) >> 1;
//     if (mid >= r) return add(id * 2, ll, mid, l, r, x);
//     if (mid < l) return add(id * 2 + 1, mid + 1, rr, l, r, x);
//     add(id * 2, ll, mid, l, mid, x);
//     add(id * 2 + 1, mid + 1, rr, mid + 1, r, x);
//     return 0;
// }
// int main() {
//     scanf("%d%d", &n, &m);
//     for (int i = 1; i <= n; i++) {
//         scanf("%lld", &k);
//         add(1, 1, n, i, i, k);
//     }
//     while (m--) {
//         scanf("%d%d%d", &s, &a, &b);
//         if (s == 1) {
//             scanf("%lld", &k);
//             add(1, 1, n, a, b, k);
//         } else
//             printf("%lld\n", query(1, 1, n, a, b));
//     }
//     return 0;
// }