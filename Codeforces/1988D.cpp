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

const int N = 3e5, ROUNDS = 30;
int a[N], dp[N][ROUNDS], pre[N][ROUNDS+1], suf[N][ROUNDS], n;
vi g[N];

void calc_dp(int u, int p) {
    for (int v : g[u]) if (v != p) {
        calc_dp(v, u);
    }
    for (int r = 0; r < ROUNDS; r++) {
        int cost = (r+1)*a[u];
        for (int v : g[u]) if (v != p) {
            cost += min(pre[v][r], r+1 == ROUNDS ? inf : suf[v][r+1]);
        }

        ckmin(dp[u][r], cost);
    }

    fill(all(pre[u]), inf);
    for (int r = 0; r < ROUNDS; r++) {
        pre[u][r+1] = min(pre[u][r], dp[u][r]);
    }
    for (int r = ROUNDS-1; r >= 0; r--) {
        suf[u][r] = min(r+1 == ROUNDS ? inf : suf[u][r+1], dp[u][r]);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i] = 0;
        g[i].clear();
        for (int j = 0; j < ROUNDS; j++) {
            dp[i][j] = inf;
        }
    }
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++){ 
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }

    calc_dp(0, -1);
    cout << pre[0][ROUNDS] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
