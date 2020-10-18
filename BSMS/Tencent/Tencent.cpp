/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Tencent.cpp
 * @Created Time:2020-04-11 15:56:28
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

vector<int> pickNnums(vector<int> &arr, int k) {
    int n = arr.size();
    if (k >= n) return arr;

    vector<int> ret(k);

    for (int i = 0; i < k; i++) {
        int randidx = rand() % (n--);
        int t = arr[randidx];
        ret[i] = t;
        swap(arr[randidx], arr[n]);
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}
