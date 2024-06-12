// both .c++ and cc are correct. mine, vs RC

#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

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

const int max_n = 1e5;
V<array<int, 2>> g[max_n];
int sz[max_n], hr[max_n], par[max_n], sub[max_n];
int par_edge_ind[max_n], vertex_by_edge[max_n];
int tin[max_n], tout[max_n], euler[max_n], timer;
int n, w[max_n];

vi t;
void build(int v, int l, int r) {
    if (l == r-1) {
        t[v] = w[par_edge_ind[euler[l]]];
        return;
    }
    int m = (l+r)/2;
    build(2*v+1, l, m);
    build(2*v+2, m, r);
    t[v] = max(t[2*v+1], t[2*v+2]);
}
void init_tree() {
    int size = 1; 
    while (size < 2*n) size *= 2;
    t.assign(size, -inf);
    build(0, 1, n);
}
void point_set(int v, int l, int r, int i, int x) {
    if (l == r-1) {
        t[v] = x;
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_set(2*v+1, l, m, i, x);
    else point_set(2*v+2, m, r, i, x);
    t[v] = max(t[2*v+1], t[2*v+2]);
}
void point_set(int i, int x) { point_set(0, 1, n, i, x); }
int range_max(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return -inf;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return max(range_max(2*v+1, l, m, L, R), range_max(2*v+2, m, r, L, R));
}
int range_max(int L, int R) { return range_max(0, 1, n, L, R); }

void calc_sub(int u, int p) {
    for (auto [v, i] : g[u]) if (v != p) {
        calc_sub(v, u);
        sub[u] += sub[v];
    }
}
void init_hld(int u, int p) {
    euler[timer] = u;
    tin[u] = timer++;
    par[u] = p;
    int heavy = -1;
    for (auto [v, i] : g[u]) if (v != p) {
        vertex_by_edge[i] = v;
        par_edge_ind[v] = i;
        if (sub[v]*2 >= sub[u] && u != 0) {
            heavy = v;
            hr[v] = hr[u];
            init_hld(v, u);
        } 
    }
    for (auto [v, i] : g[u]) if (v != p && v != heavy) {
        hr[v] = v;
        init_hld(v, u);
    }
    tout[u] = timer;
}
bool is_anc(int u, int v) { return tin[u] <= tin[v] && tout[v] <= tout[u]; }
int vertical_path_max(int u, int v) {
    int res = -inf;
    while (u != v && u != 0) {
        if (is_anc(hr[u], v)) {
            ckmax(res, range_max(tin[v]+1, tin[u]+1));
            break;
        }
        ckmax(res, range_max(tin[hr[u]], tin[u]+1));
        u = par[hr[u]];
    }
    return res;
}
int path_max(int u, int v) {
    int U = u, V = v;
    while (!is_anc(U, v)) U = par[hr[U]];
    while (!is_anc(V, u)) V = par[hr[V]];
    int lca = is_anc(U, V) ? V : U;
    return max(vertical_path_max(u, lca), vertical_path_max(v, lca));
}

void solve() {
    cin >> n; 
    for (int i = 1; i <= n-1; i++) {
        int u, v; cin >> u >> v >> w[i];
        g[u].pb({v, i}); g[v].pb({u, i});
    }
    n++;
    g[0].pb({1, 0}); g[1].pb({0, 0});

    fill(all(sub), 1);

    calc_sub(0, -1);
    init_hld(0, -1);
    init_tree();

    int q; cin >> q;
    while (q--) {
        int tp; cin >> tp;
        if (tp == 2) {
            int ind, x; cin >> ind >> x;
            w[ind] = x;
            point_set(0, 0, n, tin[vertex_by_edge[ind]], x);
        } else {
            int u, v; cin >> u >> v;
            cout << path_max(u, v) << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
