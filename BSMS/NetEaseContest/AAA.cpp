/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-09-05 15:00:48
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
int N, M;
vector<int> prices;
vector<stack<int>> vs;
int get(int idx) {
    if (vs[idx].size() == 0)
        return prices[idx];
    int ret = vs[idx].top();
    vs[idx].pop();
    return ret;
}
int main(int argc, char const *argv[]) {
    cin >> N >> M;
    prices.resize(N + 1);
    vs.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> prices[i];
    for (int i = 0; i < M; i++) {
        int t;
        cin >> t;
        int l = 0, r = 0, pl = 0, pr = 0;
        while (t--) {
            string s;
            getline(cin, s);
            //cin >> s;

            int sz = s.size();
            if (s.substr(0, 9) == "left take") {
                int idx = stoi(s.substr(10));
                pl = get(idx);
                l += pl;
            } else if (sz > 10 && s.substr(0, 10) == "right take") {
                int idx = stoi(s.substr(11));
                pr = get(idx);
                r += pr;
            } else if (sz > 11 && s.substr(0, 11) == "left return") {
                int idx = stoi(s.substr(12));
                vs[idx].push(pl);
                l -= pl;
                pl = 0;
            } else if (sz > 12 && s.substr(0, 12) == "right return") {
                int idx = stoi(s.substr(13));
                vs[idx].push(pr);
                r -= pr;
                pr = 0;
            }
        }
        cout << l + r << endl;
    }
    return 0;
}
