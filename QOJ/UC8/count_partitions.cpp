#include <bits/stdc++.h>
using namespace std;

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

// dp(i, j) = how many ways to partition i, and min size is j
const int N = 60;
int dp[N+1][N+1];

void solve() {
    for (int j = 0; j <= N; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
             for (int k = j; k <= i; k++) {
                 dp[i][j] += dp[i-k][k];
             }
        }
    }
    cout << dp[N][1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
