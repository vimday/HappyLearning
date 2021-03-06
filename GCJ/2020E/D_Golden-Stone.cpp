/*
 * @Author      :vimday
 * @Desc        :https://leetcode-cn.com/circle/article/M1wbLj/
 * @Url         :https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bef29
 * @File Name   :D_Golden-Stone.cpp
 * @Created Time:2020-10-22 21:12:37
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
    freopen("E:\\Code\\HAPPYLEARNING\\in.txt", "r", stdin);
    freopen("E:\\Code\\HAPPYLEARNING\\out.txt", "w", stdout);
#endif
}
const ll INF = 1e12;
int n, m, s, r;
int _hash(int si, int ni) { return si * (n + 1) + ni; }
void solve() {
    read(n, m, s, r);
    vector<VI> adj(n + 1), needed_by_recipes(s + 1);
    vector<VLL> stone_cost(s + 1, VLL(n + 1, INF)), recipe_cost(r, VLL(n + 1));
    vector<VI> ingredients_got(r, VI(n + 1));
    VI ingredients_need(r), product(r);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    for (int i = 0; i < m; ++i) {
        int u, v;
        read(u, v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for (int city = 1; city <= n; ++city) {
        int stone_num;
        read(stone_num);
        for (int j = 0; j < stone_num; ++j) {
            int stone;
            read(stone);
            stone_cost[stone][city] = 0;
            pq.push({0, _hash(stone, city)});
        }
    }
    for (int i = 0; i < r; ++i) {
        read(ingredients_need[i]);
        for (int j = 0; j < ingredients_need[i]; ++j) {
            int ingredient;
            read(ingredient);
            needed_by_recipes[ingredient].emplace_back(i);
        }
        read(product[i]);
    }
    while (pq.size()) {
        auto top = pq.top();
        pq.pop();
        ll c = top.first;
        int u = top.second;
        int stone = u / (n + 1), city = u % (n + 1);
        if (c != stone_cost[stone][city])
            continue;
        for (int recipe : needed_by_recipes[stone]) {
            ingredients_got[recipe][city]++;
            ll nc = recipe_cost[recipe][city] += c;
            if (ingredients_got[recipe][city] == ingredients_need[recipe]) {
                if (nc < stone_cost[product[recipe]][city]) {
                    stone_cost[product[recipe]][city] = nc;
                    pq.push({nc, _hash(product[recipe], city)});
                }
            }
        }
        for (int nxt : adj[city]) {
            if (c + 1 < stone_cost[stone][nxt]) {
                stone_cost[stone][nxt] = c + 1;
                pq.push({c + 1, _hash(stone, nxt)});
            }
        }
    }
    ll ans = *min_element(stone_cost[1].begin(), stone_cost[1].end());
    printf("%lld", ans == INF ? -1 : ans);
}

inline void printAns(int caseNum) {
    printf("Case #%d: ", caseNum);
    solve();
    printf("\n");
}
int main() {
    debug_Init();
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    int T;
    read(T);
    for (int i = 0; i < T;)
        printAns(++i);
    return 0;
}

// #include <algorithm>
// #include <cstdio>
// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;
// typedef long long ll;
// const ll INF = 1e12;

// template <typename T>
// void read(T &x) {
//     x = 0;
//     char c = getchar();
//     T sig = 1;
//     for (; !isdigit(c); c = getchar())
//         if (c == '-')
//             sig = -1;
//     for (; isdigit(c); c = getchar())
//         x = (x << 3) + (x << 1) + c - '0';
//     x *= sig;
// }

// class Solution {
//     int n, m, s, r;

//     int hash(int si, int ni) const { return si * (n + 1) + ni; };

// public:
//     void solve(int case_num) {
//         printf("Case #%d: ", case_num);
//         read(n), read(m), read(s), read(r);
//         vector<vector<int>> adj(n + 1), needed_by_recipe(s + 1);
//         vector<vector<ll>> stone_cost(s + 1, vector<ll>(n + 1, INF)),
//             recipe_cost(r, vector<ll>(n + 1));
//         vector<vector<int>> ingredients_got(r, vector<int>(n + 1));
//         vector<int> ingredients_need(r), product(r);
//         priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
//         for (int i = 0; i < m; ++i) {
//             int u, v;
//             read(u), read(v);
//             adj[u].emplace_back(v);
//             adj[v].emplace_back(u);
//         }

//         for (int city = 1; city <= n; ++city) {
//             int stone_num;
//             read(stone_num);
//             for (int j = 0; j < stone_num; ++j) {
//                 int stone;
//                 read(stone);
//                 stone_cost[stone][city] = 0;
//                 pq.push({0, hash(stone, city)});
//             }
//         }

//         for (int i = 0; i < r; ++i) {
//             read(ingredients_need[i]);
//             for (int j = 0; j < ingredients_need[i]; ++j) {
//                 int ingredient;
//                 read(ingredient);
//                 needed_by_recipe[ingredient].emplace_back(i);
//             }
//             read(product[i]);
//         }

//         while (!pq.empty()) {
//             auto top = pq.top();
//             pq.pop();
//             ll c = top.first;
//             int u = top.second;
//             int stone = u / (n + 1), city = u % (n + 1);
//             if (c != stone_cost[stone][city])
//                 continue;
//             for (int recipe : needed_by_recipe[stone]) {
//                 ingredients_got[recipe][city]++;
//                 ll nc = recipe_cost[recipe][city] += c;
//                 if (ingredients_got[recipe][city] == ingredients_need[recipe]) {
//                     if (nc < stone_cost[product[recipe]][city]) {
//                         stone_cost[product[recipe]][city] = nc;
//                         pq.push({nc, hash(product[recipe], city)});
//                     }
//                 }
//             }
//             for (int nxt : adj[city]) {
//                 if (c + 1 < stone_cost[stone][nxt]) {
//                     stone_cost[stone][nxt] = c + 1;
//                     pq.push({c + 1, hash(stone, nxt)});
//                 }
//             }
//         }
//         ll ans = *min_element(stone_cost[1].begin(), stone_cost[1].end());
//         printf("%lld\n", ans == INF ? -1 : ans);
//     }
// };

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     read(t);
//     for (int i = 1; i <= t; ++i) {
//         Solution solution = Solution();
//         solution.solve(i);
//     }
// }

// #include <algorithm>
// #include <cstdio>
// #include <iostream>
// #include <vector>

// using namespace std;
// typedef long long ll;
// const ll INF = 1e12;

// template <typename T>
// void read(T &x) {
//     x = 0;
//     char c = getchar();
//     T sig = 1;
//     for (; !isdigit(c); c = getchar())
//         if (c == '-')
//             sig = -1;
//     for (; isdigit(c); c = getchar())
//         x = (x << 3) + (x << 1) + c - '0';
//     x *= sig;
// }

// struct Recipe {
//     vector<int> in;
//     int out;
// };

// class Solution {
// public:
//     void solve(int case_num) {
//         printf("Case #%d: ", case_num);
//         int n, m, s, r;
//         read(n), read(m), read(s), read(r);
//         vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF)),
//             cost(s + 1, vector<ll>(n + 1, INF));
//         vector<ll> lo(s + 1, INF);
//         vector<Recipe> recipes;
//         for (int i = 0; i < m; ++i) {
//             int u, v;
//             read(u), read(v);
//             dist[u][v] = dist[v][u] = 1;
//         }

//         for (int k = 1; k <= n; ++k) {
//             dist[k][k] = 0;
//             for (int i = 1; i <= n; ++i) {
//                 if (i == k)
//                     continue;
//                 for (int j = 1; j <= n; ++j) {
//                     if (j == k || j == i)
//                         continue;
//                     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//                 }
//             }
//         }

//         for (int i = 1; i <= n; ++i) {
//             int c;
//             read(c);
//             for (int j = 0; j < c; ++j) {
//                 int si;
//                 read(si);
//                 lo[si] = 0;
//                 cost[si][i] = 0;
//                 for (int k = 1; k <= n; ++k)
//                     cost[si][k] = min(cost[si][k], dist[i][k]);
//             }
//         }

//         for (int i = 0; i < r; ++i) {
//             int k;
//             read(k);
//             vector<int> v(k);
//             for (int j = 0; j < k; ++j)
//                 read(v[j]);
//             sort(v.begin(), v.end());
//             int result;
//             read(result);
//             recipes.push_back({v, result});
//         }

//         bool changed = true;
//         auto valid = [&](Recipe &r) {
//             for (int i : r.in)
//                 if (lo[i] == INF)
//                     return false;
//             return true;
//         };
//         while (changed) {
//             changed = false;
//             for (auto &recipe : recipes) {
//                 if (!valid(recipe))
//                     continue;
//                 for (int i = 1; i <= n; ++i) {
//                     ll c = 0;
//                     for (int si : recipe.in)
//                         c += cost[si][i];
//                     if (c < cost[recipe.out][i]) {
//                         changed = true;
//                         lo[recipe.out] = min(lo[recipe.out], c);
//                         cost[recipe.out][i] = c;
//                         for (int j = 1; j <= n; ++j)
//                             cost[recipe.out][j] = min(cost[recipe.out][j], c + dist[i][j]);
//                     }
//                 }
//             }
//         }
//         printf("%lld\n", lo[1] == INF ? -1 : lo[1]);
//     }
// };

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     read(t);
//     for (int i = 1; i <= t; ++i) {
//         Solution solution = Solution();
//         solution.solve(i);
//     }
// }