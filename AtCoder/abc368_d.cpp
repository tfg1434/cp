#include <bits/stdc++.h>
using namespace std;

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
    int n, k; cin >> n >> k;
    V<set<int>> g(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].insert(v); g[v].insert(u);
    }
    V<bool> keep(n);
    for (int i = 0; i < k; i++) {
        int u; cin >> u; u--; keep[u] = true;
    }

    vi leaves;
    for (int u = 0; u < n; u++) {
        if (g[u].size() == 1) {
            leaves.pb(u);
        }
    }

    while (!leaves.empty()) {
        int u = leaves.back(); leaves.pop_back();
        if (keep[u]) continue;
        int v = *g[u].begin();
        g[v].erase(u);
        n--;
        
        if (g[v].size() == 1) {
            leaves.pb(v);
        }
    }

    cout << n << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
