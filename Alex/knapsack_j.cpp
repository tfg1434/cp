// learning not to waste time. let's learn!

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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

const int max_n = 100;
const int max_w = 1e5;
int n, m, w[max_n], v[max_n], f[max_n], a[max_w+1], back[max_w+1];
vi dp;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> f[i];

    memset(back, -1, sizeof back);
    dp.assign(m+1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        auto DP = dp;
        for (int j = 0; j <= m; j++) if (DP[j] != -1) {
            for (int k = 1; k <= f[i]; k++) {
                if (j+k*w[i] > m) break;
                if (ckmax(dp[j+k*w[i]], DP[j]+k*v[i])) {
                    back[j+k*w[i]] = i;
                }
            }
        }
        // for (int j = 0; j <= m; j++) ps(j, dp[j]);
    }

    int ans = 0, sol = 0;
    for (int j = 0; j <= m; j++) if (ckmax(ans, dp[j])) sol = j;
    ps(ans);
    vi freq(n);
    while (back[sol] != -1) {
        freq[back[sol]]++;
        sol -= w[back[sol]];
    }
    for (int i = 0; i < n; i++) cout << freq[i] << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
