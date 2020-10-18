/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-09-26 19:59:56
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
    string ls;
    getline(cin, ls);
    int n = ls.size();
    int sidx = 0;
    for (int i = 0; i < n; i++)
        if (ls[i] == '/') {
            sidx = i;
            break;
        }
    string ms = ls.substr(0, sidx);
    int mxc = stoi(ls.substr(sidx + 1));
    unordered_map<string, int> ind, cost;
    unordered_map<string, vector<string>> tos;
    for (int i = 0; i < sidx; i++) {
        char sign = '#';
        string ts, fs;
        int j = i, cidx = i;
        for (; j < sidx && ms[j] != ';'; j++) {
            if (ms[j] == ':') {
                if (sign == '#') {
                    ts = ms.substr(i, j - i);
                    if (ind.count(ts) == 0)
                        ind[ts] = 0;
                }
                cidx = j + 1;
                sign = ':';
            } else if (ms[j] == '[') {
                cidx = j + 1;
                sign = '[';
            } else if (ms[j] == ']' || ms[j] == ',') {
                fs = ms.substr(cidx, j - cidx);
                tos[fs].push_back(ts);
                ind[ts]++;
                cidx = j + 1;
            }
        }
        cost[ts] = stoi(ms.substr(cidx, j - cidx));
        i = j;
    }
    int res = 0, cnt = 0, curTime = 0;
    unordered_map<int, vector<string>> eds;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto p : ind) {
        int id = p.second;
        string ts = p.first;
        if (id == 0 && cnt++ < mxc) {
            int ct = cost[ts] + curTime;
            pq.push(ct);
            eds[ct].push_back(ts);
            res = max(res, ct);
        }
    }
    while (pq.size()) {
        curTime = pq.top();
        pq.pop();
        auto tss = eds[curTime];
        cnt -= tss.size();
        for (string fs : tss) {
            for (auto s : tos[fs])
                ind[s]--;
        }
        for (auto p : ind) {
            int id = p.second;
            string ts = p.first;
            if (id == 0 && cnt++ < mxc) {
                int ct = cost[ts] + curTime;
                pq.push(ct);
                eds[ct].push_back(ts);
                res = max(res, ct);
            }
        }
    }
    cout << res << endl;
    return 0;
}
