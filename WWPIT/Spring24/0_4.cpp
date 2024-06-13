// stable <==> no bridges

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
bool bridge, vis[max_n];
int up[max_n], lvl[max_n];
array<int, 3> edges[max_n];
void find_bridges(int u, int p) {
    if (p != -1) {
        lvl[u] = lvl[p]+1;
    }
    vis[u] = true;
    for (int v : g[u]) if (v != p) {
        if (vis[v]) {
            ckmin(up[u], lvl[v]);
        } else {
            find_bridges(v, u);
            ckmin(up[u], up[v]);
        }
    }
    if (u) bridge |= up[u] >= lvl[u];
}

void solve() {
    int n, m; cin >> n >> m;
    if (n == 1) while (true) {}
    for (int i = 0; i < m; i++) {
        int u, v, t; cin >> u >> v >> t; u--; v--;
        edges[i] = {t, u, v};
    }
    sort(rall(edges));

    // add first c edges (the c edges which have the largest t)
    // is there a bridge 
    int cc_count;
    auto check = [&](int c) {
        cc_count = 0;
        bridge = false;
        memset(lvl, 0, sizeof lvl);
        fill(all(vis), false);
        fill(all(up), inf);
        for (int i = 0; i < n; i++) g[i].clear();
        for (int i = 0; i < c; i++) {
            auto [t, u, v] = edges[i];
            g[u].pb(v); g[v].pb(u);
        }
        for (int i = 0; i < n; i++) if (!vis[i]) {
            find_bridges(i, -1);
            cc_count++;
        }
        return bridge;
    };

    if (check(m)) {
        cout << 0 << '\n';
        return;
    }
    int CC_COUNT = cc_count;
    int lo = 0, hi = m+1;
    while (hi-lo > 1) {
        int mi = (lo+hi)/2;
        check(mi);
        // ps(bridge, mi, cc_count, CC_COUNT);
        (!bridge && cc_count == CC_COUNT) ? hi = mi : lo = mi;
    }
    cout << edges[hi-1][0] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
