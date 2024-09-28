#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

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
V<array<array<int, 2>, 2>> dp;

void calc_dp(int u, int p) {
    bool leaf = true;
    for (int v : g[u]) if (v != p) {
        leaf = false;
        calc_dp(v, u);
        ckmin(dp[u][1][1], dp[u][0][1]+dp[v][1][1]);
        ckmin(dp[u][0][1], dp[u][1][1]+dp[v][0][1]+3);
        ckmin(dp[u][1][0], dp[u][1][0]+dp[v][1][0]);
    }
    if (leaf) {
        dp[]
    }
}

void solve() {
    int n; cin >> n;
    g.resize(n);
    dp.resize(n, {inf, inf});
    string s; cin >> s;
    calc_dp(0, -1);

    cout << min(dp[0][1][0], dp[0][1][1]) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
