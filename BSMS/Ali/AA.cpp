/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AA.cpp
 * @Created Time:2020-08-12 08:56:54
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
int n, m;
void solve(int start, int remain, vector<int> &arr) {
    if (remain < 1 || start + remain > n + 1)
        return;
    arr[m - remain] = start;
    if (remain == 1) {
        for (int i = 0; i < m - 1; i++)
            cout << arr[i] << " ";
        cout << start << endl;
        return;
    }
    //if(start+remain<=n+1)
    //cout << start << " ";

    for (int i = start + 1; i <= n - remain + 1; i++)
        solve(i, remain - 1, arr);
}
int main(int argc, char const *argv[]) {
    cin >> n >> m;
    vector<int> arr(m);
    for (int i = 1; i <= n - m + 1; i++)
        solve(i, m, arr);
    return 0;
}
