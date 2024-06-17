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

const int P = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0, sol = 0;

    vi dp(3), ways(3);
    V<bool> possible(3);
    dp[1] = s[1] == 'C';
    ways[1] = 1;
    possible[1] = true;
    ans = 1+2*dp[1];
    sol = 1;

    for (int i = 1; i < n; i++) {
        string s; cin >> s;
        auto DP = dp;
        auto WAYS = ways;
        auto POSSIBLE = possible;
        dp.assign(3, 0);
        ways.assign(3, 0);
        possible.assign(3, false);
        for (int j = 0; j < 3; j++) if (s[j] != 'W') {
            for (int k : {j-1, j, j+1}) if (0 <= k && k < 3 && POSSIBLE[k]) {
                possible[j] = true;
                if (ckmax(dp[j], DP[k]+(s[j] == 'C'))) {
                    ways[j] = 0;
                }
                if (dp[j] == DP[k]+(s[j] == 'C')) {
                    ways[j] += WAYS[k];
                    if (ways[j] >= P) ways[j] -= P;
                }
            }

            if (possible[j]) {
                int x = i+1 + 2*dp[j];
                if (ckmax(ans, x)) sol = 0;
                if (x == ans) {
                    sol += ways[j];
                    if (sol >= P) sol -= P;
                }
            }
        }
    }
    cout << ans << ' ' << sol << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
