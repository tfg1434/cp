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

const int max_n = 1e5;
vi g[max_n];
int sz[max_n];
int ans;
int n, m, c;

void calc_sz(int u, int p) {
    sz[u] = 1;
    for (int v : g[u]) if (v != p) calc_sz(v, u), sz[u]+=sz[v];
    for (int v : g[u]) if (v != p) ans = min(ans, sz[v]*sz[v]+(n-sz[v])*(n-sz[v]));
}

void solve() {
    cin >> n >> m >> c;    
    for (int i = 0; i < n; i++) {
        g[i].clear();
        sz[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    ans = inf;
    calc_sz(0, -1);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
