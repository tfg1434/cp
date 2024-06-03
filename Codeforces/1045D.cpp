#include <bits/stdc++.h>
using namespace std;
using db = long double;

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

const int max_n = 1e5+1;
int par[max_n], n, q;
db cont[max_n], p[max_n], sum;
vi g[max_n];

void dfs(int u, int fa) {
    par[u] = fa;
    for (int v : g[u]) if (v != fa) {
        dfs(v, u);
        cont[u] += 1-p[v];
    }
    cont[u] *= p[u];
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    g[0].pb(n); g[n].pb(0);
    p[n] = 1;
    dfs(n, -1);
    for (int i = 0; i <= n; i++) sum += cont[i];

    cin >> q;
    while (q--) {
        int u; db new_p; cin >> u >> new_p;
        db delta = new_p - p[u];

        sum += p[par[u]]*(p[u]-new_p);
        cont[par[u]] += p[par[u]]*(p[u]-new_p);
        auto old_cont = cont[u];
        if (p[u] > 0) cont[u] *= new_p / p[u];
        sum += cont[u]-old_cont;

        p[u] = new_p;
        // for (int i = 0; i <= n; i++) cout << cont[i] << " \n"[i==n];

        cout << sum << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(4);
    solve();
    return 0;
}
