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
    int n, m; cin >> n >> m; 
    vi deg(n);
    V<array<int, 3>> e;
    for (int i = 0; i < m; i++) {
        int u, v, t; cin >> u >> v >> t; u--; v--;
        deg[u]++; deg[v]++;
        e.pb({t, u, v});
    }
    sort(all(e));

    for (int i = 0; i < n; i++) if (deg[i] <= 1) {
        cout << "0\n";
        return;
    }
    for (auto [t, u, v] : e) {
        deg[u]--; deg[v]--;
        if (deg[u] <= 1 || deg[v] <= 1) {
            cout << t << '\n';
            return;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
