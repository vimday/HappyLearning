
/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :C_robot-path-decoding.cpp
 * @Created Time:2020-10-09 15:47:53
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
typedef long long ll;
const ll mm = 1e9;
//const ll my = 1e9;
void printAns(int caseNum, vector<ll> ans) {
    printf("Case #%d: %ld %ld\n", caseNum, ans[0], ans[1]);
}
vector<ll> getNext(const char &c) {
    if (c == 'N')
        return {0, -1};
    if (c == 'S')
        return {0, 1};
    if (c == 'E')
        return {1, 0};
    return {-1, 0};
}
void moveNext(vector<ll> &res, const vector<ll> mv) {
    res[0] += mv[0];
    res[1] += mv[1];
    while (res[0] < 1)
        res[0] += mm;
    while (res[0] > mm)
        res[0] -= mm;
    while (res[1] < 1)
        res[1] += mm;
    while (res[1] > mm)
        res[1] -= mm;
}
void addMove(vector<ll> &res, const vector<ll> mv) {
    res[0] += mv[0];
    res[1] += mv[1];
}
vector<ll> solve() {
    vector<ll> res(2, 1);
    string s;
    cin >> s;
    int n = s.size();
    stack<int> skcnt;
    stack<vector<ll>> sknxt;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c > '1' && c <= '9')
            skcnt.push(c - '0');
        else if (c == '(') {
            sknxt.push({0, 0});
        } else if (c == ')') {
            auto nxt = sknxt.top();
            sknxt.pop();
            int cnt = skcnt.top();
            skcnt.pop();
            nxt[0] *= cnt;
            nxt[0] %= mm;
            nxt[1] *= cnt;
            nxt[1] %= mm;
            if (sknxt.size()) {
                addMove(sknxt.top(), nxt);
            } else {
                sknxt.push(nxt);
            }
        } else if (sknxt.size()) {
            addMove(sknxt.top(), getNext(c));
        } else {
            moveNext(res, getNext(c));
        }
    }
    while (sknxt.size()) {
        moveNext(res, sknxt.top());
        sknxt.pop();
    }
    return res;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T;)
        printAns(++i, solve());
    return 0;
}
