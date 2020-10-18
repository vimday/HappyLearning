/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-09-06 19:34:34
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
struct myDSU {
    vector<int> data;
    void init(int n) {
        data.assign(n, -1);
    }
    bool unionSet(int y, int x) {
        x = root(x);

        y = root(y);

        if (x != y) {
            if (data[y] < data[x]) swap(x, y);

            data[x] += data[y];

            data[y] = x;
        }

        return x != y;
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};
;
int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    myDSU dsu;
    dsu.init(n);
    for (int i = 0; i < m; i++) {
        int sz;
        cin >> sz;
        int pre = -1;
        for (int j = 0; j < sz; j++) {
            if (j == 0) {
                cin >> pre;
            } else {
                int t;
                cin >> t;
                dsu.unionSet(pre, t);
            }
        }
    }
    cout << dsu.size(0) << endl;
    return 0;
}