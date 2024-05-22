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

const int max_n = 3e5;
array<int, 2> dp[max_n][2];
int n, k;
vi a;
// returns {score, number of segments} with penalty lmb for making a new subarray
array<int, 2> calc(int lmb) {
    memset(dp, 0, sizeof dp);
    // V<V<array<int, 2>>> dp(n, V<array<int, 2>>(2));
    dp[0][1] = {a[0]-lmb, 1};
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = max(array<int, 2>{ dp[i-1][0][0]+a[i]-lmb, dp[i-1][0][1]+1 },
                       array<int, 2>{ dp[i-1][1][0]+a[i],     dp[i-1][1][1] });
    }
    return max(dp[n-1][0], dp[n-1][1]);
}

void solve() {
    cin >> n >> k;
    a.resize(n); for (int i = 0; i < n; i++) cin >> a[i];

    int lo = -1, hi = 1e18;
    while (hi-lo > 1) {
        int m = (lo+hi)/2;
        auto res = calc(m);
        res[1] >= k ? lo = m : hi = m;
    }
    if (lo == -1) {
        cout << calc(0)[0] << '\n';
        return;
    }
    auto ans = calc(lo);
    cout << ans[0]+lo*k << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
