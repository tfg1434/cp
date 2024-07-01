// O(n^4)

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

const int N = 100;
int dp[N+1][N+1][N/2+1];

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;

    for (int l = 0; l <= n; l++) {
        for (int r = 0; r <= n; r++) {
            for (int k = 0; k <= n/2; k++) {
                dp[l][r][k] = 0;
            }
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l+len <= n; l++) {
            int r = l+len;
            for (int k = 0; k <= l/2; k++) {
                dp[l][r][k] = dp[l+1][r][k];
                if (a[l] > l || a[l]%2 != l%2 || (l-a[l])/2 < k) continue;

                for (int m = l+1; m < r; m += 2) {
                    if (dp[l+1][m][k] < (m-l-1)/2) continue;
                    for (int K = k; K <= min(n/2, k+(m-l+1)/2); K++) {
                        ckmax(dp[l][r][k], (m-l+1)/2 + dp[m+1][r][K]);
                    }
                    // ckmax(dp[l][r][k], (m-l+1)/2 + dp[m+1][r][min(n/2, k + (m-l+1)/2)]);
                }
                ps(l, r, k, dp[l][r][k]);
            }
        }
    }
    ps("e1", dp[0][2][0]);
    ps("e1", dp[2][4][0]);
    ps("e1", dp[4][6][2]);


    cout << dp[0][n][0] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
