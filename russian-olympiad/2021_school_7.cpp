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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

const int max_n = 1e5;
array<int, 2> dp[max_n][2];
V<array<int, 2>> g[max_n];
int n, k;

void calc_dp(int u) {
    V<array<int, 4>> sons;
    array<int, 2> tot{};
    for (auto [w, v] : g[u]) {
        calc_dp(v);
        auto mn = min(dp[v][0], dp[v][1]);
        tot[0] += mn[0], tot[1] += mn[1];
        sons.pb({dp[v][0][0]-dp[v][1][0], dp[v][0][1]-dp[v][1][1]-w, v, w});
    }
    sort(all(sons));

    array<int, 2> cur{};
    for (int i = 0; i <= min((int)sons.size(), k); i++) { 
        if (i > 0) {
            int v = sons[i-1][2], w = sons[i-1][3];
            auto mn = min(dp[v][0], dp[v][1]);
            tot[0] -= mn[0], tot[1] -= mn[1];
            cur[0] += dp[v][0][0], cur[1] += dp[v][0][1];
            cur[0]--, cur[1] += w;
        }
        auto& val = i < k ? dp[u][0] : dp[u][1];
        val = min(cur, {cur[0]+tot[0], cur[1]+tot[1]});
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int p, w; cin >> p >> w; p--;
        g[p].pb({w, i});
    }

    // initial dp? zeroes
    calc_dp(0);
    auto ans = *min_element(all(dp[0]));
    cout << -ans[0] << ' ' << ans[1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
