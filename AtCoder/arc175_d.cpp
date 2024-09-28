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

int n, k, sum_siz;
V<vi> g;
vi siz, a, all_xs, x, dep;
void precalc(int u, int p) {
    if (p != -1) {
        dep[u] = dep[p]+1;
    }
    for (int v : g[u]) if (v != p) {
        precalc(v, u);
        siz[u] += siz[v];
    }
    sum_siz += siz[u];
}

void label_nodes(int u, int p) {
    for (int v : g[u]) if (v != p) {
        if (siz[v] <= k) {
            x[v] = dep[v];
            k -= siz[v];
        } else {
            x[v] = -dep[v];
        }
        label_nodes(v, u);
    }
}

void solve() {
    cin >> n >> k;
    g.resize(n+1);
    siz.assign(n, 1);
    dep.resize(n);
    x.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }

    precalc(0, -1);
    if (k < n || k > sum_siz) {
        cout << "No\n";
        return;
    }
    k -= n;

    g[0].pb(n); g[n].pb(0);
    label_nodes(n, -1);

    cout << "Yes\n";
    vi ans(n);
    V<array<int, 2>> xu(n);
    for (int i = 0; i < n; i++) xu[i] = {x[i], i};
    sort(all(xu));
    for (int i = 0; i < n; i++) ans[xu[i][1]] = i; //ans[i] = xu[i][1];
    for (int i = 0; i < n; i++) cout << ans[i]+1 << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
