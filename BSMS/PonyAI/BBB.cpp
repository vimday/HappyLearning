/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-09-20 15:49:39
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
int n;
int p[100005];
bool f[100005];
vector<vector<int>> sons;
int main(int argc, char const *argv[]) {
    cin >> n;
    sons.clear();
    sons.resize(n + 1);
    int root = -1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] == -1)
            root = i;
        cin >> f[i];
        sons[i].push_back(i);
    }
    f[root] = 1;
    for (int i = 1; i <= n; i++) {
        if (f[i]) {
            int pi = p[i];
            while (pi != -1 && f[pi] == false) {
                f[pi] = true;
                pi = p[pi];
            }
        }
    }
    vector<int> res;
    for (int i = 1; i <= n; i++)
        if (!f[i])
            res.push_back(i);
    int sz = res.size();
    if (sz == 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < sz; i++)
        cout << res[i] << " \n"[i == sz - 1];
    return 0;
}
