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

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    V<vi> dp(n, vi(n+1, inf));
    for (int i = 0; i < n; i++) dp[i][i+1] = 0;

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l+len <= n; l++) {
            int r = l+len;
            for (int i = 0; i < n; i++) {
                int worst = 0;
                // teleport succeeds
                {
                    int L = max(l, 2*i-n+1);
                    int R = min(r, 2*i + 1);
                    if (L < R) ckmax(worst, a[i]+dp[L][R]);
                }
                // teleport fails b/c treasure is too far right
                {
                    int L = max(l, 2*i+1);
                    if (L < r) ckmax(worst, a[i]+dp[L][r]);
                }
                // too far left
                {
                    int R = min(r, 2*i-n+1);
                    if (l < R) ckmax(worst, a[i]+dp[l][R]);
                }

                assert(worst != 0);
                ckmin(dp[l][r], worst);
            }
            ps(l, r, dp[l][r]);
        }
    }

    cout << dp[0][n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
