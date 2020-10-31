/*
 * @Author      :vimday
 * @Desc        :https://blog.csdn.net/weixin_51000954/article/details/108890978
 * @Url         :https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff48/00000000003f4dea#problem
 * @File Name   :D_Yeetzhee.cpp
 * @Created Time:2020-10-31 15:56:25
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#define iout(x) printf("%d\n", x)
#define lout(x) printf("%lld\n", x)
#define REP(x, l, u) for (ll x = l; x < u; x++)
#define RREP(x, l, u) for (ll x = l; x >= u; x--)
#define complete_unique(a) a.erase(unique(a.begin(), a.end()), a.end())
#define mst(x, a) memset(x, a, sizeof(x))
#define all(a) begin(a), end(a)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define MP make_pair
#define lowbit(x) ((x) & (-(x)))
#define ls (ind << 1)
#define rs (ind << 1 | 1)
#define mid (l + ((r - l) >> 1))
#define lson l, mid, ls
#define rson mid + 1, r, rs
#define se second
#define fi first
#define sz(x) ((int)x.size())
#define EX0 exit(0);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;
namespace IO {
bool REOF = 1;  //为0表示文件结尾
inline char nc() {
    static char buf[1 << 20], *p1 = buf, *p2 = buf;
    return p1 == p2 && REOF && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? (REOF = 0, EOF) : *p1++;
}
template <typename T>
inline bool read(T &x) {
    char c = nc();
    bool f = 0;
    x = 0;
    while (c < '0' || c > '9') c == '-' && (f = 1), c = nc();
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = nc();
    if (f) x = -x;
    return REOF;
}
template <typename T>
inline void write(T x) {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
}
template <typename T, typename... T2>
inline bool read(T &x, T2 &... rest) {
    read(x);
    return read(rest...);
}
// inline bool need(char &c) { return (c == '.') || (c == '#');}
inline bool need(char &c) { return ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')) || ((c >= 'A') && (c <= 'Z')); }
// inline bool need(char &c) { return ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')) || ((c >= 'A') && (c <= 'Z')) || c==' ');}
inline bool read_str(char *a) {
    while ((*a = nc()) && need(*a) && REOF) ++a;
    *a = '\0';
    return REOF;
}
inline bool read_db(double &x) {
    bool f = 0;
    char ch = nc();
    x = 0;
    while (ch < '0' || ch > '9') {
        f |= (ch == '-');
        ch = nc();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10.0 + (ch ^ 48);
        ch = nc();
    }
    if (ch == '.') {
        double tmp = 1;
        ch = nc();
        while (ch >= '0' && ch <= '9') {
            tmp = tmp / 10.0;
            x = x + tmp * (ch ^ 48);
            ch = nc();
        }
    }
    if (f) x = -x;
    return REOF;
}
template <typename TH>
inline void _dbg(const char *sdbg, TH h) { cerr << sdbg << '=' << h << endl; }
template <class TH, class... TA>
inline void _dbg(const char *sdbg, TH h, TA... a) {
    while (*sdbg != ',') cerr << *sdbg++;
    cerr << '=' << h << ',' << ' ';
    _dbg(sdbg + 1, a...);
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> V) {
    os << "[";
    for (auto vv : V) os << vv << ",";
    return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, set<T> V) {
    os << "[";
    for (auto vv : V) os << vv << ",";
    return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, map<T, T> V) {
    os << "[";
    for (auto vv : V) os << vv << ",";
    return os << "]";
}
template <typename L, typename R>
ostream &operator<<(ostream &os, pair<L, R> P) {
    return os << "(" << P.fi << "," << P.se << ")";
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
}  // namespace IO
using namespace IO;
inline void debug_Init() {
#ifdef LOCAL
    freopen("E:\\Code\\HAPPYLEARNING\\in.txt", "r", stdin);
    freopen("E:\\Code\\HAPPYLEARNING\\out.txt", "w", stdout);
#endif
}
// int dx[4] = { 0, 1, 0, -1 };
// int dx[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };
// int dy[4] = { 1, 0, -1, 0 };
// int dy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };

const ll mod = 1e9 + 7;
const ll inf = 1e9 + 7;
const ld eps = 1e-9;
const db PI = atan(1) * 4;
const int block_size = 320;
struct VectorHash {
    int operator()(const std::vector<int> &v) const {
        std::hash<int> hasher;
        int seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
class Solution {
    int n, m, k;
    vector<int> tt;
    unordered_map<vector<int>, double, VectorHash> mp;
    bool valid(vector<int> &ct) {
        sort(ct.begin(), ct.end(), greater<int>());
        int sz = ct.size();
        if (sz > k)
            return false;
        for (int i = 0; i < sz; ++i)
            if (ct[i] > tt[i])
                return false;
        return true;
    }
    void update(vector<int> &ct, int old, int nw) {
        for (int &v : ct)
            if (v == old) {
                v = nw;
                break;
            }
    }
    double dfs(vector<int> &ct) {
        if (ct == tt)
            return 0.0;
        if (mp.count(ct))
            return mp[ct];
        int badColors = 0;
        double ans = 0.0;
        map<int, int> mcnt;
        for (int i : ct)
            ++mcnt[i];
        for (auto &p : mcnt) {
            int cnt = p.first, occurences = mcnt[cnt];
            update(ct, cnt, cnt + 1);
            if (valid(ct)) {
                double p = occurences * 1.0 / m;
                //debug(ct, cnt, p);
                ans += p * (1.0 + dfs(ct));
            } else
                //此点数不能取
                badColors += occurences;
            update(ct, cnt + 1, cnt);
        }
        int sz = ct.size();
        if (sz < k) {
            ct.push_back(1);
            double p = 1.0 - sz * 1.0 / m;
            //debug(ct, p);
            ans += p * (1.0 + dfs(ct));
            ct.pop_back();
        } else
            badColors += m - sz;
        // 需要重新扔的概率
        double p = badColors * 1.0 / m;
        // e.g 扔到六点的期望为 E
        // E = 1/6 + (6/5)*(1+E)
        // 最终期望 = 不需要重新扔的期望 + 需要重新扔的概率 * (1 + 最终期望)
        // E = ans + p(1+E)
        // E = (ans + p)/(1 - p)
        ans = (ans + p) / (1.0 - p);
        return mp[ct] = ans;
    }

public:
    void solve(int caseNum) {
        printf("Case #%d: ", caseNum);
        read(n, m, k);
        tt.resize(k);
        mp.clear();
        for (int i = 0; i < k; ++i)
            read(tt[i]);
        reverse(tt.begin(), tt.end());
        vector<int> ct;
        printf("%f\n", dfs(ct));
    }
};
int main() {
    debug_Init();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    read(T);
    Solution solution = Solution();
    for (int i = 0; i < T;) {
        solution.solve(++i);
    }
    return 0;
}