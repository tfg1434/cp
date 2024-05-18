// AC!!! 笑眯眯

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
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

int n, m, c;
const int max_n = 1e5;
vi g[max_n]; 
V<vi> sizes;
int up[max_n], sub[max_n], lvl[max_n];
bool vis[max_n];

void find_bridges(int u, int p) {
    if (p != -1) lvl[u] = lvl[p]+1;
    vis[u] = true;
    sub[u] = 1;
    for (int v : g[u]) if (v != p) {
        if (vis[v]) {
            up[u] = min(up[u], lvl[v]);
            continue;
        }
        find_bridges(v, u);
        up[u] = min(up[u], up[v]);
        sub[u] += sub[v];
    }
    if (p != -1 && up[u] >= lvl[u]) {
        sizes.back().push_back(sub[u]);
    }
}

void solve() {
    cin >> n >> m >> c; 
    sizes.clear();
    V<bitset<max_n+1>> dp(2);
    for (int i = 0; i < n; i++) {
        vis[i] = false;
        g[i].clear();
        up[i] = inf;
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }

    vi reps;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        sizes.pb(vi());
        reps.pb(i);
        find_bridges(i, -1); 
        auto freeze = sizes.back();
        for (auto size : freeze)
            sizes.back().pb(sub[i]-size);
    }

    dp[0].set(0);
    for (int i = 0; i < reps.size(); i++) {
        auto DP = dp;
        // do nothing is already loaded into dp
        // add entire tree
        for (int flag = 0; flag < 2; flag++) 
            dp[flag] |= DP[flag] << sub[reps[i]];
        // add partial tree, use flag
        for (int size : sizes[i]) 
            dp[1] |= DP[0] << size;
    }

    int min_ss = inf;
    for (int j = 0; j <= n; j++) if (dp[1].test(j)) {
        min_ss = min(min_ss, j*j+(n-j)*(n-j));
    }
    // you can choose not to split a tree iff >1 CC
    if (reps.size() > 1) {
        for (int j = 0; j <= n; j++) if (dp[0].test(j)) {
            min_ss = min(min_ss, j*j+(n-j)*(n-j));
        }
    }

    if (min_ss == inf) {
        cout << -1 << '\n';
        return;
    }
    cout << (reps.size()-1)*c + min_ss << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
