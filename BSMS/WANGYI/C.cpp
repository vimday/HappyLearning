/*
 * @Author      :vimday
 * @Desc        :wangyi C
 * @Url         :
 * @File Name   :C.cpp
 * @Created Time:2020-04-07 20:06:09
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

struct DSU {
    std::vector<int> data;

    void init(int n) { data.assign(n, -1); }

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

    bool same(int x, int y) { return root(x) == root(y); }

    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }

    int size(int x) { return -data[root(x)]; }
};

int main(int argc, char const *argv[]) {
    int n, m, f;
    cin >> n >> m >> f;

    DSU mydsu;
    mydsu.init(n);

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        int pre;
        cin >> pre;
        for (int j = 1; j < q; j++) {
            int t;
            cin >> t;
            mydsu.unionSet(pre, t);
        }
    }
    cout << mydsu.size(mydsu.root(f)) << endl;
    return 0;
}
