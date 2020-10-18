/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6
 * @File Name   :A_bike-tour.cpp
 * @Created Time:2020-10-08 23:02:48
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
void printIntAns(int caseNum, int ans) {
    printf("Case #%d: %d\n", caseNum, ans);
}
int solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res = 0;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            res++;
    }
    return res;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T;)
        printIntAns(++i, solve());
    return 0;
}