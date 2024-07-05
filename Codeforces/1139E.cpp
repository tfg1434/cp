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

V<vi> g;
V<bool> vis;
vi match;

bool kuhn(int v) {
    if (vis[v]) return false;
    vis[v] = true;
    for (int to : g[v]) if (match[to] == -1 || kuhn(match[to])) {
        match[to] = v;
        return true;
    }
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    vi p(n), c(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    int mx = *max_element(all(p));

    g.resize(mx+1);
    match.assign(m, -1);

    for (int i = 0; i < n; i++) {
        cin >> c[i]; c[i]--;
    }
    int mex = 0;
    int q; cin >> q;
    vi queries(q);
    V<bool> interesting(n);
    for (int i = 0; i < q; i++) {
        int v; cin >> v; v--;
        interesting[v] = true;
        queries[i] = v;
    }
    for (int i = 0; i < n; i++) if (!interesting[i]) {
        g[p[i]].pb(c[i]);
    }

    vi ans(q);
    for (int i = q-1; i >= 0; i--) {
        while (mex <= mx) {
            vis.assign(mx+1, false);
            if (kuhn(mex)) mex++;
            else break;
        }
        ans[i] = mex;
        int v = queries[i];
        g[p[v]].pb(c[v]);
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
