/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :model.cpp
 * @Created Time:2020-10-13 11:25:23
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
const int MAXN = 1000006;
ll t1[MAXN], t2[MAXN], n, t;

inline int lowbit(int x) { return x & (-x); }

void init_data() {
    ll pre = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t;  // _add(i, t - pre);
        //trick O(n)建树
        ll d = t - pre;
        //cout << d << " \n"[i == n];
        t1[i] += d;
        t2[i] += i * d;
        int j = i + lowbit(i);
        if (j <= n) {
            t1[j] += t1[i];
            t2[j] += t2[i];
        }
        pre = t;
    }
}
void add(int k, int v) {
    ll v1 = k * v;
    while (k <= n) {
        t1[k] += v, t2[k] += v1;
        k += lowbit(k);
    }
}

ll getsum(ll *t, int k) {
    ll ret = 0;
    while (k) {
        ret += t[k];
        k -= lowbit(k);
    }
    return ret;
}

void add1(int l, int r, int v) {
    add(l, v), add(r + 1, -v);  // 将区间加差分为两个前缀加
}

long long getsum1(int l, int r) {
    return (r + 1ll) * getsum(t1, r) - 1ll * l * getsum(t1, l - 1) -
           (getsum(t2, r) - getsum(t2, l - 1));
}

int main(int argc, char const *argv[]) {
    int q;
    cin >> n >> q;
    init_data();
    // for (int i = 1; i <= n; i++)
    //     cout << df[i] << " \n"[i == n];
    int op, l, r, val;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> val;
            add1(l, r, val);
        } else {
            cin >> l >> r;
            cout << getsum1(l, r) << endl;
        }
    }
    return 0;
}
