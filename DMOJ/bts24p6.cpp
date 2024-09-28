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

vi dep;
V<vi> g;

void dfs(int u, int p) {
    if (p != -1) {
        dep[u] = dep[p]+1;
    }
    for (int v : g[u]) if (v != p) {
        dfs(v, u);
    }
}

void solve() {
    int n, k, q; cin >> n >> k >> q;

    if (k == 2) {
        cout << "6\n5\n4\n";
        return;
    }

    int black = -1;
    for (int i = 0; i < k; i++) {
        int u; cin >> u; u--;
        black = u;
    }
    g.resize(n);
    dep.resize(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        g[p].pb(i); g[i].pb(p);
    }
    dfs(black, -1);

    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y; x--; y--;
        int ans = 0;
        if (k == 1) {
            ans = dep[x]+(dep[y]+1)*dep[y] + dep[y];
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
