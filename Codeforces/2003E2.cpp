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
    V<array<int, 2>> segs, SEGS;
    vi force(n, -1);
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r; l--;
        segs.pb({l, r});
    }

    if (!m) {
        cout << C2(n) << '\n';
        return;
    }

    sort(all(segs));
    int prv = 0, cur_max_r = 0;
    for (int i = 0; i < m; i++) {
        ckmax(cur_max_r, segs[i][1]);
        if (i+1 == m || cur_max_r <= segs[i+1][0]) {
            // ps(i, prv);
            int min_l = n, max_l = 0, min_r = n, max_r = 0;
            for (int j = prv; j <= i; j++) {
                ckmin(min_l, segs[j][0]);
                ckmax(max_l, segs[j][0]);
                ckmin(min_r, segs[j][1]);
                ckmax(max_r, segs[j][1]);
            }
            if (min_r-max_l < 2) {
                cout << -1 << '\n';
                return;
            }
            SEGS.pb({min_l, max_r});
            for (int j = min_l; j < max_r; j++) {
                if (j <= max_l) force[j] = 0;
                if (j >= min_r-1) force[j] = 1;
            }
            prv = i+1;
        }
    }
    segs = SEGS;
    m = segs.size();
    V<bool> in_seg(n), is_l(n), is_r(n+1);
    for (auto [l, r] : segs) {
        for (int i = l; i < r; i++) in_seg[i] = true;
        is_l[l] = is_r[r] = true;
    }
    // ps(segs);
    // ps(force);

    vector dp(n+1, V<vi>(2, vi(n+1, -inf)));
    dp[0][0][0] = 0;
    // dp(i, started placing 1s?, #(1s placed)) = max number of 10 pairs
    for (int i = 0; i < n; i++) {
        for (int cnt = 0; cnt <= i; cnt++) {
            if (force[i] == 0) {
                ckmax(dp[i+1][0][cnt], max(dp[i][0][cnt], dp[i][1][cnt])+cnt);
                continue;
            }
            if (force[i] == 1) {
                ckmax(dp[i+1][1][cnt+1], max(dp[i][0][cnt], dp[i][1][cnt]));
                continue;
            }

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


