#include <bits/stdc++.h>
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

typedef long long ll;
typedef double db;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define rep(i, _, __) for (int i = (_); i < (__); ++i)
#define per(i, _, __) for (int i = (_ - 1); i >= (__); --i)

#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define x1 _x
#define x2 __x
#define y1 _y
#define y2 __y
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

const double pi = acos(-1.0);

const int N = 2e5 + 5;
const int M = 2e5 + 5;
const int V = 2e7 + 5;
const int MOD = 998244353;            // 998244353 1e9+7
const int INF = 0x3f3f3f3f;           // 1e9+7 0x3f3f3f3f
const ll LLINF = 0x3f3f3f3f3f3f3f3f;  // 1e18+9 0x3f3f3f3f3f3f3f3f
const double eps = 1e-8;

// int dx[4] = { 0, 1, 0, -1 };
// int dx[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };
// int dy[4] = { 1, 0, -1, 0 };
// int dy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };

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

// #define ls (x<<1)
// #define rs (x<<1|1)
// #define mid ((l+r)>>1)
// #define lson ls,l,mid
// #define rson rs,mid+1,r

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

#define ls (x << 1)
#define rs (x << 1 | 1)
#define mid ((l + r) >> 1)
#define lson ls, l, mid
#define rson rs, mid + 1, r

struct SegmentTree {
    ll s1[N << 2], s2[N << 2];

    void push_up(int x) {
        s1[x] = s1[ls] + s1[rs];
        s2[x] = s2[ls] + s2[rs];
    }

    void build(int *a, int x, int l, int r, bool isodd) {
        if (l == r) {
            if (isodd) {
                if (l & 1)
                    s1[x] = 1ll * l * a[l], s2[x] = a[l];
                else
                    s1[x] = 0, s2[x] = 0;
            } else {
                if (l & 1)
                    s1[x] = 0, s2[x] = 0;
                else
                    s1[x] = 1ll * l * a[l], s2[x] = a[l];
            }
            return;
        }
        build(a, lson, isodd);
        build(a, rson, isodd);
        push_up(x);
    }

    ll query1(int x, int l, int r, int L, int R) {
        // debug(1, l, r, L, R);
        if (l > r || L > R) return 0;
        if (l == L && r == R) return s1[x];
        if (R <= mid)
            return query1(lson, L, R);
        else if (L > mid)
            return query1(rson, L, R);
        return query1(lson, L, mid) + query1(rson, mid + 1, R);
    }

    ll query2(int x, int l, int r, int L, int R) {
        // debug(2, l, r, L, R);
        if (l > r || L > R) return 0;
        if (l == L && r == R) return s2[x];
        if (R <= mid)
            return query2(lson, L, R);
        else if (L > mid)
            return query2(rson, L, R);
        return query2(lson, L, mid) + query2(rson, mid + 1, R);
    }

    void update(int x, int l, int r, int pos, int value) {
        // debug(3, l, r);
        if (l > r) return;
        if (l == r && l == pos) {
            s1[x] = 1ll * l * value;
            s2[x] = value;
            return;
        }

        if (pos <= mid)
            update(lson, pos, value);
        else
            update(rson, pos, value);

        push_up(x);
    }
} T1, T2;

int n, q, a[N];

void solve(int Case) {
    printf("Case #%d: ", Case);
    cin >> n >> q;
    char op[5];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    T1.build(a, 1, 1, n, 1);
    T2.build(a, 1, 1, n, 0);

    ll ans = 0;
    int x, y;
    while (q--) {
        cin >> op >> x >> y;

        if (op[0] == 'Q') {
            // for (int i = 1; i < 16; i++)
            //     cout << T1.s1[i] << " " << T1.s2[i] << " " << T2.s1[i] << " " << T2.s2[i] << endl;
            ll tmp = 0;
            if (x & 1) {
                tmp += T1.query1(1, 1, n, x, y) - 1ll * (x - 1) * T1.query2(1, 1, n, x, y);
                tmp -= T2.query1(1, 1, n, x + 1, y) - 1ll * (x - 1) * T2.query2(1, 1, n, x + 1, y);
            } else {
                tmp += T2.query1(1, 1, n, x, y) - 1ll * (x - 1) * T2.query2(1, 1, n, x, y);
                tmp -= T1.query1(1, 1, n, x + 1, y) - 1ll * (x - 1) * T1.query2(1, 1, n, x + 1, y);
            }
            ans += tmp;
            //debug(tmp, ans);
        } else if (op[0] == 'U') {
            if (x & 1)
                T1.update(1, 1, n, x, y);
            else
                T2.update(1, 1, n, x, y);
        }
    }
    printf("%lld\n", ans);
}

int main() {
    // #ifdef BACKLIGHT
    //     freopen("in.txt", "r", stdin);
    // #endif
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _T;
    cin >> _T;
    for (int _ = 1; _ <= _T; _++) solve(_);
    // int _T=1; while(read(n)) solve(_T), _T++;
    // solve(1);
    return 0;
}
