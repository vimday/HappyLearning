/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :C.cpp
 * @Created Time:2020-09-01 20:15:46
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
int N, M;
int main(int argc, char const *argv[]) {
    cin >> N >> M;
    vector<array<int, 2>> data(N);
    for (int i = 0; i < N; i++)
        cin >> data[i][0] >> data[i][1];
    vector<vector<int>> dp(M + 1, vector<int>(N + 1));
    sort(data.begin(), data.end());

    for (int i = 0; i <= M; i++)
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i][j]);
            if (i > 0)
                dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            if (i >= data[j - 1][0]) {
                //for(int k=j-1;k)
                dp[i][j] = max(dp[i][j], dp[i - data[j - 1][0]][j - 1] + data[j - 1][1]);
            }
        }

    cout << data[M][N] << endl;
    return 0;
}
