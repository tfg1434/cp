// look at line 90

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 2e18;

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

const int N = 1e5;
int tin[N], tout[N], timer;
int n;
vi sons[N];
int hr[N], sub[N], par[N];

// // { maximum suffix sum (nonempty), total sum }
// V<array<int, 2>> t;
// vi buf;
// array<int, 2> merge_info(const array<int, 2>& a, const array<int, 2>& b) {
    // if (a[0] == inf) return b;
    // if (b[0] == inf) return a;
    // return {max(a[0]+b[1], b[0]), a[1]+b[1]};
// }
// void upd(int v)  {
    // t[v] = merge_info(t[2*v+1], t[2*v+2]);
// }
// void build(int v, int l, int r) {
    // if (l == r-1) {
        // t[v] = {-1, -1};
        // return;
    // }
    // int m = (l+r)/2;
    // build(2*v+1, l, m);
    // build(2*v+2, m, r);
    // upd(v);
// }
// void init_tree() {
    // int size = 1;
    // while (size < 2*n) size *= 2;
    // t.resize(size);
    // buf.assign(size, inf);
    // build(0, 0, n);
// }
// void pd(int v, int l, int r) {
    // if (buf[v] != inf) {
        // t[v][0] = buf[v] > 0 ? buf[v]*(r-l) : buf[v];
        // t[v][1] = buf[v]*(r-l);
        // if (2*v+2 < buf.size()) {
            // buf[2*v+1] = buf[v];
            // buf[2*v+2] = buf[v];
        // }
        // buf[v] = inf;
    // }
// }
// void range_set(int v, int l, int r, int L, int R, int x) {
    // pd(v, l, r);
    // if (r <= L || R <= l) return;
    // if (L <= l && r <= R) {
        // buf[v] = x;
        // pd(v, l, r);
        // return;
    // }
    // int m = (l+r)/2;
    // range_set(2*v+1, l, m, L, R, x);
    // range_set(2*v+2, m, r, L, R, x);
    // upd(v);
// }
// void range_set(int L, int R, int x) { range_set(0, 0, n, L, R, x); }
// void point_add(int v, int l, int r, int i, int x) {
    // pd(v, l, r);
    // if (l == r-1) {
        // assert(t[v][0] == t[v][1]);
        // t[v] = {t[v][0]+x, t[v][0]+x}; // BRUH
        // return;
    // }
    // int m = (l+r)/2;
    // if (i < m) point_add(2*v+1, l, m, i, x);
    // else point_add(2*v+2, m, r, i, x);
    // upd(v);
// }
// void point_add(int i, int x) { point_add(0, 0, n, i, x); }
// array<int, 2> range_max(int v, int l, int r, int L, int R) {
    // pd(v, l, r);
    // if (r <= L || R <= l) return {inf, inf};
    // if (L <= l && r <= R) return t[v];
    // int m = (l+r)/2;
    // return merge_info(range_max(2*v+1, l, m, L, R), range_max(2*v+2, m, r, L, R));
// }
// array<int, 2> range_max(int L, int R) { return range_max(0, 0, n, L, R); }

// Segment Tree:

const int MAXN = 1e5+1;
namespace sgt {
pair<int, int> T[MAXN * 4];   // {value, sum}
bool L[MAXN * 4];  // set tag

pair<int, int> merge(pair<int, int> l, pair<int, int> r) {
	if (l.s == -LLONG_MAX) { return r; }
	if (r.s == -LLONG_MAX) { return l; }
	return {max(l.f + r.s, r.f), l.s + r.s};
}

void build(int t = 1, int tl = 0, int tr = N - 1) {
	if (tl == tr) {
		T[t].f = T[t].s = -1;
		return;
	}

	int tm = (tl + tr) >> 1;
	build(t << 1, tl, tm);
	build(t << 1 | 1, tm + 1, tr);
	T[t] = merge(T[t << 1], T[t << 1 | 1]);
}

void pushdown(int t, int tl, int tr) {
	if (!L[t]) { return; }
	int tm = (tl + tr) >> 1;
	T[t << 1] = {-1, -(tm - tl + 1)};
	T[t << 1 | 1] = {-1, -(tr - tm)};
	L[t << 1] = L[t << 1 | 1] = 1;
	L[t] = 0;
}

void update_range(int l, int r, int t = 1, int tl = 0, int tr = N - 1) {
	if (r < tl || tr < l) { return; }
	if (l <= tl && tr <= r) {
		T[t] = {-1, -(tr - tl + 1)};
		L[t] = 1;
		return;
	}
	pushdown(t, tl, tr);

	int tm = (tl + tr) >> 1;
	update_range(l, r, t << 1, tl, tm);
	update_range(l, r, t << 1 | 1, tm + 1, tr);
	T[t] = merge(T[t << 1], T[t << 1 | 1]);
}

void update_point(int i, int v, int t = 1, int tl = 0, int tr = N - 1) {
	if (tl == tr) {
		T[t].f += v;
		T[t].s += v;
		return;
	}
	pushdown(t, tl, tr);

	int tm = (tl + tr) >> 1;
	if (i <= tm) {
		update_point(i, v, t << 1, tl, tm);
	} else {
		update_point(i, v, t << 1 | 1, tm + 1, tr);
	}
	T[t] = merge(T[t << 1], T[t << 1 | 1]);
}

pair<int, int> query(int l, int r, int t = 1, int tl = 0, int tr = N - 1) {
	if (r < tl || tr < l) { return {-LLONG_MAX, -LLONG_MAX}; }
	if (l <= tl && tr <= r) { return T[t]; }
	pushdown(t, tl, tr);

	int tm = (tl + tr) >> 1;
	return merge(query(l, r, t << 1, tl, tm),
	             query(l, r, t << 1 | 1, tm + 1, tr));
}
}  // namespace sgt


void calc_sub(int u) {
    for (int v : sons[u]) {
        calc_sub(v);
        sub[u] += sub[v];
    }
}

void init_hld(int u) {
    tin[u] = timer++;
    int heavy = -1;
    for (int v : sons[u]) {
        par[v] = u;
        if (sub[v]*2 >= sub[u]) {
            heavy = v;
            hr[v] = hr[u];
            init_hld(v);
        }
    }
    for (int v : sons[u]) if (v != heavy) {
        hr[v] = v;
        init_hld(v);
    }
    tout[u] = timer;
}

int max_ss(int v) {
    // array<int, 2> res = {inf, inf};
    pair<int, int> res = {-LLONG_MAX, -LLONG_MAX};
    while (v != -1) {
        // res = merge_info(range_max(tin[hr[v]], tin[v]+1), res);
        res = sgt::merge(sgt::query(tin[hr[v]], tin[v]), res);
        v = par[hr[v]];
    }
    // return res[0];
    return res.f;
}

void solve() {
    fill(all(sub), 1);
    par[0] = -1;

    int q; cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int p; cin >> p; p--;
        sons[p].pb(i+1);
    }
    // init_tree();
    sgt::build();
    calc_sub(0);
    init_hld(0);

    for (int i = 0; i < q; i++) {
        int tp, v; cin >> tp >> v; v--;
        if (tp == 1) {
            // point_add(tin[v], 1);
            sgt::update_point(tin[v], 1);
        } else if (tp == 2) {
            // range_set(tin[v], tout[v], -1);
            sgt::update_range(tin[v], tout[v]-1);
            int mx = max_ss(v);
            // if (mx >= 0) point_add(tin[v], -mx-1);
            if (mx >= 0) sgt::update_point(tin[v], -mx-1);
        } else {
            int mx = max_ss(v); 
            cout << (mx >= 0 ? "black" : "white") << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

