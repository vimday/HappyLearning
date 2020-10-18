/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-09-21 20:23:51
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
const double eps = 1e-5;
int main(int argc, char const *argv[]) {
    double n, r;
    int m;
    cin >> n >> m >> r;
    double cx = 0, cy = 0, cr = r;

    for (int i = 0; i < m; i++) {
        while (cr > eps) {
            if (abs(cy) <= eps && abs(n - cx) > eps) {
                // 向右走
                double ad = abs(min(cr, abs(n - cx)));
                cx += ad;
                cr -= ad;
            } else if (abs(n - cx) <= eps && abs(n - cy) > eps) {
                //向上走
                double ad = min(cr, abs(n - cy));
                cy += ad;
                cr -= ad;
            } else if (abs(n - cy) <= eps && abs(cx) > eps) {
                //向左走
                double ad = min(cr, abs(cx));
                cx -= ad;
                cr -= ad;
            } else {
                //向下走
                double ad = min(cr, cy);
                cy -= ad;
                cr -= ad;
            }
        }
        cr = r;
        printf("%.2f %.2f\n", cx, cy);
    }
    return 0;
}
