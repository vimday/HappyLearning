/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :stTemplate.cpp
 * @Created Time:2020-10-09 23:07:17
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
inline int read() {
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
const int logMaxN = 21;
const int maxn = 100005;
int f[maxn][logMaxN], Logn[maxn];
void initLog() {
    Logn[1] = 0;
    Logn[2] = 1;
    for (int i = 3; i < maxn; i++)
        Logn[i] = Logn[i >> 1] + 1;
}
int main(int argc, char const *argv[]) {
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        f[i][0] = read();
    initLog();
    for (int j = 1; j <= logMaxN; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    for (int i = 1; i <= m; i++) {
        int x = read(), y = read();
        int s = Logn[y - x + 1];
        printf("%d\n", max(f[x][s], f[y - (1 << s) + 1][s]));
    }
    return 0;
}
