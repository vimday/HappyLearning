/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-09-29 19:00:34
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
    vector<int> arr(100);
    for (int i = 0; i < 100; i++)
        arr[i] = i;
    // 比swap更高效吧
    for (int i = 99; ~i; i--)
        arr[99 - i] = i;
    // 删去 能被3整除的数
    int idx = 0;
    for (int i = 0; i < 100; i++) {
        if (arr[i] % 3 == 0)
            continue;
        arr[idx++] = arr[i];
    }
    arr.erase(arr.begin() + idx, arr.end());
    for (int i : arr)
        cout << i << endl;
    //vector<int> res(arr.begin(), arr.begin() + idx);
    return 0;
}
