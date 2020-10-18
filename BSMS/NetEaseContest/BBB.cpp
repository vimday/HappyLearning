/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-09-05 15:46:54
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
int w, h, p, q;
int si, sj, is, js;
vector<string> g(105), me(105), man(105);
bool check(int bi, int bj) {
    return (bi >= w && is >= 0) || (bj >= h && js >= 0) || (bi + p <= 0 && is <= 0) || (bj + q <= 0 && js <= 0);
}
bool NotInMan(int i, int j) {
    return (i < si) || (j < sj) || (i >= si + p) || (j >= sj + q);
}
int get(int bi, int bj) {
    int res = 0;
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++) {
            int r = bi + i, c = bj + j;
            if (r >= 0 && r < w && c >= 0 && c < h && g[r][c] != man[i][j]) {
                g[r][c] = man[i][j];
                res++;
            }
        }
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++) {
            if (NotInMan(i, j) && g[i][j] != me[i][j]) {
                g[i][j] = me[i][j];
                res++;
            }
        }
    return res;
}
int solve() {
    int res = 0;
    if (check(si, sj))
        return res;
    res += get(si, sj);
    while (!check(si, sj)) {
        si += is;
        sj += js;
        res += get(si, sj);
    }
    return res;
}
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;

    while (T--) {
        cin >> w >> h;
        //g.clear();me.clear();
        g.resize(h);
        me.resize(h);
        for (int i = 0; i < h; i++)
            cin >> g[i];
        me = g;
        cin >> p >> q;
        man.resize(q);
        for (int i = 0; i < q; i++)
            cin >> man[i];

        cin >> si >> sj >> is >> js;
        si--;
        sj--;
        cout << solve() << endl;
    }

    return 0;
}
}
