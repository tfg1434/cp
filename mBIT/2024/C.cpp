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

vi col;
V<vi> g;
void color(int u, int p) {
    if (p != -1) {
        col[u] = col[p]^1;
    }
    for (int v : g[u]) if (v != p) {
        color(v, u);
    }
}

void solve() {
    int n; cin >> n;
    int s = 0;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    g.assign(n, vi());
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    col.assign(n, 0);
    color(0, -1);    
    int p = 0;
    for (int i = 0; i < n; i++) if (col[i]) p ^= a[i]&1;
    cout <<  ((p^(s/2 & 1)) == 1 ? "Borgs" : "Orgs") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
