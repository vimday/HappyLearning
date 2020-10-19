/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :D_Locked_Doors(Tree).cpp
 * @Created Time:2020-10-18 22:45:40
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
// int dx[4] = { 0, 1, 0, -1 };
// int dx[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };
// int dy[4] = { 1, 0, -1, 0 };
// int dy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };

// const ll mod = 1e9 + 7;
// const ll inf = 1e9 + 7;
// const ld eps = 1e-9;
// const db PI = atan(1) * 4;
// const int block_size = 320;

const int MXN = 100005;
const int LN = 21;
int n, q, s, k, root;
int d[MXN], nl[MXN], nr[MXN], sk[MXN], sz[MXN];
vector<int> g[MXN];
int f[MXN][LN];
void initLR() {
    sk[0] = 0;
    int idx = 0;
    nl[0] = nr[n] = -1;
    for (int i = 1; i < n; ++i) {
        while (d[sk[idx]] < d[i])
            --idx;
        nl[i] = sk[idx];
        sk[++idx] = i;
    }
    sk[0] = n;
    idx = 0;
    for (int i = n - 1; i > 0; --i) {
        while (d[sk[idx]] < d[i])
            --idx;
        nr[i] = sk[idx];
        sk[++idx] = i;
    }
    //g[1].push_back(0);
    for (int i = 1; i < n; ++i) {
        int l = nl[i], r = nr[i];
        //debug(i, l, r, d[l], d[r]);
        if (d[l] < d[r]) {
            f[i][0] = l;
            g[l].push_back(i);
        } else if (d[l] > d[r]) {
            f[i][0] = r;
            g[r].push_back(i);
        }
    }
    f[n][0] = n - 1;
    g[n - 1].push_back(n);
}
void buildTree(int cur = root) {
    sz[cur] = 1;
    if (cur == root)
        for (int i = 0; i < LN; ++i)
            f[cur][i] = 0;
    else
        for (int i = 1; i < LN; ++i)
            f[cur][i] = f[f[cur][i - 1]][i - 1];
    vector<int> &sons = g[cur];
    for (int &son : sons) {
        buildTree(son);
        sz[cur] += sz[son];
    }
}
int findFirst(int x, int k) {
    if (sz[x] >= k)
        return x;
    for (int j = 20; j >= 0; --j)
        if (f[x][j] && sz[f[x][j]] < k) {
            x = f[x][j];
        }
    return f[x][0];
}
int solve() {
    int s, k;
    read(s, k);
    if (k == 1)
        return s;
    --k;
    int x = d[s - 1] < d[s] ? s - 1 : s + 1;
    if (sz[x] >= k) {
        if (x < s)
            return s - k;
        return s + k;
    }
    int y = findFirst(x, k);
    // if (k == 4 && s == 1)
    //     debug(x, y, g[y][0], sz[g[y][0]]);
    if (sz[s] > sz[y])
        k--;
    if (x < y)
        return y + k - sz[g[y][0]];
    return y - (k - sz[g[y].back()]);
}
inline void printAns(int caseNum) {
    printf("Case #%d: ", caseNum);
    read(n, q);
    d[0] = d[n] = INT_MAX;
    int cm = 0;
    for (int i = 1; i < n; ++i) {
        g[i].clear();
        read(d[i]);
        if (d[i] > cm)
            cm = d[i], root = i;
    }
    memset(f, 0, sizeof f);
    initLR();

    buildTree();
    while (q--)
        printf("%d ", solve());
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

// #include <bits/stdc++.h>
// using namespace std;
// template <typename T1, typename T2>
// inline void chmin(T1 &a, T2 b) {
//     if (a > b) a = b;
// }
// template <typename T1, typename T2>
// inline void chmax(T1 &a, T2 b) {
//     if (a < b) a = b;
// }
// using Int = long long;
// const char newl = '\n';

// struct UnionFind {
//     Int num;
//     vector<Int> rs, ps;
//     UnionFind() {}
//     UnionFind(Int n) : num(n), rs(n, 1), ps(n, 0) { iota(ps.begin(), ps.end(), 0); }
//     Int find(Int x) {
//         return (x == ps[x] ? x : ps[x] = find(ps[x]));
//     }
//     bool same(Int x, Int y) {
//         return find(x) == find(y);
//     }
//     void unite(Int x, Int y) {
//         x = find(x);
//         y = find(y);
//         if (x == y) return;
//         if (rs[x] < rs[y]) swap(x, y);
//         rs[x] += rs[y];
//         ps[y] = x;
//         num--;
//     }
//     Int size(Int x) {
//         return rs[find(x)];
//     }
//     Int count() const {
//         return num;
//     }
// };

// //INSERT ABOVE HERE
// signed solve() {
//     Int n, q;
//     cin >> n >> q;
//     vector<Int> ds(n - 1);
//     for (Int i = 0; i < n - 1; i++) cin >> ds[i];

//     vector<Int> ss(q), ks(q);
//     for (Int i = 0; i < q; i++) cin >> ss[i] >> ks[i], ss[i]--;

//     using P = pair<Int, Int>;
//     vector<P> vp;
//     for (Int i = 0; i < n - 1; i++)
//         vp.emplace_back(ds[i], i);
//     sort(vp.begin(), vp.end());

//     vector<Int> ord(n - 1);
//     for (Int i = 0; i < n - 1; i++)
//         ord[i] = vp[i].second;

//     // check(ls[i]) = false
//     // check(rs[i]) = true
//     vector<Int> ls(q, -1), rs(q, n - 1);
//     while (1) {
//         Int flg = 0;
//         vector<vector<Int>> G(n);
//         for (Int i = 0; i < q; i++) {
//             if (ls[i] + 1 < rs[i]) {
//                 Int mid = (ls[i] + rs[i]) >> 1;
//                 G[mid].emplace_back(i);
//                 flg = 1;
//             }
//         }
//         if (!flg) break;
//         UnionFind uf(n);
//         for (Int i = 0; i < n - 1; i++) {
//             uf.unite(ord[i], ord[i] + 1);
//             for (Int k : G[i]) {
//                 if (uf.size(ss[k]) >= ks[k])
//                     rs[k] = i;
//                 else
//                     ls[k] = i;
//             }
//         }
//     }

//     vector<Int> ans(q);
//     vector<vector<Int>> G(n + 1);
//     for (Int i = 0; i < q; i++) {
//         assert(rs[i] < n - 1);
//         if (ks[i] == 1) {
//             ans[i] = ss[i];
//         } else {
//             G[rs[i]].emplace_back(i);
//         }
//     }

//     UnionFind uf(n);
//     for (Int i = 0; i < n - 1; i++) {
//         // [xL, xR] [yL, yR]
//         Int xR = ord[i];
//         Int xL = xR - (uf.size(xR) - 1);
//         assert(uf.same(xL, xR));

//         Int yL = ord[i] + 1;
//         Int yR = yL + (uf.size(yL) - 1);
//         assert(uf.same(yL, yR));

//         for (Int k : G[i]) {
//             assert(uf.size(ss[k]) < ks[k]);
//             if (uf.same(xL, ss[k])) {
//                 ans[k] = yL + (ks[k] - (uf.size(ss[k]) + 1));
//             } else {
//                 ans[k] = xR - (ks[k] - (uf.size(ss[k]) + 1));
//             }
//         }
//         uf.unite(ord[i], ord[i] + 1);
//     }

//     for (Int i = 0; i < q; i++) cout << ' ' << ans[i] + 1;
//     cout << newl;
//     return 0;
// }

// signed main() {
//     cin.tie(0);
//     ios::sync_with_stdio(0);
//     Int T;
//     cin >> T;
//     for (Int t = 1; t <= T; t++) {
//         cout << "Case #" << t << ":";
//         solve();
//     }

//     return 0;
// }