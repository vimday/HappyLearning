/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :B_Boring-Numbers.cpp
 * @Created Time:2020-11-17 19:14:06
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
    ll get(ll h) {
        string s = to_string(h);
        int n = s.size();
        ll pre[n];
        pre[0] = 1;
        ll ps = 0;
        for (int i = 1; i < n; ++i)
            pre[i] = pre[i - 1] * 5, ps += pre[i];
        for (int i = 1; i <= n; ++i) {
            int d = s[i - 1] - '0';
            int cd = d / 2 + (((i & 1) == 0) && ((d & 1) == 1)) + ((i == n) && ((i & 1) == (d & 1)));
            ps += cd * pre[n - i];
            if ((i & 1) != (d & 1))
                break;
        }
        return ps;
    }

public:
    void solve(int caseNum) {
        ll l, r;
        read(l, r);
        ll res = get(r) - get(l - 1);
        printf("Case #%d: %lld\n", caseNum, res);
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

// rank 1 code
#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; case_num++) {
        int64_t L, R;
        cin >> L >> R;
        R++;
        bool parity = 0;
        int64_t coeff = 1;
        int64_t ans = 0;
        while (L < R) {
            assert(1 <= L && L < R);
            auto is_good = [&](int64_t v) {
                assert(v > 0);
                bool d = v % 2;
                while (v > 0) {
                    if (v % 2 != d) return false;
                    d = !d;
                    v /= 10;
                }
                return d == 0;
            };
            while (L < R && L % 10 != 0) {
                if (is_good(L)) {
                    ans += coeff;
                }
                L++;
            }
            while (L < R && R % 10 != 0) {
                --R;
                if (is_good(R)) {
                    ans += coeff;
                }
            }

            if (L == R) break;
            assert(L % 10 == 0 && R % 10 == 0);
            assert(L >= 10);

            L /= 10;
            R /= 10;

            coeff *= 5;
            parity = !parity;
        }

        cout << "Case #" << case_num << ": " << ans << '\n';
    }

    return 0;
}