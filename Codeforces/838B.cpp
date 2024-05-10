// from U TO V not from V TO U

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int INF = 2e18;

int n, q;
const int max_n = 2e5;
const int max_time = 2*max_n;
vector<array<int, 2>> g[max_n];
int src[max_n], dest[max_n], a[max_n], b[max_n], dis[max_n], tin[max_n], tout[max_n];
int node_when[max_time];

int timer;
void dfs(int u) {
    node_when[timer] = u;
    tin[u] = timer++;
    for (auto [w, v] : g[u]) {
        dis[v] = dis[u]+w;
        a[v] = w;
        dfs(v);
    }
    tout[u] = timer;
}


vector<int> t, buf;
void build(int v, int l, int r) {
    if (l == r-1) {
        t[v] = dis[node_when[l]] + b[node_when[l]];
        return;
    }
    int m = (l+r)/2;
    build(2*v+1, l, m);
    build(2*v+2, m, r);
    t[v] = min(t[2*v+1], t[2*v+2]);
}
void pd(int v) {
    if (buf[v] != 0) {
        t[v] += buf[v];
        if (2*v+2 < buf.size()) {
            buf[2*v+1] += buf[v];
            buf[2*v+2] += buf[v];
        }
        buf[v] = 0;
    }
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
    t[v] = min(t[2*v+1], t[2*v+2]);
}
int range_min(int v, int l, int r, int L, int R) {
    pd(v);
    if (r <= L || R <= l) return INF;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return min(range_min(2*v+1, l, m, L, R), range_min(2*v+2, m, r, L, R));
}
void range_add(int L, int R, int x) {
    range_add(0, 0, max_time, L, R, x);
}
int range_min(int L, int R) {
    return range_min(0, 0, max_time, L, R);
}
int Get(int u) {
    return range_min(tin[u], tin[u]+1);
}
void init_tree() {
    int size = 1;
    while (size < 2*max_time) size *= 2;
    t.resize(size);
    buf.resize(size);
    build(0, 0, max_time);
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].push_back({w, v});
        a[v] = w;
        dest[i] = v;
    }
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        if (u != 0) swap(u, v);
        b[v] = w;
        src[i] = v;
    }

    dfs(0);
    init_tree();

    for (int _ = 0; _ < q; _++) {
        int tp; cin >> tp;
        if (tp == 1) {
            int i, w; cin >> i >> w; i--;
            if (i < n-1) {
                int u = dest[i];
                range_add(tin[u], tout[u], w-a[u]);
                a[u] = w;
            } else {
                i -= n-1;
                int u = src[i];
                range_add(tin[u], tin[u]+1, w-b[u]);
                b[u] = w;
            }
        } else {
            int u, v; cin >> u >> v; u--; v--;
            if (tin[u] <= tin[v] && tout[v] <= tout[u]) {
                cout << Get(v)-b[v]-(Get(u)-b[u]) << '\n';
                continue;
            }

            int mn = range_min(tin[u], tout[u]) - (Get(u)-b[u]);
            cout << mn+Get(v)-b[v] << '\n';
        }
    }
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(0);
    solve();
}


