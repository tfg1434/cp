#include <bits/stdc++.h>
using namespace std;
#define int int64_t

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int n, q;
struct node {
    int t, x, y;
    bool operator<(const node& o) const { return t > o.t; }
};
V<node> v;
vi ans;

vi t;
void init_tree() {
    int size = 1;
    while (size < 2*n) size *= 2;
    t.assign(size, 0);
}
void point_add(int v, int l, int r, int i, int x) {
    if (l == r-1) {
        t[v] += x;
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_add(2*v+1, l, m, i, x);
    else point_add(2*v+2, m, r, i, x);
    t[v] = t[2*v+1] + t[2*v+2];
}
void point_add(int i, int x) { point_add(0, 0, n, i, x); }
int range_sum(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return range_sum(2*v+1, l, m, L, R) + range_sum(2*v+2, m, r, L, R);
}
int range_sum(int L, int R) { return range_sum(0, 0, n, L, R); }

// consider the effect of removing points on [l, m) on the points from [m, r)
// removing (t0, x0, y0) involves points (t, x, y) where t0<t, x0<x, y0>y
void cdq_br(int l, int r) {
    if (l == r-1) return;
    int m = (l+r)/2;
    cdq_br(l, m); cdq_br(m, r);

    V<node> tmp;
    vi hist;
    int a = l, b = m;
    while (a < m && b < r) {
        if (v[a].x > v[b].x) point_add(v[a].y, 1), hist.pb(v[a].y), tmp.pb(v[a++]);
        else ans[v[b].t] += range_sum(0, v[b].y), tmp.pb(v[b++]);
    }
    while (a < m) tmp.pb(v[a++]);
    while (b < r) ans[v[b].t] += range_sum(0, v[b].y), tmp.pb(v[b++]);
    for (int i = l; i < r; i++) v[i] = tmp[i-l];
    for (int pos : hist) point_add(pos, -1);
}
void cdq_tl(int l, int r) {
    if (l == r-1) return;
    int m = (l+r)/2;
    cdq_tl(l, m); cdq_tl(m, r);

    V<node> tmp;
    vi hist;
    int a = l, b = m;
    while (a < m && b < r) {
        if (v[a].x < v[b].x) point_add(v[a].y, 1), hist.pb(v[a].y), tmp.pb(v[a++]);
        else ans[v[b].t] += range_sum(v[b].y, n), tmp.pb(v[b++]);
    }
    while (a < m) tmp.pb(v[a++]);
    while (b < r) ans[v[b].t] += range_sum(v[b].y, n), tmp.pb(v[b++]);
    for (int i = l; i < r; i++) v[i] = tmp[i-l];
    for (int pos : hist) point_add(pos, -1);
}

void solve() {
    cin >> n >> q;
    vi a(n), where(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        where[a[i]] = i;
    }
    init_tree();
    int tot = 0;
    for (int i = 0; i < n; i++) {
        tot += range_sum(a[i], n);
        point_add(a[i], 1);
    }
    init_tree();

    V<bool> in_del(n);
    vi del(q);
    for (int i = 0; i < q; i++) {
        cin >> del[i], del[i]--;
        in_del[del[i]] = true;
        v.pb({i, where[del[i]], del[i]});
    }
    for (int i = 0; i < n; i++) if (!in_del[a[i]]) v.pb({q, i, a[i]});

    // consider the number of inversions a point is involved in with all points to its left
    // therefore we should put the last-removed ones first and first-removed ones last 
    // also if a point is never deleted it should be on the left
    ans.resize(q+1);

    sort(all(v));
    cdq_br(0, n);
    sort(all(v));
    cdq_tl(0, n);

    for (int i = 0; i < q; i++) {
        cout << tot << '\n';
        tot -= ans[i];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
