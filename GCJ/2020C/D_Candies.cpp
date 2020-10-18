/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :D_Candies.cpp
 * @Created Time:2020-10-11 22:25:23
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
#define ls (ind << 1)
#define rs (ind << 1 | 1)
const int mxn = 200005;
typedef long long ll;
const double eps = 1e-10;

// 单点修改区间查询的线段树 不需要lazy标记
// 按奇偶性分别维护 ai 与 i*ai 共四个线段树
struct ST {
    ll ai, iai;
} odd[mxn << 2], even[mxn << 2];
int arr[mxn], n, m;
void _push_up(ST* st, int ind) {
    st[ind].ai = st[ls].ai + st[rs].ai;
    st[ind].iai = st[ls].iai + st[rs].iai;
}
void _buildTree(bool isOdd, int l = 1, int r = n, int ind = 1) {
    if (l == r) {
        if (l & 1 && isOdd)
            odd[ind].ai = arr[l], odd[ind].iai = 1ll * l * arr[l], even[ind].ai = even[ind].iai = 0;
        else if ((l & 1) == 0 && !isOdd)
            even[ind].ai = arr[l], even[ind].iai = 1ll * l * arr[l], odd[ind].ai = odd[ind].iai = 0;
        //cout << l << "++" << ind << " " << odd[ind].ai << " " << odd[ind].iai << endl;
        return;
    }
    int mi = l + r >> 1;
    _buildTree(isOdd, l, mi, ls);
    _buildTree(isOdd, mi + 1, r, rs);
    if (isOdd)
        _push_up(odd, ind);
    else
        _push_up(even, ind);
}
void buildTree() {
    _buildTree(0);
    _buildTree(1);
}
void update(int idx, int val, int l = 1, int r = n, int ind = 1) {
    if (l > r)
        return;
    if (l == r && l == idx) {
        if (l & 1)
            odd[ind].ai = val, odd[ind].iai = 1ll * l * val;
        else
            even[ind].ai = val, even[ind].iai = 1ll * l * val;
        return;
    }
    int mi = l + r >> 1;
    if (idx <= mi)
        update(idx, val, l, mi, ls);
    else
        update(idx, val, mi + 1, r, rs);
    if (idx & 1)
        _push_up(odd, ind);
    else
        _push_up(even, ind);
}
ST querryOdd(int l, int r, int cl = 1, int cr = n, int ind = 1) {
    if (l > cr || r < cl)
        return {0, 0};
    if (l == cl && r == cr)
        return odd[ind];
    int mi = cl + cr >> 1;
    if (r <= mi)
        return querryOdd(l, r, cl, mi, ls);
    else if (l > mi)
        return querryOdd(l, r, mi + 1, cr, rs);
    ST lt = querryOdd(l, mi, cl, mi, ls), rt = querryOdd(mi + 1, r, mi + 1, cr, rs);
    lt.ai += rt.ai;
    lt.iai += rt.iai;
    return lt;
}
ST querryEven(int l, int r, int cl = 1, int cr = n, int ind = 1) {
    if (l > cr || r < cl)
        return {0, 0};
    if (l == cl && r == cr)
        return even[ind];
    int mi = (cl + cr) >> 1;
    //cout << "querryEven" << l << r << cl << cr << ind << mi << endl;
    if (r <= mi)
        return querryEven(l, r, cl, mi, ls);
    else if (l > mi)
        return querryEven(l, r, mi + 1, cr, rs);
    ST lt = querryEven(l, mi, cl, mi, ls), rt = querryEven(mi + 1, r, mi + 1, cr, rs);
    lt.ai += rt.ai;
    lt.iai += rt.iai;
    //cout << "lt"
    //     << " : " << ind << " " << l << r << lt.ai << endl;
    return lt;
}
void printAns(int caseNum, ll ans) {
    printf("Case #%d: %lld\n", caseNum, ans);
}

ll getSum(int l, int r) {
    ST od, en;
    if (l & 1) {
        od = querryOdd(l, r), en = querryEven(l + 1, r);

        return od.iai - (l - 1) * od.ai - (en.iai - (l - 1) * en.ai);
    }
    en = querryEven(l, r), od = querryOdd(l + 1, r);
    //cout << "--" << l << " " << r << " : " << od.ai << " " << od.iai << endl;
    return en.iai - (l - 1) * en.ai - (od.iai - (l - 1) * od.ai);
}
ll solve() {
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    buildTree();

    ll res = 0;
    int l, r;
    string op;
    while (q--) {
        cin >> op >> l >> r;
        if (op == "U")
            update(l, r);
        else {
            res += getSum(l, r);
        }
    }
    return res;
}
int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T;)
        printAns(++i, solve());
    return 0;
}