// HLD for info on nodes
// https://www.hackerrank.com/challenges/subtrees-and-paths/problem

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
vi g[max_n];
int hr[max_n], par[max_n], sub[max_n];
int tin[max_n], tout[max_n], timer;
int n, w[max_n];

vi t, buf;
void pd(int v) {
    t[v] += buf[v];
    if (2*v+2 < buf.size()) {
        buf[2*v+1] += buf[v];
        buf[2*v+2] += buf[v];
    }
    buf[v] = 0;
}
void init_tree() {
    int size = 1; 
    while (size < 2*n) size *= 2;
    t.resize(size);
    buf.resize(size);
}
void range_add(int v, int l, int r, int L, int R, int x) {
    pd(v);
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
        buf[v] = x;
        pd(v);
        return;
    }
    int m = (l+r)/2;
    range_add(2*v+1, l, m, L, R, x);
    range_add(2*v+2, m, r, L, R, x);
    t[v] = max(t[2*v+1], t[2*v+2]);
}
void range_add(int L, int R, int x) { range_add(0, 0, n, L, R, x); }
int range_max(int v, int l, int r, int L, int R) {
    pd(v);
    if (r <= L || R <= l) return -inf;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return max(range_max(2*v+1, l, m, L, R), range_max(2*v+2, m, r, L, R));
}
int range_max(int L, int R) { return range_max(0, 0, n, L, R); }

void calc_sub(int u, int p) {
    for (int v : g[u]) if (v != p) {
        calc_sub(v, u);
        sub[u] += sub[v];
    }
}
void init_hld(int u, int p) {
    tin[u] = timer++;
    par[u] = p;
    int heavy = -1;
    for (int v : g[u]) if (v != p) {
        if (sub[v]*2 >= sub[u]) {
            heavy = v;
            hr[v] = hr[u];
            init_hld(v, u);
        } 
    }
    for (auto v : g[u]) if (v != p && v != heavy) {
        hr[v] = v;
        init_hld(v, u);
    }
    tout[u] = timer;
}
bool is_anc(int u, int v) { 
    if (u == -1) return true;
    if (v == -1) return false;
    return tin[u] <= tin[v] && tout[v] <= tout[u]; 
}

int vertical_path_max(int u, int v, bool exclusive) {
    int res = -inf;
    while (u != -1) {
        if (is_anc(hr[u], v)) {
            ckmax(res, range_max(tin[v]+exclusive, tin[u]+1));
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
    return max(vertical_path_max(u, lca, true), vertical_path_max(v, lca, false));
}

void solve() {
    cin >> n; 
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }

    fill(all(sub), 1);

    calc_sub(0, -1);
    init_hld(0, -1);
    init_tree();

    int q; cin >> q;
    while (q--) {
        string tp; cin >> tp;
        if (tp == "add") {
            int v, x; cin >> v >> x; v--;
            range_add(0, 0, n, tin[v], tout[v], x);
        } else {
            int u, v; cin >> u >> v; u--; v--;
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
