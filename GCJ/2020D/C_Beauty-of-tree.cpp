/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :C_Beauty-of-tree.cpp
 * @Created Time:2020-10-17 13:32:34
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// #include <ext/rope>
// using namespace __gnu_cxx;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef ll key_type;
// typedef null_mapped_type value_type;
// typedef tree<key_type, value_type, less<key_type>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
// typedef __gnu_pbds::priority_queue<pi,greater<pi>,pairing_heap_tag > heap;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int rnd(int l,int r){return l+rng()%(r-l+1);}

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
#define mid ((l + r) >> 1)
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
typedef complex<ll> point;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
//int tr[60][26];
//int fail[60];
//int n;
//void calcNext(string s) {
//    n = sz(s);
//    s = " " + s;
//    fail[0] = 0;
//    REP(i, 0, 26) {
//      if (s[1] == i) {
//      tr[0][i] = 1;
//      } else {
//      tr[0][i] = 0;
//      }
//    }
//    fail[1] = 0;
//    REP(i, 1, n) {
//      REP(j, 0, 26) {
//      if (s[i + 1] == j) {
//      tr[i][j] = i + 1;
//      fail[i + 1] = tr[fail[i]][j];
//      } else {
//      tr[i][j] = tr[fail[i]][j];
//      }
//      }
//    }
//}
// ll qp(ll a, ll b) {
//     ll res = 1;
//     a %= MOD;
//     assert(b >= 0);
//     while(b){
//         if(b&1)
//             res = res * a % MOD;
//         a = a * a % MOD;
//         b >>= 1;
//     }
//     return res;
// }
// ll inv(ll x) {return qp(x, MOD - 2);}
// ll factor[N], finv[N];
// void init() {
//  factor[0]=1;
//  for(int i=1; i<N; i++) factor[i] = factor[i-1] * i % MOD;
//  finv[N-1] = qp(factor[N-1], MOD - 2);
//  for(int i=N-2; i>=0; i--) finv[i] = finv[i+1] * (i+1) % MOD;
// }
// ll c(ll n, ll m) {
//     return factor[n] * finv[m] % MOD * finv[n-m] % MOD;
// }
// #define fore(_, __) for(int _=head[__]; _; _=e[_].nxt)
// int head[N], tot = 1;
// struct Edge {
//     int v, nxt;
//     Edge(){}
//     Edge(int _v, int _nxt):v(_v), nxt(_nxt) {}
// }e[M << 1];
// void addedge(int u, int v) {
//     e[tot] = Edge(v, head[u]); head[u] = tot++;
//     e[tot] = Edge(u, head[v]); head[v] = tot++;
// }
template <typename T, typename S>
inline bool upmin(T &a, const S &b) { return a > b ? a = b, 1 : 0; }
template <typename T, typename S>
inline bool upmax(T &a, const S &b) { return a < b ? a = b, 1 : 0; }
};  // namespace HELP

