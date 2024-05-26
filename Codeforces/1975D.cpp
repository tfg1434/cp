#include <bits/stdc++.h>
using namespace std;

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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int n, a, b;
V<vi> g;
vi path, lvl;
bool find_path(int u, int p) {
    if (u == a) {
        path.pb(a);
        return true;
    }
    bool found = false;
    for (int v : g[u]) if (v != p) {
        if (find_path(v, u)) found = true;
    }
    if (found) {
        path.pb(u);
        return true;
    }
    return false;
}
void find_lvl(int u, int p) {
    if (p != -1) {
        lvl[u] = lvl[p]+1;
    }
    for (int v : g[u]) if (v != p) {
        find_lvl(v, u);
    }
}

void solve() {
    cin >> n >> a >> b; a--; b--;
    path.clear();
    g.assign(n, vi());
    lvl.assign(n, 0);

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    // if (n == 1 or 2)...
    find_path(b, -1); reverse(all(path));
    int root = path[path.size()/2];
    find_lvl(root, -1);
    int mx = *max_element(all(lvl));
    cout << path.size()/2 + 2*(n-1) - mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
