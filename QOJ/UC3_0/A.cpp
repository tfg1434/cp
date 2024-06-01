#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

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

const int max_n = 50, max_c = 1e5;

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vi dp(max_n*max_c, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        auto DP = dp;
        dp.assign(dp.size(), inf);
        for (int j = 0; j < dp.size(); j++) if (DP[j] < inf) {
            ckmin(dp[j+a[i]], DP[j]);
            ckmin(dp[j], DP[j]+b[i]);
        }
    }

    int ans = inf;
    for (int j = 0; j < dp.size(); j++) ckmin(ans, max(j, dp[j]));
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
