/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :B_High_Building.cpp
 * @Created Time:2020-10-20 16:08:44
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

namespace HELP {
ull twop(ll x) { return 1ULL << x; }
ll MOD(ll a, ll m) {
    a %= m;
    if (a < 0) a += m;
    return a;
}
ll inverse(ll a, ll m) {
    a = MOD(a, m);
    if (a <= 1) return a;
    return MOD((1 - inverse(m, a) * m) / a, m);
}
template <typename T>
T sqr(T x) { return x * x; }
ll gcd(ll a, ll b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return abs(a);
}
ll fast(ll a, ll b, ll mod) {
    if (b < 0) a = inverse(a, mod), b = -b;
    ll ans = 1;
    while (b) {
        if (b & 1) {
            b--;
            ans = ans * a % mod;
        } else {
            a = a * a % mod;
            b /= 2;
        }
    }
    return ans % mod;
}
template <typename T, typename S>
inline bool upmin(T &a, const S &b) { return a > b ? a = b, 1 : 0; }
template <typename T, typename S>
inline bool upmax(T &a, const S &b) { return a < b ? a = b, 1 : 0; }
};  // namespace HELP

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
using namespace HELP;
inline void debug_Init() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
const char *IMPOSSIBLE = "IMPOSSIBLE";
void solve() {
    int n, a, b, c;
    read(n, a, b, c);
    // 数组的以头部开头的最长递增子序列的长度为 a
    // 以尾部开头的最长递增子序列的长度为 b
    // 并且有 c 个元素同时位于这两个序列
    vector<int> res(n);
    if (a + b - c > n) {
        printf(IMPOSSIBLE);
        return;
    }
    if (a == b && b == c && c < min(n, 2)) {
        printf(IMPOSSIBLE);
        return;
    }
    bool rev = false;
    if (a > b)
        swap(a, b), rev = true;
    int idx = 0;
    int ra = a - c, rb = b - c;
    for (int i = 0; i < ra; ++i)
        res[idx++] = n - 1;
    res[idx++] = n;
    for (int i = 0; i < n - ra - rb - c; ++i)
        res[idx++] = 1;
    for (int i = 0; i < c - 1; ++i)
        res[idx++] = n;
    for (int i = 0; i < rb; ++i)
        res[idx++] = n - 1;
    if (rev)
        reverse(res.begin(), res.end());
    for (int &i : res)
        printf("%d ", i);
}
inline void printAns(int caseNum) {
    printf("Case #%d: ", caseNum);
    solve();
    printf("\n");
}
int main() {
    debug_Init();
    int T;
    read(T);
    for (int i = 0; i < T;)
        printAns(++i);
    return 0;
}