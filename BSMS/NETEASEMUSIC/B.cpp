/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :B.cpp
 * @Created Time:2020-08-08 15:07:21
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
bool me[100005];
int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    memset(me, 0, sizeof me);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        me[arr[i]] = true;
    }
    //这个题没说要用到1-n啊
    int idx = 0;
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (!me[i]) {
            res.push_back(i);
        } else {
            while (idx < m && arr[idx] <= i)
                res.push_back(arr[idx++]);
        }
    }
    for (int i = 0; i < n - 1; i++)
        cout << res[i] << " ";
    cout << res[n - 1] << endl;

    return 0;
}
