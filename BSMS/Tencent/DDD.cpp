/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :DDD.cpp
 * @Created Time:2020-09-06 19:34:43
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
    if (n < 2)
        return 0;
    vector<int> arr(n);
    // unordered_map<int, int> mvi;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    int rv = sortedArr[n / 2], lv = sortedArr[n / 2 - 1];
    for (int t : arr) {
        if (t <= lv)
            cout << rv << endl;
        else if (t >= rv)
            cout << lv << endl;
    }

    return 0;
}