/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :D_bundling.cpp
 * @Created Time:2020-10-08 17:27:29
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
typedef struct _TrieNode {
    int num;
    vector<_TrieNode*> childs;
    _TrieNode() {
        num = 0;
        childs.resize(26, nullptr);
    }
} TrieNode;

class TrieTree {
public:
    TrieNode* root;
    int k;
    void insert(const string& str) {
        if (str.empty()) return;
        auto p = root;
        for (int i = 0; i < str.size(); ++i) {
            int cur = str[i] - 'A';
            if (p->childs[cur] == nullptr) {
                p->childs[cur] = new TrieNode();
            }
            p = p->childs[cur];
            p->num++;
        }
    }
    ll get_result() {
        ll result = 0;
        queue<TrieNode*> next;
        next.push(root);
        while (!next.empty()) {
            auto cur = next.front();
            next.pop();
            for (auto child : cur->childs) {
                if (child == nullptr || child->num < k) continue;
                result += child->num / k;
                next.push(child);
            }
        }
        return result;
    }
    TrieTree(int _k) {
        root = new TrieNode();
        k = _k;
    }
    ~TrieTree() {
        queue<TrieNode*> next;
        next.push(root);
        while (!next.empty()) {
            auto cur = next.front();
            next.pop();
            for (auto child : cur->childs) {
                if (child == nullptr) continue;
                next.push(child);
            }
            delete cur;
        }
    }
};
int solve() {
    int n, k;
    cin >> n >> k;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    TrieTree tree(k);
    for (auto str : arr)
        tree.insert(str);

    return tree.get_result();
}
int main(int argc, char const* argv[]) {
    int T;
    cin >> T;
    for (int i = 0; i < T;)
        printIntAns(++i, solve());
    return 0;
}
// code by rank1
// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define ar array

// int n, k, c[2000001][26], m, cnt[2000001];
// ll ans;

// void dfs(int u = 0, int d = 0) {
//     for (int v = 0; v < 26; ++v)
//         if (c[u][v])
//             dfs(c[u][v], d + 1), cnt[u] += cnt[c[u][v]];
//     while (cnt[u] >= k) {
//         cnt[u] -= k;
//         ans += d;
//     }
// }

// void solve() {
//     cin >> n >> k;
//     m = 1;
//     for (int i = 0; i < n; ++i) {
//         string s;
//         cin >> s;
//         int u = 0;
//         for (char d : s) {
//             if (!c[u][d - 'A'])
//                 c[u][d - 'A'] = m++;
//             u = c[u][d - 'A'];
//         }
//         ++cnt[u];
//     }
//     ans = 0;
//     dfs();
//     cout << ans << "\n";
//     memset(c, 0, m * sizeof(c[0]));
//     memset(cnt, 0, m * 4);
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int t, i = 1;
//     cin >> t;
//     while (t--) {
//         cout << "Case #" << i << ": ";
//         solve();
//         ++i;
//     }
// }