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

const int N = 1e5;
int dep[N], at[N];
vi g[N];

int c2(int n) { return n*(n-1)/2; }

void dfs(int u, int p) {
    if (p != -1) {
        dep[u] = dep[p]+1;
    }
    at[dep[u]]++;
    for (int v : g[u]) if (v != p) {
        dfs(v, u);
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        at[i] = 0;
        dep[i] = 0;
        g[i].clear();
    }
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(0, -1);

    int ans = 0;
    vi sum(2);
    for (int i = 0; i < n; i++) sum[i%2] += at[i];
    ans = c2(sum[0]) + c2(sum[1]);

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

