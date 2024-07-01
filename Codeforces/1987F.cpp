// O(n^2)

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

const int N = 800;
int dp[N+1][N+1];

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i >= j) dp[i][j] = 0;
            else dp[i][j] = inf;
        }
    }

    for (int len = 1; len <= n; len++) {
        for (int l = 0; l+len <= n; l++) {
            if (a[l] > l || a[l]%2 != l%2) continue;
            int r = l+len;
            for (int m = l+1; m < r; m += 2) {
                if (dp[l+1][m] > (l-a[l])/2) continue;
                int op = max((l-a[l])/2, dp[m+1][r]-(m-l+1)/2);
                ckmin(dp[l][r], op);
            }
        }
    }


    vi dp2(n+1);
    for (int i = 1; i <= n; i++) {
        dp2[i] = dp2[i-1];
        for (int j = 0; j <= i; j++) {
            if (dp2[j] >= dp[j][i]) {
                ckmax(dp2[i], dp2[j]+(i-j+1)/2);
            }
        }
    }
    cout << dp2[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
