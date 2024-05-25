// RTE?? on test 8

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

struct info {
    int mn, pos;
    info() {
        mn = inf;
        pos = -1;
    }
    info(int mn, int pos) {
        this->mn = mn;
        this->pos = pos;
    }
};
info merge_info(const info& a, const info& b) {
    if (a.mn < b.mn) return info(a.mn, a.pos);
    return info(b.mn, b.pos);
}
struct node {
    info i;
    int l, r;
    node() {
        l = r = -1;
    }
} t[20'001'000];
int tree_sz = 1;
int get_l(int v) {
    t[tree_sz] = t[t[v].l];
    t[v].l = tree_sz++;
    return t[v].l;
}
int get_r(int v) {
    t[tree_sz] = t[t[v].r];
    t[v].r = tree_sz++;
    return t[v].r;
}

void build(int v, int l, int r) {
    if (l == r-1) {
        t[v].i.pos = l;
        return;
    }
    t[v].l = tree_sz++;
    t[v].r = tree_sz++;
    int m = (l+r)/2;
    build(t[v].l, l, m);
    build(t[v].r, m, r);
}

void point_set(int v, int l, int r, int i, int x) {
    if (l == r-1) {
        t[v].i.mn = x;
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_set(get_l(v), l, m, i, x);
    else point_set(get_r(v), m, r, i, x);
    t[v].i = merge_info(t[t[v].l].i, t[t[v].r].i);
}

info range_min(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return info();
    if (L <= l && r <= R) return t[v].i;
    int m = (l+r)/2;
    return merge_info(range_min(t[v].l, l, m, L, R), range_min(t[v].r, m, r, L, R));
}

const int max_m = 5e5, max_c = 5e5;
int n;
vi a;

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    build(0, 0, n);
    vi prv(max_c+1, -1), roots(n+1);
    for (int i = 0; i < n; i++) {
        roots[i+1] = tree_sz++;
        t[roots[i+1]] = t[roots[i]];
        if (prv[a[i]] != -1)
            point_set(roots[i+1], 0, n, prv[a[i]], inf);
        point_set(roots[i+1], 0, n, i, prv[a[i]]);
        prv[a[i]] = i;
    }

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r; l--;
        auto res = range_min(roots[r], 0, n, l, r);
        if (res.mn >= l) {
            cout << "0\n";
            continue;
        }
        cout << a[res.pos] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
