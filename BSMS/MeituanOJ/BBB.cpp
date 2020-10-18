/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-08-29 16:14:45
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
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    vector<int> res(n), m(n + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[arr[i][j]] == 0) {
                m[arr[i][j]] = 1;
                res[i] = arr[i][j];
                break;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
        cout << res[i] << " ";
    cout << res[n - 1] << endl;
    return 0;
}
