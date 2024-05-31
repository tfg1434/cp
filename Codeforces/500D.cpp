#include <bits/stdc++.h>
using namespace std;
using db = long double;
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

const int max_n = 1e5;
int n, lvl[max_n], q, sub[max_n], ssd[max_n];
db f[max_n];
array<int, 3> edges[max_n];
V<array<int, 2>> g[max_n];

void precalc(int u, int p) {
    if (p != -1) lvl[u] = lvl[p]+1;
    for (auto [w, v] : g[u]) if (v != p) {
        precalc(v, u);
        sub[u] += sub[v];
        ssd[u] += sub[v]*w+ssd[v];
    }
}
void calc_f(int u, int p, int super) {
    int tot = 0;
    for (auto [w, v] : g[u]) if (v != p) 
        tot += ssd[v]+sub[v]*w;
    f[u] = tot + super;
    for (auto [w, v] : g[u]) if (v != p) {
        int new_super = super+tot-(ssd[v]+sub[v]*w) + w*(n-sub[v]);
        calc_f(v, u, new_super);
    }
}

void solve() {
    cin >> n; 
    for (int i = 0; i < n; i++) sub[i] = 1;
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].pb({w, v}); g[v].pb({w, u});
        edges[i] = {w, u, v};
    }

    precalc(0, -1);
    calc_f(0, -1, 0);

    db ans = 0, factor = 3.L/n/(n-1);
    for (int i = 0; i < n; i++) ans += f[i];
    cin >> q;
    for (int i = 0; i < q; i++) {
        int r, w; cin >> r >> w; r--;
        auto [W, u, v] = edges[r];
        if (lvl[u] < lvl[v]) swap(u, v);
        int n1 = sub[u], n2 = n-n1;
        ans += 1.L*n1*n2*2*(w-W);
        edges[r][0] = w;
        cout << fixed << setprecision(6) << factor*ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
