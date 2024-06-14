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

const int N = 3e5;
int sub[N];
bool del[N];
V<array<int, 2>> g[N];
vi mn[N], centers[N];

void calc_sub(int u, int p) {
    sub[u] = 1;
    for (auto [v, w] : g[u]) if (v != p && !del[v]) {
        calc_sub(v, u);
        sub[u] += sub[v];
    }
}

int find_center(int u, int p, int siz) {
    for (auto [v, w] : g[u]) if (v != p && !del[v]) {
        if (2*sub[v] >= siz) return find_center(v, u, siz);
    }
    return u;
}

void process_ctd(int u, int p, int center, int min_w) {
    mn[u].pb(min_w);
    centers[u].pb(center);
    for (auto [v, w] : g[u]) if (v != p && !del[v]) {
        process_ctd(v, u, center, min(min_w, w));
    }
}

void cd(int u) {
    calc_sub(u, -1);
    int center = find_center(u, -1, sub[u]);
    process_ctd(center, -1, center, inf);
    del[center] = true;
    for (auto [v, w] : g[center]) if (!del[v]) {
        cd(v);
    }
}

void solve() {
    int n, _; cin >> n >> _;    

    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].pb({v, w}); g[v].pb({u, w});
    }
    fill(all(sub), 1);
    cd(0);
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v; u--; v--;
        int lvl = 0;
        while (lvl+1 < centers[u].size() && 
                lvl+1 < centers[v].size() && 
                centers[u][lvl+1] == centers[v][lvl+1]) {
            lvl++;
        }
        cout << min(mn[u][lvl], mn[v][lvl]) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
