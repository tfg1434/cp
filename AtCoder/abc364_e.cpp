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
    int n, X, Y; cin >> n >> X >> Y;
    V<vi> dp(n+1, vi(X+1, inf));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        auto DP = dp;
        dp = V<vi>(n+1, vi(X+1, inf));

        for (int eaten = 0; eaten <= i; eaten++) {
            for (int cur_x = 0; cur_x <= X; cur_x++) {
                ckmin(dp[eaten][cur_x], DP[eaten][cur_x]);
                if (eaten+1 <= n && cur_x+a <= X){
                    ckmin(dp[eaten+1][cur_x+a], DP[eaten][cur_x]+b);
                }
            }
        }
    }

    int max_eaten = 0;
    for (int eaten = 0; eaten <= n; eaten++) {
        for (int cur_x = 0; cur_x <= X; cur_x++) {
            if (dp[eaten][cur_x] <= Y){
                ckmax(max_eaten, eaten);
            }
        }
    }
    if (max_eaten < n) max_eaten++;
    cout << max_eaten << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
