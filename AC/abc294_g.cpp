#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int max_n = 2e5;
vector<array<int, 3>> g[max_n];
int n, q;
const int max_time = 2*max_n;
int a[max_time];
vector<int> t;
void build(int v, int l, int r) {
    if (l == r-1) {
        t[v] = a[l];
        return;
    }
    int m = (l+r)/2;
    build(2*v+1, l, m);
    build(2*v+2, m, r);
    t[v] = t[2*v+1] + t[2*v+2];
}
int range_sum(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return range_sum(2*v+1, l, m, L, R) + range_sum(2*v+2, m, r, L, R);
}
void point_set(int v, int l, int r, int i, int x) {
    if (l == r-1) {
        t[v] = x;
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_set(2*v+1, l, m, i, x);
    else point_set(2*v+2, m, r, i, x);
    t[v] = t[2*v+1] + t[2*v+2];
}
void init_tree() {
    int size = 1;
    while (size < 2*max_time) size *= 2;
    t.resize(size);
    build(0, 0, max_time);
}

array<int, 2> where[max_n];
int ST[max_n], EN[max_n];
int tour;
void dfs(int u, int p) {
    ST[u] = tour;
    for (auto [w, v, ind] : g[u]) if (v != p) {
        where[ind][0] = tour;
        a[tour++] = w;
        dfs(v, u);
        where[ind][1] = tour;
        a[tour++] = -w;
    }
    
    EN[u] = tour;
}

int lvl[max_n];
int lift[18][max_n];
void precalc_dfs(int u, int p) {
    if (p != -1) {
        lvl[u] = lvl[p]+1;
        lift[0][u] = p;
    }
    for (auto [w, v, ind] : g[u]) if (v != p) {
        precalc_dfs(v, u);
    }
}
void precalc_lca() {
    precalc_dfs(0, -1);
    for (int j = 1; j < 18; j++) for (int i = 0; i < n; i++)
        lift[j][i] = lift[j-1][lift[j-1][i]];
}
int lca(int u, int v) {
    if (lvl[u] > lvl[v]) swap(u, v);
    for (int j = 17; j >= 0; j--) if ((lvl[v]-lvl[u]) & (1 << j))
        v = lift[j][v];
    if (u == v) return u;
    for (int j = 17; j >= 0; j--) if (lift[j][u] != lift[j][v])
        u = lift[j][u], v = lift[j][v];
    return lift[0][u];
}

void solve() {
    cin >> n;
    if (n == 1) {
        cin >> q;
        while (q--) {
            int tp, _, __; cin >> tp >> _ >> __;
            if (tp == 2) cout << 0 << '\n';
        }
        return;
    }

    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].push_back({w, v, i}); g[v].push_back({w, u, i});
    }
    precalc_lca();
    dfs(0, -1);
    init_tree();

    cin >> q;
    for (int _ = 0; _ < q; _++) {
        int tp; cin >> tp;
        if (tp == 1) {
            int i, w; cin >> i >> w; i--;
            point_set(0, 0, max_time, where[i][0], w);
            point_set(0, 0, max_time, where[i][1], -w);
        } else {
            int u, v; cin >> u >> v; u--; v--;
            if (lvl[u] > lvl[v]) swap(u, v);
            int lc = lca(u, v);
            if (lc == u) {
                cout << range_sum(0, 0, max_time, ST[u], ST[v]) << '\n';
            } else {
                int res = 0;
                res += range_sum(0, 0, max_time, ST[lc], ST[u]);
                res += range_sum(0, 0, max_time, ST[lc], ST[v]);
                cout << res << '\n';
            }
        }
    }
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(0);
    solve();
}


