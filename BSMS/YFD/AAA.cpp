/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-08-22 19:26:30
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
    int sz = 2, idx = 1;
    int t;
    stack<int> s;
    cin >> t;
    cout << t;
    vector<int> tmp;
    while (idx < n) {
        cin >> t;
        cout << " " << t;
        idx++;
        if (idx == n)
            break;
        tmp.clear();
        for (int i = 1; i < sz - 1 && idx < n - 1; i++) {
            cin >> t;
            tmp.push_back(t);
            idx++;
        }
        if (idx < n) {
            cin >> t;
            s.push(t);
            idx++;
        }
        sz *= 2;
    }
    for (int i : tmp)
        cout << " " << i;
    while (!s.empty()) {
        cout << " " << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}