/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :C_Painters'_Duel.cpp
 * @Created Time:2020-10-24 22:27:34
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
class Solution {
    int n, ar, ac, br, bc, c;
    vector<vector<int>> g;

public:
    bool inArea(int x, int y) {
        return x > 0 && x <= n && y > 0 && y < g[x].size();
    }
    vector<array<int, 2>> getNextPos(int x, int y) {
        vector<array<int, 2>> res;
        if (inArea(x, y - 1) && g[x][y - 1] != -1)
            res.push_back({x, y - 1});
        if (inArea(x, y + 1) && g[x][y + 1] != -1)
            res.push_back({x, y + 1});
        if (y & 1 && inArea(x + 1, y + 1) && g[x + 1][y + 1] != -1)
            res.push_back({x + 1, y + 1});
        if ((y & 1) == 0 && inArea(x - 1, y - 1) && g[x - 1][y - 1] != -1)
            res.push_back({x - 1, y - 1});
        return res;
    }
    int dfs(int ax, int ay, int bx, int by) {
        g[ax][ay] = g[bx][by] = -1;
        auto na = getNextPos(ax, ay);
        int mx = INT_MIN;
        if (na.size()) {
            for (auto &p : na) {
                int nx = p[0], ny = p[1];
                g[nx][ny] = -1;
                int mn = INT_MAX;
                auto nb = getNextPos(bx, by);
                if (nb.size()) {
                    for (auto &bp : nb) {
                        g[bp[0]][bp[1]] = -1;
                        mn = min(mn, dfs(nx, ny, bp[0], bp[1]));
                        g[bp[0]][bp[1]] = 0;
                    }
                } else {
                    //b gg
                    mn = min(mn, 1 + dfs(nx, ny, bx, by));
                }
                mx = max(mx, mn);
                g[nx][ny] = 0;
            }
            return mx;
        }
        // a gg
        auto nb = getNextPos(bx, by);
        int mn = INT_MAX;
        if (nb.size()) {
            for (auto &p : nb) {
                int nx = p[0], ny = p[1];
                g[nx][ny] = -1;
                mn = min(mn, -1 + dfs(ax, ay, nx, ny));
                g[nx][ny] = 0;
            }
            mx = max(mx, mn);
            return mx;
        }
        // a b gg
        return 0;
    }
    void solve(int caseNum) {
        read(n, ar, ac, br, bc, c);
        g.clear();
        g.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            g[i].resize(i << 1);
        }
        for (int i = 0; i < c; ++i) {
            int _r, _c;
            read(_r, _c);
            g[_r][_c] = -1;
        }
        printf("Case #%d: %d\n", caseNum, dfs(ar, ac, br, bc));
    }
};
int main() {
    debug_Init();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    read(T);

    for (int i = 0; i < T;) {
        Solution solution = Solution();
        solution.solve(++i);
    }
    return 0;
}