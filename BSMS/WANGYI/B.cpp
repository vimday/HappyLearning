/*
 * @Author      :vimday
 * @Desc        :wangyi b
 * @Url         :
 * @File Name   :B.cpp
 * @Created Time:2020-04-07 19:32:51
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
    int n, D;
    cin >> n >> D;

    vector<int> arrA(n), arrB(n);

    for (int i = 0; i < n; i++)
        cin >> arrA[i];
    for (int i = 0; i < n; i++)
        cin >> arrB[i];

    //有些伤害始终逃不掉
    int res = 0, cnt = 0;
    vector<int> me(n);
    for (int i = 0; i < n; i++) {
        if (arrA[i] >= D + n - 1) {
            me[i] = -1;
            res += arrB[i];
            cnt++;
        }
    }

    D += cnt;
    bool f = true;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (me[i] != -1 && arrA[i] < D) {
                me[i] = -1;
                cnt++;
                D++;
                f = false;
            }
        }
        if (f)
            break;
    }

    auto cmp = [&](int a, int b) { return arrA[a] == arrA[b] ? arrB[a] > arrB[b] : arrA[a] > arrA[b]; };

    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    for (int i = 0; i < n; i++)
        if (me[i] != -1) {
            pq.push(i);
        }
    while (!pq.empty()) {
        int t = pq.top();
        pq.pop();
        if (arrA[t] >= D++) {
            res += arrB[t];
        }
    }
    cout << res << endl;
    return 0;
}
