/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :D_tuozhan.cpp
 * @Created Time:2020-10-13 16:25:37
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define lson (ind << 1)
#define rson (ind << 1 | 1)
#define se second
#define fi first
#define sz(x) ((int)x.size())
#define EX0 exit(0);
#define iout(x) printf("%d\n", x)
#define lout(x) printf("%lld\n", x)

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;
typedef complex<ll> point;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll mod = 1e9 + 7;
const ll inf = 1e9 + 7;
const ld eps = 1e-9;
const db PI = atan(1) * 4;
const int block_size = 320;

namespace Help {

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) +
                                        +to_string(p.second) + ")"; }
template <typename Num>
string to_string(Num n) {
    return std::to_string(n);
}
template <typename A>
string v_to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
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
int tr[60][26];
int fail[60];
int n;
void calcNext(string s) {
    n = sz(s);
    s = " " + s;
    fail[0] = 0;
    REP(i, 0, 26) {
        if (s[1] == i) {
            tr[0][i] = 1;
        } else {
            tr[0][i] = 0;
        }
    }
    fail[1] = 0;
    REP(i, 1, n) {
        REP(j, 0, 26) {
            if (s[i + 1] == j) {
                tr[i][j] = i + 1;
                fail[i + 1] = tr[fail[i]][j];
            } else {
                tr[i][j] = tr[fail[i]][j];
            }
        }
    }
}
};  // namespace Help

template <typename T, typename S>
inline bool upmin(T &a, const S &b) { return a > b ? a = b, 1 : 0; }
template <typename T, typename S>
inline bool upmax(T &a, const S &b) { return a < b ? a = b, 1 : 0; }
inline void in() {}
template <typename T, typename... Tail>
inline void in(T &x, Tail &... y) {
    x = 0;
    T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
    in(y...);
}
inline void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
inline void printAns(int caseNum, ll ans) {
    printf("Case #%d: %lld\n", caseNum, ans);
}
int m, n;
int op, x, y, r, c, val;
const int mxn = (1 << 12) + 7;
ll arr[mxn][mxn];
void add() {
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= m; j += lowbit(j))
            arr[i][j] += val;
}
ll querry(int x, int y) {
    ll ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            ret += arr[i][j];
    return ret;
}
ll querry() {
    return querry(r, c) - querry(r, y - 1) - querry(x - 1, c) + querry(x - 1, y - 1);
}

ll solve() {
    mst(arr, 0);

    while (cin >> op) {
        if (op == 1) {
            cin >> x >> y >> val;
            //in(x, y, val);
            //Help::debug_out("----", op, x, y, val);
            add();
        } else {
            //in(x, y, r, c);
            cin >> x >> y >> r >> c;
            //Help::debug_out("----", op, x, y, r, c);
            //lout(querry());
            cout << querry() << endl;
        }
    }
    return 0;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    in(n, m);
    solve();
    return 0;
}