/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :C.cpp
 * @Created Time:2020-08-08 15:24:10
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
int me[16];
int n;
int get(int t) {
    int res = 0;
    for (int i = 0; i < n; i++)
        if (((t >> i) & 1) == 0)
            res += me[i];
    return res;
}
int getArr(int t, vector<int> &arr) {
    int res = 0;
    int sz = arr.size();
    for (int i = 0; i < sz; i++)
        if (((t >> i) & 1) == 0)
            res += arr[i];
    return res;
}
bool can(int t) {
    vector<int> arr;
    int sum = 0;
    for (int i = 0; i < n; i++)
        if ((t >> i) & 1) {
            arr.push_back(me[i]);
            sum += me[i];
        }

    if (sum & 1)
        return false;
    int sz = arr.size();
    //bf
    for (int i = 0; i < 1 << sz; i++)
        if (getArr(i, arr) == sum / 2)
            return true;
    return false;
}
int help() {
    memset(me, 0, sizeof me);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> me[i];
    int res = INT_MAX;

    for (int i = 0; i < 1 << n; i++)
        if (can(i)) {
            res = min(res, get(i));
        }
    // cout << can(25) << endl;
    return res;
}
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    while (T--) {
        cout << help() << endl;
    }
    return 0;
}