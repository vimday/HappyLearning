/*
 * @Author      :vimday
 * @Desc        :
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
typedef long long ll;
const int maxn = 1000006;
ll arr[maxn];
int n;
inline int lowbit(int x) { return x & (-x); }
void add(int idx, int val) {
    while (idx <= n) {
        arr[idx] += val;
        idx += lowbit(idx);
    }
}
void init_data() {
    memset(arr + 1, 0, n << 2);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        arr[i] += t;
        //add(i, t);
        //trick
        int j = i + lowbit(i);
        if (j <= n)
            arr[j] += arr[i];
    }
}
ll querry(int idx) {
    ll res = 0;
    while (idx) {
        res += arr[idx];
        idx -= lowbit(idx);
    }
    return res;
}
ll querry(int l, int r) {
    return querry(r) - querry(l - 1);
}

int main(int argc, char const *argv[]) {
    int q;
    cin >> n >> q;
    init_data();
    int op, l, r;
    while (q--) {
        cin >> op >> l >> r;
        if (op == 1)
            add(l, r);
        else
            cout << querry(l, r) << endl;
    }
    return 0;
}
