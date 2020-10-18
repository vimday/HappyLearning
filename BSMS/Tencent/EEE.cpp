/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :EEE.cpp
 * @Created Time:2020-09-06 19:46:58
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
int solve(string s, vector<int> ids, int n) {
    int res = 0, sz = 2 * n;
    int pred = n + 1, pblack = n + 1;

    priority_queue<int, vector<int>, greater<int>> pqr, pqb;
    if (s[n - 1] == 'R') {
        pred = ids[n - 1];
        pqr.push(ids[n - 1]);
    } else {
        pblack = ids[n - 1];
        pqb.push(ids[n - 1]);
    }
    for (int i = sz - 1; i >= 0; i--) {
        if (s[i] == 'R') {
            if (ids[i] <= pred) {
                pred = ids[i];
                pqr.push(ids[i]);
                continue;
            } else {
                vector<int> tmp;
                tmp.push_back(ids[i]);
                for (int j = i + 1; j < sz; j++) {
                    if (s[j] == 'B') {
                        swap(s[j], s[j - 1]);
                        swap(ids[j], ids[j - 1]);
                        res++;
                    } else {
                        int t = pqr.top();
                        tmp.push_back(t);
                        pqr.pop();
                        swap(s[j], s[j - 1]);
                        swap(ids[j], ids[j - 1]);
                        res++;
                        if (pqr.empty() || pqr.top() >= tmp[0])
                            break;
                    }
                }
                for (int tt : tmp)
                    pqr.push(tt);
            }
        } else {
            if (ids[i] <= pblack) {
                pblack = ids[i];
                //vr[++lr] = i;
                pqb.push(ids[i]);
                continue;
            } else {
                vector<int> tmp;
                tmp.push_back(ids[i]);
                for (int j = i + 1; j < sz; j++) {
                    if (s[j] == 'R') {
                        swap(s[j], s[j - 1]);
                        swap(ids[j], ids[j - 1]);
                        res++;
                    } else {
                        int t = pqb.top();
                        tmp.push_back(t);
                        pqb.pop();
                        swap(s[j], s[j - 1]);
                        swap(ids[j], ids[j - 1]);
                        res++;
                        if (pqb.empty() || pqb.top() >= tmp[0])
                            break;
                    }
                }
                for (int tt : tmp)
                    pqb.push(tt);
            }
        }
    }
    return res;
}
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        cout << 0 << endl;
    }
    int sz = 2 * n;
    vector<int> ids(sz);
    for (int i = 0; i < sz; i++)
        cin >> ids[i];
    // dp的话 如何转移呢
    // dp[i][2]
    int res = 0;
    int res2 = solve(s, ids, n);
    vector<int> vr(n, -1), vb(n, -1);
    int lr = -1, lb = -1;
    int pred = -1, pblack = -1;

    priority_queue<int> pqr, pqb;
    if (s[0] == 'R') {
        pred = ids[0];
        lr = 0;
        pqr.push(ids[0]);
    } else {
        pblack = ids[0];
        lb = 0;
        pqb.push(ids[0]);
    }
    for (int i = 1; i < sz; i++) {
        if (s[i] == 'R') {
            if (ids[i] >= pred) {
                pred = ids[i];
                //vr[++lr] = i;
                pqr.push(ids[i]);
                continue;
            } else {
                vector<int> tmp;
                tmp.push_back(ids[i]);
                for (int j = i - 1; j >= 0; j--) {
                    if (s[j] == 'B') {
                        swap(s[j], s[j + 1]);
                        swap(ids[j], ids[j + 1]);
                        res++;
                    } else {
                        int t = pqr.top();
                        tmp.push_back(t);
                        pqr.pop();
                        swap(s[j], s[j + 1]);
                        swap(ids[j], ids[j + 1]);
                        res++;
                        if (pqr.empty() || pqr.top() <= ids[j + 1])
                            break;
                    }
                }
                for (int tt : tmp)
                    pqr.push(tt);
            }
        } else {
            if (ids[i] >= pblack) {
                pblack = ids[i];
                //vr[++lr] = i;
                pqb.push(ids[i]);
                continue;
            } else {
                vector<int> tmp;
                tmp.push_back(ids[i]);
                for (int j = i - 1; j >= 0; j--) {
                    if (s[j] == 'R') {
                        swap(s[j], s[j + 1]);
                        swap(ids[j], ids[j + 1]);
                        res++;
                    } else {
                        int t = pqb.top();
                        tmp.push_back(t);
                        pqb.pop();
                        swap(s[j], s[j + 1]);
                        swap(ids[j], ids[j + 1]);
                        res++;
                        if (pqb.empty() || pqb.top() <= ids[j + 1])
                            break;
                    }
                }
                for (int tt : tmp)
                    pqb.push(tt);
            }
        }
    }
    cout << min(res, res2) << endl;
    return 0;
}
