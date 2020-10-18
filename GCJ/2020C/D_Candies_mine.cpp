/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :D_Candies_mine.cpp
 * @Created Time:2020-10-15 13:48:40
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
#define ls (ind << 1)
#define rs (ind << 1 | 1)
#define mid ((l + r) >> 1)
#define lson l, mid, ls
#define rson mid + 1, r, rs
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
typedef long long ll;
const int MaxN = 200005;
struct STNode {
    ll iMulAi, Ai;
    STNode operator+(const STNode &rh) {
        return {iMulAi + rh.iMulAi, Ai + rh.Ai};
    }
    STNode operator+(const STNode &&rh) {
        return {iMulAi + rh.iMulAi, Ai + rh.Ai};
    }
};
int n, arr[MaxN];
struct SegmentTree {
    STNode st[MaxN << 2];
    bool isOdd;
    void init(bool isOdd) {
        this->isOdd = isOdd;
        _build();
    }
    void _pushUp(int ind) {
        st[ind] = st[ls] + st[rs];
    }
    void _build(int l = 1, int r = n, int ind = 1) {
        if (l == r) {
            if (isOdd && (l & 1))
                st[ind].Ai = arr[l], st[ind].iMulAi = 1ll * l * arr[l];
            else if (!isOdd && ((l & 1) == 0))
                st[ind].Ai = arr[l], st[ind].iMulAi = 1ll * l * arr[l];
            else
                st[ind].Ai = st[ind].iMulAi = 0;
            return;
        }
        _build(lson);
        _build(rson);
        _pushUp(ind);
    };
    STNode querry(int ql, int qr, int l = 1, int r = n, int ind = 1) {
        if (ql > r || qr < l)
            return {0, 0};
        if (ql == l && qr == r)
            return st[ind];
        if (qr <= mid)
            return querry(ql, qr, lson);
        else if (ql > mid)
            return querry(ql, qr, rson);
        return querry(ql, mid, lson) + querry(mid + 1, qr, rson);
    }
    void update(int idx, int val, int l = 1, int r = n, int ind = 1) {
        if (l > r)
            return;
        if (l == r && l == idx) {
            st[ind].Ai = val;
            st[ind].iMulAi = 1ll * l * val;
            return;
        }
        if (idx <= mid)
            update(idx, val, lson);
        else
            update(idx, val, rson);
        _pushUp(ind);
    }
} oddTree, evenTree;
ll getSum(int l, int r) {
    STNode od, en;
    if (l & 1) {
        od = oddTree.querry(l, r);
        en = evenTree.querry(l + 1, r);
        return od.iMulAi - (l - 1) * od.Ai - (en.iMulAi - (l - 1) * en.Ai);
    }
    en = evenTree.querry(l, r), od = oddTree.querry(l + 1, r);
    return en.iMulAi - (l - 1) * en.Ai - (od.iMulAi - (l - 1) * od.Ai);
}
ll solve() {
    int q;
    in(n, q);
    for (int i = 1; i <= n; i++)
        in(arr[i]);
    oddTree.init(true);
    evenTree.init(false);
    ll res = 0;
    int l, r;
    string op;
    while (q--) {
        cin >> op >> l >> r;
        if (op == "U") {
            if (l & 1)
                oddTree.update(l, r);
            else
                evenTree.update(l, r);
        } else {
            res += getSum(l, r);
        }
    }
    return res;
}
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    in(T);
    for (int i = 0; i < T;)
        printAns(++i, solve());
    return 0;
}