/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-09-06 19:34:00
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
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int m;
    cin >> m;
    int barr[m];
    for (int i = 0; i < m; i++)
        cin >> barr[i];
    vector<int> res;
    int ai = 0;
    int bi = 0;
    while (ai < n && bi < m) {
        if (arr[ai] == barr[bi]) {
            res.push_back(arr[ai]);
            ai++;
            bi++;
        } else if (arr[ai] > barr[bi])
            ai++;
        else {
            bi++;
        }
    }
    int sz = res.size();
    for (int i = 0; i < sz; i++)
        cout << res[i] << " \n"[i == sz - 1];
    return 0;
}
