/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :quickSort.cpp
 * @Created Time:2020-04-17 10:12:35
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

int myparition(vector<int>& arr, int l, int h) {
    swap(arr[l], arr[l + rand() % (h - l)]);
    int t = arr[l];
    while (l < h) {
        while (l < h && arr[--h] > t)
            ;
        //arr[h]<=t
        arr[l] = arr[h];
        while (l < h && arr[++l] < t)
            ;
        //arr[l]>=t
        arr[h] = arr[l];
    }
    //l==h
    arr[l] = t;
    return l;
}

void mySort(vector<int>& arr, int l, int h) {
    if (l >= h) return;
    int paridx = myparition(arr, l, h);
    mySort(arr, l, paridx);
    mySort(arr, paridx + 1, h);
}

void myQuickSort(vector<int>& arr) {
    mySort(arr, 0, arr.size());
}

void stackSort(vector<int>& v) {
    int n = v.size(), l = 0, h = n;
    if (l >= h) return;
    stack<array<int, 3>> sk;

    sk.push({myparition(v, l, h), l, h});

    while (sk.size()) {
        auto t = sk.top();
        sk.pop();
        int pidx = t[0];
        l = t[1], h = t[2];
        if (pidx > l) {
            sk.push({myparition(v, l, pidx), l, pidx});
        }
        if (h > pidx + 1) {
            sk.push({myparition(v, pidx + 1, h), pidx + 1, h});
        }
    }
    return;
}

vector<int> getrandv(int sz, int l, int h) {
    vector<int> res(sz);
    for (int i = 0; i < sz; i++)
        res[i] = l + rand() % (h - l);
    return res;
}
int main(int argc, char const* argv[]) {
    vector<int> arr = getrandv(10, 0, 100);
    for (int& i : arr)
        cout << i << " ";
    cout << endl;

    vector<int> tt = arr;
    sort(tt.begin(), tt.end());
    stackSort(arr);
    for (int& i : arr)
        cout << i << " ";
    cout << endl;
    int n = arr.size();

    for (int i = 0; i < n; i++)
        if (arr[i] != tt[i]) {
            cout << "wrong!";
            break;
        }
    return 0;
}
