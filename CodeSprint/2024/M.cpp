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

using db = long double;

int n;
const int max_n = 1000;
db p[max_n];
db dp[max_n+1][max_n+1], dp2[max_n+1][max_n+1];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    dp2[0][0] = 1;
    for (int i = 1; i <= n; i++) for (int open = 0; open <= i; open++) {
        if (open > 0) dp2[i][open] += p[i-1]*dp2[i-1][open-1];
        dp2[i][open] += (1-p[i-1])*dp2[i-1][open+1];
        if (open == 0) dp2[i][0] += (1-p[i-1])*dp2[i-1][0];
    }
    // for (int i = 1; i <= n; i++) for (int open = 0; open <= i; open++) {
        // if (open > 0) {
            // db P1 = p[i-1]*dp2[i-1][open-1];
            // db P2 = (1-p[i-1])*dp2[i-1][open+1];
            // if (P1 < eps && P2 < eps) continue;
            // db p1 = P1/(P1+P2), p2 = 1-p1;
            // dp2[i][open] = p1*dp2[i-1][open-1]+p2*dp2[i-1][open+1];
        // } else {
            // db P2 = dp2[i-1][1];
            // db P3 = dp2[i-1][0];
            // if (P2 < eps && P3 < eps) continue;
            // db p2 = P2/(P2+P3), p3 = 1-p2;
            // dp2[i][0] = p2*dp2[i-1][1] + p3*dp2[i-1][0];
        // }
        // ps(i, open, dp2[i][open]);
    // }

    for (int i = 1; i <= n; i++) {
        for (int open = 0; open <= i; open++) {
            if (open > 0) {
                db P1 = p[i-1]*dp2[i-1][open-1];
                db P2 = (1-p[i-1])*dp2[i-1][open+1];
                db p1 = P1/(P1+P2), p2 = 1-p1;
                dp[i][open] = p1*dp[i-1][open-1] + p2*(dp[i-1][open+1]+2);
            } else {
                db P1 = 0;
                db P2 = dp2[i-1][1];
                db P3 = dp2[i-1][0];
                db p2 = P2/(P2+P3), p3 = 1-p2;
                dp[i][open] = p2*(dp[i-1][1]+2) + p3*dp[i-1][0];
            }
        }
    }

    db ans = 0;
    for (int open = 0; open <= n; open++) ans += dp[n][open]*dp2[n][open];
    cout << fixed << setprecision(7) << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
