/*
 * @Author      :vimday
 * @Desc        :ali a
 * @Url         :
 * @File Name   :A.cpp
 * @Created Time:2020-03-30 18:55:41
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}

typedef long long ll;
int main() {
    int n, m, k, t;
    ll base(0), sum(0);
    scanf("%d%d%d", &n, &m, &k);
    priority_queue<int> heap;  //默认大根堆
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        heap.emplace(t);
        sum += t;
    }
    for (int i = 0; i < m; i++) {
        base += k;
        t = heap.top() + base;
        int d = (t + 1) / 2;
        heap.pop();
        heap.emplace(t - d - base);
        sum -= d;
    }
    printf("%lld\n", base * n + sum);
}

int bf(int n, int m, int k, vector<ll> data) {
    while (m--) {
        for (ll &i : data)
            i += k;
        sort(data.begin(), data.end());
        data.back() /= 2;
    }
    ll res = 0;
    for (ll &I : data)
        res += I;
    return res;
}

int main(int argc, char const *argv[]) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> data(n);
    for (int i = 0; i < n; i++)
        cin >> data[i];
    cout << bf(n, m, k, data) << endl;
    return 0;
    priority_queue<ll> pq;
    ll cs = 0, idx = 0, curadd = 0;
    for (ll &i : data) {
        pq.push(i);
        cs += i;
    }
    while (idx++ < m) {
        ll t = pq.top();
        pq.pop();
        curadd += k;
        t += curadd;
        t /= 2;
        pq.push(t - curadd);
    }
    ll res = 0;
    while (!pq.empty()) {
        res += pq.top();
        pq.pop();
    }
    cout << res + n * m * k << endl;
    return 0;
}