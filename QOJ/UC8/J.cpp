#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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

int timer, n;
vi tin, tout, sub, euler, hr, par_edge_w, par;
V<bool> is_mst_edge;
V<V<array<int, 3>>> g;


V<array<int, 2>> t;
array<int, 2> merge(array<int, 2> a, array<int, 2> b) {
    return {max(a[0], b[0]), max(a[1], b[1])};
}
void pull(int v) {
    t[v] = merge(t[2*v+1], t[2*v+2]);
}
void build(int v=0, int l=0, int r=n) {
    if (l == r-1) {
        int w = par_edge_w[euler[l]];
        t[v][w%2] = w;
        return;
    }
    int m = (l+r)/2;
    build(2*v+1, l, m);
    build(2*v+2, m, r);
    pull(v);
}
array<int, 2> range_max(int L, int R, int v=0, int l=0, int r=n) {
    if (r <= L || R <= l) return {0, 0};
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return merge(range_max(L, R, 2*v+1, l, m), range_max(L, R, 2*v+2, m, r));
}
void init_tree() {
    int siz = 1;
    while (siz < 2*n) siz *= 2;
    t.resize(siz);
    build();
}

void precalc(int u, int p) {
    par[u] = p;
    sub[u] = 1;
    for (auto [v, w, i] : g[u]) if (is_mst_edge[i] && v != p) {
        par_edge_w[v] = w;
        sub[u] += sub[v];
    }
}
void hld(int u, int p) {
    euler[timer] = u;
    tin[u] = timer++;
    int hc = -1;
    for (auto [v, w, i] : g[u]) if (is_mst_edge[i] && v != p && 2*sub[v] >= sub[u]) {
        hc = v;
        hr[v] = hr[u];
        hld(v, u);
    }
    for (auto [v, w, i] : g[u]) if (is_mst_edge[i] && v != p && v != hc) {
        hr[v] = v;
        hld(v, u);
    }
    tout[u] = timer;
}
bool is_anc(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}
int find_lca(int u, int v) {
    int lc0 = u, lc1 = v;
    while (!is_anc(lc0, v)) lc0 = par[hr[lc0]];
    while (!is_anc(lc1, u)) lc1 = par[hr[lc1]];
    return is_anc(lc0, lc1) ? lc1 : lc0;
}
int vert_path_max(int top, int bot, int pty) {
    int res = 0;
    while (bot != top) {
        if (is_anc(hr[bot], top)) {
            ckmax(res, range_max(tin[top]+1, tin[bot]+1)[pty]);
            break;
        } else {
            ckmax(res, range_max(tin[hr[bot]], tin[bot]+1)[pty]);
            bot = par[hr[bot]];
        }
    }
    return res;
}
int path_max(int u, int v, int pty) {
    int lca = find_lca(u, v);
    return max(vert_path_max(lca, u, pty), vert_path_max(lca, v, pty));
}

vi e;
int find(int u) {
    return e[u] < 0 ? u : e[u]=find(e[u]);
}
void unite(int u, int v) {
    if ((u=find(u)) != (v=find(v))) {
        if (e[u] > e[v]) swap(u, v);
        e[u] += e[v];
        e[v] = u;
    }
}

void solve() {
    int m; cin >> n >> m;    

    e.assign(n, -1);
    timer = 0;
    tin.resize(n);
    tout.resize(n);
    sub.resize(n);
    euler.resize(n);
    hr.assign(n, -1);
    par_edge_w.resize(n); // par_edge_w[0] = 0
    par.resize(n);
    is_mst_edge.assign(m, false);
    g.resize(n);
    for (int i = 0; i < n; i++) g[i].clear();

    V<array<int, 4>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        edges.pb({w, u, v, i});
    }
    sort(all(edges));

    int mst_cost = 0, mst_edges = 0;
    for (auto [w, u, v, i] : edges) {
        if (find(u) != find(v)) {
            mst_cost += w;
            mst_edges++;
            unite(u, v);
            g[u].pb({v, w, i}); g[v].pb({u, w, i});
            is_mst_edge[i] = true;
        }
    }
    if (mst_edges < n-1) {
        cout << "-1 -1\n";
        return;
    }
    precalc(0, -1);
    hld(0, -1);
    init_tree();

    int ans = inf;
    for (auto [w, u, v, i] : edges) if (!is_mst_edge[i]) {
        int mx = path_max(u, v, w%2^1);
        ckmin(ans, mst_cost+w-mx);
    }
    if (ans == inf) ans = -1;
    if (mst_cost%2) cout << ans << ' ' << mst_cost << '\n';
    else cout << mst_cost << ' ' << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
