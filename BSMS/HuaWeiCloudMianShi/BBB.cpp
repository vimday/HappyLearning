/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-10-12 10:09:02
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
int getMaxCntNum(vector<int>& arr) {
    int n = arr.size();
    if (n == 0)
        return -1;
    int res = arr[0], cnt = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == res)
            ++cnt;
        else if (--cnt == 0) {
            res = arr[i];
            cnt = 1;
        }
    }
    cnt = 0;
    for (int& i : arr)
        if (i == res)
            ++cnt;
    return cnt > (n >> 1) ? res : -1;
}
int main(int argc, char const* argv[]) {
    //vector<int> arr = {1, 2, 3, 2, 2};
    vector<int> arr = {3, 3, 3, 4, 4, 4, 2};
    cout << getMaxCntNum(arr) << endl;
    return 0;
}
