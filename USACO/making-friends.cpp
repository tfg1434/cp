#include <bits/stdc++.h>
using namespace std;
#define int int64_t

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

void solve() {
    int n, m; cin >> n >> m;
    V<set<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].insert(v); g[v].insert(u);
    }

    int ans = 0;
    for (int u = 0; u < n; u++) if (!g[u].empty()) {
        int min_nei = *g[u].begin();
        for (int v : g[u]) {
            g[v].erase(u);
        }
        g[u].erase(min_nei); g[min_nei].erase(u);

        if (g[u].size() <= g[min_nei].size()) {
            for (int v : g[u]) if (!g[min_nei].count(v)) {
                // ps(u+1, v+1, min_nei+1);
                g[min_nei].insert(v);
                g[v].insert(min_nei);
                ans++;
            }
        } else {
            int inter = 0;
            for (int v : g[min_nei]) {
                inter += g[u].count(v);
            }
            ans += g[u].size() - inter;
            for (int v : g[min_nei]) {
                g[u].insert(min_nei);
            }
            swap(g[u], g[min_nei]);
            g[u].clear();
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
