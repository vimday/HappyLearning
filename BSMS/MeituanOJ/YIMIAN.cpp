/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :YIMIAN.cpp
 * @Created Time:2020-09-02 23:37:25
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

int bsl(vector<int> &arr, int t) {
    int h = arr.size(), l = 0;
    while (l < h) {
        int mi = l + (h - l >> 1);
        arr[mi] < t ? l = mi + 1 : h = mi;
    }
    // l==h  arr[l]>=t;
    return --l;
}

int bsh(vector<int> &arr, int t) {
    int h = arr.size(), l = 0;
    while (l < h) {
        int mi = l + (h - l >> 1);
        arr[mi] > t ? h = mi : l = mi + 1;
    }
    // l==h arr[l]>t
    return l;
}

int findTimes(vector<int> &arr, int t) {
    //bsl 返回 arr 中小于 t 的最大索引
    int l = bsl(arr, t);
    //bsh 返回 arr 中大于 t 的最小索引
    int h = bsh(arr, t) - 1;
    return h - l;
}

int main() {
    vector<int> arr = {1, 32, 423, 556, 556, 1988};
    cout << findTimes(arr, 556) << endl;
    //int a;
    //cin >> a;
    //cout << a << endl;
    cout << "Hello World!" << endl;
}