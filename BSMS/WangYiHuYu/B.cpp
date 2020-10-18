/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :B.cpp
 * @Created Time:2020-04-11 19:27:30
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
// const static int MAXN = 10000 + 10;
// int fa[MAXN], ds[MAXN], rk[MAXN];
// int S[MAXN], top;
// void init(int n) {
//     for (int i = 1; i <= n; ++i) {
//         fa[i] = i, rk[i] = ds[i] = 0;
//     }

//     top = 0;
// }
// int dis(int x) {
//     int r(0);

//     for (; x != fa[x]; x = fa[x]) r ^= ds[x];

//     return r;
// }
// int get(int x) {
//     while (x != fa[x]) x = fa[x];

//     return fa[x];
// }
// void merge(int x, int y, int d) {
//     x = get(x);

//     y = get(y);

//     if (x == y) return;

//     if (rk[x] > rk[y]) std::swap(x, y);

//     if (rk[x] == rk[y]) ++rk[y], S[++top] = -y;

//     fa[x] = y;

//     ds[x] = d;

//     S[++top] = x;
// }
// void restore(int ed) {
//     for (; top > ed; --top) {
//         if (S[top] < 0)
//             --rk[-S[top]];

//         else
//             fa[S[top]] = S[top], ds[S[top]] = 0;
//     }
// }

struct DSU {
    std::vector<int> data;
    std::vector<unordered_set<int>> mp;
    void init(int n) {
        data.assign(n, -1);
        mp = vector<unordered_set<int>>(n);
    }

    bool unionSet(int y, int x) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) std::swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    //bf
    void remove(int x) {
        int n = data.size();
        if (size(x) == 1)
            return;

        int rx = root(x);
        if (rx == x) {
            int pre = -1;
            for (int i = 1; i < n; i++) {
                if (i != x && root(i) == root(x)) {
                    if (pre == -1) {
                        pre = i;
                        data[i] = -1;
                    } else {
                        data[i] = -1;
                        unionSet(i, pre);
                    }
                }
            }
        } else {
            data[root(x)]++;
        }
        data[x] = -1;
    }
    bool same(int x, int y) { return root(x) == root(y); }

    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }

    int size(int x) { return -data[root(x)]; }
};
void solve() {
    int N, M;
    cin >> N >> M;
    DSU myDSU;
    myDSU.init(N + 1);
    while (M--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            myDSU.unionSet(x, y);
        } else if (op == 3) {
            int x;
            cin >> x;
            cout << myDSU.size(x) << endl;
        } else {
            int x;
            cin >> x;
            myDSU.remove(x);
        }
    }
}

int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
