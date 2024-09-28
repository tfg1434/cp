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

int C2(int n) {
    return n*(n-1)/2;
}

void solve() {
    int n, m; cin >> n >> m;
    V<bool> in_seg(n), is_l(n), is_r(n+1);
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r; l--;
        for (int j = l; j < r; j++) in_seg[j] = true;
        is_l[l] = is_r[r] = true;
        // a[l] = r;
    }

    vector dp(n+1, V<vi>(2, vi(n+1, -inf)));
    dp[0][0][0] = 0;
    // dp(i, started placing 1s?, #(1s placed)) = max number of 10 pairs
    for (int i = 0; i < n; i++) {
        for (int cnt = 0; cnt <= i; cnt++) {
            if (in_seg[i] && !is_r[i]) {
                // place a 1
                ckmax(dp[i+1][1][cnt+1], dp[i][1][cnt]);
            }
            if (is_r[i]) {
                // place a 0
                ckmax(dp[i+1][0][cnt], dp[i][1][cnt]+cnt);
            }
            if (is_r[i] && !is_l[i]) {
                // place a 1
                ckmax(dp[i+1][0][cnt+1], dp[i][1][cnt]);
            }

            // you cannot place a 0 on before the right border of a segment
            if (!is_r[i+1]) {
                // place a 0
                ckmax(dp[i+1][0][cnt], dp[i][0][cnt]+cnt);
            }
            // you cannot place a 1 on the first cell of a segment
            if (!is_l[i]) {
                // place a 1
                ckmax(dp[i+1][in_seg[i]][cnt+1], dp[i][0][cnt]);
            }
        }
    }

    int ans = 0;
    for (int cnt = 0; cnt <= n; cnt++) {
        for (int started = 0; started < 2; started++) {
            ckmax(ans, dp[n][started][cnt]+C2(cnt)+C2(n-cnt));
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}


