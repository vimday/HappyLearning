/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :CCC.cpp
 * @Created Time:2020-09-05 17:06:44
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
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        unordered_map<int, vector<int>> mg;

        int si = 1000, sj = 1000, ei = si, ej = sj;
        for (int i = 0; i < n; i++) {
            int op, f;
            cin >> op >> f;
            int t = ei * 2000 + ej;
            if (f) {
                if (op == 0) {
                    ei--;
                    mg[t].push_back(ei * 2000 + ej);
                } else if (op == 1) {
                    ei++;
                    mg[t].push_back(ei * 2000 + ej);
                } else if (op = 2) {
                    ej--;
                    mg[t].push_back(ei * 2000 + ej);
                } else {
                    ej++;
                    mg[t].push_back(ei * 2000 + ej);
                }
            }
        }
        queue<int> q;
        q.push(si * 2000 + sj);
        unordered_set<int> ms;
        ms.insert(si * 2000 + sj);
        int res = 0;
        bool f = false;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                int t = q.front();
                q.pop();
                int nx = t / 2000, ny = t % 2000;
                if (nx == ei && ny == ej) {
                    f = true;
                    break;
                }
                for (auto nb : mg[t]) {
                    if (ms.count(nb) == 0) {
                        q.push(nb);
                        ms.insert(nb);
                    }
                }
            }
            if (f)
                break;
            res++;
        }
        cout << res << endl;
    }
    return 0;
}
