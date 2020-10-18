/*
 * @Author      :vimday
 * @Desc        :baidu b
 * @Url         :
 * @File Name   :B.cpp
 * @Created Time:2020-03-29 19:51:11
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    //freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
int main(int argc, char const *argv[]) {
    debug();
    /* code */
    int n;
    cin >> n;
    vector<ll> vl(n);
    for (int i = 0; i < n; i++)
        cin >> vl[i];
    //每次相当于总和-1；
    priority_queue<ll> pq;
    for (ll i : vl)
        pq.push(i);
    int res = 0, cs = 0;
    while (!pq.empty()) {
        ll t = pq.top() + cs;
        pq.pop();
        if (t < n) {
            cout << res << endl;
            return 0;
        }
        ll tm = (t - n) / n + 1;

        res += tm;
        cs += tm;
        t = t - tm * n - cs;
        cout << t << endl;
        pq.push(t);
    }
    return 0;
}
