/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-09-26 19:00:47
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
    unordered_map<string, int> pm;
    unordered_map<string, set<string>> mw, zw, mz;
    map<int, set<string>> mc;
    string ls;
    bool f = false;
    while (getline(cin, ls)) {
        istringstream is(ls);
        vector<string> vs;
        int n = ls.size();
        for (int i = 0; i < n; i++) {
            int b = i;
            while (i < n && ls[i] != ',') i++;
            vs.push_back(ls.substr(b, i - b));
        }
        int sz = vs.size();
        if (sz == 2) {
            pm[vs[0]] = stoi(vs[1]);
        } else if (sz == 3) {
            mw[vs[0]].insert(vs[2]);
            zw[vs[1]].insert(vs[2]);
            mz[vs[0]].insert(vs[1]);
        }
    }
    for (auto p : mw) {
        string m = p.first;
        auto ws = p.second;
        int cnt = 0;
        for (auto s : ws)
            cnt += pm[s];
        mc[cnt].insert(m);
    }
    // for (auto p : zw) {
    //     string z = p.first;
    //     atuo ws = p.second;
    //     int cnt = 0;
    //     for (auto s : ws)
    //         cnt += pm[s];
    //     zc[cnt].insert(z);
    // }
    for (auto it = mc.rbegin(); it != mc.rend(); it++) {
        auto p = *it;
        auto ms = p.second;
        string cs = to_string(p.first);
        for (auto s : ms) {
            cout << s << "<" << cs << ">" << endl;
            auto zs = mz[s];
            map<int, set<string>> zc;
            for (string zy : zs) {
                int cnt = 0;
                for (string ws : zw[zy])
                    cnt += pm[ws];
                zc[cnt].insert(zy);
            }
            for (auto zit = zc.rbegin(); zit != zc.rend(); zit++) {
                auto zp = *zit;
                string zcs = to_string(zp.first);
                auto zzs = zp.second;
                for (string zys : zzs) {
                    cout << "-" << zys << "<" << zcs << ">" << endl;
                    auto waibaos = zw[zys];
                    map<int, set<string>> wc;
                    for (string wb : waibaos) {
                        wc[pm[wb]].insert(wb);
                    }
                    for (auto wit = wc.rbegin(); wit != wc.rend(); wit++) {
                        auto wp = *wit;
                        auto ts = wp.second;
                        for (string sss : ts)
                            cout << "--" << sss << "<" << to_string(wp.first) << ">" << endl;
                    }
                }
            }
        }
    }
    return 0;
}
