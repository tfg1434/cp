// Reading doubles can be extremely slow because c++ is initializing some buffers
// or doing some other behind-the-scenes stuff; this was the source of TLE
// scanf/printf can be faster in some cases, but you need to change everything
// or it has a null (or negative) impact
// Remove fastIO before scanf, use %d for int, %lf for double
// setprecision will round to the nearest value

#include <bits/stdc++.h>
using namespace std;
using db = double;

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
db sum_sons[max_n], p[max_n], sum;
vi g[max_n];

void dfs(int u, int fa) {
    par[u] = fa;
    for (int v : g[u]) if (v != fa) {
        dfs(v, u);
        sum_sons[u] += 1-p[v];
    }
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lf", &p[i]);
    for (int i = 0; i < n-1; i++) {
        int u, v; scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }
    n++;
    g[0].pb(n-1); g[n-1].pb(0); 
    p[n-1] = 1;
    dfs(n-1, -1);
    for (int i = 0; i < n; i++) sum += p[i]*sum_sons[i];

    int q; scanf("%d", &q);
    while (q--) {
        int u; db new_p; 
        scanf("%d%lf", &u, &new_p);

        sum -= p[par[u]]*sum_sons[par[u]];
        sum -= p[u]*sum_sons[u];
        sum_sons[par[u]] -= 1-p[u]; 
        p[u] = new_p;
        sum_sons[par[u]] += 1-p[u]; 
        sum += p[u]*sum_sons[u];
        sum += p[par[u]]*sum_sons[par[u]];

        printf("%.4lf\n", sum);
    }
}

signed main() {
    solve();
    return 0;
}