namespace IO {
template <typename T>
inline void in(T &x) {
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
}
template <typename T, typename... Tail>
inline void in(T &x, Tail &... y) {
    in(x);
    in(y...);
}
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
string to_string(vector<A> v) {
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
inline void printAns(int caseNum, double ans) {
    printf("Case #%d: %lf\n", caseNum, ans);
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
const int MAXN = 500005;
ll n, a, b, t;
int fp[MAXN];
bool me[MAXN];
ll aCnt[MAXN], bCnt[MAXN];
vector<int> g[MAXN];

vector<int> path;
void dfs(int pos) {
    path.push_back(pos);
    ++aCnt[pos];
    ++bCnt[pos];
    for (int son : g[pos])
        dfs(son);
    path.pop_back();
    int sz = path.size();
    if (sz >= a)
        aCnt[path[sz - a]] += aCnt[pos];
    if (sz >= b)
        bCnt[path[sz - b]] += bCnt[pos];
}
db solve() {
    read(n, a, b);
    for (int i = 1; i <= n; ++i)
        g[i].clear();

    for (int i = 2; i <= n; ++i) {
        read(t);
        g[t].push_back(i);
    }
    // mst(aCnt, 0);
    // mst(bCnt, 0);
    memset(aCnt, 0, (n + 1) << 2);
    memset(bCnt, 0, (n + 1) << 2);
    // for (int i = 1; i <= n; i++)
    //     aCnt[i] = bCnt[i] = 1;
    path.clear();
    dfs(1);
    db res = 0.0;
    for (int i = 1; i <= n; i++) {
        res += 1.0 * (aCnt[i] + bCnt[i]) / n - 1.0 * aCnt[i] * bCnt[i] / (n * n);
        //debug(i, aCnt[i]);
    }

    return res;
}

int getParent(int idx, int k) {
    while (k--) {
        idx = fp[idx];
    }
    return idx;
}
void bf_dfs(int pos) {
    for (int son : g[pos])
        bf_dfs(son);
    if (pos != 1) {
        int pa = getParent(pos, a);
        int pb = getParent(pos, b);
        if (pa)
            aCnt[pa] += aCnt[pos];
        if (pb)
            bCnt[pb] += bCnt[pos];
    }
}
ll dfs1(int idx, int k, bool f = false) {
    ll cnt = me[idx];
    if (f)
        me[idx] = false;
    int i = 0;
    while (idx != 1) {
        idx = fp[idx];
        if (++i % k == 0) {
            cnt += me[idx];
            if (f)
                me[idx] = false;
        }
    }
    return cnt;
}
db bf() {
    read(n, a, b);
    for (int i = 2; i <= n; ++i)
        read(fp[i]);
    db res = 1.0 / (n * n);
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; j++)
            me[j] = true;
        ll pre = dfs1(i, a, true);
        cnt += n * pre;
        for (int j = 1; j <= n; ++j)
            cnt += dfs1(j, b);
    }
    //write(cnt);
    return cnt * res;
}
int main() {
    debug_Init();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    read(T);
    for (int i = 0; i < T;)
        printAns(++i, solve());
    return 0;
}

// https://doowzs.com/code/ks2020d-c/

// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <vector>
// using namespace std;

// class Node {
// public:
//     int parents[20];
//     vector<int> children;
//     double pA, pB;
// };

// int n = 0, A = 0, B = 0;
// Node tree[500005] = {};

// int getParent(int pos, int x) {
//     int pow = 0;
//     while (x) {
//         if (x & 1) {
//             pos = tree[pos].parents[pow];
//             if (pos == 0) return 0;
//         }
//         x >>= 1;
//         pow += 1;
//     }
//     return pos;
// }

// void dfs(int pos) {
//     for (auto child : tree[pos].children) {
//         dfs(child);
//     }
//     if (pos != 1) {
//         int parentA = getParent(pos, A);
//         int parentB = getParent(pos, B);
//         if (parentA > 0)
//             tree[parentA].pA += tree[pos].pA;
//         if (parentB > 0)
//             tree[parentB].pB += tree[pos].pB;
//     }
// }

// int main() {
//     int T = 0;
//     scanf("%d", &T);
//     memset(tree[0].parents, 0, sizeof(int) * 20);
//     for (int t = 1; t <= T; ++t) {
//         scanf("%d %d %d", &n, &A, &B);
//         tree[1].parents[0] = 0;
//         tree[1].children.clear();
//         tree[1].pA = tree[1].pB = 1.0 / n;
//         for (int i = 2; i <= n; ++i) {
//             int p = 0;
//             scanf("%d", &p);
//             tree[i].parents[0] = p;
//             tree[i].children.clear();
//             tree[p].children.emplace_back(i);
//             tree[i].pA = tree[i].pB = 1.0 / n;
//         }
//         for (int i = 1; i < 20; ++i) {
//             for (int pos = 1; pos <= n; ++pos) {
//                 tree[pos].parents[i] = tree[tree[pos].parents[i - 1]].parents[i - 1];
//             }
//         }
//         dfs(1);
//         double ans = 0.0;
//         for (int pos = 1; pos <= n; ++pos) {
//             ans += tree[pos].pA + tree[pos].pB - tree[pos].pA * tree[pos].pB;
//         }
//         printf("Case #%d: %.8lf\n", t, ans);
//     }
//     return 0;
// }