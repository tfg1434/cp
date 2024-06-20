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

int c2(int x) { return x*(x-1)/2; }

const int N = 5e4;
int w[N], par[N], n;
bool a[N];
vi g[N];

void dfs(int u, int p) {
    par[u] = p;
    w[u] = a[u];
    for (int v : g[u]) if (v != p) {
        dfs(v, u);
        w[u] += w[v];
    }
}

void solve() {
    int q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int bw; cin >> bw;
        a[i] = bw;
    } 
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }

    dfs(0, -1);
    while (q--) {
        int tp, u; cin >> tp >> u; u--;
        if (tp == 1) {
            while (u != -1) {
                a[u] = !a[u];
                u = par[u];
            }

        } else {
            dfs(0, -1);
            int ans = c2(w[u]);
            for (int v : g[u]) if (v != par[u]) {
                ans -= c2(w[v]);
            }
            cout << ans << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

