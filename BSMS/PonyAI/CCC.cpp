/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :CCC.cpp
 * @Created Time:2020-09-20 16:07:27
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
ll res = 0;
int main(int argc, char const *argv[]) {
    int n;
    vector<int> arr(n), pa(n, -1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> gt(n);
    auto cmp = [&arr](array<int, 2> &a, array<int, 2> &b) {
        return arr[a[1]] - arr[a[0]] < arr[b[1]] - arr[b[0]];
    };
    priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp)>
        pq(cmp);
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[i]) {
                gt[i].push_back(j);
                pq.push({i, j});
            }
    res = 0;
    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        int i = p[0], j = p[1];
        cout << i << " " << j << endl;
        if (pa[i] == -1 && pa[j] == -1) {
            res += arr[j] - arr[i];
            pa[i] = j;
            pa[j] = i;
            continue;
        }
        // int add = arr[j] - arr[i];
        // if (pa[i] == -1) {
        //     int pj = pa[j];
        //     int padd = abs(arr[j] - arr[pj]);
        //     if(add>)
        // }
    }
    cout << res << endl;
    return 0;
}
