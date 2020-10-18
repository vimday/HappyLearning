/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :A.cpp
 * @Created Time:2020-08-01 19:27:41
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
    if (n < 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<array<int, 2>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr.begin(), arr.end());
    int st = arr[0][0], et = arr[0][1];
    int res = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i][0] < et) {
            res++;
            st = arr[i][0];
        }
    }
    return 0;
}
