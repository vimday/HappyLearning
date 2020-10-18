/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :B_Stable-Wall.CPP
 * @Created Time:2020-10-10 22:51:18
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
const double eps = 1e-10;

void printAns(int caseNum, string ans) {
    int a, b;
    printf("Case #%d: %s\n", caseNum, ans);
    //cout << "Case #" + to_string(caseNum) + ": " + ans << endl;
}
int m, n;
int cnt[26], ind[26];
bool me[31][31];
set<int> fs[26], ts[26];
vector<string> vs;
void dfs(int i, int j) {
    int c = vs[i][j] - 'A';
    cnt[c]++;
    me[i][j] = true;
    if (i > 0) {
        int tc = vs[i - 1][j] - 'A';
        if (tc != c) {
            ts[tc].insert(c);
            fs[c].insert(tc);
        }
        dfs(i - 1, j);
    }
}

string solve() {
    cin >> m >> n;
    vs.resize(m);
    for (int i = 0; i < m; i++)
        cin >> vs[i];
    memset(cnt, 0, sizeof cnt);
    memset(ind, 0, sizeof ind);
    memset(me, 0, sizeof me);
    for (int i = 0; i < 26; i++) {
        fs[i].clear();
        ts[i].clear();
    }

    for (int i = m - 1; i >= 0; i--)
        for (int j = 0; j < n; j++) {
            if (!me[i][j])
                dfs(i, j);
        }
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] && ts[i].empty()) {
            q.push(i);
            cnt[i] = 0;
        }

        ind[i] = ts[i].size();
    }
    string res;
    while (q.size()) {
        int t = q.front();
        q.pop();
        res.push_back(t + 'A');
        //cout << res << endl;
        //cnt[t] = 0;
        for (int nb : fs[t])
            ind[nb]--;
        for (int i = 0; i < 26; i++)
            if (cnt[i] > 0 && ind[i] == 0) {
                q.push(i);
                cnt[i] = 0;
            }
    }
    for (int i = 0; i < 26; i++)
        if (cnt[i])
            return "-1";
    return res;
}
int main(int argc, char const *argv[]) {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // int T;
    // cin >> T;
    // for (int i = 0; i < T;)
    //     printAns(++i, solve());
    printAns(1, "fadsfsda");
    printf("%d %s\n", 1, "dfsafdsa");
    printf("%s\n", "afdsfsd");
    return 0;
}